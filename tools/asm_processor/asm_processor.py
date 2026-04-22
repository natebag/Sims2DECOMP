"""asm_processor entrypoint — runs the full pipeline for a single wall.

Pipeline:
    1. Read source, parse // ASMPROC_<name>: directives
    2. Strip directives + all line comments → clean .cpp
    3. Run SN cc1plus on clean source → .s
    4. For each directive: mutators.REGISTRY[name].apply(asm_text, args)
    5. Run NgcAs on mutated .s → .o
    6. Extract .text bytes + relocations from .o
    7. Byte-diff vs DOL at (addr, size) with relocation-aware masking
    8. Print MATCH / MISMATCH / SIZE_MISMATCH and exit (0 / 1)

Usage:
    python tools/asm_processor/asm_processor.py \\
        --src src/wip/version_diff/wall_0x80224048_*.cpp \\
        --addr 0x80224048 --size 24

    python tools/asm_processor/asm_processor.py \\
        --manifest tools/asm_processor/walls_manifest.yaml --addr 0x80224048

Exit codes: 0 = MATCH, 1 = MISMATCH or error.
"""
from __future__ import annotations

import argparse
import os
import sys
import traceback
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[2]
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))


from tools.asm_processor import compile as apc
from tools.asm_processor import directives as apd
from tools.asm_processor import mutators as apm


def _parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    ap = argparse.ArgumentParser(description="asm-processor: post-compile .s mutator for SN ProDG matching")
    ap.add_argument("--src", type=Path, help="C++ source path with embedded // ASMPROC_* directives")
    ap.add_argument("--addr", help="DOL address (e.g. 0x80224048)")
    ap.add_argument("--size", type=int, help="function size in bytes (must equal DVD map size)")
    ap.add_argument("--outdir", type=Path, default=REPO_ROOT / "build" / "asm_processor",
                    help="Scratch dir for .s/.o and diff artifacts")
    ap.add_argument("--keep-noop", action="store_true",
                    help="Run compile+assemble even if the source has zero ASMPROC directives "
                         "(default: baseline-only path for smoke testing)")
    ap.add_argument("--print-asm", action="store_true", help="Dump mutated .s to stdout")
    ap.add_argument("--verbose", action="store_true", help="Verbose logging")
    return ap.parse_args(argv)


def _log(msg: str, verbose: bool = True) -> None:
    if verbose:
        print(msg, flush=True)


def run(src: Path, addr: int, size: int, outdir: Path,
        verbose: bool = False, print_asm: bool = False,
        keep_noop: bool = False) -> int:
    outdir.mkdir(parents=True, exist_ok=True)
    basename = src.stem
    clean_src = outdir / f"{basename}_clean.cpp"
    asm_raw = outdir / f"{basename}.s.raw"
    asm_mut = outdir / f"{basename}.s"
    obj = outdir / f"{basename}.o"

    text = src.read_text(encoding="utf-8")
    extra_flags = apc.extract_flag_override(text)

    dirs = apd.parse_directives(text)
    if not dirs and not keep_noop:
        print(f"NO_DIRECTIVES: {src} has no // ASMPROC_* comments; nothing to do.")
        print("(pass --keep-noop to run the baseline compile for smoke-testing)")
        return 1
    _log(f"directives: {len(dirs)}", verbose)
    for d in dirs:
        _log(f"  line {d.lineno}: {d}", verbose)

    stripped = apd.strip_directives(text)
    clean = apc.strip_line_comments(stripped)
    clean_src.write_text(clean, encoding="utf-8")

    _log(f"cc1plus -> {asm_raw}", verbose)
    result = apc.run_cc1plus(clean_src, asm_raw, extra_flags=extra_flags)
    asm_text = result.asm_text

    for d in dirs:
        try:
            asm_text = apm.REGISTRY[d.name].apply(asm_text, d.args)
        except KeyError:
            print(f"ERROR: no mutator registered for ASMPROC_{d.name!r}. "
                  f"Registered: {sorted(apm.REGISTRY)}")
            return 1
        except apm.NoApplicableSite as exc:
            print(f"ERROR: ASMPROC_{d.name} (line {d.lineno}) skipped — no applicable site: {exc}")
            return 1
        except Exception as exc:
            print(f"ERROR: ASMPROC_{d.name} (line {d.lineno}) raised {type(exc).__name__}: {exc}")
            return 1

    asm_mut.write_text(asm_text, encoding="utf-8")
    if print_asm:
        print("=== mutated .s ===")
        print(asm_text)
        print("=== end ===")

    _log(f"NgcAs -> {obj}", verbose)
    apc.run_as(asm_mut, obj)

    compiled = apc.extract_text_bytes(obj)[:size]
    relocs = apc.extract_relocations(obj)
    dol_bytes = apc.read_dol_bytes(addr, size)

    diff = apc.diff_bytes_with_relocs(dol_bytes, compiled, relocs)
    print()
    print(f"DOL bytes      : {diff.dol_hex}")
    print(f"Compiled bytes : {diff.compiled_hex}")
    if relocs:
        print("Relocations:")
        for off, rtype, target in relocs:
            print(f"  0x{off:04x} {rtype} {target}")
    print()
    print(diff.summary())

    if diff.match:
        print(f"\nMATCH! Function at 0x{addr:08x} ({size} bytes) matches perfectly (with relocations masked).")
        print(f"  via asm_processor: {src.name} after {len(dirs)} mutator pass(es).")
        return 0
    if diff.size_mismatch:
        return 1
    print("\nMasked diff (DOL vs compiled, 8B chunks; relocations normalized to 0xCC):")
    for i in range(0, len(diff.dol_hex), 16):
        dm = diff.masked_dol_hex[i:i + 16]
        cm = diff.masked_compiled_hex[i:i + 16]
        if dm != cm:
            print(f"  off 0x{i // 2:03x}: dol={dm} cmp={cm}")
    print("\nDisassembly of compiled .o:")
    print(apc.disasm(obj))
    return 1


def main(argv: list[str] | None = None) -> int:
    args = _parse_args(argv)
    if not args.src or not args.addr or args.size is None:
        print("Usage: --src PATH --addr HEX --size INT")
        return 1
    try:
        addr = int(args.addr, 16) if args.addr.lower().startswith("0x") else int(args.addr, 16)
    except ValueError:
        print(f"bad --addr {args.addr!r}")
        return 1
    try:
        return run(
            src=args.src.resolve(),
            addr=addr,
            size=args.size,
            outdir=args.outdir,
            verbose=args.verbose,
            print_asm=args.print_asm,
            keep_noop=args.keep_noop,
        )
    except apc.CompileError as exc:
        print(f"COMPILE_ERROR: {exc}")
        return 1
    except Exception:
        traceback.print_exc()
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
