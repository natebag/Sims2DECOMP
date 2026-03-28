#!/usr/bin/env python3
"""
Import Sims 2 GC functions into decomp.me as scratches.

Usage:
    # Import a single function
    python tools/decompme_import.py "ESimsCam::Init"

    # Import a list of functions from a file (one per line)
    python tools/decompme_import.py --batch functions.txt

    # Dry run (show what would be uploaded without creating scratches)
    python tools/decompme_import.py --dry-run "ESimsCam::Init"

    # Specify ProDG version (default: prodg_35)
    python tools/decompme_import.py --compiler prodg_37 "ESimsCam::Init"

Requires:
    - extracted/files/u2_ngc_release.map (symbol map)
    - extracted/files/u2_ngc_release_dvd.elf (ELF with debug symbols)
    - powerpc-eabi-objdump (from devkitPPC) on PATH
    - requests: pip install requests
"""

import argparse
import json
import os
import re
import subprocess
import sys

try:
    import requests
except ImportError:
    print("ERROR: 'requests' package required. Install with: pip install requests")
    sys.exit(1)

DECOMP_ME_API = "https://decomp.me/api"
PLATFORM = "gc_wii"
DEFAULT_COMPILER = "prodg_35"

# Compiler flags that match our build (from CLAUDE.md)
# ProDG for GameCube — adjust if needed for decomp.me
DEFAULT_FLAGS = "-O2"

MAP_FILE = os.path.join(os.path.dirname(__file__), "..", "extracted", "files", "u2_ngc_release.map")
ELF_FILE = os.path.join(os.path.dirname(__file__), "..", "extracted", "files", "u2_ngc_release_dvd.elf")


def parse_map_file(map_path):
    """Parse the SN Systems symbol map to get function names and addresses.

    Map format (indented = function within an .obj):
        800034c0 000011b0     4                 path/to/file.obj
        800034c0 0000018c     0                         FunctionName(args)
        8000364c 000002cc     0                         AnotherFunction(args)
    """
    symbols = {}
    in_text = False
    with open(map_path, "r", encoding="utf-8", errors="replace") as f:
        for line in f:
            # Detect .text section
            if ".text" in line and not line.startswith(" " * 30):
                in_text = True
                continue
            # Detect other sections (end of .text)
            if in_text and line.strip() and not line.startswith(" "):
                parts = line.strip().split()
                if len(parts) >= 4 and parts[2] != ".text" and parts[2].startswith("."):
                    in_text = False
                    continue

            if not in_text:
                continue

            # Function lines are deeply indented (40+ spaces before the name)
            # Format: ADDRESS SIZE ALIGN NAME
            stripped = line.rstrip()
            if not stripped:
                continue

            parts = stripped.split()
            if len(parts) < 3:
                continue

            try:
                addr = int(parts[0], 16)
                size = int(parts[1], 16)
            except (ValueError, IndexError):
                continue

            # Functions have size > 0 and are deeply indented with the name at the end
            if size <= 0:
                continue

            # The map has lines like:
            # 804727bc 00000060     0                         FastAllocPool::Alloc(void)
            # Format: ADDR SIZE ALIGN <lots of spaces> NAME
            # The name follows after extensive whitespace padding
            # Use: split on 2+ consecutive spaces after the third field
            # parts[0]=addr, parts[1]=size, parts[2]=align, then name
            if len(parts) < 4:
                continue
            # Find where the name starts: after the align field + whitespace
            align_end = stripped.find(parts[2], stripped.find(parts[1]) + len(parts[1]))
            if align_end < 0:
                continue
            name = stripped[align_end + len(parts[2]):].strip()

            # Skip object files and sections
            if name.endswith(".obj") or name.endswith(".o"):
                continue
            if "\\" in name or name.startswith(".") or "c:\\Build" in name:
                continue

            if name:
                symbols[name] = {"addr": addr, "size": size, "name": name}

    return symbols


def find_symbol(symbols, query):
    """Find a symbol by exact or partial name match."""
    # Exact match first
    if query in symbols:
        return symbols[query]

    # Try demangled-style match (e.g., "ESimsCam::Init" matches mangled name)
    matches = [s for name, s in symbols.items() if query in name]
    if len(matches) == 1:
        return matches[0]
    elif len(matches) > 1:
        print(f"Multiple matches for '{query}':")
        for m in matches[:10]:
            print(f"  0x{m['addr']:08X} ({m['size']:5d} bytes) {m['name']}")
        if len(matches) > 10:
            print(f"  ... and {len(matches) - 10} more")
        return None
    else:
        print(f"No symbol found matching '{query}'")
        return None


def disassemble_function(func_name):
    """Disassemble a function using the project's disasm.py tool."""
    disasm_script = os.path.join(os.path.dirname(__file__), "disasm.py")

    try:
        result = subprocess.run(
            [sys.executable, disasm_script, func_name],
            capture_output=True,
            text=True,
            timeout=30,
            cwd=os.path.join(os.path.dirname(__file__), ".."),
        )
    except FileNotFoundError:
        print("ERROR: disasm.py not found")
        sys.exit(1)

    # Extract raw hex bytes from disasm.py output as .4byte directives
    # Format: "  0x802D7374:  7c 6b 1b 78  mr     r11,r3"
    # Output: ".4byte 0x7C6B1B78  /* mr r11,r3 */"
    lines = []
    for line in result.stdout.split("\n"):
        match = re.match(
            r"\s*0x[0-9A-Fa-f]+:\s+([0-9a-f]{2}\s+[0-9a-f]{2}\s+[0-9a-f]{2}\s+[0-9a-f]{2})\s+(.*)",
            line,
        )
        if match:
            hex_bytes = match.group(1).replace(" ", "").upper()
            instr = match.group(2).strip()
            lines.append(f".4byte 0x{hex_bytes}")

    return "\n".join(lines)


def get_context_for_function(symbol_name):
    """Generate minimal context (typedefs) for a function.

    In a full setup, this would pull from include/classes/ headers.
    For now, provide basic types.
    """
    return """// Sims 2 GameCube - basic types
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef int BOOL;
#define TRUE 1
#define FALSE 0
#define NULL 0
"""


def create_scratch(name, target_asm, context, compiler, compiler_flags, session_id=None, dry_run=False):
    """Create a scratch on decomp.me via the API."""
    payload = {
        "compiler": compiler,
        "platform": PLATFORM,
        "target_asm": target_asm,
        "context": context,
        "diff_label": name,
        "name": name,
        "compiler_flags": compiler_flags,
    }

    if dry_run:
        print(f"\n[DRY RUN] Would create scratch:")
        print(f"  Name: {name}")
        print(f"  Compiler: {compiler}")
        print(f"  Flags: {compiler_flags}")
        print(f"  Assembly: {len(target_asm.split(chr(10)))} lines")
        print(f"  Context: {len(context.split(chr(10)))} lines")
        print(f"  Auth: {'session cookie' if session_id else 'anonymous'}")
        return {"html_url": "(dry run)"}

    headers = {"Content-Type": "application/json"}
    cookies = {}
    if session_id:
        cookies["sessionid"] = session_id
    cf_clearance = os.environ.get("DECOMPME_CF_CLEARANCE")
    if cf_clearance:
        cookies["cf_clearance"] = cf_clearance

    resp = requests.post(
        f"{DECOMP_ME_API}/scratch",
        json=payload,
        headers=headers,
        cookies=cookies,
    )

    if resp.status_code == 201:
        data = resp.json()
        slug = data.get("slug", "unknown")
        url = f"https://decomp.me/scratch/{slug}"
        print(f"  Created: {url}")

        # Claim the scratch to the user's account if authenticated
        claim_token = data.get("claim_token")
        if session_id and claim_token:
            claim_cookies = {"sessionid": session_id}
            if cf_clearance:
                claim_cookies["cf_clearance"] = cf_clearance
            claim_resp = requests.post(
                f"{DECOMP_ME_API}/scratch/{slug}/claim",
                json={"token": claim_token},
                cookies=claim_cookies,
            )
            if claim_resp.status_code == 200 and claim_resp.json().get("success"):
                print(f"  Claimed to your account!")
            else:
                print(f"  Warning: claim failed ({claim_resp.status_code}): {claim_resp.text[:100]}")

        return data
    else:
        print(f"  ERROR {resp.status_code}: {resp.text[:200]}")
        return None


def main():
    parser = argparse.ArgumentParser(description="Import Sims 2 GC functions to decomp.me")
    parser.add_argument("function", nargs="?", help="Function name to import")
    parser.add_argument("--batch", help="File with function names (one per line)")
    parser.add_argument("--compiler", default=DEFAULT_COMPILER,
                        choices=["prodg_35", "prodg_35_b140", "prodg_37", "prodg_381", "prodg_393"],
                        help="ProDG compiler version (default: prodg_35)")
    parser.add_argument("--flags", default=DEFAULT_FLAGS, help="Compiler flags")
    parser.add_argument("--session", help="decomp.me session cookie (to create under your account)")
    parser.add_argument("--dry-run", action="store_true", help="Show what would be created")
    parser.add_argument("--list-functions", action="store_true", help="List all functions in map")
    args = parser.parse_args()

    # Resolve paths
    map_path = os.path.normpath(MAP_FILE)
    elf_path = os.path.normpath(ELF_FILE)

    if not os.path.exists(map_path):
        print(f"ERROR: Map file not found: {map_path}")
        sys.exit(1)

    print("Parsing symbol map...")
    symbols = parse_map_file(map_path)
    print(f"Found {len(symbols)} code functions in .text section")

    if args.list_functions:
        for name in sorted(symbols.keys()):
            s = symbols[name]
            print(f"  0x{s['addr']:08X} ({s['size']:6d} bytes) {s['name']}")
        return

    if not os.path.exists(elf_path):
        print(f"ERROR: ELF file not found: {elf_path}")
        sys.exit(1)

    # Get function list
    functions = []
    if args.batch:
        with open(args.batch) as f:
            functions = [line.strip() for line in f if line.strip() and not line.startswith("#")]
    elif args.function:
        functions = [args.function]
    else:
        parser.print_help()
        return

    # Process each function
    created = 0
    failed = 0
    for func_name in functions:
        print(f"\n--- {func_name} ---")

        # If func_name doesn't have parens, try to find full signature from map
        if "(" not in func_name:
            sym = find_symbol(symbols, func_name)
            if sym:
                func_name = sym["name"]
                print(f"  Full name: {func_name}")
            else:
                print(f"  Warning: not in map, trying disasm.py directly")

        # Disassemble using disasm.py (it uses the ELF which matches the DOL)
        print("  Disassembling...")
        asm = disassemble_function(func_name)
        if not asm:
            print("  ERROR: No assembly output")
            failed += 1
            continue
        print(f"  Got {len(asm.split(chr(10)))} instructions")

        # Get context
        context = get_context_for_function(sym["name"])

        # Create scratch
        result = create_scratch(
            name=func_name,
            target_asm=asm,
            context=context,
            compiler=args.compiler,
            compiler_flags=args.flags,
            session_id=args.session or os.environ.get("DECOMPME_SESSION"),
            dry_run=args.dry_run,
        )
        if result:
            created += 1
        else:
            failed += 1

    print(f"\n=== Done: {created} created, {failed} failed ===")


if __name__ == "__main__":
    main()
