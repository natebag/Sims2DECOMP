#!/usr/bin/env python3
"""Sims2DECOMP configure.py — minimal dtk-template-compatible entry point.

This is a STUB, not the full ninja+SN-ProDG build pipeline that the canonical
encounter/dtk-template configure.py implements. Its purpose is to make the
standard dtk-template CI workflow signature work for our project so we can:
- Run a build job
- Produce build/<VERSION>/report.json
- Get listed on decomp.dev

For the full build pipeline (ninja + per-file SN ProDG compilation + asm_processor
mutators + dtk dol diff), we currently rely on tools/verify_match.sh per function
plus tools/generate_report.py to roll up progress. A full configure.py adaptation
is a future infrastructure project.

Usage:
    python configure.py                  # default mode (configure)
    python configure.py progress          # print human-readable progress
    python configure.py --version G4ZE69 --map --binutils PATH --compilers PATH

Accepts and silently ignores the dtk-template-standard flags (--map, --binutils,
--compilers) so the same CI workflow can be reused.
"""

import argparse
import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent
sys.path.insert(0, str(REPO_ROOT / "tools"))
from generate_report import main as gen_report_main

DEFAULT_VERSION = "G4ZE69"
VERSIONS = [DEFAULT_VERSION]


def cmd_configure(args: argparse.Namespace) -> int:
    """Configure mode — produce build artifacts (currently: report.json).

    A full implementation would also write build.ninja and set up dtk
    invocations. For now, it just runs generate_report.py to populate
    build/<VERSION>/report.json.
    """
    print(f"[configure.py] Sims2DECOMP, version={args.version}")
    print(f"[configure.py] STUB MODE: generating report.json only "
          f"(full ninja+SN-ProDG pipeline is future work).")
    sys.argv = [
        "generate_report.py",
        "--version", args.version,
        "--print-summary",
    ]
    return gen_report_main()


def cmd_progress(args: argparse.Namespace) -> int:
    """Progress mode — read existing report.json and pretty-print."""
    report_path = REPO_ROOT / "build" / args.version / "report.json"
    if not report_path.is_file():
        print(f"[configure.py] No report at {report_path} — running configure first.")
        rc = cmd_configure(args)
        if rc != 0:
            return rc

    import json
    with open(report_path, encoding="utf-8") as f:
        report = json.load(f)

    m = report["measures"]
    print(f"\nProgress for {args.version}:")
    print(f"  Overall:  {m['matched_code_percent']:.2f}% matched "
          f"({m['matched_code']:,} / {m['total_code']:,} bytes, "
          f"{m['matched_functions']:,} / {m['total_functions']:,} funcs)")
    for cat in report.get("categories", []):
        cm = cat["measures"]
        if cm["total_code"] == 0:
            continue
        print(f"  {cat['name']}: {cm['matched_code_percent']:.2f}% matched "
              f"({cm['matched_code']:,} / {cm['total_code']:,} bytes, "
              f"{cm['matched_functions']:,} / {cm['total_functions']:,} funcs)")
    return 0


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    parser.add_argument(
        "mode",
        choices=["configure", "progress"],
        default="configure",
        nargs="?",
        help="script mode (default: configure)",
    )
    parser.add_argument(
        "-v", "--version",
        choices=VERSIONS,
        type=str.upper,
        default=DEFAULT_VERSION,
        help="game version to build",
    )
    # dtk-template-standard flags we currently accept-and-ignore
    parser.add_argument("--map", action="store_true",
                        help="(ignored) generate map output — already covered by report.json")
    parser.add_argument("--binutils", default=None,
                        help="(ignored) path to binutils — we use SN ProDG via verify_match.sh")
    parser.add_argument("--compilers", default=None,
                        help="(ignored) path to compilers")
    parser.add_argument("--no-progress", action="store_true",
                        help="(ignored) disable progress calculation")
    args = parser.parse_args()

    if args.mode == "configure":
        return cmd_configure(args)
    return cmd_progress(args)


if __name__ == "__main__":
    sys.exit(main())
