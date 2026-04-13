#!/usr/bin/env python3
"""matcher_bot.py — Phase A1/A2: compiler-aware flag + source search.

Spec: docs/tracking/next-attack-plan-20260412.md (Track A Phase A1 + A2).

Given a C++ source + DOL address/size, try combinations of:
  - flag-space variants (M0..M10 — see FLAG_VARIANTS)
  - text-level mutators (M10 decl-order swap, M11 compiler-barrier inject)
...and pick the first that byte-matches the DOL. Uses tools/verify_match.sh
as the correctness oracle.

Exit codes:
    0 = MATCH (prints winner path + flags line, also copies to out dir)
    2 = NEAR_MATCH (writes top-3 variants + scores to out dir)
    1 = usage / tool error

Usage:
    python tools/matcher_bot.py --wip src/wip/version_diff/match_0xADDR_name.cpp
    python tools/matcher_bot.py --src path.cpp --addr 0x80322EA8 --size 172
    python tools/matcher_bot.py --wip file.cpp --addr 0x... --size ...    # overrides
    python tools/matcher_bot.py --wip file.cpp --budget 60 --no-text

Options:
    --out-dir DIR        Where to dump variants + report (default: build/matcher_bot)
    --budget N           Max compile attempts per target (default 60)
    --no-text            Disable M10/M11 text mutators — flag-space only (A1 mode)
    --verbose            Print per-variant compile log tails
"""

from __future__ import annotations

import argparse
import os
import re
import shutil
import subprocess
import sys
from dataclasses import dataclass, field
from pathlib import Path
from typing import Optional

REPO_ROOT = Path(__file__).resolve().parent.parent
VERIFY_SCRIPT = REPO_ROOT / "tools" / "verify_match.sh"
DEFAULT_OUT_DIR = REPO_ROOT / "build" / "matcher_bot"

# verify_match.sh is written for msys2 bash + devkitPPC/SN toolchain living
# under F:\coding\Decompiles\Tools\devkitPro. Plain `bash` on Windows resolves
# to WSL bash which can't see those paths, so we pin to the msys2 bash that
# shipped with devkitPro.
_MSYS2_BASH_CANDIDATES = [
    Path(r"F:\coding\Decompiles\Tools\devkitPro\msys2\usr\bin\bash.exe"),
    Path(r"C:\devkitPro\msys2\usr\bin\bash.exe"),
]


def _find_bash() -> str:
    for candidate in _MSYS2_BASH_CANDIDATES:
        if candidate.is_file():
            return str(candidate)
    env_override = os.environ.get("MATCHER_BOT_BASH")
    if env_override and Path(env_override).is_file():
        return env_override
    # Fallback — probably wrong on Windows, but better than silent failure.
    return "bash"


BASH = _find_bash()


def _to_bash_path(p: Path) -> str:
    """Convert a Windows absolute path to an msys2-style /f/... path.
    msys2 bash accepts Windows paths in most contexts, but scripts that
    internally do `grep foo "$1"` or `sed -i ... "$1"` work more reliably
    with /drive/... paths. Relative paths are returned unchanged.
    """
    if not p.is_absolute():
        return str(p).replace("\\", "/")
    parts = p.parts
    if len(parts) >= 1 and len(parts[0]) >= 2 and parts[0][1] == ":":
        drive = parts[0][0].lower()
        rest = "/".join(parts[1:])
        return f"/{drive}/{rest}"
    return str(p).replace("\\", "/")

# Phase A1 flag-space mutation set.
# Each entry is (label, flag-string-for-FLAGS-header).
# An empty flag-string means "no // FLAGS: header — let verify_match.sh use
# its default SN_FLAGS". That's equivalent to the baseline M0.
FLAG_VARIANTS: list[tuple[str, str]] = [
    ("M0_default",                    ""),
    ("M1_no_schedule_insns",          "-fno-schedule-insns"),
    ("M2_no_schedule_insns2",         "-fno-schedule-insns2"),
    ("M3_no_elide_ctors",             "-fno-elide-constructors"),
    ("M4_no_peephole",                "-fno-peephole"),
    ("M5_M1_M3",                      "-fno-schedule-insns -fno-elide-constructors"),
    ("M6_M1_M4",                      "-fno-schedule-insns -fno-peephole"),
    ("M7_M3_M4",                      "-fno-elide-constructors -fno-peephole"),
    ("M8_M1_M3_M4",                   "-fno-schedule-insns -fno-elide-constructors -fno-peephole"),
    ("M9_all_four",                   "-fno-schedule-insns -fno-schedule-insns2 -fno-elide-constructors -fno-peephole"),
    # Counter-intuitive but proven on BGExec_LoadHouse in session 1:
    ("M10_bgexec_combo",              "-fno-elide-constructors -fno-peephole"),
]


@dataclass
class VariantResult:
    label: str
    flags: str
    source_path: Path
    match: bool
    score: float
    mismatch_chunks: int
    compile_failed: bool
    verify_stdout: str = field(repr=False, default="")
    verify_exit: int = 0

    def sort_key(self) -> tuple[int, float, int]:
        # Higher is better; MATCH first, then higher score, then fewer mismatches.
        return (1 if self.match else 0, self.score, -self.mismatch_chunks)


# ---------- source handling ----------

FLAGS_LINE_RE = re.compile(r"^\s*//\s*FLAGS:\s*(.*?)\s*$")
HEADER_ADDR_RE = re.compile(r"0x([0-9A-Fa-f]{8})")
HEADER_SIZE_RE_PARENS = re.compile(r"\(\s*([0-9]+)\s*[Bb]\s*\)")
HEADER_SIZE_RE_WORD = re.compile(r"\b([0-9]+)\s*(?:bytes|B)\b")


def read_source(path: Path) -> list[str]:
    return path.read_text(encoding="utf-8", errors="replace").splitlines(keepends=True)


def parse_header_meta(lines: list[str]) -> tuple[Optional[int], Optional[int]]:
    """Best-effort scan of the first ~8 lines for an address and size."""
    addr: Optional[int] = None
    size: Optional[int] = None
    for raw in lines[:8]:
        line = raw.rstrip("\n")
        if addr is None:
            m = HEADER_ADDR_RE.search(line)
            if m:
                addr = int(m.group(1), 16)
        if size is None:
            m = HEADER_SIZE_RE_PARENS.search(line)
            if not m:
                m = HEADER_SIZE_RE_WORD.search(line)
            if m:
                try:
                    size = int(m.group(1))
                except ValueError:
                    pass
        if addr is not None and size is not None:
            break
    return addr, size


def rewrite_flags(lines: list[str], new_flags: str) -> list[str]:
    """Return a copy of `lines` with the first `// FLAGS:` line rewritten
    (or removed if `new_flags` is empty). If no FLAGS line exists and
    `new_flags` is non-empty, prepend one.
    """
    out: list[str] = []
    rewrote = False
    for raw in lines:
        if not rewrote and FLAGS_LINE_RE.match(raw):
            rewrote = True
            if new_flags:
                out.append(f"// FLAGS: {new_flags}\n")
            # else: drop the line (default flags)
            continue
        out.append(raw)
    if not rewrote and new_flags:
        out.insert(0, f"// FLAGS: {new_flags}\n")
    return out


# ---------- Phase A2 text mutators ----------
#
# Each mutator takes the full source line-list and returns a list of
# (label, mutated-lines) pairs. Identity is handled separately; these only
# produce *new* variants. An empty list means "no useful mutations here".

# Match a local variable declaration:
#   indent Type name ;
#   indent Type name = expr;
#   indent Type * name ;
# Captures the indent so adjacent-swap can keep indentation.
# Deliberately conservative — skips control-flow lines, operator lines, etc.
DECL_RE = re.compile(
    r"^(?P<indent>[ \t]+)"
    r"(?P<type>(?:const\s+)?(?:unsigned\s+|signed\s+)?[A-Za-z_][A-Za-z0-9_:]*\s*\*?\s*\*?)"
    r"\s+(?P<name>[A-Za-z_][A-Za-z0-9_]*)"
    r"(?:\s*=\s*[^;{}]*)?"
    r"\s*;\s*$"
)

# Match a store-like statement (assignment to a deref / member / array).
# Purposefully looser than DECL_RE — covers:
#   *p = x;
#   p->field = x;
#   p->f = obj->f2;
#   this->x = y;
#   arr[0] = v;
#   *(T*)p = q;
# Rejects local-decl lines (they'd look like a store but have a type name).
STORE_RE = re.compile(
    r"^(?P<indent>[ \t]+)"
    r"(?:\*|&)?"
    r"(?P<lhs>[^=;{}]+?)"      # everything up to = (non-greedy)
    r"\s*=\s*"
    r"(?P<rhs>[^;{}]+?)"
    r"\s*;\s*$"
)

# Control-flow / scope tokens that disqualify a line from being a "store" for
# barrier purposes (we don't want to inject between `if` and its body).
_SCOPE_TOKENS = ("if", "else", "for", "while", "do", "return", "switch",
                 "case", "break", "continue", "goto", "throw")


def _is_store_line(line: str) -> bool:
    stripped = line.lstrip()
    if not stripped or stripped.startswith("//") or stripped.startswith("/*"):
        return False
    for tok in _SCOPE_TOKENS:
        if stripped == tok or stripped.startswith(tok + " ") or stripped.startswith(tok + "("):
            return False
    m = STORE_RE.match(line)
    if not m:
        return False
    # Disqualify if it looks like a local variable declaration (covered by M10).
    if DECL_RE.match(line):
        return False
    return True


_FUNC_OPEN_RE = re.compile(r"\)\s*(?:const\s*)?(?:noexcept\s*)?\{")
_STRUCT_OPEN_RE = re.compile(r"\b(struct|class|union)\b[^;]*\{")


def _decl_block_is_in_function_body(lines: list[str], block_start: int) -> bool:
    """Scan backwards from block_start to the nearest `{` line, and classify
    it as function body vs struct/class body. Returns True only for function
    bodies. This prevents M10 from reordering struct field declarations (which
    would be a structural ABI change, not a local scheduling tweak).
    """
    depth = 0
    for i in range(block_start - 1, -1, -1):
        line = lines[i]
        # Count nesting: every `}` we see on the way up, we need one more
        # matching `{` to get back to our enclosing scope.
        depth += line.count("}")
        opens_on_line = line.count("{")
        if opens_on_line:
            depth -= opens_on_line
            if depth < 0:
                # Found the enclosing `{`. Classify by what's on that line
                # (or, if the `{` is alone, the previous nonblank line).
                check_idx = i
                if _FUNC_OPEN_RE.search(line):
                    return True
                if _STRUCT_OPEN_RE.search(line):
                    return False
                # `{` on its own line — look one line up for the signature.
                j = i - 1
                while j >= 0 and not lines[j].strip():
                    j -= 1
                if j >= 0:
                    prev = lines[j]
                    if _FUNC_OPEN_RE.search(prev) or prev.rstrip().endswith(")"):
                        return True
                    if _STRUCT_OPEN_RE.search(prev):
                        return False
                # Unknown — err on the safe side and reject.
                return False
    return False


def m10_var_swap_mutator(lines: list[str]) -> list[tuple[str, list[str]]]:
    """Adjacent-swap permutations of consecutive local variable declarations.

    Finds the first block of 2+ consecutive declaration lines inside a
    function body (NOT a struct/class declaration) and produces one variant
    per adjacent swap within that block.
    """
    block_start: Optional[int] = None
    block_end: Optional[int] = None
    run_start: Optional[int] = None
    for i, raw in enumerate(lines):
        if DECL_RE.match(raw):
            if run_start is None:
                run_start = i
        else:
            if run_start is not None and i - run_start >= 2:
                if _decl_block_is_in_function_body(lines, run_start):
                    block_start, block_end = run_start, i
                    break
            run_start = None
    if block_start is None and run_start is not None and len(lines) - run_start >= 2:
        if _decl_block_is_in_function_body(lines, run_start):
            block_start, block_end = run_start, len(lines)
    if block_start is None or block_end is None:
        return []

    variants: list[tuple[str, list[str]]] = []
    block_len = block_end - block_start
    # At most 6 adjacent-swaps so we don't blow the budget on long decl blocks.
    for k in range(min(block_len - 1, 6)):
        i = block_start + k
        new_lines = list(lines)
        new_lines[i], new_lines[i + 1] = new_lines[i + 1], new_lines[i]
        label = f"T10_swap{k}"
        variants.append((label, new_lines))
    return variants


def m11_barrier_mutator(lines: list[str]) -> list[tuple[str, list[str]]]:
    """Inject `asm volatile("" ::: "memory");` between consecutive stores.

    Finds adjacent `lhs = rhs;` lines (not decls, not control-flow) and
    produces:
      - Single-barrier variants: one per insertion point (capped at 8)
      - Double-barrier variants: all C(N, 2) unordered pairs of insertion
        points, capped at 15 (A3 pivot — single barriers left EThread
        and audiostreamman 2 chunks off; multi-barrier closes the tail).

    Empty-string asm is whitelisted by the pre-commit hook at
    .git/hooks/pre-commit:93-105.
    """
    store_idxs: list[int] = [i for i, raw in enumerate(lines) if _is_store_line(raw)]
    # Insertion points are gaps between consecutive store lines where they
    # are also consecutive in the source (i and i+1 both stores).
    insert_points: list[int] = []
    for j, idx in enumerate(store_idxs[:-1]):
        nxt = store_idxs[j + 1]
        if nxt == idx + 1:
            insert_points.append(idx + 1)
    # Cap single-barrier insertion points to 8 to keep single-barrier
    # budget bounded.
    single_points = insert_points[:8]

    # SN ProDG cc1plus 2.95 rejects the `:::` shorthand. The spaced
    # form `: : : "memory"` parses identically at the AST level and
    # is accepted. Still an empty-string asm (zero instructions) so
    # it passes the pre-commit whitelist.
    def _make_barrier(line_at: int) -> str:
        indent_src = lines[line_at] if line_at < len(lines) else ""
        m = re.match(r"^([ \t]+)", indent_src)
        indent = m.group(1) if m else "    "
        return f'{indent}asm volatile("" : : : "memory");\n'

    def _insert_barriers(sorted_positions: list[int]) -> list[str]:
        """Insert barriers at each position. Positions MUST be sorted
        ascending; we walk from the back so earlier indices stay valid."""
        out = list(lines)
        for pos in sorted(sorted_positions, reverse=True):
            barrier = _make_barrier(pos)
            out = out[:pos] + [barrier] + out[pos:]
        return out

    variants: list[tuple[str, list[str]]] = []

    # Single-barrier variants (A2 behavior).
    for k, pos in enumerate(single_points):
        new_lines = _insert_barriers([pos])
        variants.append((f"T11_barrier{k}", new_lines))

    # Double-barrier variants (A3 addition).
    # Use the full insert_points list (up to 8 => C(8,2)=28, we cap at 15).
    # Prefer pairs that span different regions of the function (skip pairs
    # where both positions are back-to-back — those degrade into slightly
    # stronger single barriers and rarely change codegen usefully).
    double_pairs: list[tuple[int, int]] = []
    n_pts = min(len(insert_points), 8)
    for a in range(n_pts):
        for b in range(a + 1, n_pts):
            # Skip pairs that are immediately adjacent in store order
            # (the typical "barrier right after barrier" case produces the
            # same codegen as a single barrier at that position).
            if b - a == 1 and insert_points[b] - insert_points[a] <= 2:
                continue
            double_pairs.append((insert_points[a], insert_points[b]))
    double_pairs = double_pairs[:15]

    for k, (p1, p2) in enumerate(double_pairs):
        new_lines = _insert_barriers([p1, p2])
        variants.append((f"T11_barrier2x{k}", new_lines))

    return variants


def m12_stmt_swap_mutator(lines: list[str]) -> list[tuple[str, list[str]]]:
    """Adjacent-swap permutations of consecutive store-like statements
    inside a function body.

    Analogous to M10 but for body statements (not local variable decls).
    Used when the source has two stores in the wrong order relative to
    the DOL — no amount of compiler-barrier preserves-source-order will
    fix that, only swapping the source lines will.

    Strategy: find every maximal run of 2+ consecutive store-like lines
    inside a function body, then for each pair (i, i+1) inside that run
    produce one swap variant. Caps at 10 total swap candidates per
    function to bound variant explosion.
    """
    store_idxs: list[int] = [i for i, raw in enumerate(lines) if _is_store_line(raw)]
    if len(store_idxs) < 2:
        return []

    # Find maximal runs of consecutive (index-wise) store lines.
    runs: list[list[int]] = []
    current: list[int] = [store_idxs[0]]
    for idx in store_idxs[1:]:
        if idx == current[-1] + 1:
            current.append(idx)
        else:
            if len(current) >= 2:
                runs.append(current)
            current = [idx]
    if len(current) >= 2:
        runs.append(current)
    if not runs:
        return []

    # Only swap within runs that are inside a function body (use the same
    # backwards-scan helper M10 uses — avoids swapping lines inside a
    # struct/class body or at top-level).
    variants: list[tuple[str, list[str]]] = []
    for run in runs:
        if not _decl_block_is_in_function_body(lines, run[0]):
            continue
        for k in range(len(run) - 1):
            a = run[k]
            b = run[k + 1]
            new_lines = list(lines)
            new_lines[a], new_lines[b] = new_lines[b], new_lines[a]
            # Label includes file-line index so several runs distinguish.
            variants.append((f"T12_swap@{a}", new_lines))
            if len(variants) >= 10:
                return variants
    return variants


def build_text_variants(lines: list[str]) -> list[tuple[str, list[str]]]:
    """Produce the ordered list of text mutations to try, NOT including identity.
    Order: M11 single/double barrier → M12 statement swap → M10 decl swap.
    Priority based on cracks per target class:
      - M11 has 2/2 proven cracks (movieman indirectly via flag combo,
        EThread via double-barrier)
      - M12 is brand new and targets the "source is in wrong order" wall
        (audiostreamman class)
      - M10 is the fallback for reg-alloc walls driven by local-decl order
    """
    out: list[tuple[str, list[str]]] = []
    out.extend(m11_barrier_mutator(lines))
    out.extend(m12_stmt_swap_mutator(lines))
    out.extend(m10_var_swap_mutator(lines))
    return out


# ---------- Phase A3 permuter mutators (M13-M20) ----------
#
# These are stochastic mutators for the hill-climbing permuter mode.
# Each takes source lines and returns a SINGLE mutated variant (random site).
# Unlike M10-M12 which enumerate all variants upfront, these pick one random
# applicable site per invocation — the search loop calls them repeatedly.

import random

# Regex for local variable type keywords we can swap
_LOCAL_TYPE_RE = re.compile(
    r"^(?P<indent>[ \t]+)"
    r"(?P<qual>(?:const\s+)?(?:static\s+)?)"
    r"(?P<type>(?:unsigned\s+|signed\s+)?(?:int|short|char|long))"
    r"(?P<rest>\s+[A-Za-z_][A-Za-z0-9_]*(?:\s*=\s*[^;{}]*)?\s*;\s*)$"
)

_TYPE_SWAPS = {
    "int": ["short", "unsigned int", "long"],
    "short": ["int", "unsigned short", "char"],
    "char": ["int", "short", "unsigned char"],
    "long": ["int", "unsigned long"],
    "unsigned int": ["int", "unsigned short", "unsigned long"],
    "unsigned short": ["short", "unsigned int", "int"],
    "unsigned char": ["char", "unsigned int", "int"],
    "unsigned long": ["long", "unsigned int"],
    "signed int": ["int", "unsigned int", "short"],
    "signed short": ["short", "unsigned short"],
    "signed char": ["char", "unsigned char"],
}


def m13_type_width_swap(lines: list[str]) -> Optional[tuple[str, list[str]]]:
    """Swap the type of a random local variable (int↔short↔char↔unsigned)."""
    candidates = []
    for i, raw in enumerate(lines):
        m = _LOCAL_TYPE_RE.match(raw)
        if m and _decl_block_is_in_function_body(lines, i):
            candidates.append((i, m))
    if not candidates:
        return None
    idx, m = random.choice(candidates)
    old_type = m.group("type")
    # Normalize for lookup
    normalized = old_type.strip()
    swaps = _TYPE_SWAPS.get(normalized)
    if not swaps:
        return None
    new_type = random.choice(swaps)
    new_line = f"{m.group('indent')}{m.group('qual')}{new_type}{m.group('rest')}"
    if not new_line.endswith("\n"):
        new_line += "\n"
    out = list(lines)
    out[idx] = new_line
    return (f"T13_type_{normalized}_to_{new_type.replace(' ', '_')}@{idx}", out)


# Regex for expressions we can wrap in a cast
_EXPR_IN_ASSIGN_RE = re.compile(
    r"^(?P<indent>[ \t]+)(?P<lhs>[^=;{}]+?)\s*=\s*(?P<rhs>[^;{}]+?)\s*;\s*$"
)
_CAST_TYPES = ["(int)", "(short)", "(unsigned int)", "(unsigned short)", "(char)", "(unsigned char)"]


def m14_cast_insertion(lines: list[str]) -> Optional[tuple[str, list[str]]]:
    """Wrap the RHS of a random assignment in a type cast."""
    candidates = []
    for i, raw in enumerate(lines):
        m = _EXPR_IN_ASSIGN_RE.match(raw)
        if m and not raw.lstrip().startswith("//") and not DECL_RE.match(raw):
            # Skip if RHS already starts with a cast
            rhs = m.group("rhs").strip()
            if not rhs.startswith("("):
                candidates.append((i, m))
    if not candidates:
        return None
    idx, m = random.choice(candidates)
    cast = random.choice(_CAST_TYPES)
    rhs = m.group("rhs").strip()
    new_line = f"{m.group('indent')}{m.group('lhs')} = {cast}({rhs});\n"
    out = list(lines)
    out[idx] = new_line
    return (f"T14_cast_{cast[1:-1].replace(' ', '_')}@{idx}", out)


# Comparison operators we can invert
_CMP_PATTERNS = [
    (re.compile(r"(\S+)\s*>=\s*(\S+)"), r"!(\1 < \2)", "ge_to_notlt"),
    (re.compile(r"(\S+)\s*<=\s*(\S+)"), r"!(\1 > \2)", "le_to_notgt"),
    (re.compile(r"(\S+)\s*>\s*(\S+)"),  r"!(\1 <= \2)", "gt_to_notle"),
    (re.compile(r"(\S+)\s*<\s*(\S+)"),  r"!(\1 >= \2)", "lt_to_notge"),
    (re.compile(r"(\S+)\s*==\s*0\b"),   r"!\1", "eq0_to_not"),
    (re.compile(r"(\S+)\s*!=\s*0\b"),   r"!!\1", "ne0_to_notnot"),
]


def m15_comparison_inversion(lines: list[str]) -> Optional[tuple[str, list[str]]]:
    """Invert a comparison: x >= y → !(x < y), x == 0 → !x, etc."""
    candidates = []
    for i, raw in enumerate(lines):
        stripped = raw.lstrip()
        if stripped.startswith("//") or stripped.startswith("/*"):
            continue
        for pat, repl, label in _CMP_PATTERNS:
            if pat.search(raw):
                candidates.append((i, pat, repl, label))
    if not candidates:
        return None
    idx, pat, repl, label = random.choice(candidates)
    new_line = pat.sub(repl, lines[idx], count=1)
    out = list(lines)
    out[idx] = new_line
    return (f"T15_cmp_{label}@{idx}", out)


# Match simple early-return patterns: if (cond) return val; return default;
_EARLY_RETURN_RE = re.compile(
    r"^(?P<indent>[ \t]+)if\s*\((?P<cond>[^)]+)\)\s*return\s+(?P<val>[^;]+);\s*$"
)
_DEFAULT_RETURN_RE = re.compile(
    r"^(?P<indent>[ \t]+)return\s+(?P<default>[^;]+);\s*$"
)


def m16_preset_return(lines: list[str]) -> Optional[tuple[str, list[str]]]:
    """Transform `if(c) return v; return 0;` → `r=0; if(c) r=v; return r;`"""
    candidates = []
    for i in range(len(lines) - 1):
        m_if = _EARLY_RETURN_RE.match(lines[i])
        m_ret = _DEFAULT_RETURN_RE.match(lines[i + 1])
        if m_if and m_ret:
            candidates.append((i, m_if, m_ret))
    if not candidates:
        return None
    idx, m_if, m_ret = random.choice(candidates)
    indent = m_if.group("indent")
    cond = m_if.group("cond")
    val = m_if.group("val")
    default = m_ret.group("default")
    # Generate pre-set pattern
    var_name = "_preset_r"
    new_lines = [
        f"{indent}int {var_name} = {default};\n",
        f"{indent}if ({cond}) {var_name} = {val};\n",
        f"{indent}return {var_name};\n",
    ]
    out = list(lines)
    out[idx:idx + 2] = new_lines
    return (f"T16_preset_return@{idx}", out)


# Commutative operators
_COMMUTATIVE_RE = re.compile(
    r"(?P<a>[A-Za-z_][A-Za-z0-9_>.*\[\]]*)"
    r"\s*(?P<op>[+|&^*])\s*"
    r"(?P<b>[A-Za-z_][A-Za-z0-9_>.*\[\]]*)"
)


def m17_operand_swap(lines: list[str]) -> Optional[tuple[str, list[str]]]:
    """Swap operands of a commutative binary op: a + b → b + a."""
    candidates = []
    for i, raw in enumerate(lines):
        stripped = raw.lstrip()
        if stripped.startswith("//") or stripped.startswith("/*"):
            continue
        # Find commutative ops in assignments
        matches = list(_COMMUTATIVE_RE.finditer(raw))
        for m in matches:
            if m.group("a").strip() != m.group("b").strip():
                candidates.append((i, m))
    if not candidates:
        return None
    idx, m = random.choice(candidates)
    old = m.group(0)
    swapped = f"{m.group('b')} {m.group('op')} {m.group('a')}"
    new_line = lines[idx][:m.start()] + swapped + lines[idx][m.end():]
    out = list(lines)
    out[idx] = new_line
    return (f"T17_commute_{m.group('op')}@{idx}", out)


# Expression split: a = b + c; → a = b; a += c;
_SPLIT_ASSIGN_RE = re.compile(
    r"^(?P<indent>[ \t]+)(?P<lhs>[A-Za-z_][A-Za-z0-9_>.*\[\]]*)"
    r"\s*=\s*"
    r"(?P<first>[A-Za-z_][A-Za-z0-9_>.*\[\]]*)"
    r"\s*(?P<op>[+\-|&^])\s*"
    r"(?P<second>[A-Za-z_][A-Za-z0-9_>.*\[\]]*)"
    r"\s*;\s*$"
)


def m18_expression_split(lines: list[str]) -> Optional[tuple[str, list[str]]]:
    """Split `a = b + c;` into `a = b; a += c;`."""
    candidates = []
    for i, raw in enumerate(lines):
        m = _SPLIT_ASSIGN_RE.match(raw)
        if m and not raw.lstrip().startswith("//"):
            candidates.append((i, m))
    if not candidates:
        return None
    idx, m = random.choice(candidates)
    indent = m.group("indent")
    lhs = m.group("lhs")
    first = m.group("first")
    op = m.group("op")
    second = m.group("second")
    new_lines = [
        f"{indent}{lhs} = {first};\n",
        f"{indent}{lhs} {op}= {second};\n",
    ]
    out = list(lines)
    out[idx:idx + 1] = new_lines
    return (f"T18_split_{op}@{idx}", out)


# Negate condition: if(x) → if(!(!x)), DeMorgan on && / ||
_IF_COND_RE = re.compile(r"^(?P<pre>[ \t]+if\s*\()(?P<cond>[^)]+)(?P<post>\).*)$")


def m19_negate_condition(lines: list[str]) -> Optional[tuple[str, list[str]]]:
    """Double-negate a condition or apply DeMorgan."""
    candidates = []
    for i, raw in enumerate(lines):
        m = _IF_COND_RE.match(raw)
        if m:
            candidates.append((i, m))
    if not candidates:
        return None
    idx, m = random.choice(candidates)
    cond = m.group("cond").strip()
    # Try DeMorgan if && or || present
    if "&&" in cond:
        # !(a && b) → (!a || !b) — but we want equivalent, so double negate
        new_cond = f"!(!({cond}))"
        label = "double_negate"
    elif "||" in cond:
        new_cond = f"!(!({cond}))"
        label = "double_negate"
    elif cond.startswith("!"):
        # Remove double negation if present
        inner = cond[1:].strip()
        if inner.startswith("(") and inner.endswith(")"):
            inner = inner[1:-1]
        new_cond = inner
        label = "remove_negate"
    else:
        new_cond = f"!(!({cond}))"
        label = "double_negate"
    new_line = f"{m.group('pre')}{new_cond}{m.group('post')}"
    if not new_line.endswith("\n"):
        new_line += "\n"
    out = list(lines)
    out[idx] = new_line
    return (f"T19_{label}@{idx}", out)


# Struct deref swap: a.field → (&a)->field and vice versa
_DOT_ACCESS_RE = re.compile(r"([A-Za-z_][A-Za-z0-9_]*)\s*\.\s*([A-Za-z_][A-Za-z0-9_]*)")
_ARROW_ACCESS_RE = re.compile(r"([A-Za-z_][A-Za-z0-9_]*)\s*->\s*([A-Za-z_][A-Za-z0-9_]*)")


def m20_struct_deref_swap(lines: list[str]) -> Optional[tuple[str, list[str]]]:
    """Swap a.field → (&a)->field or p->field → (*p).field."""
    candidates = []
    for i, raw in enumerate(lines):
        stripped = raw.lstrip()
        if stripped.startswith("//") or stripped.startswith("/*"):
            continue
        for m in _DOT_ACCESS_RE.finditer(raw):
            candidates.append((i, m, "dot_to_arrow"))
        for m in _ARROW_ACCESS_RE.finditer(raw):
            candidates.append((i, m, "arrow_to_dot"))
    if not candidates:
        return None
    idx, m, direction = random.choice(candidates)
    old = m.group(0)
    if direction == "dot_to_arrow":
        new = f"(&{m.group(1)})->{m.group(2)}"
    else:
        new = f"(*{m.group(1)}).{m.group(2)}"
    new_line = lines[idx][:m.start()] + new + lines[idx][m.end():]
    out = list(lines)
    out[idx] = new_line
    return (f"T20_{direction}@{idx}", out)


# All stochastic mutators for the permuter
PERMUTER_MUTATORS = [
    m13_type_width_swap,
    m14_cast_insertion,
    m15_comparison_inversion,
    m16_preset_return,
    m17_operand_swap,
    m18_expression_split,
    m19_negate_condition,
    m20_struct_deref_swap,
]


# ---------- Hill-climbing permuter search ----------

def pick_random_mutation(
    lines: list[str],
) -> Optional[tuple[str, list[str]]]:
    """Pick a random mutator, apply it to a random site. Returns (label, mutated_lines)
    or None if no mutator found an applicable site."""
    # Shuffle mutators to avoid bias
    order = list(range(len(PERMUTER_MUTATORS)))
    random.shuffle(order)
    for idx in order:
        result = PERMUTER_MUTATORS[idx](lines)
        if result is not None:
            return result
    return None


def run_permuter(
    source_lines: list[str],
    addr: int,
    size: int,
    work_dir: Path,
    budget: int = 200,
    max_chain: int = 20,
    verbose: bool = False,
) -> list[VariantResult]:
    """Hill-climbing search with stochastic mutations.

    1. Score baseline with each flag variant
    2. Pick best-scoring flag as the base
    3. Repeatedly apply random mutations, keep improvements
    4. 60% chance to reset to best-known on failure, 40% keep exploring
    5. Stop on MATCH or budget exhaustion
    """
    work_dir.mkdir(parents=True, exist_ok=True)
    results: list[VariantResult] = []
    best_score = 0.0
    best_lines = source_lines
    best_flags = ""
    best_label = "baseline"
    chain_depth = 0
    attempt = 0

    # Phase 1: Try all flag variants on original source (same as A1)
    print("  Phase 1: Flag sweep on baseline source...")
    for flag_label, flag_str in FLAG_VARIANTS:
        attempt += 1
        variant_src = work_dir / f"p1_{flag_label}.cpp"
        variant_lines = rewrite_flags(source_lines, flag_str)
        variant_src.write_text("".join(variant_lines), encoding="utf-8")

        exit_code, output = run_verify(variant_src, addr, size, outdir=work_dir)
        matched, score, mismatch_chunks, compile_failed = score_verify_output(
            exit_code, output, size
        )
        result = VariantResult(
            label=f"p1_{flag_label}", flags=flag_str or "(default)",
            source_path=variant_src, match=matched, score=score,
            mismatch_chunks=mismatch_chunks, compile_failed=compile_failed,
            verify_stdout=output, verify_exit=exit_code,
        )
        results.append(result)

        status = "MATCH" if matched else ("FAIL" if compile_failed else f"{score*100:5.1f}%")
        print(f"    [{attempt:3d}/{budget}] {flag_label:30s} {status}")

        if matched:
            return results
        if score > best_score:
            best_score = score
            best_lines = source_lines  # original source, not flag-rewritten
            best_flags = flag_str
            best_label = flag_label

    if attempt >= budget:
        return results

    print(f"  Phase 2: Hill-climbing from best={best_label} (score={best_score*100:.1f}%)...")
    current_lines = best_lines
    current_flags = best_flags
    current_score = best_score

    while attempt < budget:
        attempt += 1

        # Pick a random mutation
        mutation = pick_random_mutation(current_lines)
        if mutation is None:
            # No applicable mutations — try a different flag combo
            flag_label, flag_str = random.choice(FLAG_VARIANTS)
            mutation = (f"flag_{flag_label}", current_lines)
            current_flags = flag_str

        mut_label, mut_lines = mutation

        # Occasionally randomize flags too (20% chance)
        if random.random() < 0.2:
            flag_label, flag_str = random.choice(FLAG_VARIANTS)
            current_flags = flag_str

        # Sanitize label for Windows filenames (no *|<>?:" etc.)
        safe_label = re.sub(r'[<>:"/\\|?*]', '_', mut_label[:40])
        variant_src = work_dir / f"p2_{attempt:04d}_{safe_label}.cpp"
        variant_lines = rewrite_flags(mut_lines, current_flags)
        variant_src.write_text("".join(variant_lines), encoding="utf-8")

        exit_code, output = run_verify(variant_src, addr, size, outdir=work_dir)
        matched, score, mismatch_chunks, compile_failed = score_verify_output(
            exit_code, output, size
        )
        result = VariantResult(
            label=f"p2_{mut_label}", flags=current_flags or "(default)",
            source_path=variant_src, match=matched, score=score,
            mismatch_chunks=mismatch_chunks, compile_failed=compile_failed,
            verify_stdout=output, verify_exit=exit_code,
        )
        results.append(result)

        if verbose or matched or score > best_score:
            status = "MATCH" if matched else ("FAIL" if compile_failed else f"{score*100:5.1f}%")
            improvement = ""
            if score > best_score and not matched:
                improvement = f" (+{(score - best_score)*100:.1f}%)"
            print(f"    [{attempt:3d}/{budget}] {mut_label[:35]:35s} {status}{improvement}")

        if matched:
            print(f"\n  MATCH at attempt {attempt}! Mutation chain: {mut_label}")
            return results

        if score > best_score:
            # Improvement — keep this as new baseline
            best_score = score
            best_lines = mut_lines
            best_flags = current_flags
            best_label = mut_label
            current_lines = mut_lines
            chain_depth += 1
            if chain_depth >= max_chain:
                # Chain too long — reset to best
                current_lines = best_lines
                chain_depth = 0
        elif score >= current_score:
            # Same or similar — keep exploring from here (chain continues)
            current_lines = mut_lines
            chain_depth += 1
            if chain_depth >= max_chain:
                current_lines = best_lines
                chain_depth = 0
        else:
            # Worse — probabilistic reset
            if random.random() < 0.6:
                current_lines = best_lines
                current_flags = best_flags
                chain_depth = 0
            else:
                # Keep exploring (40% chance)
                current_lines = mut_lines
                chain_depth += 1

    print(f"  Budget exhausted. Best score: {best_score*100:.1f}% ({best_label})")
    return results


# ---------- Batch mode ----------

def run_batch(
    batch_dir: Path,
    out_dir: Path,
    budget: int,
    permute: bool,
    enable_text: bool,
    verbose: bool,
) -> int:
    """Run permuter/matcher across all .cpp files in batch_dir."""
    cpp_files = sorted(batch_dir.glob("*.cpp"))
    if not cpp_files:
        print(f"No .cpp files found in {batch_dir}")
        return 1

    results_dir = out_dir / "batch_results"
    results_dir.mkdir(parents=True, exist_ok=True)

    matches = []
    near_matches = []
    stuck = []

    print(f"Batch mode: {len(cpp_files)} files in {batch_dir}")
    print(f"  budget per file: {budget}")
    print(f"  mode: {'permuter (hill-climbing)' if permute else 'exhaustive'}")
    print()

    for i, cpp_file in enumerate(cpp_files, 1):
        lines = read_source(cpp_file)
        addr, size = parse_header_meta(lines)
        if addr is None or size is None:
            print(f"[{i:3d}/{len(cpp_files)}] SKIP {cpp_file.name} (no addr/size header)")
            stuck.append((cpp_file.name, 0.0, "no header"))
            continue

        print(f"[{i:3d}/{len(cpp_files)}] {cpp_file.name} (0x{addr:08X}, {size}B)")

        work_dir = results_dir / f"{cpp_file.stem}_0x{addr:08X}"
        if work_dir.exists():
            shutil.rmtree(work_dir)

        if permute:
            file_results = run_permuter(lines, addr, size, work_dir, budget, verbose=verbose)
        else:
            candidates = build_candidates(lines, budget, enable_text=enable_text)
            file_results = run_candidates(candidates, addr, size, work_dir, verbose=verbose)

        winner = next((r for r in file_results if r.match), None)
        if winner:
            matches.append((cpp_file.name, winner.label, winner.flags))
            print(f"  => MATCH ({winner.label})\n")
        else:
            ranked = sorted(file_results, key=VariantResult.sort_key, reverse=True)
            top = ranked[0] if ranked else None
            top_score = top.score if top else 0.0
            if top_score >= 0.8:
                near_matches.append((cpp_file.name, top_score, top.label if top else ""))
                print(f"  => NEAR ({top_score*100:.1f}%)\n")
            else:
                stuck.append((cpp_file.name, top_score, top.label if top else ""))
                print(f"  => STUCK ({top_score*100:.1f}%)\n")

            # Save top variants for near-matches
            if top and file_results:
                save_top_variants(file_results, work_dir, addr, size, cpp_file.stem)

    # Print summary
    print("\n" + "=" * 72)
    print(f"BATCH SUMMARY: {len(cpp_files)} files processed")
    print(f"  MATCH: {len(matches)}")
    for name, label, flags in matches:
        print(f"    {name} — {label} (flags: {flags})")
    print(f"  NEAR (≥80%): {len(near_matches)}")
    for name, score, label in near_matches:
        print(f"    {name} — {score*100:.1f}% ({label})")
    print(f"  STUCK (<80%): {len(stuck)}")
    print("=" * 72)

    # Write summary to file
    summary_path = results_dir / "batch_summary.txt"
    with open(summary_path, "w") as f:
        f.write(f"Batch run: {len(cpp_files)} files, budget={budget}, permute={permute}\n\n")
        f.write(f"MATCH ({len(matches)}):\n")
        for name, label, flags in matches:
            f.write(f"  {name} — {label} (flags: {flags})\n")
        f.write(f"\nNEAR ({len(near_matches)}):\n")
        for name, score, label in near_matches:
            f.write(f"  {name} — {score*100:.1f}% ({label})\n")
        f.write(f"\nSTUCK ({len(stuck)}):\n")
        for name, score, label in stuck:
            f.write(f"  {name} — {score*100:.1f}% ({label})\n")
    print(f"\nSummary written to {summary_path}")

    return 0 if matches else 2


# ---------- verify_match.sh wrapper ----------

def run_verify(source_path: Path, addr: int, size: int, outdir: Path | None = None) -> tuple[int, str]:
    """Invoke verify_match.sh. Returns (exit_code, stdout+stderr).

    When `outdir` is provided, passes --outdir to verify_match.sh so that the
    .o / .s / _clean.cpp temp files are written into a unique per-target
    directory. Required when multiple matcher_bot processes run concurrently
    (variant labels collide in the default build/verify dir otherwise).
    """
    cmd = [
        BASH,
        _to_bash_path(VERIFY_SCRIPT),
    ]
    if outdir is not None:
        cmd.extend(["--outdir", _to_bash_path(outdir)])
    cmd.extend([
        _to_bash_path(source_path),
        f"0x{addr:08X}",
        str(size),
    ])
    try:
        proc = subprocess.run(
            cmd,
            cwd=str(REPO_ROOT),
            capture_output=True,
            text=True,
            timeout=180,
        )
    except subprocess.TimeoutExpired as e:
        return 124, f"TIMEOUT after {e.timeout}s"
    return proc.returncode, (proc.stdout or "") + (proc.stderr or "")


MATCH_RE = re.compile(r"^MATCH!", re.MULTILINE)
MISMATCH_OFFSET_RE = re.compile(r"^\s*offset 0x[0-9a-fA-F]+:", re.MULTILINE)
SIZE_MISMATCH_RE = re.compile(r"^SIZE_MISMATCH", re.MULTILINE)
COMPILE_FAIL_RE = re.compile(r"^(COMPILE FAILED|ASSEMBLE FAILED)", re.MULTILINE)


def score_verify_output(exit_code: int, output: str, size: int) -> tuple[bool, float, int, bool]:
    """Parse verify_match.sh output into (match, score, mismatch_chunks, compile_failed).

    Score model (Phase A1):
        - MATCH:          score = 1.0
        - COMPILE FAILED: score = 0.0, compile_failed=True
        - SIZE_MISMATCH:  score = 0.0
        - MISMATCH:       score = max(0, 1 - (mismatch_chunks * 4) / size)
                          where mismatch_chunks counts 4-byte words that
                          differ in the reloc-masked comparison
                          (verify_match.sh prints one line per 4-byte word:
                          `offset 0x00c: DOL=b00b000c  COMPILED=b003000c`)
    This is a rough proxy — the true diff is done in byte space inside
    verify_match.sh — but it's monotone-enough to rank variants.
    """
    if COMPILE_FAIL_RE.search(output):
        return False, 0.0, 0, True
    if exit_code == 0 or MATCH_RE.search(output):
        return True, 1.0, 0, False
    if SIZE_MISMATCH_RE.search(output):
        return False, 0.0, 0, False
    chunks = len(MISMATCH_OFFSET_RE.findall(output))
    if chunks == 0 and exit_code != 0:
        # No MATCH marker, no mismatch offsets, but nonzero exit.
        # verify_match.sh uses `set -e`, so if cc1plus/NgcAs crashes it
        # bails out before printing "COMPILE FAILED". Treat as compile
        # failure rather than falsely crediting score=1.0 for zero chunks.
        return False, 0.0, 0, True
    if size <= 0:
        return False, 0.0, chunks, False
    bytes_wrong = min(size, chunks * 4)
    score = max(0.0, 1.0 - bytes_wrong / size)
    return False, score, chunks, False


# ---------- main drive loop ----------

# Compact flag set used when attaching flags to a text-mutated variant.
# Keeps budget manageable: 5 flags × text_variant is tight enough to fit
# many text variants into a 60-compile budget.
COMPACT_FLAGS: list[tuple[str, str]] = [
    ("M0_default",          ""),
    ("M1_no_schedule_insns", "-fno-schedule-insns"),
    ("M3_no_elide_ctors",    "-fno-elide-constructors"),
    ("M7_M3_M4",             "-fno-elide-constructors -fno-peephole"),
    ("M8_M1_M3_M4",          "-fno-schedule-insns -fno-elide-constructors -fno-peephole"),
]


def build_candidates(
    source_lines: list[str],
    budget: int,
    enable_text: bool,
) -> list[tuple[str, str, list[str]]]:
    """Produce an ordered list of (combined_label, flag_string, mutated_lines)
    candidates, capped at `budget`. Order = priority:
        1. identity text × all 11 flag variants (A1 baseline)
        2. each text mutation × compact flag set (M11 first, then M10)
    """
    candidates: list[tuple[str, str, list[str]]] = []

    # Phase A1 baseline — identity text, full flag space.
    for flag_label, flag_str in FLAG_VARIANTS:
        candidates.append((f"T0_identity__{flag_label}", flag_str, source_lines))
        if len(candidates) >= budget:
            return candidates

    if not enable_text:
        return candidates

    # Phase A2 — text mutations × compact flag set.
    text_variants = build_text_variants(source_lines)
    for text_label, text_lines in text_variants:
        for flag_label, flag_str in COMPACT_FLAGS:
            candidates.append((f"{text_label}__{flag_label}", flag_str, text_lines))
            if len(candidates) >= budget:
                return candidates
    return candidates


def run_candidates(
    candidates: list[tuple[str, str, list[str]]],
    addr: int,
    size: int,
    work_dir: Path,
    verbose: bool = False,
) -> list[VariantResult]:
    work_dir.mkdir(parents=True, exist_ok=True)
    results: list[VariantResult] = []

    for combined_label, flag_str, text_lines in candidates:
        variant_src = work_dir / f"{combined_label}.cpp"
        variant_lines = rewrite_flags(text_lines, flag_str)
        variant_src.write_text("".join(variant_lines), encoding="utf-8")

        # Pass work_dir as --outdir so verify_match.sh's intermediates land in
        # the per-target unique directory. Prevents cross-process collisions
        # when multiple matcher_bot runs hit the same variant label.
        exit_code, output = run_verify(variant_src, addr, size, outdir=work_dir)
        matched, score, mismatch_chunks, compile_failed = score_verify_output(
            exit_code, output, size
        )

        result = VariantResult(
            label=combined_label,
            flags=flag_str or "(default)",
            source_path=variant_src,
            match=matched,
            score=score,
            mismatch_chunks=mismatch_chunks,
            compile_failed=compile_failed,
            verify_stdout=output,
            verify_exit=exit_code,
        )
        results.append(result)

        status = "MATCH" if matched else ("COMPILE_FAIL" if compile_failed else f"{score*100:5.1f}%")
        print(f"  [{combined_label:38s}] {status:>12s}  flags={flag_str or '(default)'}")
        if verbose and not matched:
            tail = "\n".join(output.strip().splitlines()[-8:])
            print("    " + tail.replace("\n", "\n    "))
        if matched:
            return results
    return results


def save_top_variants(
    results: list[VariantResult],
    out_dir: Path,
    addr: int,
    size: int,
    symbol: Optional[str],
) -> None:
    out_dir.mkdir(parents=True, exist_ok=True)
    ranked = sorted(results, key=VariantResult.sort_key, reverse=True)
    top = ranked[:3]

    for rank, r in enumerate(top, 1):
        dest = out_dir / f"top{rank}_{r.label}.cpp"
        shutil.copy2(r.source_path, dest)

    report = out_dir / "report.txt"
    lines = [
        f"matcher_bot report",
        f"  addr:   0x{addr:08X}",
        f"  size:   {size}",
        f"  symbol: {symbol or '(unknown)'}",
        f"  variants tried: {len(results)}",
        "",
        f"{'rank':4s} {'label':38s} {'score':>8s} {'chunks':>8s} {'flags'}",
    ]
    for rank, r in enumerate(ranked, 1):
        marker = "MATCH" if r.match else ("FAIL" if r.compile_failed else f"{r.score*100:5.1f}%")
        lines.append(f"{rank:<4d} {r.label:38s} {marker:>8s} {r.mismatch_chunks:>8d} {r.flags}")
    report.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print()
    print(f"Top-3 variants + report written to {out_dir}")
    print(f"  report: {report}")


def parse_args() -> argparse.Namespace:
    ap = argparse.ArgumentParser(description="Compiler-aware matcher bot (A1+A2+permuter).")
    ap.add_argument("--wip", type=Path, help="Path to a src/wip/... cpp to attack.")
    ap.add_argument("--src", type=Path, help="Explicit source cpp path (alias of --wip).")
    ap.add_argument("--addr", type=lambda s: int(s, 0), help="DOL virtual address (hex).")
    ap.add_argument("--size", type=int, help="Function size in bytes.")
    ap.add_argument("--symbol", type=str, default=None, help="Function symbol (for reports).")
    ap.add_argument("--out-dir", type=Path, default=DEFAULT_OUT_DIR)
    ap.add_argument("--budget", type=int, default=100, help="Max compile attempts (default 100).")
    ap.add_argument("--no-text", action="store_true",
                    help="A1 mode — disable M10/M11 text mutators.")
    ap.add_argument("--permute", action="store_true",
                    help="Enable hill-climbing permuter with M13-M20 stochastic mutations.")
    ap.add_argument("--batch-dir", type=Path, default=None,
                    help="Run across all .cpp files in a directory (batch mode).")
    ap.add_argument("--verbose", action="store_true")
    return ap.parse_args()


def main() -> int:
    args = parse_args()

    if not VERIFY_SCRIPT.is_file():
        print(f"error: verify script missing: {VERIFY_SCRIPT}", file=sys.stderr)
        return 1

    # Batch mode
    if args.batch_dir is not None:
        if not args.batch_dir.is_dir():
            print(f"error: batch dir not found: {args.batch_dir}", file=sys.stderr)
            return 1
        return run_batch(
            batch_dir=args.batch_dir,
            out_dir=args.out_dir,
            budget=args.budget,
            permute=args.permute,
            enable_text=not args.no_text,
            verbose=args.verbose,
        )

    # Single-file mode
    source_path: Optional[Path] = args.wip or args.src
    if source_path is None:
        print("error: --wip or --src is required", file=sys.stderr)
        return 1
    if not source_path.is_file():
        print(f"error: source not found: {source_path}", file=sys.stderr)
        return 1

    lines = read_source(source_path)
    header_addr, header_size = parse_header_meta(lines)
    addr = args.addr if args.addr is not None else header_addr
    size = args.size if args.size is not None else header_size
    if addr is None or size is None:
        print(
            "error: could not determine addr/size — pass --addr and --size "
            "or put `// 0xADDR (Nb)` in the source header",
            file=sys.stderr,
        )
        return 1

    symbol = args.symbol or source_path.stem

    basename = source_path.stem
    work_dir = args.out_dir / f"{basename}_0x{addr:08X}"
    if work_dir.exists():
        shutil.rmtree(work_dir)
    work_dir.mkdir(parents=True)

    # Permuter mode (hill-climbing with M13-M20)
    if args.permute:
        print(f"matcher_bot v2 — PERMUTER MODE")
        print(f"  source: {source_path}")
        print(f"  addr:   0x{addr:08X}")
        print(f"  size:   {size}")
        print(f"  symbol: {symbol}")
        print(f"  budget: {args.budget}")
        print(f"  mutations: M0-M10 flags + M13-M20 stochastic")
        print(f"  search: hill-climbing with scoring")
        print(f"  work:   {work_dir}")
        print()

        results = run_permuter(lines, addr, size, work_dir, args.budget, verbose=args.verbose)

        winner = next((r for r in results if r.match), None)
        if winner is not None:
            print()
            print(f"MATCH found: {winner.label}")
            print(f"  flags:  {winner.flags}")
            print(f"  source: {winner.source_path}")
            return 0

        save_top_variants(results, work_dir, addr, size, symbol)
        print()
        print("No match found. See report.txt for best variants.")
        return 2

    # Classic exhaustive mode (A1+A2)
    candidates = build_candidates(lines, args.budget, enable_text=not args.no_text)

    print(f"matcher_bot")
    print(f"  source: {source_path}")
    print(f"  addr:   0x{addr:08X}")
    print(f"  size:   {size}")
    print(f"  symbol: {symbol}")
    print(f"  text mutators: {'OFF' if args.no_text else 'ON (M10 decl-swap, M11 barrier)'}")
    print(f"  budget: {args.budget} (planned: {len(candidates)})")
    print(f"  work:   {work_dir}")
    print()

    results = run_candidates(candidates, addr, size, work_dir, verbose=args.verbose)

    winner = next((r for r in results if r.match), None)
    if winner is not None:
        print()
        print(f"MATCH found: {winner.label}")
        print(f"  flags:  {winner.flags}")
        print(f"  source: {winner.source_path}")
        return 0

    save_top_variants(results, work_dir, addr, size, symbol)
    print()
    print("NEAR_MATCH — no variant reached 100%. See report.txt for ranking.")
    return 2


if __name__ == "__main__":
    sys.exit(main())
