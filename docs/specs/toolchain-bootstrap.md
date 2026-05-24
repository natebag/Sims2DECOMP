# Toolchain Bootstrap

How to obtain the compilers needed to build this project. Driven by
`tools/download_tool.py` (addresses GitHub issue #3).

## What you need

| Tool | Purpose | License | How to get |
|------|---------|---------|------------|
| **SN Systems ProDG for GameCube v3.93** | Compiles game code (the original-build toolchain) | Proprietary, NOT redistributable | User-supplied or project release artifact |
| **MWCC GC-1.2.5n** (planned) | Compiles DolphinSDK region for issue #1 | Public via decomp.dev mirror | `download_tool.py mwcc --tag GC-1.2.5n` |
| **devkitPPC** | Linker (`powerpc-eabi-ld`) + objdump | Open source | Install separately per devkitPro docs |

## Quick start (existing developers)

If you already have `compiler/ProDGforNGCv393/` populated (the legacy
checked-in layout), the build will continue to work as-is. The download
tool's `verify` command confirms what's installed:

```bash
python tools/download_tool.py verify --version v393
```

## Fresh clone (no compiler/ directory)

SN ProDG is license-restricted and not redistributed by decomp.dev. Three
ways to obtain it:

### Option 1 — from a SN Systems ProDG installer you own

If you have the original ProDG for GameCube installer disc / ISO:

1. Extract the `Disk1/data1/Build_Tools_Bin/` directory from the installer
2. Wrap it in a tar archive:
   ```bash
   tar czf prodg_v393.tar.gz Disk1/data1/Build_Tools_Bin/
   ```
3. Install with:
   ```bash
   python tools/download_tool.py sn-prodg --version v393 \
       --from-archive prodg_v393.tar.gz
   ```

### Option 2 — from a project release artifact (if maintainer has uploaded one)

The repo maintainer may host a private release with the compiler artifact.
If so, the URL goes in an env var:

```bash
export SN_PRODG_RELEASE_URL=https://github.com/.../prodg_v393.tar.gz
python tools/download_tool.py sn-prodg --version v393
```

The tool SHA-verifies the download against the manifest in `download_tool.py`
to detect tampering. If the maintainer rotates the artifact, the manifest
hash must be updated in lockstep.

### Option 3 — alternate ProDG versions (for A/B compiler-flag testing)

Versions 3.5, 3.7, and 3.81 are also tracked. They produce *slightly* different
output than 3.93 and are useful for diagnosing whether a wall is a compiler-
version-specific quirk. SHA hashes for these are pinned in `download_tool.py`.

```bash
python tools/download_tool.py sn-prodg --version v381 \
    --from-archive prodg_v381.tar.gz
```

## For project maintainers — uploading a release artifact

If you have authoritative SN ProDG binaries and want to make fresh clones
work, host them as a GitHub Release:

1. Archive the canonical install:
   ```bash
   cd compiler/
   tar czf ../prodg_v393.tar.gz ProDGforNGCv393/
   ```
2. Compute the SHA256:
   ```bash
   sha256sum prodg_v393.tar.gz
   ```
3. Update `tools/download_tool.py`'s `SN_PRODG_MANIFEST["v393"]["sha256"]`
   with the new hash, replacing the `REPLACE_ME` placeholder.
4. Create a GitHub Release on the project:
   ```bash
   gh release create v0.1-toolchain prodg_v393.tar.gz \
       --title "Toolchain bootstrap v0.1" \
       --notes "SN ProDG v3.93 binary release for Sims2DECOMP. See \
       docs/specs/toolchain-bootstrap.md."
   ```
5. Update README + project docs to point users at the release URL via
   the `SN_PRODG_RELEASE_URL` env var.

**Licensing caveat:** SN Systems ProDG is proprietary. Verify your rights to
redistribute before uploading to a public release. If in doubt, leave the
release private + only share the URL with verified contributors who own
their own license.

## MWCC for DolphinSDK matching (issue #1)

Once the SDK-MWCC build path lands (planned in S19), this command will
fetch the canonical Metrowerks compiler from decomp.dev's public mirror:

```bash
python tools/download_tool.py mwcc --tag GC-1.2.5n
```

MWCC archives are public and SHA-verified through decomp.dev. No license
ambiguity here — many active decomp projects use the same mirror.

## Layout produced

After running the tool, the canonical layout is:

```
compiler/
├── ProDGforNGCv393/Disk1/data1/Build_Tools_Bin/   # primary (v3.93)
│   ├── cc1plus.exe       # C++ compiler driver
│   ├── NgcAs.exe         # assembler
│   ├── cpp.exe           # preprocessor
│   └── (other ProDG bits)
└── alt_versions/v{35,37,381}/                       # alt versions (optional)
    └── (similar contents)

build/tools/mwcc/<tag>/
└── mwcceppc.exe         # MWCC for SDK matching (issue #1)
```

This matches what `tools/verify_match.sh` and `configure.py` look for —
existing scripts work transparently after install.
