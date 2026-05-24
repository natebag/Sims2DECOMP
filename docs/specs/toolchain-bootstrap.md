# Toolchain Bootstrap

How to install the compilers needed to build this project. Driven by
`tools/download_tool.py` (addresses GitHub issue #3).

## Quick start

```bash
python tools/download_tool.py compilers
```

That's the whole bootstrap. Fetches `compilers_latest.zip` (~80MB) from
`files.decomp.dev` and extracts the compilers we use into `compiler/`.
The same archive is used by other GameCube / Wii decomp projects on
decomp.dev — no special permissions, no licensing-restricted private
mirror, no GitHub release artifacts to manage.

After install, run `python tools/download_tool.py verify` to confirm.

## What gets installed

| Path | Compiler | Purpose |
|------|----------|---------|
| `compiler/prodg/3.9.3/` | SN ProDG 3.9.3 (GCC 2.95.3 + SN BUILD v1.76) | **Primary game compiler** — what the original DOL was built with |
| `compiler/prodg/3.8.1/` | SN ProDG 3.8.1 | A/B alt — flag-divergence testing |
| `compiler/prodg/3.7/` | SN ProDG 3.7 | A/B alt |
| `compiler/prodg/3.5/` | SN ProDG 3.5 | A/B alt |
| `compiler/mwcc/1.2.5n/` | Metrowerks CodeWarrior GC-1.2.5n | **DolphinSDK matching** (issue #1) |

The archive also contains MWCC variants for Wii / Xbox 360 and additional
GameCube MWCC versions. Those are skipped by default. To opt into one:

```bash
python tools/download_tool.py mwcc --tag 1.3.2
```

## Verification

```bash
$ python tools/download_tool.py verify
  [OK]    SN ProDG 3.9.3 (primary)            compiler/prodg/3.9.3/cc1plus.exe
  [OK]    SN ProDG 3.8.1 (alt)                compiler/prodg/3.8.1/cc1plus.exe
  [OK]    SN ProDG 3.7   (alt)                compiler/prodg/3.7/cc1plus.exe
  [OK]    SN ProDG 3.5   (alt)                compiler/prodg/3.5/cc1plus.exe
  [OK]    MWCC GC-1.2.5n (DolphinSDK)         compiler/mwcc/1.2.5n/mwcceppc.exe
```

`tools/verify_match.sh` looks for `compiler/prodg/3.9.3/cc1plus.exe` first
and falls back to the legacy `compiler/ProDGforNGCv393/Disk1/data1/Build_Tools_Bin/`
path so existing checkouts keep working during the migration.

`configure.py`'s MWCC rule points at `compiler/mwcc/1.2.5n/mwcceppc.exe`.

## Reproducibility

The compilers archive on decomp.dev is versioned by tag (e.g.
`compilers_20240706.zip`). The default `--tag latest` follows whatever
decomp.dev publishes as current. To pin a specific snapshot for build
reproducibility:

```bash
python tools/download_tool.py compilers --tag 20240706
```

The cached archive lives at `build/tools/downloads/compilers_<tag>.zip`
and is gitignored.

## What you still need separately

| Tool | Why | Install |
|------|-----|---------|
| `devkitPPC` | Linker (`powerpc-eabi-ld`) + objdump + assembler | https://devkitpro.org |
| `decomp-toolkit` (`dtk`) | ELF/DOL operations, diffing, ldscript helpers | https://github.com/encounter/decomp-toolkit |
| Python 3.10+ | All build scripts | https://python.org |

These have their own license / installer flows. The compilers archive
covers only the GameCube-specific compiler binaries.

## Removing the in-tree compiler/ checkout

The repo currently ships some compiler binaries committed under
`compiler/ProDGforNGCv393/`, `compiler/alt_versions/`, and `compiler/maybe/`
(predates the `download_tool.py` workflow). Once you've confirmed the
download path works on your machine, the maintainer can drop those from
git with:

```bash
git rm --cached -r compiler/ProDGforNGCv393/ compiler/alt_versions/ compiler/maybe/
echo "compiler/" >> .gitignore
git commit -m "compiler/: migrate to download_tool.py, drop in-tree binaries"
```

After that, fresh clones pull the compilers from decomp.dev on demand.
The existing developer's `compiler/` directory is untouched on disk;
only the git tracking changes.
