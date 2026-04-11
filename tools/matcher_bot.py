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
    produces one variant per single-insertion-point. Empty-string asm is
    whitelisted by the pre-commit hook at .git/hooks/pre-commit:93-105.
    """
    store_idxs: list[int] = [i for i, raw in enumerate(lines) if _is_store_line(raw)]
    # Insertion points are gaps between consecutive store lines where they
    # are also consecutive in the source (i and i+1 both stores).
    insert_points: list[tuple[int, str]] = []
    for j, idx in enumerate(store_idxs[:-1]):
        nxt = store_idxs[j + 1]
        if nxt == idx + 1:
            insert_points.append((idx + 1, lines[idx].lstrip(" \t").rstrip()[:20]))
    # De-duplicate adjacent insertion points if we have too many.
    # Cap to 8 to control variant explosion.
    insert_points = insert_points[:8]

    variants: list[tuple[str, list[str]]] = []
    for k, (insert_at, _label_hint) in enumerate(insert_points):
        indent_src = lines[insert_at] if insert_at < len(lines) else ""
        m = re.match(r"^([ \t]+)", indent_src)
        indent = m.group(1) if m else "    "
        # SN ProDG cc1plus 2.95 rejects the `:::` shorthand. The spaced
        # form `: : : "memory"` parses identically at the AST level and
        # is accepted. Still an empty-string asm (zero instructions) so
        # it passes the pre-commit whitelist.
        barrier = f'{indent}asm volatile("" : : : "memory");\n'
        new_lines = lines[:insert_at] + [barrier] + lines[insert_at:]
        label = f"T11_barrier{k}"
        variants.append((label, new_lines))
    return variants


def build_text_variants(lines: list[str]) -> list[tuple[str, list[str]]]:
    """Produce the ordered list of text mutations to try, NOT including identity.
    Ordering: M11 (compiler-barrier) first, then M10 (decl-swap).
    A5 data showed the NEAR_MATCH targets with the highest scores (ETexture,
    EThread, audiostreamman) all look like store-ordering walls, so M11
    gets first crack.
    """
    out: list[tuple[str, list[str]]] = []
    out.extend(m11_barrier_mutator(lines))
    out.extend(m10_var_swap_mutator(lines))
    return out


# ---------- verify_match.sh wrapper ----------

def run_verify(source_path: Path, addr: int, size: int) -> tuple[int, str]:
    """Invoke verify_match.sh. Returns (exit_code, stdout+stderr)."""
    cmd = [
        BASH,
        _to_bash_path(VERIFY_SCRIPT),
        _to_bash_path(source_path),
        f"0x{addr:08X}",
        str(size),
    ]
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

        exit_code, output = run_verify(variant_src, addr, size)
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
    ap = argparse.ArgumentParser(description="Compiler-aware matcher bot (A1+A2).")
    ap.add_argument("--wip", type=Path, help="Path to a src/wip/... cpp to attack.")
    ap.add_argument("--src", type=Path, help="Explicit source cpp path (alias of --wip).")
    ap.add_argument("--addr", type=lambda s: int(s, 0), help="DOL virtual address (hex).")
    ap.add_argument("--size", type=int, help="Function size in bytes.")
    ap.add_argument("--symbol", type=str, default=None, help="Function symbol (for reports).")
    ap.add_argument("--out-dir", type=Path, default=DEFAULT_OUT_DIR)
    ap.add_argument("--budget", type=int, default=60, help="Max compile attempts (default 60).")
    ap.add_argument("--no-text", action="store_true",
                    help="A1 mode — disable M10/M11 text mutators.")
    ap.add_argument("--verbose", action="store_true")
    return ap.parse_args()


def main() -> int:
    args = parse_args()

    source_path: Optional[Path] = args.wip or args.src
    if source_path is None:
        print("error: --wip or --src is required", file=sys.stderr)
        return 1
    if not source_path.is_file():
        print(f"error: source not found: {source_path}", file=sys.stderr)
        return 1
    if not VERIFY_SCRIPT.is_file():
        print(f"error: verify script missing: {VERIFY_SCRIPT}", file=sys.stderr)
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
