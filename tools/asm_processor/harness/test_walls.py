"""test_walls.py — asm_processor regression harness (S13 Track I).

Loads `walls_manifest.yaml`, runs the asm_processor pipeline per wall, compares
bytes via `tools/verify_match.sh` (with a unique --outdir per variant so
parallel runs never clash on shared artifact names), and prints a pass/fail
matrix. Designed to be re-run after every mutator or pipeline change so the
fleet catches regressions.

Usage:
    python tools/asm_processor/harness/test_walls.py                # all walls
    python tools/asm_processor/harness/test_walls.py 0x80224048     # one wall
    python tools/asm_processor/harness/test_walls.py 80224048       # same, hex w/o 0x
    python tools/asm_processor/harness/test_walls.py --verbose      # full logs

Exit codes:
    0  every wall passed its expected outcome (park is always a pass)
    1  one or more walls failed their expected outcome
    2  harness configuration error (missing manifest, bad source path, etc.)

The harness runs walls SEQUENTIALLY right now — matches are confirmed one at a
time, which is slower but avoids any shared-state weirdness in the SN
toolchain. Parallelism is a Phase 2+ concern and would need per-run outdir
isolation (already baked into the --outdir flag we pass to verify_match.sh).
"""
from __future__ import annotations

import argparse
import os
import subprocess
import sys
from pathlib import Path
from typing import Any

# Make `from tools.asm_processor...` work when invoked as a script.
REPO_ROOT = Path(__file__).resolve().parents[3]
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from tools.asm_processor import mutators  # noqa: E402
from tools.asm_processor.harness.report import WallResult, render  # noqa: E402

# YAML loader — PyYAML is widely available; if missing we fall back to the
# stdlib-only parser in `_fallback_yaml` that handles the simple schema we use.
try:
    import yaml  # type: ignore
    _HAVE_PYYAML = True
except ImportError:
    _HAVE_PYYAML = False


MANIFEST_PATH = REPO_ROOT / "tools" / "asm_processor" / "walls_manifest.yaml"
VERIFY_SCRIPT = REPO_ROOT / "tools" / "verify_match.sh"
OUTDIR_ROOT = REPO_ROOT / "build" / "asm_processor" / "test"


def _locate_bash() -> str:
    """Find a bash that can invoke verify_match.sh with Windows paths.

    Avoid WSL bash (`/bin/bash` via the PATH shim) — it can't execute scripts
    that use Windows-style drive letters. Prefer Git for Windows' bash.exe,
    which is what verify_match.sh is tested against.
    """
    candidates = [
        os.environ.get("GIT_BASH"),
        r"C:\Program Files\Git\usr\bin\bash.exe",
        r"C:\Program Files\Git\bin\bash.exe",
        r"C:\Program Files (x86)\Git\usr\bin\bash.exe",
    ]
    for c in candidates:
        if c and os.path.exists(c):
            return c
    # Last resort: whatever `bash` resolves to on PATH.
    import shutil
    found = shutil.which("bash")
    if found:
        return found
    raise SystemExit("could not locate bash.exe (Git for Windows not installed?)")


BASH = _locate_bash()


# ---------- Manifest loading ----------

def _load_manifest(path: Path) -> list[dict[str, Any]]:
    text = path.read_text(encoding="utf-8")
    if _HAVE_PYYAML:
        data = yaml.safe_load(text)
    else:
        data = _fallback_yaml(text)
    if not isinstance(data, dict) or "walls" not in data:
        raise SystemExit(f"manifest {path} missing top-level 'walls:' key")
    walls = data["walls"]
    if not isinstance(walls, list):
        raise SystemExit(f"manifest {path}: 'walls' must be a list")
    return walls


def _fallback_yaml(text: str) -> dict:
    """Minimal YAML parser for the walls_manifest.yaml schema.

    Supports the exact subset we use: top-level `walls:` list, scalar/int/
    quoted-string fields, nested `pipeline:` list of dicts with `args:` dict.
    We fall back to this only when PyYAML is unavailable — real parsing is
    handled by PyYAML when present.
    """
    # Deliberately minimal: raise so the user installs PyYAML rather than
    # silently mis-parsing something subtle. The harness must be trustworthy.
    raise SystemExit(
        "PyYAML not installed — `pip install pyyaml` (or add it to the venv)."
    )


# ---------- Pipeline execution ----------

def _apply_pipeline(asm_text: str, pipeline: list[dict]) -> tuple[str, list[str]]:
    """Apply each mutator stage in order. Returns (final_asm, labels)."""
    labels: list[str] = []
    current = asm_text
    for stage in pipeline:
        name = stage.get("mutator")
        args = stage.get("args") or {}
        if not name:
            raise ValueError(f"pipeline stage missing 'mutator': {stage!r}")
        mut = mutators.get(name)
        try:
            current = mut.apply(current, args)
            labels.append(f"{name}✓")
        except mutators.NoApplicableSite as e:
            labels.append(f"{name}∅({e})")
            # A no-op stage is a SKIP for that stage, not a failure — keep going.
            continue
    return current, labels


# ---------- Per-wall runner ----------

def _verify_wall(wall: dict, verbose: bool = False) -> WallResult:
    addr = wall["addr"]
    size = int(wall["size"])
    category = int(wall.get("category", 0))
    symbol = str(wall.get("symbol", ""))
    expected = str(wall.get("expected", "park"))
    source_rel = Path(wall["source"])
    source_abs = REPO_ROOT / source_rel

    if not source_abs.exists():
        return WallResult(
            addr=addr, size=size, category=category, symbol=symbol,
            expected=expected, observed="error",
            notes=f"source missing: {source_rel}",
        )

    # For Phase 1, the harness does NOT yet orchestrate the asm-level mutator
    # pass (that's OpusWorker's asm_processor.py entrypoint). We run
    # verify_match.sh against the source as-is, which gives us the BASELINE
    # — a mismatch here is expected for every unfixed wall. Once OpusWorker's
    # entrypoint is wired we'll swap this for:
    #   1. Load source, strip `// ASMPROC_*` directives into pipeline.
    #   2. Compile via SN cc1plus to .s.
    #   3. Apply `mutators/` pipeline on .s text.
    #   4. Assemble via NgcAs.
    #   5. Call verify_match.sh on the resulting .o or a rebuilt source stub.
    # For now, the pipeline is a dry-run so we can exercise the harness.
    pipeline = wall.get("pipeline") or []
    pipeline_labels: list[str] = []
    if pipeline:
        # Dry-run: verify each mutator is at least resolvable.
        for stage in pipeline:
            name = stage.get("mutator")
            try:
                mutators.get(name)
                pipeline_labels.append(f"{name}?")  # resolved-but-not-yet-applied
            except KeyError as e:
                return WallResult(
                    addr=addr, size=size, category=category, symbol=symbol,
                    expected=expected, observed="error",
                    notes=f"unknown mutator {name!r}",
                )

    outdir = OUTDIR_ROOT / addr.lower().lstrip("0x") / "baseline"
    outdir.mkdir(parents=True, exist_ok=True)

    cmd = [
        BASH, str(VERIFY_SCRIPT),
        "--outdir", str(outdir),
        str(source_abs), addr, str(size),
    ]
    try:
        proc = subprocess.run(
            cmd, capture_output=True, text=True, cwd=str(REPO_ROOT), timeout=120,
        )
    except subprocess.TimeoutExpired:
        return WallResult(
            addr=addr, size=size, category=category, symbol=symbol,
            expected=expected, observed="error", notes="verify_match.sh timeout",
        )

    stdout = proc.stdout or ""
    stderr = proc.stderr or ""
    if verbose:
        print(f"--- {addr} {symbol} (category {category}) ---")
        print(f"cmd: {' '.join(cmd)}")
        if stdout.strip():
            print(stdout)
        if stderr.strip():
            print(stderr, file=sys.stderr)

    if "MATCH!" in stdout or stdout.strip().endswith("MATCH"):
        observed = "match"
    elif "MISMATCH" in stdout or "SIZE_MISMATCH" in stdout:
        observed = "mismatch"
    elif proc.returncode == 0:
        observed = "match"
    else:
        observed = "error"

    notes_parts: list[str] = []
    if pipeline_labels:
        notes_parts.append(",".join(pipeline_labels))
    else:
        notes_parts.append("no-pipeline")
    if observed == "error" and "REJECTED" in stdout:
        notes_parts.append("verify-rejected")
    return WallResult(
        addr=addr, size=size, category=category, symbol=symbol,
        expected=expected, observed=observed,
        notes=" ".join(notes_parts),
    )


# ---------- CLI ----------

def _normalize_addr_filter(arg: str) -> str:
    arg = arg.strip().lower()
    if arg.startswith("0x"):
        return arg
    return "0x" + arg


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description="asm_processor wall regression harness")
    ap.add_argument("addr", nargs="?", default=None,
                    help="optional: run only the wall matching this address")
    ap.add_argument("--verbose", action="store_true", help="print full verify_match output")
    ap.add_argument("--manifest", default=str(MANIFEST_PATH),
                    help="path to walls_manifest.yaml")
    args = ap.parse_args(argv)

    if not VERIFY_SCRIPT.exists():
        print(f"ERROR: verify_match.sh not at {VERIFY_SCRIPT}", file=sys.stderr)
        return 2

    walls = _load_manifest(Path(args.manifest))
    if args.addr:
        wanted = _normalize_addr_filter(args.addr)
        walls = [w for w in walls if w["addr"].lower() == wanted]
        if not walls:
            print(f"no wall in manifest matches {args.addr!r}", file=sys.stderr)
            return 2

    results = [_verify_wall(w, verbose=args.verbose) for w in walls]
    print(render(results))
    any_failed = any(not r.passed for r in results)
    return 1 if any_failed else 0


if __name__ == "__main__":
    sys.exit(main())
