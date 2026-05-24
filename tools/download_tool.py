#!/usr/bin/env python3
"""Download/install toolchain artifacts for the Sims 2 GC decomp build.

Uses decomp.dev's public compilers archive — the same source that other
GameCube/Wii decomp projects use. No release-artifact upload or
licensing-restricted private mirror needed.

  python tools/download_tool.py compilers [--tag latest]
    Fetches files.decomp.dev/compilers_<tag>.zip (~80MB) and extracts:
      ProDG/3.9.3/   -> compiler/prodg/3.9.3/   (primary game compiler)
      ProDG/3.5/     -> compiler/prodg/3.5/     (alt version)
      ProDG/3.7/     -> compiler/prodg/3.7/     (alt version)
      ProDG/3.8.1/   -> compiler/prodg/3.8.1/   (alt version)
      GC/1.2.5n/     -> compiler/mwcc/1.2.5n/   (DolphinSDK matcher)
    Other versions in the zip (X360, Wii, GC variants) are skipped.

  python tools/download_tool.py mwcc --tag <ver>
    Extract one additional MWCC variant from the cached compilers zip.
    Useful for A/B SDK-flag testing against alternative GC/* versions.

  python tools/download_tool.py verify
    Print install status of each canonical compiler.

This replaces a previous "private release artifact" design (closes #3 via
dbalatoni13's much cleaner approach).
"""

import argparse
import io
import os
import sys
import urllib.request
import zipfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from paths import REPO_ROOT


COMPILERS_URL_TEMPLATE = "https://files.decomp.dev/compilers_{tag}.zip"

# Subdirectories of compilers_<tag>.zip that we extract by default.
# Each entry: source-prefix-in-zip  ->  destination under compiler/
DEFAULT_EXTRACT = {
    "ProDG/3.9.3/":  "prodg/3.9.3",
    "ProDG/3.8.1/":  "prodg/3.8.1",
    "ProDG/3.7/":    "prodg/3.7",
    "ProDG/3.5/":    "prodg/3.5",
    "GC/1.2.5n/":    "mwcc/1.2.5n",
}

# All MWCC GC variants known in the archive (per info.txt). Used by the
# `mwcc --tag <ver>` subcommand for opt-in extra installs.
KNOWN_MWCC_TAGS = {
    "1.0", "1.1", "1.1p1", "1.2.5", "1.2.5n",
    "1.3", "1.3.2", "1.3.2r",
    "2.0", "2.0p1", "2.5", "2.6", "2.7",
    "3.0a3", "3.0a3p1", "3.0a3.2", "3.0a3.3", "3.0a3.4",
    "3.0a5", "3.0a5.2",
}


def _cache_path(tag: str) -> Path:
    """Where we cache the downloaded compilers_<tag>.zip."""
    cache = REPO_ROOT / "build" / "tools" / "downloads"
    cache.mkdir(parents=True, exist_ok=True)
    return cache / f"compilers_{tag}.zip"


def _download(url: str, target: Path) -> None:
    """Stream `url` to `target`. Atomic via *.partial swap."""
    if target.exists():
        print(f"[cache] using existing {target} ({target.stat().st_size // (1024*1024)}MB)")
        return
    print(f"[download] {url}")
    partial = target.with_suffix(target.suffix + ".partial")
    try:
        with urllib.request.urlopen(url) as resp, open(partial, "wb") as f:
            total = 0
            while True:
                chunk = resp.read(1 << 20)
                if not chunk:
                    break
                f.write(chunk)
                total += len(chunk)
                # Single-line progress; flush so the user sees it during long fetches.
                print(f"\r[download] {total // (1024*1024)}MB...", end="", flush=True)
        print()
        partial.replace(target)
        print(f"[download] wrote {target} ({target.stat().st_size // (1024*1024)}MB)")
    except Exception:
        # Don't leave a half-written file behind on Ctrl-C / network error.
        if partial.exists():
            partial.unlink()
        raise


def _extract_subdir(zf: zipfile.ZipFile, src_prefix: str, dest_dir: Path,
                    force: bool = False) -> bool:
    """Extract everything under `src_prefix` from zf into dest_dir/, dropping the
    prefix from each path. Returns True if any files were written.

    Skips silently if dest_dir already contains a sentinel binary (cc1plus.exe
    for ProDG, mwcceppc.exe for MWCC) unless force=True. Refuses path-traversal
    entries.
    """
    sentinel = "cc1plus.exe" if "prodg" in str(dest_dir).lower() else "mwcceppc.exe"
    if not force and (dest_dir / sentinel).exists():
        print(f"[skip] {dest_dir} already populated ({sentinel} present)")
        return False
    dest_dir.mkdir(parents=True, exist_ok=True)
    members = [n for n in zf.namelist() if n.startswith(src_prefix) and not n.endswith("/")]
    if not members:
        print(f"[warn] no entries matching {src_prefix} in archive")
        return False
    written = 0
    for name in members:
        rel = name[len(src_prefix):]
        if not rel or rel.startswith("../") or rel.startswith("/"):
            continue  # path-traversal guard
        out_path = (dest_dir / rel).resolve()
        if not str(out_path).startswith(str(dest_dir.resolve())):
            print(f"[warn] refusing path-traversal entry: {name}")
            continue
        out_path.parent.mkdir(parents=True, exist_ok=True)
        with zf.open(name) as src, open(out_path, "wb") as out:
            out.write(src.read())
        # Preserve executable bit on .exe / no-extension files (unix-ish hosts).
        if rel.endswith(".exe") or "." not in Path(rel).name:
            try:
                os.chmod(out_path, 0o755)
            except OSError:
                pass
        written += 1
    print(f"[extract] {src_prefix} -> {dest_dir.relative_to(REPO_ROOT)} ({written} files)")
    return True


def install_compilers(tag: str, force: bool = False,
                      only: list[str] | None = None) -> int:
    """Fetch compilers_<tag>.zip and extract the default subdirs."""
    archive = _cache_path(tag)
    _download(COMPILERS_URL_TEMPLATE.format(tag=tag), archive)

    compiler_root = REPO_ROOT / "compiler"
    compiler_root.mkdir(parents=True, exist_ok=True)

    target_map = DEFAULT_EXTRACT
    if only:
        target_map = {k: v for k, v in DEFAULT_EXTRACT.items()
                      if any(k.startswith(o) for o in only)}
        if not target_map:
            print(f"[error] --only filter matched no defaults: {only}")
            return 1

    with zipfile.ZipFile(archive) as zf:
        for src_prefix, dest_rel in target_map.items():
            _extract_subdir(zf, src_prefix, compiler_root / dest_rel, force=force)

    return 0


def install_extra_mwcc(tag: str, archive_tag: str = "latest",
                       force: bool = False) -> int:
    """Extract an additional MWCC GC variant from the cached compilers zip."""
    if tag not in KNOWN_MWCC_TAGS:
        print(f"[warn] '{tag}' not in known MWCC variants; trying anyway")
    archive = _cache_path(archive_tag)
    if not archive.exists():
        _download(COMPILERS_URL_TEMPLATE.format(tag=archive_tag), archive)

    dest = REPO_ROOT / "compiler" / "mwcc" / tag
    with zipfile.ZipFile(archive) as zf:
        ok = _extract_subdir(zf, f"GC/{tag}/", dest, force=force)
    return 0 if ok else 1


def cmd_verify() -> int:
    """Status check for every canonical install location."""
    rows = [
        ("compiler/prodg/3.9.3/cc1plus.exe",   "SN ProDG 3.9.3 (primary)"),
        ("compiler/prodg/3.8.1/cc1plus.exe",   "SN ProDG 3.8.1 (alt)"),
        ("compiler/prodg/3.7/cc1plus.exe",     "SN ProDG 3.7   (alt)"),
        ("compiler/prodg/3.5/cc1plus.exe",     "SN ProDG 3.5   (alt)"),
        ("compiler/mwcc/1.2.5n/mwcceppc.exe",  "MWCC GC-1.2.5n (DolphinSDK)"),
    ]
    rc = 0
    for path_rel, label in rows:
        p = REPO_ROOT / path_rel
        if p.exists():
            print(f"  [OK]    {label:<35} {path_rel}")
        else:
            print(f"  [MISS]  {label:<35} {path_rel}")
            rc = 1
    if rc:
        print()
        print("Run: python tools/download_tool.py compilers")
    return rc


def main() -> int:
    parser = argparse.ArgumentParser(
        description=__doc__.split("\n\n")[0],
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    sub = parser.add_subparsers(dest="cmd", required=True)

    p_co = sub.add_parser("compilers",
                          help="install ProDG + MWCC from decomp.dev's compilers archive")
    p_co.add_argument("--tag", default="latest",
                      help="compilers_<tag>.zip version (default: latest)")
    p_co.add_argument("--force", action="store_true",
                      help="re-extract even if a target dir is already populated")
    p_co.add_argument("--only", nargs="+", default=None, metavar="PREFIX",
                      help="restrict to subset (e.g. --only ProDG/3.9.3 GC/1.2.5n)")

    p_mw = sub.add_parser("mwcc",
                          help="install one additional MWCC GC variant (opt-in beyond defaults)")
    p_mw.add_argument("--tag", required=True,
                      help=f"MWCC GC version (choices: {', '.join(sorted(KNOWN_MWCC_TAGS))})")
    p_mw.add_argument("--archive-tag", default="latest",
                      help="compilers_<tag>.zip version to source from (default: latest)")
    p_mw.add_argument("--force", action="store_true")

    sub.add_parser("verify", help="print install status of canonical compilers")

    args = parser.parse_args()

    if args.cmd == "compilers":
        return install_compilers(args.tag, force=args.force, only=args.only)
    if args.cmd == "mwcc":
        return install_extra_mwcc(args.tag, archive_tag=args.archive_tag, force=args.force)
    if args.cmd == "verify":
        return cmd_verify()
    return 2


if __name__ == "__main__":
    sys.exit(main())
