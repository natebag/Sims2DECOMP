#!/usr/bin/env python3
"""decomp_agent.py — Automated function matching using AI APIs.

Feeds PPC disassembly to an AI, gets C++ back, compiles and verifies
against the original DOL. Retries on mismatch with diff feedback.

Usage:
    # Using Claude API (Anthropic)
    python tools/decomp_agent.py --api anthropic --key sk-ant-XXXX --count 50

    # Using OpenAI API
    python tools/decomp_agent.py --api openai --key sk-XXXX --count 50

    # Dry run — show what would be attempted
    python tools/decomp_agent.py --dry-run --count 20

    # Resume from where we left off
    python tools/decomp_agent.py --api anthropic --key sk-ant-XXXX --resume
"""

import struct
import sys
import os
import re
import json
import subprocess
import time
import argparse

# Paths
DOL_PATH = "extracted/sys/main.dol"
MAP_PATH = "extracted/files/u2_ngc_release_dvd.map"
MATCHED_DIR = "src/matched"
VERIFY_SCRIPT = "tools/verify_match.sh"
PROGRESS_FILE = "tools/decomp_progress.json"
BASH_EXE = r"C:\Program Files\Git\bin\bash.exe"

# ============================================================================
# DOL reading
# ============================================================================

def read_dol():
    with open(DOL_PATH, "rb") as f:
        return f.read()

def vaddr_to_offset(dol, vaddr):
    for i in range(7):
        off = struct.unpack(">I", dol[i*4:i*4+4])[0]
        addr = struct.unpack(">I", dol[0x48+i*4:0x48+i*4+4])[0]
        sz = struct.unpack(">I", dol[0x90+i*4:0x90+i*4+4])[0]
        if addr <= vaddr < addr + sz:
            return off + (vaddr - addr)
    return None

def extract_bytes(dol, vaddr, size):
    foff = vaddr_to_offset(dol, vaddr)
    if foff is None: return None
    return dol[foff:foff+size]

def disassemble_function(dol, vaddr, size):
    """Get hex dump + basic disassembly for a function."""
    raw = extract_bytes(dol, vaddr, size)
    if not raw: return None

    lines = []
    hex_str = " ".join(f"{b:02X}" for b in raw)
    lines.append(f"// Address: 0x{vaddr:08X} | Size: {size} bytes")
    lines.append(f"// Raw bytes: {hex_str}")
    lines.append(f"//")

    # Use objdump for proper disassembly
    tmp_bin = "build/verify/_tmp_func.bin"
    os.makedirs("build/verify", exist_ok=True)
    with open(tmp_bin, "wb") as f:
        f.write(raw)

    result = subprocess.run(
        [BASH_EXE, "-c",
         f'export PATH="/f/coding/Decompiles/Tools/devkitPro/msys2/usr/bin:$PATH" && '
         f'/f/coding/Decompiles/Tools/devkitPro/devkitPPC/bin/powerpc-eabi-objdump '
         f'-D -b binary -m powerpc -EB "{tmp_bin}"'],
        capture_output=True, text=True, timeout=10
    )

    if result.returncode == 0:
        for line in result.stdout.splitlines():
            if ":" in line and not line.startswith("/"):
                # Rewrite addresses to be absolute
                m = re.match(r'\s*([0-9a-f]+):\s+(.*)', line)
                if m:
                    rel_addr = int(m.group(1), 16)
                    abs_addr = vaddr + rel_addr
                    lines.append(f"//   {abs_addr:08X}:  {m.group(2)}")
    else:
        lines.append("// (objdump failed, raw hex only)")

    return "\n".join(lines)

# ============================================================================
# Map file parsing
# ============================================================================

def parse_all_functions():
    """Parse all code functions from the DVD map."""
    funcs = []
    with open(MAP_PATH, "r", errors="replace") as f:
        for line in f:
            m = re.match(r'([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{8})\s+\d+\s+(.*)', line)
            if m:
                addr = int(m.group(1), 16)
                size = int(m.group(2), 16)
                name = m.group(3).strip()
                if size > 0 and 0x80003100 <= addr < 0x803CA900:
                    funcs.append((addr, size, name))
    return funcs

def get_already_matched():
    """Get set of addresses already matched."""
    matched = set()
    for root, dirs, files in os.walk(MATCHED_DIR):
        for f in files:
            if f.endswith(".cpp"):
                m = re.match(r'match_([0-9A-Fa-f]{8})_', f)
                if m:
                    matched.add(int(m.group(1), 16))
    return matched

def get_unmatched_functions(max_size=64):
    """Get functions not yet matched, sorted by size (easiest first)."""
    all_funcs = parse_all_functions()
    matched = get_already_matched()
    unmatched = [(a, s, n) for a, s, n in all_funcs if a not in matched and s <= max_size]
    unmatched.sort(key=lambda x: x[1])  # smallest first
    return unmatched

# ============================================================================
# AI API calls
# ============================================================================

SYSTEM_PROMPT = """You are a GameCube (PowerPC) decompilation expert. Your job is to write C++ that compiles to byte-identical PPC output using the SN Systems ProDG compiler (GCC 2.95.3).

COMPILER: SN Systems ProDG cc1plus.exe — GCC 2.95.3 SN BUILD v1.76 for Nintendo GameCube
This is the ORIGINAL compiler that built the game. It produces matching output naturally.

CRITICAL C++ RULES (GCC 2.95 / C++98):
1. NO // comments that start with hex like // 0x... (use /* */ instead or put comments after code)
2. NO modern C++ (no auto, no range-for, no nullptr — use NULL)
3. Output ONLY the C++ code, no explanations or markdown
4. Include the class declaration if it's a member function
5. Use exact field offsets with pointer arithmetic: *(int*)((char*)this + 0xOFFSET)
6. The function must compile standalone (include all needed declarations)
7. Do NOT use #include — the compiler has no include path configured

PPC CONVENTIONS:
- r3 = this pointer (for member functions) or first param
- r4 = first param (member) or second param (free function)
- r3 = return value (int/pointer), f1 = return value (float)
- r13 = Small Data Area base (static/global variables)
- blr = return from function

COMMON PATTERNS:
- lwz r3, off(r3); blr  →  return *(int*)((char*)this + off);
- stw r4, off(r3); blr  →  *(int*)((char*)this + off) = param;
- li r3, N; blr          →  return N;
- li r0, N; stw r0, off(r3); blr  →  *(int*)((char*)this + off) = N;
- stwu r1, -N(r1) ... blr  →  function with stack frame
- rlwinm r3,r3,N,M,K; blr  →  bit extraction: return (field >> shift) & mask;
- lha = signed short load, lhz = unsigned short load, lbz = unsigned char load
"""

def call_anthropic(api_key, prompt, model="claude-sonnet-4-20250514"):
    """Call Anthropic Claude API."""
    import urllib.request
    import json as j

    data = j.dumps({
        "model": model,
        "max_tokens": 2048,
        "system": SYSTEM_PROMPT,
        "messages": [{"role": "user", "content": prompt}]
    }).encode()

    req = urllib.request.Request(
        "https://api.anthropic.com/v1/messages",
        data=data,
        headers={
            "Content-Type": "application/json",
            "x-api-key": api_key,
            "anthropic-version": "2023-06-01"
        }
    )

    try:
        with urllib.request.urlopen(req, timeout=60) as resp:
            result = j.loads(resp.read())
            return result["content"][0]["text"]
    except Exception as e:
        return f"API ERROR: {e}"

def call_openai(api_key, prompt, model="gpt-4o"):
    """Call OpenAI API."""
    import urllib.request
    import json as j

    data = j.dumps({
        "model": model,
        "messages": [
            {"role": "system", "content": SYSTEM_PROMPT},
            {"role": "user", "content": prompt}
        ],
        "max_tokens": 2048,
        "temperature": 0.2
    }).encode()

    req = urllib.request.Request(
        "https://api.openai.com/v1/chat/completions",
        data=data,
        headers={
            "Content-Type": "application/json",
            "Authorization": f"Bearer {api_key}"
        }
    )

    try:
        with urllib.request.urlopen(req, timeout=60) as resp:
            result = j.loads(resp.read())
            return result["choices"][0]["message"]["content"]
    except Exception as e:
        return f"API ERROR: {e}"

# ============================================================================
# Verification
# ============================================================================

def verify_match(cpp_path, addr, size):
    """Run verify_match.sh and return (matched: bool, output: str)."""
    try:
        result = subprocess.run(
            [BASH_EXE, VERIFY_SCRIPT, cpp_path, f"0x{addr:08X}", str(size)],
            capture_output=True, text=True, timeout=30
        )
        output = result.stdout.strip()
        matched = "MATCH!" in output
        return matched, output
    except Exception as e:
        return False, f"VERIFY ERROR: {e}"

# ============================================================================
# Main loop
# ============================================================================

def extract_cpp_from_response(response):
    """Extract C++ code from AI response (strip markdown fences etc)."""
    # Remove markdown code fences
    code = response.strip()
    if code.startswith("```"):
        lines = code.split("\n")
        # Find start and end of code block
        start = 1  # skip first ```
        if lines[0].startswith("```cpp") or lines[0].startswith("```c"):
            start = 1
        end = len(lines)
        for i in range(len(lines) - 1, 0, -1):
            if lines[i].strip() == "```":
                end = i
                break
        code = "\n".join(lines[start:end])
    return code

def attempt_match(dol, addr, size, name, api_func, max_retries=3):
    """Try to match a function using the AI API."""
    disasm = disassemble_function(dol, addr, size)
    if not disasm:
        return False, "Could not disassemble"

    prompt = f"""Decompile this PowerPC function to matching C++:

Function: {name}
{disasm}

Write C++ that compiles to these exact bytes with devkitPPC GCC (-mcpu=750 -O2).
Output ONLY the code, no explanations."""

    for attempt in range(max_retries):
        response = api_func(prompt)

        if "API ERROR" in response:
            print(f"    API error: {response}")
            time.sleep(2)
            continue

        cpp_code = extract_cpp_from_response(response)

        # Write to temp file
        safe_name = re.sub(r'[^a-zA-Z0-9_]', '_', name.split('(')[0])
        filename = f"{MATCHED_DIR}/agent/match_{addr:08X}_{safe_name}.cpp"
        os.makedirs(f"{MATCHED_DIR}/agent", exist_ok=True)

        with open(filename, "w") as f:
            f.write(cpp_code)

        # Verify
        matched, output = verify_match(filename, addr, size)

        if matched:
            return True, filename

        # If not matched, add diff feedback and retry
        if attempt < max_retries - 1:
            prompt = f"""Your previous attempt did NOT match. Here's the diff:

{output}

The function is:
{name}
{disasm}

Try again. The bytes must match EXACTLY. Adjust register usage, instruction order, or field access patterns.
Output ONLY the corrected C++ code."""

        # Clean up failed attempt
        if not matched and os.path.exists(filename):
            os.remove(filename)

    return False, "Max retries exceeded"

def main():
    parser = argparse.ArgumentParser(description="Automated decomp agent")
    parser.add_argument("--api", choices=["anthropic", "openai"], default="anthropic")
    parser.add_argument("--key", help="API key")
    parser.add_argument("--model", help="Model override")
    parser.add_argument("--count", type=int, default=20, help="Number of functions to attempt")
    parser.add_argument("--max-size", type=int, default=64, help="Max function size in bytes")
    parser.add_argument("--max-retries", type=int, default=3, help="Max retries per function")
    parser.add_argument("--dry-run", action="store_true", help="Show what would be attempted")
    parser.add_argument("--resume", action="store_true", help="Skip already matched functions")
    args = parser.parse_args()

    # Get unmatched functions
    unmatched = get_unmatched_functions(max_size=args.max_size)
    print(f"Unmatched functions (size <= {args.max_size}B): {len(unmatched)}")

    if args.dry_run:
        for addr, size, name in unmatched[:args.count]:
            print(f"  0x{addr:08X} ({size:3d}B) {name}")
        return

    if not args.key:
        # Check environment variable
        if args.api == "anthropic":
            args.key = os.environ.get("ANTHROPIC_API_KEY")
        else:
            args.key = os.environ.get("OPENAI_API_KEY")

    if not args.key:
        print(f"ERROR: No API key. Use --key or set {'ANTHROPIC_API_KEY' if args.api == 'anthropic' else 'OPENAI_API_KEY'}")
        sys.exit(1)

    # Set up API function
    if args.api == "anthropic":
        model = args.model or "claude-sonnet-4-20250514"
        api_func = lambda prompt: call_anthropic(args.key, prompt, model)
    else:
        model = args.model or "gpt-4o"
        api_func = lambda prompt: call_openai(args.key, prompt, model)

    print(f"API: {args.api} ({model})")
    print(f"Attempting {min(args.count, len(unmatched))} functions...")
    print()

    dol = read_dol()
    matched_count = 0
    failed_count = 0
    total_attempted = 0

    for addr, size, name in unmatched[:args.count]:
        total_attempted += 1
        print(f"[{total_attempted}/{args.count}] 0x{addr:08X} ({size}B) {name}")

        success, result = attempt_match(dol, addr, size, name, api_func, args.max_retries)

        if success:
            matched_count += 1
            print(f"  -> MATCHED! Saved to {result}")
        else:
            failed_count += 1
            print(f"  -> Failed: {result}")

        # Rate limiting
        time.sleep(0.5)

    print(f"\n{'='*50}")
    print(f"Results: {matched_count} matched, {failed_count} failed out of {total_attempted} attempted")
    print(f"Success rate: {matched_count*100/max(total_attempted,1):.1f}%")

    # Update progress
    already = len(get_already_matched())
    print(f"Total matched functions: {already}")
    print(f"Progress: {already} / 20508 ({already*100/20508:.1f}%)")

if __name__ == "__main__":
    main()
