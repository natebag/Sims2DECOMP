#!/usr/bin/env python3
"""matcher_bot.py — Phase A1: compiler-aware flag-space search.

Spec: docs/tracking/next-attack-plan-20260412.md (Track A Phase A1).

Given a C++ source + DOL address/size, exhaustively try a fixed set of
SN ProDG flag combinations and pick the best match. Uses tools/verify_match.sh
as the correctness oracle — whatever it says is MATCH/MISMATCH is final.

Exit codes:
    0 = MATCH (prints winner path + flags line, also copies to out dir)
    2 = NEAR_MATCH (writes top-3 variants + scores to out dir)
    1 = usage / tool error

Usage:
    python tools/matcher_bot.py --wip src/wip/version_diff/match_0xADDR_name.cpp
    python tools/matcher_bot.py --src path.cpp --addr 0x80322EA8 --size 172
    python tools/matcher_bot.py --wip file.cpp --addr 0x... --size ...    # overrides

Options:
    --out-dir DIR        Where to dump variants + report (default: build/matcher_bot)
    --keep-baseline      Also test the source unchanged (no flag rewrite)
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

def run_all_variants(
    source_lines: list[str],
    addr: int,
    size: int,
    work_dir: Path,
    verbose: bool = False,
) -> list[VariantResult]:
    work_dir.mkdir(parents=True, exist_ok=True)
    results: list[VariantResult] = []

    for label, flags in FLAG_VARIANTS:
        variant_src = work_dir / f"{label}.cpp"
        variant_lines = rewrite_flags(source_lines, flags)
        variant_src.write_text("".join(variant_lines), encoding="utf-8")

        exit_code, output = run_verify(variant_src, addr, size)
        matched, score, mismatch_chunks, compile_failed = score_verify_output(
            exit_code, output, size
        )

        result = VariantResult(
            label=label,
            flags=flags or "(default)",
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
        print(f"  [{label:22s}] {status:>12s}  flags={flags or '(default)'}")
        if verbose and not matched:
            tail = "\n".join(output.strip().splitlines()[-8:])
            print("    " + tail.replace("\n", "\n    "))
        if matched:
            # Early-exit on first match — Phase A1 is exhaustive-but-early-stop.
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
        f"matcher_bot Phase A1 report",
        f"  addr:   0x{addr:08X}",
        f"  size:   {size}",
        f"  symbol: {symbol or '(unknown)'}",
        f"  variants tried: {len(results)}",
        "",
        f"{'rank':4s} {'label':22s} {'score':>8s} {'chunks':>8s} {'flags'}",
    ]
    for rank, r in enumerate(ranked, 1):
        marker = "MATCH" if r.match else ("FAIL" if r.compile_failed else f"{r.score*100:5.1f}%")
        lines.append(f"{rank:<4d} {r.label:22s} {marker:>8s} {r.mismatch_chunks:>8d} {r.flags}")
    report.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print()
    print(f"Top-3 variants + report written to {out_dir}")
    print(f"  report: {report}")


def parse_args() -> argparse.Namespace:
    ap = argparse.ArgumentParser(description="Phase A1 flag-space matcher bot.")
    ap.add_argument("--wip", type=Path, help="Path to a src/wip/... cpp to attack.")
    ap.add_argument("--src", type=Path, help="Explicit source cpp path (alias of --wip).")
    ap.add_argument("--addr", type=lambda s: int(s, 0), help="DOL virtual address (hex).")
    ap.add_argument("--size", type=int, help="Function size in bytes.")
    ap.add_argument("--symbol", type=str, default=None, help="Function symbol (for reports).")
    ap.add_argument("--out-dir", type=Path, default=DEFAULT_OUT_DIR)
    ap.add_argument("--verbose", action="store_true")
    return ap.parse_args()


def main() -> int:
    args = parse_args()

    source_path: Optional[Path] = args.wip or args.src
    if source_path is None:
        print("error: --wip or --src is required for Phase A1", file=sys.stderr)
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

    print(f"matcher_bot Phase A1")
    print(f"  source: {source_path}")
    print(f"  addr:   0x{addr:08X}")
    print(f"  size:   {size}")
    print(f"  symbol: {symbol}")
    print(f"  variants: {len(FLAG_VARIANTS)}")
    print(f"  work:   {work_dir}")
    print()

    results = run_all_variants(lines, addr, size, work_dir, verbose=args.verbose)

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
