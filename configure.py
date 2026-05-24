#!/usr/bin/env python3
"""Sims2DECOMP configure.py — generates build.ninja for the matching build.

Emits a build.ninja that drives the existing inject-based build pipeline with
ninja parallelism + dependency tracking. The internals (skeleton generation +
byte injection + link) are unchanged; ninja just provides:

  * Parallel compilation of 10K+ matched .cpp files (~10x faster than make on
    multi-core boxes — `make compile` is serial without -jN).
  * Incremental rebuilds — only changed sources recompile + re-link.
  * Standard dtk-template surface: `python configure.py && ninja` works the
    way decomp.dev / objdiff users expect.

The build graph:

    config/symbols.txt + tools/gen_skeleton.py
        |
        v
    build/G4ZE69/skeleton/{init,text,ctors,...}.s        (gen_skeleton rule)
        |
        v
    src/matched/**/*.cpp + src/**/*.cpp   ->   build/G4ZE69/obj/**/*.o   (cxx rule, parallel)
        |
        v
    tools/inject_matches.py --rebuild reads all .o files + DOL, patches matched
    bytes into skeleton .s, reassembles, and links the final ELF.   (inject rule)
        |
        v
    build/G4ZE69/main.elf  ->  build/G4ZE69/main.dol   (elf2dol rule)
        |
        v
    sha1sum -c config/G4ZE69/build.sha1                 (verify rule)
        |
        v
    tools/generate_report.py -> build/G4ZE69/report.json (report rule)

Usage:

    python configure.py                  # generate build.ninja
    python configure.py -v G4ZE69        # explicit version
    python configure.py progress         # print progress (uses existing report.json)

    ninja                                # default target: build/G4ZE69/main.dol
    ninja skeleton                       # just generate skeleton
    ninja compile                        # just compile all .cpp files
    ninja diff                           # full build + dtk dol diff
    ninja verify                         # full build + sha1 check
    ninja report                         # regenerate report.json
    ninja all                            # everything (verify + report)

Note: this is the **Tier 1 wrapper** — it drives the existing devkitPPC-GCC
compile + inject pipeline. The "full SN ProDG per-file compile" pipeline
(where every matched .cpp goes through SN cc1plus.exe + asm_processor and the
final DOL is link-built, not injection-built) is Tier 2 and is a separate
multi-session project.
"""

from __future__ import annotations

import argparse
import os
import re
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent
sys.path.insert(0, str(REPO_ROOT / "tools"))

from ninja_syntax import Writer as NinjaWriter, escape_path  # noqa: E402

DEFAULT_VERSION = "G4ZE69"
VERSIONS = [DEFAULT_VERSION]

# Skeleton sections (must match tools/gen_skeleton.py SECTION_BASES order).
SKELETON_SECTIONS = ["init", "text", "ctors", "rodata", "data", "bss", "sdata", "sbss", "sdata2"]

# Default toolchain locations on Windows. Override via env vars if your install
# lives elsewhere; configure.py also accepts --binutils / --compilers.
DEFAULT_DEVKITPPC = "F:/coding/Decompiles/Tools/devkitPro/devkitPPC"
DEFAULT_DTK = "F:/coding/Decompiles/Tools/dtk-windows-x86_64.exe"


def _valid_devkitppc(path: str) -> bool:
    """A devkitPPC root is valid if its powerpc-eabi-gcc binary exists."""
    if not path:
        return False
    base = Path(path)
    for cand in ("bin/powerpc-eabi-gcc.exe", "bin/powerpc-eabi-gcc"):
        if (base / cand).is_file():
            return True
    return False


def detect_toolchain(args: argparse.Namespace) -> dict[str, str]:
    """Resolve toolchain paths from args + env + sensible defaults.

    Validates that the resolved devkitPPC actually contains the compiler — Git
    Bash on Windows sometimes injects a stale DEVKITPPC pointing at a
    pre-existing devkitPro install that's missing the PPC toolchain.
    """
    candidates_devkitppc = [args.binutils, os.environ.get("DEVKITPPC"), DEFAULT_DEVKITPPC]
    devkitppc = next((c for c in candidates_devkitppc if _valid_devkitppc(c or "")), DEFAULT_DEVKITPPC)

    dtk = args.dtk or os.environ.get("DTK") or DEFAULT_DTK
    python = args.python or os.environ.get("PYTHON") or sys.executable
    return {
        "devkitppc": devkitppc.replace("\\", "/"),
        "dtk": dtk.replace("\\", "/"),
        "python": python.replace("\\", "/"),
    }


# Per-file SN-ProDG flag override. Pre-commit verifies matches with SN ProDG
# using these flags, but the inject-based build below still uses devkitPPC GCC
# (the SN .o format isn't linker-compatible without more glue — Tier 2 work).
FLAGS_PATTERN = re.compile(r"^//\s*FLAGS:\s*(.+?)\s*$", re.MULTILINE)

# Per-file compiler selector (GitHub issue #1). Default is the project-wide
# devkitPPC g++. Setting `// COMPILER: mwcc` at the top of a source file routes
# it to the MWCC compile rule, which is required for matching the DolphinSDK
# region (originally built with Metrowerks CodeWarrior, byte-incompatible
# with GCC output regardless of source coax).
#
# MWCC must be installed first via `python tools/download_tool.py mwcc`.
# See docs/specs/toolchain-bootstrap.md.
COMPILER_PATTERN = re.compile(r"^//\s*COMPILER:\s*(\S+)\s*$", re.MULTILINE)


def parse_per_file_flags(src_path: Path) -> str | None:
    """Read the first `// FLAGS: ...` line from a source file, if any."""
    try:
        with open(src_path, encoding="utf-8", errors="replace") as f:
            head = f.read(2048)
    except OSError:
        return None
    m = FLAGS_PATTERN.search(head)
    return m.group(1).strip() if m else None


def parse_per_file_compiler(src_path: Path) -> str | None:
    """Read the first `// COMPILER: ...` line, if any. Returns the lowercased
    compiler name (e.g. 'mwcc') or None for the default (devkitPPC g++).
    """
    try:
        with open(src_path, encoding="utf-8", errors="replace") as f:
            head = f.read(2048)
    except OSError:
        return None
    m = COMPILER_PATTERN.search(head)
    return m.group(1).strip().lower() if m else None


def enumerate_cxx_sources(full: bool) -> list[Path]:
    """Return .cpp sources to compile.

    Default scope (the meaningful set for byte-matching):
      * src/matched/ — the only files whose compiled bytes inject_matches.py
        actually reads and patches into the skeleton. ~10K files.

    Full scope (--full, mirrors the Makefile's CXX_SRCS):
      * Everything under src/ except scaffolding-only roots (wip, asm_decomp,
        pending_matches). ~20K files, hours to compile, contributes nothing
        useful to the inject pipeline because the non-matched .o bytes are
        ignored. Useful for a CI sanity-compile that "everything builds".

    asm_decomp/wip/pending_matches/test_scroll are ALWAYS excluded.
    """
    sources: list[Path] = []
    excluded_roots = {"asm_decomp", "wip", "pending_matches"}
    src_dir = REPO_ROOT / "src"
    # src/matched is the only root whose compiled .o actually contributes — that's
    # what inject_matches.py reads to extract byte-matching function bytes. The
    # other roots compile fine but their .o is discarded (asm_wrappers contains
    # legacy inline-asm "fake match" files; everything else is empty scaffolding).
    included_roots = None if full else {"matched"}
    for p in src_dir.rglob("*.cpp"):
        try:
            rel = p.relative_to(src_dir)
        except ValueError:
            continue
        if not rel.parts:
            continue
        root = rel.parts[0]
        if root in excluded_roots:
            continue
        if included_roots is not None and root not in included_roots:
            continue
        sources.append(p)
    sources.sort()
    return sources


def enumerate_c_sources(full: bool) -> list[Path]:
    """Return .c sources to compile (same scoping rules as enumerate_cxx_sources)."""
    sources: list[Path] = []
    excluded_roots = {"asm_decomp", "wip", "pending_matches"}
    src_dir = REPO_ROOT / "src"
    # src/matched is the only root whose compiled .o actually contributes — that's
    # what inject_matches.py reads to extract byte-matching function bytes. The
    # other roots compile fine but their .o is discarded (asm_wrappers contains
    # legacy inline-asm "fake match" files; everything else is empty scaffolding).
    included_roots = None if full else {"matched"}
    for p in src_dir.rglob("*.c"):
        try:
            rel = p.relative_to(src_dir)
        except ValueError:
            continue
        if not rel.parts:
            continue
        root = rel.parts[0]
        if root in excluded_roots:
            continue
        if included_roots is not None and root not in included_roots:
            continue
        sources.append(p)
    sources.sort()
    return sources


def write_build_ninja(version: str, args: argparse.Namespace) -> Path:
    tc = detect_toolchain(args)

    build_dir = REPO_ROOT / "build" / version
    obj_dir = build_dir / "obj"
    # gen_skeleton.py writes to build/skeleton/ (legacy path); we honor that and
    # only stage the final ELF/DOL into build/$version/. inject_matches.py also
    # reads/writes build/skeleton/.
    skeleton_dir = REPO_ROOT / "build" / "skeleton"
    build_ninja = REPO_ROOT / "build.ninja"

    cxx_sources = enumerate_cxx_sources(args.full)
    c_sources = enumerate_c_sources(args.full)

    print(f"[configure.py] version={version}")
    print(f"[configure.py] DEVKITPPC={tc['devkitppc']}")
    print(f"[configure.py] DTK={tc['dtk']}")
    print(f"[configure.py] PYTHON={tc['python']}")
    print(f"[configure.py] sources: {len(cxx_sources)} .cpp, {len(c_sources)} .c")
    print(f"[configure.py] writing {build_ninja.relative_to(REPO_ROOT)}")

    fh = open(build_ninja, "w", encoding="utf-8", newline="\n")
    n = NinjaWriter(fh, width=120)

    n.comment(f"build.ninja for Sims2DECOMP {version} -- AUTOGENERATED by configure.py.")
    n.comment("Do not hand-edit; re-run `python configure.py` to regenerate.")
    n.newline()

    # Required ninja_required_version
    n.variable("ninja_required_version", "1.10")
    n.newline()

    # ---- toolchain variables ----
    n.variable("devkitppc", tc["devkitppc"])
    n.variable("dtk", tc["dtk"])
    n.variable("python", tc["python"])
    n.variable("cc", "$devkitppc/bin/powerpc-eabi-gcc")
    n.variable("cxx", "$devkitppc/bin/powerpc-eabi-g++")
    n.variable("as_", "$devkitppc/bin/powerpc-eabi-as")
    n.variable("ld", "$devkitppc/bin/powerpc-eabi-ld")
    n.variable("objdump", "$devkitppc/bin/powerpc-eabi-objdump")
    n.newline()

    # ---- compile flags (mirror Makefile) ----
    arch_flags = "-mcpu=750 -meabi -mhard-float"
    opt_flags = (
        "-O2 -fno-schedule-insns -fno-schedule-insns2 "
        "-fno-inline -fno-inline-small-functions"
    )
    cxx_flags_base = (
        f"{arch_flags} {opt_flags} -fno-exceptions -fno-rtti -fno-builtin "
        "-fshort-wchar -nostdinc++ -Wall -Wno-unused -Wno-return-type -fpermissive"
    )
    c_flags_base = f"{arch_flags} {opt_flags} -fno-builtin -Wall -Wno-unused"
    includes = "-Iinclude -Isrc -Ilibs/dolphinsdk -Ilibs/sn_runtime -Ilibs/apt"
    defines = "-DNDEBUG -DEA_PLATFORM_GAMECUBE=1 -DGEKKO"

    n.variable("cxxflags_base", f"{cxx_flags_base} {includes} {defines}")
    n.variable("cflags_base", f"{c_flags_base} {includes} {defines}")
    n.variable("asflags", "-mgekko -mregnames -memb")
    n.newline()

    # ---- MWCC (Metrowerks) — for DolphinSDK matching (issue #1) ----
    # Installed by `python tools/download_tool.py mwcc --tag GC-1.2.5n`.
    # Path is best-effort: a source file with `// COMPILER: mwcc` invokes
    # $mwcc; if MWCC isn't installed, the rule's command will fail with a
    # clear error. Default-build users without any MWCC-tagged source see
    # no behavior change.
    mwcc_tag_default = "GC-1.2.5n"
    mwcc_path = REPO_ROOT / "build" / "tools" / "mwcc" / mwcc_tag_default / "mwcceppc.exe"
    n.variable("mwcc_tag", mwcc_tag_default)
    n.variable("mwcc", str(mwcc_path).replace("\\", "/"))
    # MWCC flags for DolphinSDK 1.0 HW2 build — match the canonical GC-1.2.5n
    # defaults that other GameCube decomp projects use for the SDK region.
    # See zeldaret/oot's Makefile + doldecomp/melee's tools/configure.py for
    # the reference flag set. -O4,p = aggressive optimization with peephole;
    # -fp hard = hardware FP; -enum int = MSVC-compatible enum sizing.
    mwcc_flags = (
        "-c -proc gekko -fp hard -O4,p -enum int "
        "-Cpp_exceptions off -RTTI off -inline auto -nodefaults"
    )
    n.variable("mwccflags_base", f"{mwcc_flags} {includes} {defines}")
    n.newline()

    # ---- linker config (mirrors Makefile) ----
    n.variable("ldscript", "config/ldscript.lcf")
    n.variable("ldflags", "-T $ldscript -nostdlib --allow-multiple-definition --no-check-sections --noinhibit-exec")
    n.newline()

    # ---- pools ----
    # Limit inject + link to 1 at a time (they touch shared state).
    n.pool("singleton", 1)
    n.newline()

    # ---- rules ----

    n.rule(
        "cxx",
        command='"$cxx" $cxxflags_base $extra_flags -MMD -MF "$out.d" -c "$in" -o "$out"',
        description="CXX $in",
        depfile="$out.d",
        deps="gcc",
    )
    n.newline()

    n.rule(
        "cc",
        command='"$cc" $cflags_base $extra_flags -MMD -MF "$out.d" -c "$in" -o "$out"',
        description="CC $in",
        depfile="$out.d",
        deps="gcc",
    )
    n.newline()

    # MWCC rule for source files marked `// COMPILER: mwcc` — needed for
    # DolphinSDK matching (issue #1). Only invoked when a build statement
    # explicitly targets it; default builds with no MWCC-tagged sources are
    # unaffected. If MWCC isn't installed, the command fails with a clear
    # error directing users to download_tool.py.
    n.rule(
        "cxx_mwcc",
        command='"$mwcc" $mwccflags_base $extra_flags -o "$out" "$in"',
        description="MWCC $in",
    )
    n.newline()

    n.rule(
        "gen_skeleton",
        command='"$python" tools/gen_skeleton.py',
        description="GEN skeleton ($out)",
        # restat = treat outputs whose mtime didn't change as no-op for downstream
        restat=True,
    )
    n.newline()

    # inject_matches.py is monolithic: compile (we skip via --no-compile if
    # they let us... actually it has --rebuild which assumes pre-compiled .o
    # files are in build/obj/matched/. The implicit deps wire that up.).
    # It (1) rewrites skeleton .s to bake in matched bytes, (2) assembles
    # skeleton .s -> .o, (3) links to build/sims2.elf.
    n.rule(
        "inject_and_link",
        command='"$python" tools/inject_matches.py --rebuild',
        description="INJECT+LINK build/sims2.elf",
        pool="singleton",
    )
    n.newline()

    # Copy/rename the legacy output into the dtk-template path.
    if os.name == "nt":
        copy_cmd = 'cmd /c copy /Y "build\\sims2.elf" "$out"'
    else:
        copy_cmd = "cp build/sims2.elf $out"
    n.rule(
        "stage_elf",
        command=copy_cmd,
        description="STAGE $out",
    )
    n.newline()

    n.rule(
        "elf2dol",
        command='"$dtk" elf2dol "$in" "$out"',
        description="ELF2DOL $out",
    )
    n.newline()

    n.rule(
        "dol_diff",
        command='"$dtk" dol diff config/sims2_gc.yml "$in"',
        description="DIFF $in vs original DOL",
        pool="console",
    )
    n.newline()

    if os.name == "nt":
        # On Windows use sha1sum via msys2 if present; else fall back to certutil.
        sha1_cmd = (
            'bash -c "sha1sum -c config/G4ZE69/build.sha1" '
            '|| ($python tools/verify_sha1.py config/G4ZE69/build.sha1)'
        )
    else:
        sha1_cmd = "sha1sum -c config/G4ZE69/build.sha1"
    n.rule(
        "sha1_verify",
        command=sha1_cmd,
        description="SHA1 verify $in",
        pool="console",
    )
    n.newline()

    n.rule(
        "gen_report",
        command='"$python" tools/generate_report.py --version ' + version,
        description=f"REPORT build/{version}/report.json",
        pool="singleton",
        restat=True,
    )
    n.newline()

    # configure.py regenerator. ninja reruns configure.py automatically when
    # any of these inputs change (touched source files don't trigger reconfigure
    # by themselves -- ninja only reconfigures if the configure.py inputs change).
    n.rule(
        "configure",
        command='"$python" configure.py -v ' + version,
        description="RECONFIGURE build.ninja",
        generator=True,
        pool="console",
    )
    n.newline()

    # ---- build statements ----

    # Skeleton .s files. Single rule with 9 outputs because gen_skeleton.py
    # writes them all at once into build/skeleton/ (legacy path).
    skeleton_s = [
        f"build/skeleton/{s}.s" for s in SKELETON_SECTIONS
    ]
    n.build(
        outputs=skeleton_s,
        rule="gen_skeleton",
        inputs=["config/symbols.txt"],
        implicit=["tools/gen_skeleton.py"],
    )
    n.newline()

    # Compile every .cpp / .c source. Files with `// FLAGS:` get per-file extra flags.
    # Files with `// COMPILER: mwcc` route to the MWCC rule (DolphinSDK matching).
    all_objs: list[str] = []
    mwcc_count = 0
    src_dir_rel = "src"
    for src in cxx_sources:
        rel = src.relative_to(REPO_ROOT / src_dir_rel)
        obj_rel = (obj_dir / rel).with_suffix(".o").relative_to(REPO_ROOT)
        obj_str = str(obj_rel).replace("\\", "/")
        src_str = str(src.relative_to(REPO_ROOT)).replace("\\", "/")
        extra = parse_per_file_flags(src)
        compiler = parse_per_file_compiler(src)
        variables = {"extra_flags": extra} if extra else None
        if compiler == "mwcc":
            n.build(outputs=obj_str, rule="cxx_mwcc", inputs=src_str, variables=variables)
            mwcc_count += 1
        else:
            n.build(outputs=obj_str, rule="cxx", inputs=src_str, variables=variables)
        all_objs.append(obj_str)
    if mwcc_count > 0:
        print(f"[configure.py] {mwcc_count} source(s) routed to MWCC "
              f"(install via `python tools/download_tool.py mwcc`)")
    for src in c_sources:
        rel = src.relative_to(REPO_ROOT / src_dir_rel)
        obj_rel = (obj_dir / rel).with_suffix(".o").relative_to(REPO_ROOT)
        obj_str = str(obj_rel).replace("\\", "/")
        src_str = str(src.relative_to(REPO_ROOT)).replace("\\", "/")
        n.build(outputs=obj_str, rule="cc", inputs=src_str)
        all_objs.append(obj_str)
    n.newline()

    # Compile phony alias.
    n.build(outputs="compile", rule="phony", inputs=all_objs)
    n.build(outputs="skeleton", rule="phony", inputs=skeleton_s)
    n.newline()

    # Inject + link. Reads all matched .o + skeleton .s, outputs the ELF.
    legacy_elf = "build/sims2.elf"
    n.build(
        outputs=legacy_elf,
        rule="inject_and_link",
        inputs=all_objs,
        implicit=skeleton_s + ["config/ldscript.lcf", "config/symbols.txt", "tools/inject_matches.py"],
    )
    n.newline()

    # Stage final ELF into the dtk-template path.
    final_elf = f"build/{version}/main.elf"
    n.build(outputs=final_elf, rule="stage_elf", inputs=legacy_elf)
    n.newline()

    # ELF -> DOL.
    final_dol = f"build/{version}/main.dol"
    n.build(outputs=final_dol, rule="elf2dol", inputs=final_elf)
    n.newline()

    # Diff vs original (phony).
    n.build(outputs="diff", rule="dol_diff", inputs=final_dol)
    n.newline()

    # SHA1 verify (phony).
    n.build(outputs="verify", rule="sha1_verify", inputs=final_dol)
    n.newline()

    # Report. Reads matched filenames + symbols.txt only -- does NOT depend on
    # compiled objects (matches are detected via match_<addr>_*.cpp filename
    # convention, not via objdump). This lets `ninja report` run without
    # triggering a 10K-file compile.
    report_path = f"build/{version}/report.json"
    n.build(
        outputs=report_path,
        rule="gen_report",
        implicit=[
            "tools/generate_report.py",
            "config/symbols.txt",
        ],
    )
    n.build(outputs="report", rule="phony", inputs=report_path)
    n.newline()

    # all = verify + report
    n.build(outputs="all", rule="phony", inputs=["verify", "report"])
    n.newline()

    # Reconfigure if configure.py or its key inputs change.
    n.build(
        outputs="build.ninja",
        rule="configure",
        implicit=[
            "configure.py",
            "tools/ninja_syntax.py",
            "config/symbols.txt",
        ],
    )
    n.newline()

    n.default(final_dol)
    n.close()

    print(f"[configure.py] wrote {build_ninja.relative_to(REPO_ROOT)} "
          f"({build_ninja.stat().st_size:,} bytes)")
    return build_ninja


def cmd_configure(args: argparse.Namespace) -> int:
    write_build_ninja(args.version, args)
    return 0


def cmd_progress(args: argparse.Namespace) -> int:
    """Print human-readable progress from build/<version>/report.json."""
    import json
    report_path = REPO_ROOT / "build" / args.version / "report.json"
    if not report_path.is_file():
        print(f"[configure.py] No report at {report_path}.")
        print("[configure.py] Run: python configure.py && ninja report")
        return 1
    with open(report_path, encoding="utf-8") as f:
        report = json.load(f)
    m = report["measures"]
    pct_code = float(m.get("matched_code_percent", 0))
    pct_funcs = float(m.get("matched_functions_percent", 0))
    print(f"\nProgress for {args.version}:")
    print(f"  Bytes:     {pct_code:.2f}% matched "
          f"({int(m.get('matched_code', 0)):,} / {int(m.get('total_code', 0)):,})")
    print(f"  Functions: {pct_funcs:.2f}% matched "
          f"({int(m.get('matched_functions', 0)):,} / {int(m.get('total_functions', 0)):,})")
    for cat in report.get("categories", []):
        cm = cat["measures"]
        if int(cm.get("total_code", 0)) == 0:
            continue
        print(f"  {cat['name']:8s}  {float(cm.get('matched_code_percent', 0)):6.2f}% "
              f"({int(cm.get('matched_code', 0)):>9,} / {int(cm.get('total_code', 0)):>9,} bytes)")
    return 0


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Sims2DECOMP configure.py -- emits build.ninja.",
    )
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
    # dtk-template-standard flags. We accept them so the same CI workflow works
    # across decomp.dev-listed projects; the ones we actually use are wired.
    parser.add_argument("--binutils", default=None,
                        help="path to devkitPPC root (overrides DEVKITPPC env)")
    parser.add_argument("--compilers", default=None,
                        help="(ignored) path to compilers directory")
    parser.add_argument("--dtk", default=None,
                        help="path to dtk binary (overrides DTK env)")
    parser.add_argument("--python", default=None,
                        help="path to python interpreter (default: this one)")
    parser.add_argument("--map", action="store_true",
                        help="(ignored) generate map output (build always emits map)")
    parser.add_argument("--no-progress", action="store_true",
                        help="(ignored) disable progress regen")
    parser.add_argument("--full", action="store_true",
                        help="compile EVERY .cpp under src/ (default: src/matched/ only). "
                             "Use for full-tree compile sanity check (~20K files, hours).")
    args = parser.parse_args()

    if args.mode == "progress":
        return cmd_progress(args)
    return cmd_configure(args)


if __name__ == "__main__":
    sys.exit(main())
