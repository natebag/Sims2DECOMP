#!/usr/bin/env python3
"""Download/install toolchain artifacts for the Sims 2 GC decomp build.

Modeled on encounter/dtk-template's tools/download_tool.py with two
project-specific additions:

  - sn-prodg: SN Systems ProDG for GameCube (the primary toolchain — the
    compiler the game was originally built with). License-restricted: NOT
    redistributable by decomp.dev. Either install from a user-supplied
    archive (--from-archive) or from a private release URL configured via
    SN_PRODG_RELEASE_URL env var.

  - mwcc: Metrowerks CodeWarrior PPC compiler. Public via decomp.dev's
    standard compilers_<tag>.zip mirror. Needed for matching the
    DolphinSDK region (issue #1).

Usage:
    # SN ProDG v3.93 from a local archive (user owns it)
    python tools/download_tool.py sn-prodg --version v393 \\
        --from-archive ~/Downloads/prodg_v393.tar.gz

    # SN ProDG from a configured release URL
    SN_PRODG_RELEASE_URL=https://.../prodg_v393.tar.gz \\
    python tools/download_tool.py sn-prodg --version v393

    # MWCC for DolphinSDK matching
    python tools/download_tool.py mwcc --tag GC-1.2.5n

    # Verify what's already installed without downloading anything
    python tools/download_tool.py verify --version v393

Layout produced (matches what tools/verify_match.sh + configure.py expect):
    compiler/ProDGforNGCv393/Disk1/data1/Build_Tools_Bin/<binaries>
    compiler/alt_versions/v{35,37,381}/<binaries>
    build/tools/mwcc/<tag>/mwcceppc.exe
"""

import argparse
import hashlib
import io
import os
import sys
import tarfile
import urllib.request
import zipfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from paths import REPO_ROOT


# SHA-256 manifest. Pinned hashes for the canonical archive shapes — any
# divergence aborts install. Update by running `sha256sum <archive>` on a
# known-good copy before bumping.
#
# SN ProDG archives are .tar.gz of the ProDG installer's Build_Tools_Bin/
# directory (plus Disk1/data1/ wrapper for v3.93 — see _layout_for_version).
SN_PRODG_MANIFEST = {
    "v393": {
        # Canonical v3.93 — the version the original DOL was built with.
        # SHA computed against the project's existing compiler/ProDGforNGCv393/
        # tree once it's archived. The placeholder below MUST be replaced
        # before this tool is usable for fresh clones.
        "sha256": "REPLACE_ME_with_archive_sha256_at_release_upload_time",
        "size_mb": 38,
        "description": "SN Systems ProDG for GameCube v3.93 (original-build compiler)",
    },
    "v35": {
        "sha256": "0dd4314e76c8532acd4e61cc9a0dd3c74030af831e7e16eb13663d5190b99cad",
        "size_mb": 9,
        "description": "SN Systems ProDG for GameCube v3.5 (A/B alt-version)",
    },
    "v37": {
        "sha256": "31ab9635d4dd0ceac0f0e5d8e7a54a44514da00359e9008e5ffdce6582ee65da",
        "size_mb": 9,
        "description": "SN Systems ProDG for GameCube v3.7 (A/B alt-version)",
    },
    "v381": {
        "sha256": "62ecf15ce4e1cbafae68ab9a2b5aa8c5d72f94481e5e1a5eb61868d5d8487a84",
        "size_mb": 9,
        "description": "SN Systems ProDG for GameCube v3.81 (A/B alt-version)",
    },
}


# MWCC versions (from decomp.dev mirror). GC-1.2.5n is the canonical
# DolphinSDK 1.0 HW2 compiler — closest match to the linked SDK objects.
# decomp.dev hosts these at files.decomp.dev/compilers_<tag>.zip.
MWCC_MANIFEST = {
    "GC-1.2.5n": {
        "description": "MWCC GC-1.2.5n — DolphinSDK 1.0 HW2 canonical",
    },
    "GC-1.3.2": {
        "description": "MWCC GC-1.3.2 — alternative SDK build candidate",
    },
}


def _layout_for_version(version: str) -> Path:
    """Where binaries land after extraction. Matches the paths the existing
    verify_match.sh + configure.py already use.
    """
    if version == "v393":
        return REPO_ROOT / "compiler" / "ProDGforNGCv393"
    if version in {"v35", "v37", "v381"}:
        return REPO_ROOT / "compiler" / "alt_versions" / version
    raise ValueError(f"unknown SN ProDG version: {version}")


def _sha256_file(path: Path, chunk_size: int = 1 << 16) -> str:
    h = hashlib.sha256()
    with open(path, "rb") as f:
        while True:
            chunk = f.read(chunk_size)
            if not chunk:
                break
            h.update(chunk)
    return h.hexdigest()


def _verify_sha(path: Path, expected: str) -> None:
    if expected.startswith("REPLACE_ME"):
        raise SystemExit(
            f"SHA manifest entry for {path.name} is a placeholder — the project "
            f"maintainer has not yet uploaded a canonical archive. See "
            f"docs/specs/toolchain-bootstrap.md for the upload workflow."
        )
    actual = _sha256_file(path)
    if actual != expected:
        raise SystemExit(
            f"SHA mismatch on {path}:\n"
            f"  expected: {expected}\n"
            f"  got:      {actual}\n"
            f"Refusing to install — the archive may be tampered with or the "
            f"manifest may be outdated."
        )


def _is_installed(version: str) -> bool:
    """Cheap check: is the canonical binary (cc1plus.exe) present?"""
    target = _layout_for_version(version)
    if version == "v393":
        return (target / "Disk1" / "data1" / "Build_Tools_Bin" / "cc1plus.exe").exists()
    return (target / "cc1plus.exe").exists()


def _extract_tar_gz(archive: Path, target: Path) -> None:
    """Extract a .tar.gz to target/. Refuses path-traversal entries."""
    target.mkdir(parents=True, exist_ok=True)
    with tarfile.open(archive, "r:gz") as tf:
        for member in tf.getmembers():
            # Reject absolute paths and parent-dir escapes
            member_path = (target / member.name).resolve()
            if not str(member_path).startswith(str(target.resolve())):
                raise SystemExit(f"refusing path-traversal entry: {member.name}")
            tf.extract(member, target)


def install_sn_prodg(version: str, from_archive: Path | None) -> int:
    """Install one SN ProDG version. Source priority:
      1. --from-archive <path>  (user-supplied local archive)
      2. SN_PRODG_RELEASE_URL env var (project private mirror)
      3. Error with bootstrap instructions
    """
    if version not in SN_PRODG_MANIFEST:
        raise SystemExit(f"unknown SN ProDG version: {version}. "
                         f"Known: {', '.join(SN_PRODG_MANIFEST)}")
    spec = SN_PRODG_MANIFEST[version]
    target = _layout_for_version(version)

    if _is_installed(version):
        print(f"[sn-prodg] {version} already installed at {target}, skipping.")
        return 0

    archive_path: Path
    if from_archive is not None:
        archive_path = from_archive
        if not archive_path.exists():
            raise SystemExit(f"--from-archive: {archive_path} does not exist")
    else:
        url = os.environ.get("SN_PRODG_RELEASE_URL")
        if not url:
            raise SystemExit(
                f"\n  SN Systems ProDG {version} is not installed and no source "
                f"was provided.\n"
                f"  Options:\n"
                f"    1. Provide a local archive: --from-archive PATH\n"
                f"    2. Set env var SN_PRODG_RELEASE_URL to a mirror URL\n"
                f"  SN ProDG is license-restricted; the project does not "
                f"redistribute the compiler directly. See "
                f"docs/specs/toolchain-bootstrap.md for guidance."
            )
        # Stream the URL to a temp file under build/tools/.
        cache_dir = REPO_ROOT / "build" / "tools" / "downloads"
        cache_dir.mkdir(parents=True, exist_ok=True)
        archive_path = cache_dir / f"prodg_{version}.tar.gz"
        print(f"[sn-prodg] downloading {url} -> {archive_path}")
        with urllib.request.urlopen(url) as resp, open(archive_path, "wb") as f:
            while True:
                chunk = resp.read(1 << 20)
                if not chunk:
                    break
                f.write(chunk)

    print(f"[sn-prodg] verifying {archive_path} ({spec['size_mb']}MB)")
    _verify_sha(archive_path, spec["sha256"])

    print(f"[sn-prodg] extracting to {target}")
    _extract_tar_gz(archive_path, target)
    print(f"[sn-prodg] {version} installed.")
    return 0


def install_mwcc(tag: str) -> int:
    """Install one MWCC version from decomp.dev's standard mirror. Mirrors
    encounter/dtk-template's compilers_url() flow.
    """
    if tag not in MWCC_MANIFEST:
        print(f"[mwcc] WARNING: '{tag}' is not in the project's tested manifest. "
              f"Known: {', '.join(MWCC_MANIFEST)}. Continuing anyway.")
    target_dir = REPO_ROOT / "build" / "tools" / "mwcc" / tag
    if (target_dir / "mwcceppc.exe").exists():
        print(f"[mwcc] {tag} already installed at {target_dir}, skipping.")
        return 0
    target_dir.mkdir(parents=True, exist_ok=True)

    url = f"https://files.decomp.dev/compilers_{tag}.zip"
    print(f"[mwcc] downloading {url}")
    with urllib.request.urlopen(url) as resp:
        zip_bytes = resp.read()
    print(f"[mwcc] extracting to {target_dir} ({len(zip_bytes) // 1024}KB)")
    with zipfile.ZipFile(io.BytesIO(zip_bytes)) as zf:
        zf.extractall(target_dir)
    print(f"[mwcc] {tag} installed.")
    return 0


def cmd_verify(version: str) -> int:
    """Verify a version is correctly installed without re-downloading."""
    if not _is_installed(version):
        print(f"[verify] {version}: NOT INSTALLED")
        return 1
    target = _layout_for_version(version)
    bin_dir = (target / "Disk1" / "data1" / "Build_Tools_Bin"
               if version == "v393" else target)
    print(f"[verify] {version}: installed at {bin_dir}")
    return 0


def main() -> int:
    parser = argparse.ArgumentParser(
        description=__doc__.split("\n\n")[0],
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    sub = parser.add_subparsers(dest="cmd", required=True)

    p_sn = sub.add_parser("sn-prodg", help="install SN Systems ProDG (primary toolchain)")
    p_sn.add_argument("--version", default="v393",
                      choices=sorted(SN_PRODG_MANIFEST.keys()),
                      help="which ProDG version (default: v393, the original-build compiler)")
    p_sn.add_argument("--from-archive", type=Path, default=None,
                      help="install from a user-supplied .tar.gz instead of network fetch")
    p_sn.add_argument("--all", action="store_true",
                      help="install all known versions (v393 + alt-versions)")

    p_mw = sub.add_parser("mwcc", help="install MWCC from decomp.dev mirror (for DolphinSDK)")
    p_mw.add_argument("--tag", default="GC-1.2.5n",
                      help="MWCC version tag (default: GC-1.2.5n, DolphinSDK 1.0 HW2)")

    p_vf = sub.add_parser("verify", help="check if a version is installed")
    p_vf.add_argument("--version", default="v393",
                      choices=sorted(SN_PRODG_MANIFEST.keys()))

    args = parser.parse_args()

    if args.cmd == "sn-prodg":
        if args.all:
            rc = 0
            for v in sorted(SN_PRODG_MANIFEST.keys()):
                rc |= install_sn_prodg(v, args.from_archive)
            return rc
        return install_sn_prodg(args.version, args.from_archive)
    if args.cmd == "mwcc":
        return install_mwcc(args.tag)
    if args.cmd == "verify":
        return cmd_verify(args.version)
    return 2


if __name__ == "__main__":
    sys.exit(main())
