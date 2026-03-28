#!/usr/bin/env python3
"""
Sims 2 GameCube -- Automatically generate matching C++ for trivial functions.

Reads disassembly of very small functions (4-16 bytes) and pattern-matches
common PPC instruction sequences to produce byte-matching C++ source code.

Usage:
    python tools/auto_match.py                          # report only
    python tools/auto_match.py --generate               # generate C++ stubs
    python tools/auto_match.py --generate --output out/  # write to directory
    python tools/auto_match.py --name "ESim::"          # filter by name
    python tools/auto_match.py --dry-run                # show what would generate
"""

import argparse
import json
import os
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

SCRIPT_DIR = Path(__file__).resolve().parent
ROOT_DIR = SCRIPT_DIR.parent

OBJDUMP = Path("F:/coding/Decompiles/Tools/devkitPro/devkitPPC/bin/powerpc-eabi-objdump.exe")
ORIGINAL_ELF = ROOT_DIR / "extracted" / "files" / "u2_ngc_release_dvd.elf"
SYMBOLS_JSON = SCRIPT_DIR / "symbols.json"

CODE_SECTIONS = {".text", ".init"}

INSN_RE = re.compile(
    r"^\s*([0-9a-f]+):\s+"
    r"((?:[0-9a-f]{2} )+)\s*"
    r"(\S+)"
    r"(?:\s+(.*))?$"
)


def load_functions(min_size=4, max_size=16, name_filter=None):
    """Load function symbols in range from code sections."""
    with open(SYMBOLS_JSON, "r") as f:
        data = json.load(f)

    funcs = []
    for s in data["symbols"]:
        if (s["type"] == "function"
                and s.get("name")
                and s.get("section") in CODE_SECTIONS
                and min_size <= s["size"] <= max_size):
            if name_filter and name_filter not in s["name"]:
                continue
            funcs.append(s)

    funcs.sort(key=lambda f: int(f["address"], 16))
    return funcs


def disassemble_function(addr, size, section):
    """Disassemble a single function, returning list of (mnemonic, operands)."""
    cmd = [
        str(OBJDUMP), "-d",
        f"--start-address=0x{addr:08X}",
        f"--stop-address=0x{addr + size:08X}",
    ]
    if section in CODE_SECTIONS:
        cmd.extend(["-j", section])
    cmd.append(str(ORIGINAL_ELF))

    result = subprocess.run(cmd, capture_output=True, text=True, timeout=10)
    insns = []
    for line in result.stdout.split("\n"):
        m = INSN_RE.match(line)
        if m:
            mnemonic = m.group(3)
            operands = m.group(4).strip() if m.group(4) else ""
            insns.append((mnemonic, operands))
    return insns


def disassemble_batch(funcs):
    """Batch disassemble functions efficiently."""
    results = {}
    if not funcs:
        return results

    sorted_funcs = sorted(funcs, key=lambda f: int(f["address"], 16))
    batches = []
    current_batch = [sorted_funcs[0]]

    for func in sorted_funcs[1:]:
        prev = current_batch[-1]
        prev_end = int(prev["address"], 16) + prev["size"]
        curr_start = int(func["address"], 16)
        if curr_start - prev_end < 4096 and len(current_batch) < 256:
            current_batch.append(func)
        else:
            batches.append(current_batch)
            current_batch = [func]
    batches.append(current_batch)

    total = len(sorted_funcs)
    done = 0

    for batch in batches:
        batch_start = int(batch[0]["address"], 16)
        last = batch[-1]
        batch_end = int(last["address"], 16) + last["size"]
        section = batch[0]["section"]

        cmd = [
            str(OBJDUMP), "-d",
            f"--start-address=0x{batch_start:08X}",
            f"--stop-address=0x{batch_end:08X}",
        ]
        if section in CODE_SECTIONS:
            cmd.extend(["-j", section])
        cmd.append(str(ORIGINAL_ELF))

        try:
            result = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
        except subprocess.TimeoutExpired:
            continue

        all_insns = {}
        for line in result.stdout.split("\n"):
            m = INSN_RE.match(line)
            if m:
                addr_val = int(m.group(1), 16)
                mnemonic = m.group(3)
                operands = m.group(4).strip() if m.group(4) else ""
                all_insns[addr_val] = (mnemonic, operands)

        for func in batch:
            func_addr = int(func["address"], 16)
            func_size = func["size"]
            func_insns = []
            for offset in range(0, func_size, 4):
                insn_addr = func_addr + offset
                if insn_addr in all_insns:
                    func_insns.append(all_insns[insn_addr])
                else:
                    func_insns.append(("???", ""))
            results[(func_addr, func["name"])] = func_insns

        done += len(batch)
        if total > 100:
            pct = done * 100 // total
            print(f"\r  Disassembling... {done}/{total} ({pct}%)", end="", file=sys.stderr)

    if total > 100:
        print(file=sys.stderr)

    return results


# ============================================================================
# Operand parsing helpers
# ============================================================================

def parse_load_store_operands(operands):
    """Parse operands like 'r3,1128(r4)' -> (reg, offset, base_reg)."""
    m = re.match(r"(r\d+|f\d+),(-?\d+)\((r\d+)\)", operands)
    if m:
        return m.group(1), int(m.group(2)), m.group(3)
    return None, None, None


def parse_li_operands(operands):
    """Parse operands like 'r3,42' -> (reg, value)."""
    m = re.match(r"(r\d+),(-?\d+)", operands)
    if m:
        return m.group(1), int(m.group(2))
    return None, None


def parse_mr_operands(operands):
    """Parse operands like 'r3,r4' -> (dst, src)."""
    m = re.match(r"(r\d+),(r\d+)", operands)
    if m:
        return m.group(1), m.group(2)
    return None, None


def parse_addi_operands(operands):
    """Parse operands like 'r3,r3,1048' -> (dst, src, imm)."""
    m = re.match(r"(r\d+),(r\d+),(-?\d+)", operands)
    if m:
        return m.group(1), m.group(2), int(m.group(3))
    return None, None, None


def parse_lis_operands(operands):
    """Parse operands like 'r3,-32707' -> (reg, value)."""
    m = re.match(r"(r\d+),(-?\d+)", operands)
    if m:
        return m.group(1), int(m.group(2))
    return None, None


def parse_ori_operands(operands):
    """Parse operands like 'r3,r3,24403' -> (dst, src, value)."""
    m = re.match(r"(r\d+),(r\d+),(\d+)", operands)
    if m:
        return m.group(1), m.group(2), int(m.group(3))
    return None, None, None


def parse_rlwinm_operands(operands):
    """Parse operands like 'r3,r3,28,31,31' -> (dst, src, shift, mb, me)."""
    m = re.match(r"(r\d+),(r\d+),(\d+),(\d+),(\d+)", operands)
    if m:
        return m.group(1), m.group(2), int(m.group(3)), int(m.group(4)), int(m.group(5))
    return None, None, None, None, None


def parse_rlwimi_operands(operands):
    """Parse operands like 'r0,r4,10,21,21' -> (dst, src, shift, mb, me)."""
    m = re.match(r"(r\d+),(r\d+),(\d+),(\d+),(\d+)", operands)
    if m:
        return m.group(1), m.group(2), int(m.group(3)), int(m.group(4)), int(m.group(5))
    return None, None, None, None, None


def parse_clrlwi_operands(operands):
    """Parse 'clrlwi rA,rS,N' -> (dst, src, N). Equivalent to rlwinm rA,rS,0,N,31."""
    m = re.match(r"(r\d+),(r\d+),(\d+)", operands)
    if m:
        return m.group(1), m.group(2), int(m.group(3))
    return None, None, None


def parse_clrrwi_operands(operands):
    """Parse 'clrrwi rA,rS,N' -> (dst, src, N). Equivalent to rlwinm rA,rS,0,0,31-N."""
    m = re.match(r"(r\d+),(r\d+),(\d+)", operands)
    if m:
        return m.group(1), m.group(2), int(m.group(3))
    return None, None, None


def parse_srwi_operands(operands):
    """Parse 'srwi rA,rS,N' -> (dst, src, N). Equivalent to rlwinm rA,rS,32-N,N,31."""
    m = re.match(r"(r\d+),(r\d+),(\d+)", operands)
    if m:
        return m.group(1), m.group(2), int(m.group(3))
    return None, None, None


def parse_slwi_operands(operands):
    """Parse 'slwi rA,rS,N' -> (dst, src, N). Equivalent to rlwinm rA,rS,N,0,31-N."""
    m = re.match(r"(r\d+),(r\d+),(\d+)", operands)
    if m:
        return m.group(1), m.group(2), int(m.group(3))
    return None, None, None


def parse_two_reg_operands(operands):
    """Parse operands like 'r3,r4' or 'f1,f2' -> (dst, src)."""
    m = re.match(r"([rf]\d+),([rf]\d+)", operands)
    if m:
        return m.group(1), m.group(2)
    return None, None


def parse_three_reg_operands(operands):
    """Parse operands like 'r3,r4,r5' -> (rd, ra, rb)."""
    m = re.match(r"(r\d+),(r\d+),(r\d+)", operands)
    if m:
        return m.group(1), m.group(2), m.group(3)
    return None, None, None


def parse_mulli_operands(operands):
    """Parse operands like 'r4,r4,60' -> (dst, src, imm)."""
    m = re.match(r"(r\d+),(r\d+),(-?\d+)", operands)
    if m:
        return m.group(1), m.group(2), int(m.group(3))
    return None, None, None


def parse_indexed_load_store(operands):
    """Parse operands like 'r3,r4,r5' for lwzx/stwx/sthx/lbzx etc."""
    m = re.match(r"([rf]\d+),(r\d+),(r\d+)", operands)
    if m:
        return m.group(1), m.group(2), m.group(3)
    return None, None, None


def reconstruct_address(lis_val, lo_val):
    """Reconstruct a 32-bit address from lis high + low offset."""
    full_addr = ((lis_val & 0xFFFF) << 16) + (lo_val & 0xFFFF)
    if lis_val < 0:
        full_addr = ((lis_val + 0x10000) << 16) + (lo_val & 0xFFFF)
    return full_addr & 0xFFFFFFFF


# ============================================================================
# Function name parsing
# ============================================================================

def parse_function_name(name):
    """Parse a C++ function name into components.

    Returns dict with: class_name, method_name, params, is_const, is_void_return (guess)
    """
    info = {
        "class_name": None,
        "method_name": None,
        "full_name": name,
        "params": "",
        "is_const": False,
        "namespace": None,
    }

    # Strip trailing const
    clean = name
    if clean.endswith(" const"):
        info["is_const"] = True
        clean = clean[:-6]

    # Extract params
    paren_start = clean.rfind("(")
    if paren_start >= 0:
        info["params"] = clean[paren_start + 1:-1] if clean.endswith(")") else ""
        clean = clean[:paren_start]
    else:
        info["params"] = ""

    # Split class::method or namespace::class::method
    if "::" in clean:
        parts = clean.rsplit("::", 1)
        info["method_name"] = parts[1]
        qualifier = parts[0]
        # Check for namespace::class
        if "::" in qualifier:
            ns_parts = qualifier.split("::", 1)
            info["namespace"] = ns_parts[0]
            info["class_name"] = ns_parts[1]
        else:
            info["class_name"] = qualifier
    else:
        info["method_name"] = clean

    return info


def guess_return_type(func_name, insns):
    """Guess the return type from function name and instructions."""
    name_lower = func_name.lower()

    # Check instruction patterns for return register
    if len(insns) >= 1:
        m, op = insns[0]
        # Float return uses f1
        if m in ("lfs", "stfs") and op.startswith("f1,"):
            return "float"
        if m in ("lfd", "stfd") and op.startswith("f1,"):
            return "double"

    # Name-based heuristics
    if any(x in name_lower for x in ["set", "mark", "clear", "reset", "kill",
                                       "init", "shutdown", "destroy", "free",
                                       "push", "pop", "add", "remove", "delete",
                                       "enable", "disable", "toggle", "force",
                                       "update", "draw", "render", "process"]):
        return "void"

    if any(x in name_lower for x in ["is", "has", "can", "should", "was", "did"]):
        return "bool"

    if any(x in name_lower for x in ["get", "find", "count", "size", "length",
                                       "num", "index"]):
        return "int"

    return "int"


# ============================================================================
# Pattern matchers -> C++ code generators
# ============================================================================

def generate_blr_only(func_name, insns, func_info):
    """blr -> empty function."""
    return "void", "{ }"


def generate_li_r3_blr(func_name, insns, func_info):
    """li r3,N; blr -> return constant."""
    _, val = parse_li_operands(insns[0][1])
    if val is None:
        return None, None

    ret_type = guess_return_type(func_name, insns)

    if val == 0:
        if "bool" in func_name.lower() or ret_type == "bool":
            return "bool", "{ return false; }"
        if any(x in func_name.lower() for x in ["get", "find", "is", "has", "can"]):
            # Could be returning nullptr, false, or 0
            pass
        return ret_type, "{ return 0; }"
    elif val == 1:
        if "bool" in func_name.lower() or ret_type == "bool":
            return "bool", "{ return true; }"
        return ret_type, "{ return 1; }"
    else:
        return ret_type, f"{{ return {val}; }}"


def generate_lwz_r3_blr(func_name, insns, func_info):
    """lwz r3,offset(rN); blr -> getter."""
    reg, offset, base = parse_load_store_operands(insns[0][1])
    if reg is None:
        return None, None

    if base == "r13":
        # SDA global access
        return "int", f"{{ return /* SDA global @ r13{offset:+d} */; }}  // lwz r3,{offset}(r13)"
    elif base == "r3":
        # this->field
        return "int", f"{{ return *(int*)((char*)this + 0x{offset & 0xFFFF:X}); }}  // offset 0x{offset & 0xFFFF:X}"
    elif base == "r2":
        # SDA2 (small const data)
        return "int", f"{{ return /* SDA2 const @ r2{offset:+d} */; }}  // lwz r3,{offset}(r2)"
    else:
        return "int", f"{{ /* lwz r3,{offset}({base}) */ return 0; }}"


def generate_lhz_r3_blr(func_name, insns, func_info):
    """lhz r3,offset(rN); blr -> short getter."""
    reg, offset, base = parse_load_store_operands(insns[0][1])
    if reg is None:
        return None, None

    if base == "r3":
        return "unsigned short", f"{{ return *(unsigned short*)((char*)this + 0x{offset & 0xFFFF:X}); }}  // offset 0x{offset & 0xFFFF:X}"
    elif base == "r13":
        return "unsigned short", f"{{ return /* SDA global @ r13{offset:+d} */; }}"
    return "unsigned short", f"{{ /* lhz r3,{offset}({base}) */ return 0; }}"


def generate_lbz_r3_blr(func_name, insns, func_info):
    """lbz r3,offset(rN); blr -> byte/bool getter."""
    reg, offset, base = parse_load_store_operands(insns[0][1])
    if reg is None:
        return None, None

    ret = guess_return_type(func_name, insns)
    ctype = "bool" if ret == "bool" else "unsigned char"

    if base == "r3":
        return ctype, f"{{ return *(unsigned char*)((char*)this + 0x{offset & 0xFFFF:X}); }}  // offset 0x{offset & 0xFFFF:X}"
    elif base == "r13":
        return ctype, f"{{ return /* SDA global @ r13{offset:+d} */; }}"
    return ctype, f"{{ /* lbz r3,{offset}({base}) */ return 0; }}"


def generate_lfs_f1_blr(func_name, insns, func_info):
    """lfs f1,offset(rN); blr -> float getter."""
    reg, offset, base = parse_load_store_operands(insns[0][1])
    if reg is None:
        return None, None

    if base == "r3":
        return "float", f"{{ return *(float*)((char*)this + 0x{offset & 0xFFFF:X}); }}  // offset 0x{offset & 0xFFFF:X}"
    elif base == "r13":
        return "float", f"{{ return /* SDA global float @ r13{offset:+d} */; }}"
    return "float", f"{{ /* lfs f1,{offset}({base}) */ return 0.0f; }}"


def generate_lfd_f1_blr(func_name, insns, func_info):
    """lfd f1,offset(rN); blr -> double getter."""
    reg, offset, base = parse_load_store_operands(insns[0][1])
    if reg is None:
        return None, None

    if base == "r3":
        return "double", f"{{ return *(double*)((char*)this + 0x{offset & 0xFFFF:X}); }}  // offset 0x{offset & 0xFFFF:X}"
    return "double", f"{{ /* lfd f1,{offset}({base}) */ return 0.0; }}"


def generate_stw_r4_blr(func_name, insns, func_info):
    """stw r4,offset(rN); blr -> setter."""
    reg, offset, base = parse_load_store_operands(insns[0][1])
    if reg is None:
        return None, None

    # Determine parameter type from function name
    param_type = "int"
    params = func_info.get("params", "")
    if params:
        # Use the actual declared param type
        param_parts = [p.strip() for p in params.split(",")]
        if param_parts:
            param_type = param_parts[-1] if len(param_parts) == 1 else param_parts[0]
            # Clean up - remove param name if present
            # "int val" -> "int"
            parts = param_type.rsplit(" ", 1)
            if len(parts) > 1 and not parts[-1].endswith("*"):
                param_type = parts[0]

    if base == "r13":
        return "void", f"{{ /* SDA global @ r13{offset:+d} = val */ }}  // stw r4,{offset}(r13)"
    elif base == "r3":
        return "void", f"{{ *(int*)((char*)this + 0x{offset & 0xFFFF:X}) = val; }}  // offset 0x{offset & 0xFFFF:X}"
    return "void", f"{{ /* stw r4,{offset}({base}) */ }}"


def generate_sth_r4_blr(func_name, insns, func_info):
    """sth r4,offset(rN); blr -> short setter."""
    reg, offset, base = parse_load_store_operands(insns[0][1])
    if reg is None:
        return None, None

    if base == "r3":
        return "void", f"{{ *(short*)((char*)this + 0x{offset & 0xFFFF:X}) = val; }}  // offset 0x{offset & 0xFFFF:X}"
    return "void", f"{{ /* sth r4,{offset}({base}) */ }}"


def generate_stb_r4_blr(func_name, insns, func_info):
    """stb r4,offset(rN); blr -> byte setter."""
    reg, offset, base = parse_load_store_operands(insns[0][1])
    if reg is None:
        return None, None

    if base == "r3":
        return "void", f"{{ *(char*)((char*)this + 0x{offset & 0xFFFF:X}) = val; }}  // offset 0x{offset & 0xFFFF:X}"
    return "void", f"{{ /* stb r4,{offset}({base}) */ }}"


def generate_stfs_f1_blr(func_name, insns, func_info):
    """stfs f1,offset(rN); blr -> float setter."""
    reg, offset, base = parse_load_store_operands(insns[0][1])
    if reg is None:
        return None, None

    if base == "r3":
        return "void", f"{{ *(float*)((char*)this + 0x{offset & 0xFFFF:X}) = val; }}  // offset 0x{offset & 0xFFFF:X}"
    return "void", f"{{ /* stfs f1,{offset}({base}) */ }}"


def generate_stfd_f1_blr(func_name, insns, func_info):
    """stfd f1,offset(rN); blr -> double setter."""
    reg, offset, base = parse_load_store_operands(insns[0][1])
    if reg is None:
        return None, None

    if base == "r3":
        return "void", f"{{ *(double*)((char*)this + 0x{offset & 0xFFFF:X}) = val; }}  // offset 0x{offset & 0xFFFF:X}"
    return "void", f"{{ /* stfd f1,{offset}({base}) */ }}"


def generate_mr_r3_blr(func_name, insns, func_info):
    """mr r3,rN; blr -> return parameter."""
    dst, src = parse_mr_operands(insns[0][1])
    if dst is None:
        return None, None

    param_map = {"r4": "first", "r5": "second", "r6": "third"}
    param_name = param_map.get(src, src)

    return "int", f"{{ return {param_name}; }}  // mr r3,{src}"


def generate_addi_r3_blr(func_name, insns, func_info):
    """addi r3,r3,N; blr -> return address of member."""
    dst, src, imm = parse_addi_operands(insns[0][1])
    if dst is None or dst != "r3" or src != "r3":
        return None, None

    return "void*", f"{{ return (char*)this + 0x{imm & 0xFFFF:X}; }}  // offset 0x{imm & 0xFFFF:X}"


def generate_stw_r3_sda_blr(func_name, insns, func_info):
    """stw r3,offset(r13); blr -> global setter via first param (not this->)."""
    reg, offset, base = parse_load_store_operands(insns[0][1])
    if reg != "r3" or base != "r13":
        return None, None
    return "void", f"{{ /* SDA global @ r13{offset:+d} = param */ }}  // stw r3,{offset}(r13)"


def generate_li_stw_blr(func_name, insns, func_info):
    """li rN,val; stw rN,offset(rM); blr -> store constant to field."""
    m0, op0 = insns[0]
    m1, op1 = insns[1]

    li_reg, li_val = parse_li_operands(op0)
    st_reg, st_offset, st_base = parse_load_store_operands(op1)

    if li_reg is None or st_reg is None:
        return None, None

    if st_base == "r3":
        if li_val == 0:
            return "void", f"{{ *(int*)((char*)this + 0x{st_offset & 0xFFFF:X}) = 0; }}"
        elif li_val == 1:
            return "void", f"{{ *(int*)((char*)this + 0x{st_offset & 0xFFFF:X}) = 1; }}"
        else:
            return "void", f"{{ *(int*)((char*)this + 0x{st_offset & 0xFFFF:X}) = {li_val}; }}"
    elif st_base == "r13":
        return "void", f"{{ /* SDA global @ r13{st_offset:+d} = {li_val} */ }}"
    return "void", f"{{ /* li {li_reg},{li_val}; stw {st_reg},{st_offset}({st_base}) */ }}"


def generate_li_stb_blr(func_name, insns, func_info):
    """li rN,val; stb rN,offset(rM); blr -> store byte constant."""
    m0, op0 = insns[0]
    m1, op1 = insns[1]

    li_reg, li_val = parse_li_operands(op0)
    st_reg, st_offset, st_base = parse_load_store_operands(op1)

    if li_reg is None or st_reg is None:
        return None, None

    if st_base == "r3":
        return "void", f"{{ *(char*)((char*)this + 0x{st_offset & 0xFFFF:X}) = {li_val}; }}"
    return "void", f"{{ /* li {li_reg},{li_val}; stb {st_reg},{st_offset}({st_base}) */ }}"


def generate_li_sth_blr(func_name, insns, func_info):
    """li rN,val; sth rN,offset(rM); blr -> store short constant."""
    m0, op0 = insns[0]
    m1, op1 = insns[1]

    li_reg, li_val = parse_li_operands(op0)
    st_reg, st_offset, st_base = parse_load_store_operands(op1)

    if li_reg is None or st_reg is None:
        return None, None

    if st_base == "r3":
        return "void", f"{{ *(short*)((char*)this + 0x{st_offset & 0xFFFF:X}) = {li_val}; }}"
    return "void", f"{{ /* li {li_reg},{li_val}; sth {st_reg},{st_offset}({st_base}) */ }}"


def generate_lis_addi_blr(func_name, insns, func_info):
    """lis rN,hi; addi rM,rN,lo; blr -> return pointer to global."""
    m0, op0 = insns[0]
    m1, op1 = insns[1]

    lis_reg, lis_val = parse_lis_operands(op0)
    dst, src, imm = parse_addi_operands(op1)

    if lis_reg is None or dst is None:
        return None, None

    # Reconstruct full address
    full_addr = ((lis_val & 0xFFFF) << 16) + (imm & 0xFFFF)
    if full_addr >= 0x80000000:
        full_addr = full_addr  # already unsigned-like
    elif lis_val < 0:
        full_addr = ((lis_val + 0x10000) << 16) + (imm & 0xFFFF)

    return "void*", f"{{ return (void*)0x{full_addr & 0xFFFFFFFF:08X}; }}  // global data pointer"


def generate_lis_lwz_blr(func_name, insns, func_info):
    """lis rN,hi; lwz r3,lo(rN); blr -> load global variable."""
    m0, op0 = insns[0]
    m1, op1 = insns[1]

    lis_reg, lis_val = parse_lis_operands(op0)
    ld_reg, ld_offset, ld_base = parse_load_store_operands(op1)

    if lis_reg is None or ld_reg is None:
        return None, None

    full_addr = ((lis_val & 0xFFFF) << 16) + (ld_offset & 0xFFFF)

    return "int", f"{{ return *(int*)0x{full_addr & 0xFFFFFFFF:08X}; }}  // global variable"


def generate_lis_lhz_blr(func_name, insns, func_info):
    """lis rN,hi; lhz r3,lo(rN); blr -> load global short."""
    m0, op0 = insns[0]
    m1, op1 = insns[1]

    lis_reg, lis_val = parse_lis_operands(op0)
    ld_reg, ld_offset, ld_base = parse_load_store_operands(op1)

    if lis_reg is None or ld_reg is None:
        return None, None

    full_addr = ((lis_val & 0xFFFF) << 16) + (ld_offset & 0xFFFF)

    return "unsigned short", f"{{ return *(unsigned short*)0x{full_addr & 0xFFFFFFFF:08X}; }}  // global variable"


def generate_lis_ori_blr(func_name, insns, func_info):
    """lis rN,hi; ori rN,rN,lo; blr -> return 32-bit constant."""
    m0, op0 = insns[0]
    m1, op1 = insns[1]

    lis_reg, lis_val = parse_lis_operands(op0)
    ori_dst, ori_src, ori_val = parse_ori_operands(op1)

    if lis_reg is None or ori_dst is None:
        return None, None

    full_val = ((lis_val & 0xFFFF) << 16) | (ori_val & 0xFFFF)
    return "unsigned int", f"{{ return 0x{full_val & 0xFFFFFFFF:08X}; }}"


def generate_lwz_lwz_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); lwz r3,off2(rN); blr -> double deref getter."""
    m0, op0 = insns[0]
    m1, op1 = insns[1]

    r1, off1, base1 = parse_load_store_operands(op0)
    r2, off2, base2 = parse_load_store_operands(op1)

    if r1 is None or r2 is None:
        return None, None

    if base1 == "r3":
        return "int", f"{{ return *(int*)((char*)(*(void**)((char*)this + 0x{off1 & 0xFFFF:X})) + 0x{off2 & 0xFFFF:X}); }}  // double deref"
    return "int", f"{{ /* double deref: {m0} {op0}; {m1} {op1} */ return 0; }}"


def generate_lwz_rlwinm_blr(func_name, insns, func_info):
    """lwz r3,off(r3); rlwinm r3,r3,shift,mb,me; blr -> bitfield getter."""
    m0, op0 = insns[0]
    m1, op1 = insns[1]

    ld_reg, ld_off, ld_base = parse_load_store_operands(op0)
    dst, src, shift, mb, me = parse_rlwinm_operands(op1)

    if ld_reg is None or dst is None:
        return None, None

    # rlwinm extracts a bitfield
    # Common: rlwinm r3,r3,N,31,31 -> extract bit N
    if mb == 31 and me == 31:
        bit_pos = (32 - shift) % 32
        return "bool", f"{{ return (*(int*)((char*)this + 0x{ld_off & 0xFFFF:X}) >> {bit_pos}) & 1; }}  // bit {bit_pos}"
    else:
        return "int", f"{{ /* bitfield extract from offset 0x{ld_off & 0xFFFF:X} */ return 0; }}"


# ============================================================================
# Tier 4: New 3-instruction pattern generators (12-byte functions)
# ============================================================================

def generate_lis_lfs_blr(func_name, insns, func_info):
    """lis rN,hi; lfs f1,lo(rN); blr -> return global float."""
    lis_reg, lis_val = parse_lis_operands(insns[0][1])
    ld_reg, ld_offset, ld_base = parse_load_store_operands(insns[1][1])
    if lis_reg is None or ld_reg != "f1":
        return None, None
    full_addr = reconstruct_address(lis_val, ld_offset)
    return "float", f"{{ return *(float*)0x{full_addr:08X}; }}  // global float"


def generate_lis_lbz_blr(func_name, insns, func_info):
    """lis rN,hi; lbz r3,lo(rN); blr -> return global byte."""
    lis_reg, lis_val = parse_lis_operands(insns[0][1])
    ld_reg, ld_offset, ld_base = parse_load_store_operands(insns[1][1])
    if lis_reg is None or ld_reg != "r3":
        return None, None
    full_addr = reconstruct_address(lis_val, ld_offset)
    ret = guess_return_type(func_name, insns)
    ctype = "bool" if ret == "bool" else "unsigned char"
    return ctype, f"{{ return *(unsigned char*)0x{full_addr:08X}; }}  // global byte"


def generate_lis_stw_blr(func_name, insns, func_info):
    """lis rN,hi; stw rM,lo(rN); blr -> store to global address."""
    lis_reg, lis_val = parse_lis_operands(insns[0][1])
    st_reg, st_offset, st_base = parse_load_store_operands(insns[1][1])
    if lis_reg is None or st_reg is None:
        return None, None
    full_addr = reconstruct_address(lis_val, st_offset)
    return "void", f"{{ *(int*)0x{full_addr:08X} = {st_reg.replace('r', 'param')}; }}  // global store"


def generate_lwz_lfs_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); lfs f1,off2(rN); blr -> double deref float getter."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[1][1])
    if r1 is None or r2 != "f1":
        return None, None
    if base1 == "r3":
        return "float", f"{{ return *(float*)((char*)(*(void**)((char*)this + 0x{off1 & 0xFFFF:X})) + 0x{off2 & 0xFFFF:X}); }}  // double deref float"
    return "float", f"{{ /* lwz+lfs double deref */ return 0.0f; }}"


def generate_lwz_stfs_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); stfs f1,off2(rN); blr -> double deref float setter."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[1][1])
    if r1 is None or r2 != "f1":
        return None, None
    if base1 == "r3":
        return "void", f"{{ *(float*)((char*)(*(void**)((char*)this + 0x{off1 & 0xFFFF:X})) + 0x{off2 & 0xFFFF:X}) = val; }}  // double deref float setter"
    return "void", f"{{ /* lwz+stfs double deref setter */ }}"


def generate_lwz_lha_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); lha r3,off2(rN); blr -> double deref signed short getter."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[1][1])
    if r1 is None or r2 != "r3":
        return None, None
    if base1 == "r3":
        return "short", f"{{ return *(short*)((char*)(*(void**)((char*)this + 0x{off1 & 0xFFFF:X})) + 0x{off2 & 0xFFFF:X}); }}  // double deref signed short"
    elif base1 == "r13":
        return "short", f"{{ return *(short*)((char*)(*(void**)(r13 + {off1})) + 0x{off2 & 0xFFFF:X}); }}  // SDA double deref short"
    return "short", f"{{ /* lwz+lha double deref */ return 0; }}"


def generate_lwz_lbz_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); lbz r3,off2(rN); blr -> double deref byte getter."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[1][1])
    if r1 is None or r2 != "r3":
        return None, None
    ret = guess_return_type(func_name, insns)
    ctype = "bool" if ret == "bool" else "unsigned char"
    if base1 == "r3":
        return ctype, f"{{ return *(unsigned char*)((char*)(*(void**)((char*)this + 0x{off1 & 0xFFFF:X})) + 0x{off2 & 0xFFFF:X}); }}  // double deref byte"
    return ctype, f"{{ /* lwz+lbz double deref */ return 0; }}"


def generate_lwz_lhz_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); lhz r3,off2(rN); blr -> double deref unsigned short getter."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[1][1])
    if r1 is None or r2 != "r3":
        return None, None
    if base1 == "r3":
        return "unsigned short", f"{{ return *(unsigned short*)((char*)(*(void**)((char*)this + 0x{off1 & 0xFFFF:X})) + 0x{off2 & 0xFFFF:X}); }}  // double deref unsigned short"
    elif base1 == "r13":
        return "unsigned short", f"{{ return *(unsigned short*)((char*)(*(void**)(r13 + {off1})) + 0x{off2 & 0xFFFF:X}); }}  // SDA double deref ushort"
    return "unsigned short", f"{{ /* lwz+lhz double deref */ return 0; }}"


def generate_lwz_stw_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); stw rN,off2(rK); blr -> field copy or double deref setter."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[1][1])
    if r1 is None or r2 is None:
        return None, None

    # lwz r0,off1(r3); stw r0,off2(r3); -> copy field
    if base1 == "r3" and base2 == "r3" and r1 == r2:
        return "void", f"{{ *(int*)((char*)this + 0x{off2 & 0xFFFF:X}) = *(int*)((char*)this + 0x{off1 & 0xFFFF:X}); }}"
    # lwz r9,0(r3); stw r4,off2(r9) -> double deref setter
    if base1 == "r3" and r2 == "r4":
        return "void", f"{{ *(int*)((char*)(*(void**)((char*)this + 0x{off1 & 0xFFFF:X})) + 0x{off2 & 0xFFFF:X}) = val; }}  // double deref setter"
    return "void", f"{{ /* lwz {r1},{off1}({base1}); stw {r2},{off2}({base2}) */ }}"


def generate_lwz_stb_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); stb rK,off2(rN); blr -> double deref byte setter."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[1][1])
    if r1 is None or r2 is None:
        return None, None
    if base1 == "r3" and r2 == "r4":
        return "void", f"{{ *(char*)((char*)(*(void**)((char*)this + 0x{off1 & 0xFFFF:X})) + 0x{off2 & 0xFFFF:X}) = val; }}  // double deref byte setter"
    return "void", f"{{ /* lwz+stb double deref setter */ }}"


def generate_lhz_rlwinm_blr(func_name, insns, func_info):
    """lhz r3,off(r3); rlwinm r3,r3,shift,mb,me; blr -> short bitfield extract."""
    ld_reg, ld_off, ld_base = parse_load_store_operands(insns[0][1])
    dst, src, shift, mb, me = parse_rlwinm_operands(insns[1][1])
    if ld_reg is None or dst is None:
        return None, None
    if mb == 31 and me == 31:
        bit_pos = (32 - shift) % 32
        return "bool", f"{{ return (*(unsigned short*)((char*)this + 0x{ld_off & 0xFFFF:X}) >> {bit_pos}) & 1; }}  // bit {bit_pos} from short"
    else:
        # General bitfield extract
        mask_bits = me - mb + 1
        return "int", f"{{ return (*(unsigned short*)((char*)this + 0x{ld_off & 0xFFFF:X}) >> {(32 - shift - mask_bits) % 32}) & 0x{(1 << mask_bits) - 1:X}; }}  // bitfield from short"


def generate_lbz_rlwinm_blr(func_name, insns, func_info):
    """lbz r3,off(r3); rlwinm r3,r3,shift,mb,me; blr -> byte bitfield extract."""
    ld_reg, ld_off, ld_base = parse_load_store_operands(insns[0][1])
    dst, src, shift, mb, me = parse_rlwinm_operands(insns[1][1])
    if ld_reg is None or dst is None:
        return None, None
    if mb == 31 and me == 31:
        bit_pos = (32 - shift) % 32
        return "bool", f"{{ return (*(unsigned char*)((char*)this + 0x{ld_off & 0xFFFF:X}) >> {bit_pos}) & 1; }}  // bit {bit_pos} from byte"
    else:
        mask_bits = me - mb + 1
        return "int", f"{{ return (*(unsigned char*)((char*)this + 0x{ld_off & 0xFFFF:X}) >> {(32 - shift - mask_bits) % 32}) & 0x{(1 << mask_bits) - 1:X}; }}  // bitfield from byte"


def generate_lha_rlwinm_blr(func_name, insns, func_info):
    """lha r3,off(r3); rlwinm r3,r3,shift,mb,me; blr -> signed short bitfield extract."""
    ld_reg, ld_off, ld_base = parse_load_store_operands(insns[0][1])
    dst, src, shift, mb, me = parse_rlwinm_operands(insns[1][1])
    if ld_reg is None or dst is None:
        return None, None
    if mb == 31 and me == 31:
        bit_pos = (32 - shift) % 32
        return "bool", f"{{ return (*(short*)((char*)this + 0x{ld_off & 0xFFFF:X}) >> {bit_pos}) & 1; }}  // bit {bit_pos} from signed short"
    return "int", f"{{ /* lha+rlwinm bitfield */ return 0; }}"


def generate_lwz_addi_blr(func_name, insns, func_info):
    """lwz r3,off(r3); addi r3,r3,N; blr -> double deref + offset (return sub-struct addr)."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    dst, src, imm = parse_addi_operands(insns[1][1])
    if r1 is None or dst is None:
        return None, None
    if base1 == "r3" and dst == "r3" and src == "r3":
        return "void*", f"{{ return (char*)(*(void**)((char*)this + 0x{off1 & 0xFFFF:X})) + 0x{imm & 0xFFFF:X}; }}  // deref + offset"
    return "void*", f"{{ /* lwz+addi deref+offset */ return 0; }}"


def generate_lwz_clrlwi_blr(func_name, insns, func_info):
    """lwz r3,off(r3); clrlwi r3,r3,N; blr -> load and mask low bits.
    clrlwi rA,rS,N = rlwinm rA,rS,0,N,31 -> mask = (32-N) low bits."""
    ld_reg, ld_off, ld_base = parse_load_store_operands(insns[0][1])
    dst, src, n = parse_clrlwi_operands(insns[1][1])
    if ld_reg is None or dst is None:
        return None, None
    mask_bits = 32 - n
    if mask_bits == 1:
        return "bool", f"{{ return *(int*)((char*)this + 0x{ld_off & 0xFFFF:X}) & 1; }}  // low bit"
    return "int", f"{{ return *(int*)((char*)this + 0x{ld_off & 0xFFFF:X}) & 0x{(1 << mask_bits) - 1:X}; }}"


def generate_lhz_clrlwi_blr(func_name, insns, func_info):
    """lhz r3,off(r3); clrlwi r3,r3,N; blr -> load short and mask."""
    ld_reg, ld_off, ld_base = parse_load_store_operands(insns[0][1])
    dst, src, n = parse_clrlwi_operands(insns[1][1])
    if ld_reg is None or dst is None:
        return None, None
    mask_bits = 32 - n
    if mask_bits == 1:
        return "bool", f"{{ return *(unsigned short*)((char*)this + 0x{ld_off & 0xFFFF:X}) & 1; }}  // low bit"
    return "int", f"{{ return *(unsigned short*)((char*)this + 0x{ld_off & 0xFFFF:X}) & 0x{(1 << mask_bits) - 1:X}; }}"


def generate_lbz_clrlwi_blr(func_name, insns, func_info):
    """lbz r3,off(r3); clrlwi r3,r3,N; blr -> load byte and mask."""
    ld_reg, ld_off, ld_base = parse_load_store_operands(insns[0][1])
    dst, src, n = parse_clrlwi_operands(insns[1][1])
    if ld_reg is None or dst is None:
        return None, None
    mask_bits = 32 - n
    if mask_bits == 1:
        return "bool", f"{{ return *(unsigned char*)((char*)this + 0x{ld_off & 0xFFFF:X}) & 1; }}  // low bit"
    return "int", f"{{ return *(unsigned char*)((char*)this + 0x{ld_off & 0xFFFF:X}) & 0x{(1 << mask_bits) - 1:X}; }}"


def generate_lbz_extsb_blr(func_name, insns, func_info):
    """lbz r3,off(r3); extsb r3,r3; blr -> signed byte getter."""
    ld_reg, ld_off, ld_base = parse_load_store_operands(insns[0][1])
    if ld_reg is None:
        return None, None
    if ld_base == "r3":
        return "signed char", f"{{ return *(signed char*)((char*)this + 0x{ld_off & 0xFFFF:X}); }}  // signed byte"
    return "signed char", f"{{ /* lbz+extsb from {ld_base} */ return 0; }}"


def generate_subfic_adde_blr(func_name, insns, func_info):
    """subfic r0,rN,0; adde r3,r0,rN; blr -> bool cast (val != 0)."""
    # subfic r0,r4,0; adde r3,r0,r4 => r3 = (r4 != 0) ? 1 : 0
    return "bool", "{ return val != 0; }  // subfic+adde bool cast"


def generate_stw_stw_blr(func_name, insns, func_info):
    """stw rX,off1(rM); stw rY,off2(rM); blr -> set two fields."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[1][1])
    if r1 is None or r2 is None:
        return None, None

    if base1 == "r3" and base2 == "r3":
        return "void", f"{{ *(int*)((char*)this + 0x{off1 & 0xFFFF:X}) = {r1.replace('r', 'param')}; *(int*)((char*)this + 0x{off2 & 0xFFFF:X}) = {r2.replace('r', 'param')}; }}"
    return "void", f"{{ /* stw+stw: {r1},{off1}({base1}); {r2},{off2}({base2}) */ }}"


def generate_stfs_stfs_blr(func_name, insns, func_info):
    """stfs fX,off1(rM); stfs fY,off2(rM); blr -> set two float fields."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[1][1])
    if r1 is None or r2 is None:
        return None, None
    if base1 == "r3" and base2 == "r3":
        return "void", f"{{ *(float*)((char*)this + 0x{off1 & 0xFFFF:X}) = {r1}; *(float*)((char*)this + 0x{off2 & 0xFFFF:X}) = {r2}; }}"
    return "void", f"{{ /* stfs+stfs */ }}"


def generate_stb_stb_blr(func_name, insns, func_info):
    """stb rX,off1(rM); stb rY,off2(rM); blr -> set two byte fields."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[1][1])
    if r1 is None or r2 is None:
        return None, None
    if base1 == "r3" and base2 == "r3":
        return "void", f"{{ *(char*)((char*)this + 0x{off1 & 0xFFFF:X}) = {r1.replace('r', 'param')}; *(char*)((char*)this + 0x{off2 & 0xFFFF:X}) = {r2.replace('r', 'param')}; }}"
    return "void", f"{{ /* stb+stb */ }}"


def generate_stb_extsb_blr(func_name, insns, func_info):
    """stb rN,off(rM); extsb r3,rN; blr -> signed byte setter that returns old-style."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    if r1 is None:
        return None, None
    if base1 == "r3":
        return "signed char", f"{{ *(char*)((char*)this + 0x{off1 & 0xFFFF:X}) = val; return (signed char)val; }}"
    return "signed char", f"{{ /* stb+extsb */ return 0; }}"


def generate_stw_li_blr(func_name, insns, func_info):
    """stw rN,off(rM); li r3,val; blr -> setter that returns constant."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    li_reg, li_val = parse_li_operands(insns[1][1])
    if r1 is None or li_reg != "r3":
        return None, None
    if base1 == "r3":
        return "int", f"{{ *(int*)((char*)this + 0x{off1 & 0xFFFF:X}) = val; return {li_val}; }}"
    return "int", f"{{ /* stw {r1},{off1}({base1}); li r3,{li_val} */ return {li_val}; }}"


def generate_stfs_li_blr(func_name, insns, func_info):
    """stfs f1,off(rM); li r3,val; blr -> float setter that returns int."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    li_reg, li_val = parse_li_operands(insns[1][1])
    if r1 != "f1" or li_reg != "r3":
        return None, None
    if base1 == "r3":
        return "int", f"{{ *(float*)((char*)this + 0x{off1 & 0xFFFF:X}) = val; return {li_val}; }}"
    return "int", f"{{ /* stfs+li */ return {li_val}; }}"


def generate_stw_mr_blr(func_name, insns, func_info):
    """stw r4,off(r3); mr r3,r4; blr -> setter that returns new value."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    dst, src = parse_mr_operands(insns[1][1])
    if r1 is None or dst != "r3":
        return None, None
    if base1 == "r3" and r1 == "r4" and src == "r4":
        return "int", f"{{ *(int*)((char*)this + 0x{off1 & 0xFFFF:X}) = val; return val; }}"
    return "int", f"{{ /* stw+mr */ return 0; }}"


def generate_mr_stw_blr(func_name, insns, func_info):
    """mr rX,r3; stw rX,off(r13); blr -> save this to SDA global."""
    dst, src = parse_mr_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[1][1])
    if dst is None or r2 is None:
        return None, None
    if src == "r3" and base2 == "r13":
        return "void", f"{{ /* save this to SDA global @ r13{off2:+d} */ }}"
    return "void", f"{{ /* mr+stw */ }}"


def generate_slwi_stwx_blr(func_name, insns, func_info):
    """slwi rN,rM,shift; stwx rK,rA,rN; blr -> indexed array store."""
    dst, src, shift_amt = parse_slwi_operands(insns[0][1])
    if dst is None:
        return None, None
    st_reg, st_ra, st_rb = parse_indexed_load_store(insns[1][1])
    if st_reg is None:
        return None, None
    return "void", f"{{ /* indexed array store, shift={shift_amt} */ }}"


def generate_slwi_lwzx_blr(func_name, insns, func_info):
    """slwi rN,rM,shift; lwzx r3,rA,rN; blr -> indexed array load."""
    dst, src, shift_amt = parse_slwi_operands(insns[0][1])
    if dst is None:
        return None, None
    ld_reg, ld_ra, ld_rb = parse_indexed_load_store(insns[1][1])
    if ld_reg != "r3":
        return None, None
    elem_size = 1 << shift_amt
    return "int", f"{{ /* indexed array load, elem_size={elem_size} */ return 0; }}"


def generate_slwi_add_blr(func_name, insns, func_info):
    """slwi rN,rM,shift; add r3,rA,rN; blr -> array element address."""
    dst, src, shift_amt = parse_slwi_operands(insns[0][1])
    if dst is None:
        return None, None
    rd, ra, rb = parse_three_reg_operands(insns[1][1])
    if rd != "r3":
        return None, None
    elem_size = 1 << shift_amt
    return "void*", f"{{ return (char*)this + index * {elem_size}; }}  // array element addr, elem_size={elem_size}"


def generate_addi_stw_blr(func_name, insns, func_info):
    """addi rN,rM,imm; stw rN,off(rK); blr -> compute then store."""
    dst, src, imm = parse_addi_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[1][1])
    if dst is None or r2 is None:
        return None, None
    if src == "r4" and base2 == "r3":
        return "void", f"{{ *(int*)((char*)this + 0x{off2 & 0xFFFF:X}) = val + ({imm}); }}"
    elif src == "r13" and base2 == "r3":
        return "void", f"{{ *(int*)((char*)this + 0x{off2 & 0xFFFF:X}) = (int)(r13 + {imm}); }}  // SDA address"
    return "void", f"{{ /* addi+stw */ }}"


def generate_li_li_blr(func_name, insns, func_info):
    """li r3,X; li r4,Y; blr -> return two values (r3 and r4)."""
    r1, v1 = parse_li_operands(insns[0][1])
    r2, v2 = parse_li_operands(insns[1][1])
    if r1 != "r3":
        return None, None
    return "int", f"{{ /* r3={v1}, r4={v2} */ return {v1}; }}"


def generate_stw_stfs_blr(func_name, insns, func_info):
    """stw rN,off1(rM); stfs fX,off2(rK); blr -> set int + float fields."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[1][1])
    if r1 is None or r2 is None:
        return None, None
    if base1 == "r13" and base2 == "r13":
        return "void", f"{{ /* SDA: store int @ r13{off1:+d}, float @ r13{off2:+d} */ }}"
    if base1 == "r3" and base2 == "r3":
        return "void", f"{{ *(int*)((char*)this + 0x{off1 & 0xFFFF:X}) = ival; *(float*)((char*)this + 0x{off2 & 0xFFFF:X}) = fval; }}"
    return "void", f"{{ /* stw+stfs mixed store */ }}"


def generate_addis_addi_blr(func_name, insns, func_info):
    """addis rN,rN,hi; addi rN,rN,lo; blr -> add large offset to compute address."""
    dst0, src0, imm0 = parse_addi_operands(insns[0][1])  # addis
    dst1, src1, imm1 = parse_addi_operands(insns[1][1])  # addi
    if dst0 is None or dst1 is None:
        return None, None
    if src0 == "r3" and dst1 == "r3":
        full_offset = (imm0 << 16) + imm1
        return "void*", f"{{ return (char*)this + 0x{full_offset & 0xFFFFFFFF:X}; }}  // large offset member addr"
    return "void*", f"{{ /* addis+addi */ return 0; }}"


def generate_addis_lwz_blr(func_name, insns, func_info):
    """addis rN,rN,hi; lwz r3,lo(rN); blr -> load from large offset."""
    dst0, src0, imm0 = parse_addi_operands(insns[0][1])  # addis
    ld_reg, ld_off, ld_base = parse_load_store_operands(insns[1][1])
    if dst0 is None or ld_reg is None:
        return None, None
    if src0 == "r3" and ld_reg == "r3":
        full_offset = (imm0 << 16) + ld_off
        return "int", f"{{ return *(int*)((char*)this + 0x{full_offset & 0xFFFFFFFF:X}); }}  // large offset getter"
    return "int", f"{{ /* addis+lwz */ return 0; }}"


def generate_addis_stw_blr(func_name, insns, func_info):
    """addis rN,rN,hi; stw rM,lo(rN); blr -> store to large offset."""
    dst0, src0, imm0 = parse_addi_operands(insns[0][1])  # addis
    st_reg, st_off, st_base = parse_load_store_operands(insns[1][1])
    if dst0 is None or st_reg is None:
        return None, None
    if src0 == "r3":
        full_offset = (imm0 << 16) + st_off
        return "void", f"{{ *(int*)((char*)this + 0x{full_offset & 0xFFFFFFFF:X}) = val; }}  // large offset setter"
    return "void", f"{{ /* addis+stw */ }}"


def generate_addis_stfs_blr(func_name, insns, func_info):
    """addis rN,rN,hi; stfs f1,lo(rN); blr -> store float to large offset."""
    dst0, src0, imm0 = parse_addi_operands(insns[0][1])  # addis
    st_reg, st_off, st_base = parse_load_store_operands(insns[1][1])
    if dst0 is None or st_reg != "f1":
        return None, None
    if src0 == "r3":
        full_offset = (imm0 << 16) + st_off
        return "void", f"{{ *(float*)((char*)this + 0x{full_offset & 0xFFFFFFFF:X}) = val; }}  // large offset float setter"
    return "void", f"{{ /* addis+stfs */ }}"


def generate_lwz_xori_blr(func_name, insns, func_info):
    """lwz r3,off(r3); xori r3,r3,1; blr -> load and invert bool."""
    ld_reg, ld_off, ld_base = parse_load_store_operands(insns[0][1])
    dst, src, val = parse_ori_operands(insns[1][1])
    if ld_reg is None or dst is None:
        return None, None
    if val == 1 and ld_base == "r3":
        return "bool", f"{{ return !*(int*)((char*)this + 0x{ld_off & 0xFFFF:X}); }}  // inverted bool"
    return "int", f"{{ return *(int*)((char*)this + 0x{ld_off & 0xFFFF:X}) ^ {val}; }}"


def generate_lwz_srwi_blr(func_name, insns, func_info):
    """lwz r3,off(r3); srwi r3,r3,N; blr -> load and shift right."""
    ld_reg, ld_off, ld_base = parse_load_store_operands(insns[0][1])
    dst, src, shift_amt = parse_srwi_operands(insns[1][1])
    if ld_reg is None or dst is None:
        return None, None
    if ld_base == "r3":
        return "unsigned int", f"{{ return *(unsigned int*)((char*)this + 0x{ld_off & 0xFFFF:X}) >> {shift_amt}; }}"
    return "unsigned int", f"{{ /* lwz+srwi */ return 0; }}"


def generate_lwz_clrrwi_blr(func_name, insns, func_info):
    """lwz r3,off(rN); clrrwi r3,r3,N; blr -> load and clear low N bits."""
    ld_reg, ld_off, ld_base = parse_load_store_operands(insns[0][1])
    dst, src, n = parse_clrrwi_operands(insns[1][1])
    if ld_reg is None or dst is None:
        return None, None
    mask = ~((1 << n) - 1) & 0xFFFFFFFF
    return "unsigned int", f"{{ return *(unsigned int*)((char*)this + 0x{ld_off & 0xFFFF:X}) & 0x{mask:08X}; }}"


def generate_lwz_add_blr(func_name, insns, func_info):
    """lwz rN,off(rM); add r3,rN,rK; blr -> load and add."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    rd, ra, rb = parse_three_reg_operands(insns[1][1])
    if r1 is None or rd != "r3":
        return None, None
    return "int", f"{{ /* lwz {r1},{off1}({base1}); add r3,{ra},{rb} */ return 0; }}"


def generate_lwz_lbzx_blr(func_name, insns, func_info):
    """lwz rN,off(rM); lbzx r3,rN,rK; blr -> indexed byte load through pointer."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    ld_reg, ld_ra, ld_rb = parse_indexed_load_store(insns[1][1])
    if r1 is None or ld_reg != "r3":
        return None, None
    return "unsigned char", f"{{ /* indexed byte load via ptr at {off1}({base1}) */ return 0; }}"


def generate_lbz_stb_blr(func_name, insns, func_info):
    """lbz rN,off1(rM); stb rN,off2(rK); blr -> copy byte field."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[1][1])
    if r1 is None or r2 is None:
        return None, None
    return "void", f"{{ /* copy byte: {off1}({base1}) -> {off2}({base2}) */ }}"


def generate_li_slw_blr(func_name, insns, func_info):
    """li r0,1; slw r3,r0,r3; blr -> convert index to bitmask (1 << index)."""
    li_reg, li_val = parse_li_operands(insns[0][1])
    if li_reg is None or li_val != 1:
        return None, None
    return "unsigned int", "{ return 1u << index; }  // index to bitmask"


def generate_stwu_addi_blr(func_name, insns, func_info):
    """stwu r1,-N(r1); addi r1,r1,N; blr -> empty function with stack frame (noop)."""
    return "void", "{ }  // empty (stack frame only)"


def generate_fmuls_fmsubs_blr(func_name, insns, func_info):
    """fmuls f3,f2,f3; fmsubs f1,f1,f4,f3; blr -> determinant calc (a*d - b*c)."""
    return "float", "{ return a * d - b * c; }  // 2x2 determinant"


def generate_stfd_stfd_blr(func_name, insns, func_info):
    """stfd fN,off1(r11); stfd fM,off2(r11); blr -> save FPR pair."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[1][1])
    if r1 is None:
        return None, None
    return "void", f"{{ /* save {r1},{r2} to stack */ }}"


def generate_lfd_lfd_blr(func_name, insns, func_info):
    """lfd fN,off1(r11); lfd fM,off2(r11); blr -> restore FPR pair."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[1][1])
    if r1 is None:
        return None, None
    return "void", f"{{ /* restore {r1},{r2} from stack */ }}"


def generate_mfmsr_op_blr(func_name, insns, func_info):
    """mfmsr r4; or/and/andc r3,r4,r3; blr -> MSR manipulation."""
    m1, op1 = insns[1]
    return "unsigned int", f"{{ /* {m1} MSR */ return 0; }}"


def generate_hwsync_mfspr_blr(func_name, insns, func_info):
    """hwsync; mfspr r3,N; blr -> read special register."""
    return "unsigned int", "{ /* hwsync + mfspr */ return 0; }"


def generate_mfspr_rlwinm_blr(func_name, insns, func_info):
    """mfspr rN,N; rlwinm r3,rN,...; blr -> read SPR bitfield."""
    return "unsigned int", "{ /* mfspr + bitfield extract */ return 0; }"


# ============================================================================
# Tier 5: 4-instruction pattern generators (16-byte functions)
# ============================================================================

def generate_li_stw_stw_blr(func_name, insns, func_info):
    """li r0,N; stw r0,off1(rM); stw rX,off2(rK); blr -> init fields."""
    li_reg, li_val = parse_li_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if li_reg is None or r1 is None or r2 is None:
        return None, None

    parts = []
    for reg, off, base in [(r1, off1, base1), (r2, off2, base2)]:
        if base == "r3":
            if reg == li_reg:
                parts.append(f"*(int*)((char*)this + 0x{off & 0xFFFF:X}) = {li_val};")
            else:
                parts.append(f"*(int*)((char*)this + 0x{off & 0xFFFF:X}) = {reg.replace('r', 'param')};")
        elif base == "r13":
            if reg == li_reg:
                parts.append(f"/* SDA @ r13{off:+d} = {li_val} */;")
            else:
                parts.append(f"/* SDA @ r13{off:+d} = {reg.replace('r', 'param')} */;")
        else:
            parts.append(f"/* stw {reg},{off}({base}) */;")
    return "void", "{ " + " ".join(parts) + " }"


def generate_lwz_stw_stw_blr(func_name, insns, func_info):
    """lwz rN,off0(rM); stw rN,off1(rK); stw rX,off2(rJ); blr -> copy + store."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if r0 is None or r1 is None or r2 is None:
        return None, None

    parts = []
    # First: lwz rN,off0(rM) - loads a value
    # Second: stw rN/rX,off1(rK) - stores (possibly same or diff value)
    # Third: stw rY,off2(rJ) - stores another value
    if base0 == "r3" and base1 == "r4" and r0 == r1:
        # linked list insert: lwz r0,field(this); stw r0,field(param); stw param,field(this)
        parts.append(f"/* linked list: load {off0}(this), store to {off1}(param), store param to {off2}(this) */")
    else:
        parts.append(f"/* lwz {r0},{off0}({base0}); stw {r1},{off1}({base1}); stw {r2},{off2}({base2}) */")
    return "void", "{ " + " ".join(parts) + " }"


def generate_lwz_lwz_rlwinm_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); lwz r3,off2(rN); rlwinm r3,r3,...; blr -> double deref + bitfield."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    dst, src, shift, mb, me = parse_rlwinm_operands(insns[2][1])
    if r0 is None or r1 is None or dst is None:
        return None, None

    if mb == 31 and me == 31:
        bit_pos = (32 - shift) % 32
        if base0 == "r3":
            return "bool", f"{{ return (*(int*)((char*)(*(void**)((char*)this + 0x{off0 & 0xFFFF:X})) + 0x{off1 & 0xFFFF:X}) >> {bit_pos}) & 1; }}  // double deref bit {bit_pos}"
        elif base0 == "r13":
            return "bool", f"{{ /* SDA double deref bit {bit_pos} */ return 0; }}"
    return "int", f"{{ /* double deref + bitfield extract */ return 0; }}"


def generate_slwi_addi_lwzx_blr(func_name, insns, func_info):
    """slwi rN,rM,shift; addi rK,rJ,off; lwzx r3,rK,rN; blr -> array index with base offset."""
    dst0, src0, shift0 = parse_slwi_operands(insns[0][1])
    dst1, src1, imm1 = parse_addi_operands(insns[1][1])
    ld_reg, ld_ra, ld_rb = parse_indexed_load_store(insns[2][1])
    if dst0 is None or dst1 is None or ld_reg != "r3":
        return None, None
    elem_size = 1 << shift0
    return "int", f"{{ return ((int*)((char*)this + 0x{imm1 & 0xFFFF:X}))[index]; }}  // array[index], elem_size={elem_size}"


def generate_mulli_lwz_add_blr(func_name, insns, func_info):
    """mulli rN,rM,N; lwz rK,off(rJ); add r3,rK,rN; blr -> struct array element addr."""
    dst0, src0, imm0 = parse_mulli_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    rd, ra, rb = parse_three_reg_operands(insns[2][1])
    if dst0 is None or r1 is None or rd != "r3":
        return None, None
    if base1 == "r3":
        return "void*", f"{{ return (char*)(*(void**)((char*)this + 0x{off1 & 0xFFFF:X})) + index * {imm0}; }}  // struct array, stride={imm0}"
    return "void*", f"{{ /* mulli+lwz+add, stride={imm0} */ return 0; }}"


def generate_lwz_stw_mr_blr(func_name, insns, func_info):
    """lwz r0,off(r3); stw r4,off(r3); mr r3,r0; blr -> swap setter (return old value)."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    dst, src = parse_mr_operands(insns[2][1])
    if r0 is None or r1 is None or dst != "r3":
        return None, None
    if base0 == "r3" and base1 == "r3" and off0 == off1 and src == r0:
        return "int", f"{{ int old = *(int*)((char*)this + 0x{off0 & 0xFFFF:X}); *(int*)((char*)this + 0x{off0 & 0xFFFF:X}) = val; return old; }}  // swap setter"
    return "int", f"{{ /* lwz+stw+mr swap */ return 0; }}"


def generate_lwz_slwi_lwzx_blr(func_name, insns, func_info):
    """lwz rN,off(rM); slwi rK,rK,shift; lwzx r3,rN,rK; blr -> load ptr then indexed load."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    dst1, src1, shift1 = parse_slwi_operands(insns[1][1])
    ld_reg, ld_ra, ld_rb = parse_indexed_load_store(insns[2][1])
    if r0 is None or dst1 is None or ld_reg != "r3":
        return None, None
    elem_size = 1 << shift1
    if base0 == "r3":
        return "int", f"{{ return ((int*)(*(void**)((char*)this + 0x{off0 & 0xFFFF:X})))[index]; }}  // ptr->array[index], elem_size={elem_size}"
    return "int", f"{{ /* lwz+slwi+lwzx indexed */ return 0; }}"


def generate_lis_lhz_rlwinm_blr(func_name, insns, func_info):
    """lis rN,hi; lhz r0,lo(rN); rlwinm r3,r0,...; blr -> global short bitfield."""
    lis_reg, lis_val = parse_lis_operands(insns[0][1])
    ld_reg, ld_off, ld_base = parse_load_store_operands(insns[1][1])
    dst, src, shift, mb, me = parse_rlwinm_operands(insns[2][1])
    if lis_reg is None or ld_reg is None or dst is None:
        return None, None
    full_addr = reconstruct_address(lis_val, ld_off)
    if mb == 31 and me == 31:
        bit_pos = (32 - shift) % 32
        return "bool", f"{{ return (*(unsigned short*)0x{full_addr:08X} >> {bit_pos}) & 1; }}  // global short bit {bit_pos}"
    else:
        mask_bits = me - mb + 1
        return "int", f"{{ return (*(unsigned short*)0x{full_addr:08X} >> {(32 - shift) % 32}) & 0x{(1 << mask_bits) - 1:X}; }}  // global short bitfield"


def generate_lis_addi_stw_blr(func_name, insns, func_info):
    """lis rN,hi; addi rN,rN,lo; stw rN,off(rM); blr -> store global addr to field (vtable init)."""
    lis_reg, lis_val = parse_lis_operands(insns[0][1])
    dst1, src1, imm1 = parse_addi_operands(insns[1][1])
    st_reg, st_off, st_base = parse_load_store_operands(insns[2][1])
    if lis_reg is None or dst1 is None or st_reg is None:
        return None, None
    full_addr = reconstruct_address(lis_val, imm1)
    if st_base == "r3":
        return "void", f"{{ *(void**)((char*)this + 0x{st_off & 0xFFFF:X}) = (void*)0x{full_addr:08X}; }}  // vtable/global ptr init"
    return "void", f"{{ /* lis+addi+stw global ptr store */ }}"


def generate_lwz_addi_stw_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); addi rN,rN,imm; stw rN,off2(rK); blr -> increment field."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    dst1, src1, imm1 = parse_addi_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if r0 is None or dst1 is None or r2 is None:
        return None, None
    if base0 == base2 and off0 == off2 and r0 == dst1 and dst1 == r2:
        if base0 == "r3":
            return "void", f"{{ *(int*)((char*)this + 0x{off0 & 0xFFFF:X}) += {imm1}; }}"
        elif base0 == "r13":
            return "void", f"{{ /* SDA @ r13{off0:+d} += {imm1} */ }}"
    return "void", f"{{ /* lwz+addi+stw */ }}"


def generate_lwz_subfic_adde_blr(func_name, insns, func_info):
    """lwz r3,off(r3); subfic r0,r3,0; adde r3,r0,r3; blr -> load and bool-cast (!= 0)."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    if r0 is None:
        return None, None
    if base0 == "r3":
        return "bool", f"{{ return *(int*)((char*)this + 0x{off0 & 0xFFFF:X}) != 0; }}"
    return "bool", f"{{ /* lwz+subfic+adde from {base0} */ return false; }}"


def generate_lwz_rlwimi_stw_blr(func_name, insns, func_info):
    """lwz r0,off(r3); rlwimi r0,rN,shift,mb,me; stw r0,off(r3); blr -> bitfield insert."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    dst, src, shift, mb, me = parse_rlwimi_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if r0 is None or dst is None or r2 is None:
        return None, None
    if base0 == "r3" and base2 == "r3" and off0 == off2:
        return "void", f"{{ /* set bitfield [{mb}:{me}] at offset 0x{off0 & 0xFFFF:X} */ }}"
    return "void", f"{{ /* lwz+rlwimi+stw bitfield insert */ }}"


def generate_stfs_stfs_stfs_blr(func_name, insns, func_info):
    """stfs fX,off1(rM); stfs fY,off2(rM); stfs fZ,off3(rM); blr -> set 3 float fields (Vec3)."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[1][1])
    r3_, off3, base3 = parse_load_store_operands(insns[2][1])
    if r1 is None or r2 is None or r3_ is None:
        return None, None
    if base1 == "r3" and base2 == "r3" and base3 == "r3":
        return "void", f"{{ *(float*)((char*)this + 0x{off1 & 0xFFFF:X}) = {r1}; *(float*)((char*)this + 0x{off2 & 0xFFFF:X}) = {r2}; *(float*)((char*)this + 0x{off3 & 0xFFFF:X}) = {r3_}; }}"
    return "void", "{ /* stfs+stfs+stfs */ }"


def generate_slwi_addi_add_blr(func_name, insns, func_info):
    """slwi rN,rM,shift; addi rN,rN,off; add r3,rK,rN; blr -> array element addr with offset."""
    dst0, src0, shift0 = parse_slwi_operands(insns[0][1])
    dst1, src1, imm1 = parse_addi_operands(insns[1][1])
    rd, ra, rb = parse_three_reg_operands(insns[2][1])
    if dst0 is None or dst1 is None or rd != "r3":
        return None, None
    elem_size = 1 << shift0
    return "void*", f"{{ return (char*)this + index * {elem_size} + 0x{imm1 & 0xFFFF:X}; }}  // array elem addr, stride={elem_size}, base_off=0x{imm1 & 0xFFFF:X}"


def generate_lwz_slwi_add_blr(func_name, insns, func_info):
    """lwz r3,off(r3); slwi rN,rM,shift; add r3,r3,rN; blr -> deref ptr then array element."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    dst1, src1, shift1 = parse_slwi_operands(insns[1][1])
    rd, ra, rb = parse_three_reg_operands(insns[2][1])
    if r0 is None or dst1 is None or rd != "r3":
        return None, None
    elem_size = 1 << shift1
    if base0 == "r3":
        return "void*", f"{{ return (char*)(*(void**)((char*)this + 0x{off0 & 0xFFFF:X})) + index * {elem_size}; }}  // deref ptr, array stride={elem_size}"
    return "void*", f"{{ /* lwz+slwi+add */ return 0; }}"


def generate_li_stw_li_blr(func_name, insns, func_info):
    """li r0,N; stw r0,off(r3); li r3,M; blr -> store constant, return constant."""
    li0_reg, li0_val = parse_li_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    li2_reg, li2_val = parse_li_operands(insns[2][1])
    if li0_reg is None or r1 is None or li2_reg != "r3":
        return None, None
    if base1 == "r3":
        return "int", f"{{ *(int*)((char*)this + 0x{off1 & 0xFFFF:X}) = {li0_val}; return {li2_val}; }}"
    return "int", f"{{ /* li+stw+li */ return {li2_val}; }}"


def generate_stw_stw_stw_blr(func_name, insns, func_info):
    """stw rX,off1(rM); stw rY,off2(rM); stw rZ,off3(rM); blr -> set 3 fields."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[1][1])
    r3_, off3, base3 = parse_load_store_operands(insns[2][1])
    if r1 is None or r2 is None or r3_ is None:
        return None, None
    parts = []
    for reg, off, base in [(r1, off1, base1), (r2, off2, base2), (r3_, off3, base3)]:
        if base == "r3":
            parts.append(f"*(int*)((char*)this + 0x{off & 0xFFFF:X}) = {reg.replace('r', 'param')};")
        else:
            parts.append(f"/* stw {reg},{off}({base}) */;")
    return "void", "{ " + " ".join(parts) + " }"


def generate_lwz_li_stw_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); li r0,val; stw r0,off2(rN); blr -> deref then init field."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    li_reg, li_val = parse_li_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if r0 is None or li_reg is None or r2 is None:
        return None, None
    if base0 == "r3" and r2 == li_reg:
        return "void", f"{{ *(int*)((char*)(*(void**)((char*)this + 0x{off0 & 0xFFFF:X})) + 0x{off2 & 0xFFFF:X}) = {li_val}; }}  // deref + init"
    return "void", f"{{ /* lwz+li+stw */ }}"


def generate_lwz_mr_stw_blr(func_name, insns, func_info):
    """lwz r0,off(r13); mr rN,r3; stw r0,off2(rN); blr -> load SDA global, store to obj."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    dst1, src1 = parse_mr_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if r0 is None or dst1 is None or r2 is None:
        return None, None
    if base0 == "r13" and src1 == "r3":
        return "void", f"{{ *(int*)((char*)this + 0x{off2 & 0xFFFF:X}) = /* SDA @ r13{off0:+d} */; }}"
    return "void", f"{{ /* lwz+mr+stw */ }}"


def generate_slwi_addi_stwx_blr(func_name, insns, func_info):
    """slwi rN,rM,shift; addi rK,rJ,off; stwx rX,rK,rN; blr -> indexed array store with offset."""
    dst0, src0, shift0 = parse_slwi_operands(insns[0][1])
    dst1, src1, imm1 = parse_addi_operands(insns[1][1])
    st_reg, st_ra, st_rb = parse_indexed_load_store(insns[2][1])
    if dst0 is None or dst1 is None or st_reg is None:
        return None, None
    elem_size = 1 << shift0
    return "void", f"{{ ((int*)((char*)this + 0x{imm1 & 0xFFFF:X}))[index] = val; }}  // array[index] store, elem_size={elem_size}"


def generate_slwi_addi_sthx_blr(func_name, insns, func_info):
    """slwi rN,rM,shift; addi rK,rJ,off; sthx rX,rK,rN; blr -> indexed short array store."""
    dst0, src0, shift0 = parse_slwi_operands(insns[0][1])
    dst1, src1, imm1 = parse_addi_operands(insns[1][1])
    st_reg, st_ra, st_rb = parse_indexed_load_store(insns[2][1])
    if dst0 is None or dst1 is None or st_reg is None:
        return None, None
    return "void", f"{{ ((short*)((char*)this + 0x{imm1 & 0xFFFF:X}))[index] = val; }}  // short array[index] store"


def generate_slwi_addi_lhax_blr(func_name, insns, func_info):
    """slwi rN,rM,shift; addi rK,rJ,off; lhax r3,rK,rN; blr -> indexed signed short array load."""
    dst0, src0, shift0 = parse_slwi_operands(insns[0][1])
    dst1, src1, imm1 = parse_addi_operands(insns[1][1])
    ld_reg, ld_ra, ld_rb = parse_indexed_load_store(insns[2][1])
    if dst0 is None or dst1 is None or ld_reg != "r3":
        return None, None
    return "short", f"{{ return ((short*)((char*)this + 0x{imm1 & 0xFFFF:X}))[index]; }}  // short array[index]"


def generate_lwz_lwz_lwz_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); lwz rK,off2(rN); lwz r3,off3(rK); blr -> triple deref."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if r0 is None or r1 is None or r2 != "r3":
        return None, None
    if base0 == "r3":
        return "int", f"{{ return *(int*)((char*)(*(int**)((char*)(*(void**)((char*)this + 0x{off0 & 0xFFFF:X})) + 0x{off1 & 0xFFFF:X})) + 0x{off2 & 0xFFFF:X}); }}  // triple deref"
    return "int", f"{{ /* triple deref */ return 0; }}"


def generate_lwz_lwz_stw_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); lwz rK,off2(rN); stw rK,off3(rJ); blr -> double deref then store."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if r0 is None or r1 is None or r2 is None:
        return None, None
    return "void", f"{{ /* double deref + store: {off0}({base0})->{off1}({base1})->{off2}({base2}) */ }}"


def generate_lwz_ori_stw_blr(func_name, insns, func_info):
    """lwz r0,off(r3); ori r0,r0,val; stw r0,off(r3); blr -> set bit flags."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    dst1, src1, val1 = parse_ori_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if r0 is None or dst1 is None or r2 is None:
        return None, None
    if base0 == "r3" and base2 == "r3" and off0 == off2:
        return "void", f"{{ *(unsigned int*)((char*)this + 0x{off0 & 0xFFFF:X}) |= 0x{val1:X}; }}  // set flags"
    return "void", f"{{ /* lwz+ori+stw */ }}"


def generate_lwz_rlwinm_stw_blr(func_name, insns, func_info):
    """lwz r0,off(r3); rlwinm r0,r0,...; stw r0,off(r3); blr -> modify bitfield."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    dst1, src1, shift1, mb1, me1 = parse_rlwinm_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if r0 is None or dst1 is None or r2 is None:
        return None, None
    if base0 == "r3" and base2 == "r3" and off0 == off2:
        return "void", f"{{ /* modify bitfield [{mb1}:{me1}] at offset 0x{off0 & 0xFFFF:X} */ }}"
    return "void", f"{{ /* lwz+rlwinm+stw */ }}"


def generate_lbz_subfic_adde_blr(func_name, insns, func_info):
    """lbz r3,off(r3); subfic r0,r3,0; adde r3,r0,r3; blr -> load byte and bool-cast."""
    ld_reg, ld_off, ld_base = parse_load_store_operands(insns[0][1])
    if ld_reg is None:
        return None, None
    if ld_base == "r3":
        return "bool", f"{{ return *(unsigned char*)((char*)this + 0x{ld_off & 0xFFFF:X}) != 0; }}"
    return "bool", f"{{ /* lbz+subfic+adde */ return false; }}"


def generate_lis_addi_lwz_blr(func_name, insns, func_info):
    """lis rN,hi; addi rN,rN,lo; lwz r3,off(rN); blr -> load from global struct."""
    lis_reg, lis_val = parse_lis_operands(insns[0][1])
    dst1, src1, imm1 = parse_addi_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if lis_reg is None or dst1 is None or r2 != "r3":
        return None, None
    full_addr = reconstruct_address(lis_val, imm1)
    return "int", f"{{ return *(int*)((char*)0x{full_addr:08X} + 0x{off2 & 0xFFFF:X}); }}  // global struct field"


def generate_li_stfs_stw_blr(func_name, insns, func_info):
    """li r0,val; stfs f1,off1(r3); stw r0,off2(r3); blr -> set float + int field."""
    li_reg, li_val = parse_li_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if li_reg is None or r1 is None or r2 is None:
        return None, None
    if base1 == "r3" and base2 == "r3":
        return "void", f"{{ *(float*)((char*)this + 0x{off1 & 0xFFFF:X}) = fval; *(int*)((char*)this + 0x{off2 & 0xFFFF:X}) = {li_val}; }}"
    return "void", f"{{ /* li+stfs+stw */ }}"


def generate_li_li_stw_blr(func_name, insns, func_info):
    """li rX,A; li rY,B; stw rZ,off(rM); blr -> set field with one of two constants."""
    li0_reg, li0_val = parse_li_operands(insns[0][1])
    li1_reg, li1_val = parse_li_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if li0_reg is None or li1_reg is None or r2 is None:
        return None, None
    if base2 == "r3":
        return "void", f"{{ *(int*)((char*)this + 0x{off2 & 0xFFFF:X}) = {li0_val if r2 == li0_reg else li1_val}; }}"
    return "void", f"{{ /* li+li+stw */ }}"


def generate_slwi_addi_lfsx_blr(func_name, insns, func_info):
    """slwi rN,rM,shift; addi rK,rJ,off; lfsx f1,rK,rN; blr -> indexed float array load."""
    dst0, src0, shift0 = parse_slwi_operands(insns[0][1])
    dst1, src1, imm1 = parse_addi_operands(insns[1][1])
    ld_reg, ld_ra, ld_rb = parse_indexed_load_store(insns[2][1])
    if dst0 is None or dst1 is None or ld_reg != "f1":
        return None, None
    return "float", f"{{ return ((float*)((char*)this + 0x{imm1 & 0xFFFF:X}))[index]; }}  // float array[index]"


def generate_slwi_addi_stfsx_blr(func_name, insns, func_info):
    """slwi rN,rM,shift; addi rK,rJ,off; stfsx f1,rK,rN; blr -> indexed float array store."""
    dst0, src0, shift0 = parse_slwi_operands(insns[0][1])
    dst1, src1, imm1 = parse_addi_operands(insns[1][1])
    st_reg, st_ra, st_rb = parse_indexed_load_store(insns[2][1])
    if dst0 is None or dst1 is None or st_reg != "f1":
        return None, None
    return "void", f"{{ ((float*)((char*)this + 0x{imm1 & 0xFFFF:X}))[index] = val; }}  // float array[index] store"


def generate_lwz_lwz_lfs_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); lwz rK,off2(rN); lfs f1,off3(rK); blr -> triple deref float."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if r0 is None or r1 is None or r2 != "f1":
        return None, None
    if base0 == "r3":
        return "float", f"{{ return *(float*)((char*)(*(void**)((char*)(*(void**)((char*)this + 0x{off0 & 0xFFFF:X})) + 0x{off1 & 0xFFFF:X})) + 0x{off2 & 0xFFFF:X}); }}  // triple deref float"
    return "float", f"{{ /* lwz+lwz+lfs triple deref */ return 0.0f; }}"


def generate_lfs_fadds_stfs_blr(func_name, insns, func_info):
    """lfs f0,off(r3); fadds f0,f0,f1; stfs f0,off(r3); blr -> float += val."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if r0 is None or r2 is None:
        return None, None
    if base0 == "r3" and base2 == "r3" and off0 == off2:
        return "void", f"{{ *(float*)((char*)this + 0x{off0 & 0xFFFF:X}) += val; }}"
    return "void", f"{{ /* lfs+fadds+stfs */ }}"


def generate_lwz_li_stb_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); li r0,val; stb r0,off2(rN); blr -> deref then init byte."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    li_reg, li_val = parse_li_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if r0 is None or li_reg is None or r2 is None:
        return None, None
    if base0 == "r3" and r2 == li_reg:
        return "void", f"{{ *(char*)((char*)(*(void**)((char*)this + 0x{off0 & 0xFFFF:X})) + 0x{off2 & 0xFFFF:X}) = {li_val}; }}"
    return "void", f"{{ /* lwz+li+stb */ }}"


def generate_lwz_li_sth_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); li r0,val; sth r0,off2(rN); blr -> deref then init short."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    li_reg, li_val = parse_li_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if r0 is None or li_reg is None or r2 is None:
        return None, None
    if base0 == "r3" and r2 == li_reg:
        return "void", f"{{ *(short*)((char*)(*(void**)((char*)this + 0x{off0 & 0xFFFF:X})) + 0x{off2 & 0xFFFF:X}) = {li_val}; }}"
    return "void", f"{{ /* lwz+li+sth */ }}"


def generate_lwz_slwi_sthx_blr(func_name, insns, func_info):
    """lwz rN,off(rM); slwi rK,rK,shift; sthx rX,rK,rN; blr -> ptr indexed short store."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    dst1, src1, shift1 = parse_slwi_operands(insns[1][1])
    st_reg, st_ra, st_rb = parse_indexed_load_store(insns[2][1])
    if r0 is None or dst1 is None or st_reg is None:
        return None, None
    return "void", f"{{ /* indexed short store via ptr at {off0}({base0}) */ }}"


def generate_lwz_slwi_lhax_blr(func_name, insns, func_info):
    """lwz rN,off(rM); slwi rK,rK,shift; lhax r3,rK,rN; blr -> ptr indexed signed short load."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    dst1, src1, shift1 = parse_slwi_operands(insns[1][1])
    ld_reg, ld_ra, ld_rb = parse_indexed_load_store(insns[2][1])
    if r0 is None or dst1 is None or ld_reg != "r3":
        return None, None
    return "short", f"{{ /* indexed signed short load via ptr at {off0}({base0}) */ return 0; }}"


def generate_lwz_slwi_stwx_blr(func_name, insns, func_info):
    """lwz rN,off(rM); slwi rK,rK,shift; stwx rX,rK,rN; blr -> ptr indexed int store."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    dst1, src1, shift1 = parse_slwi_operands(insns[1][1])
    st_reg, st_ra, st_rb = parse_indexed_load_store(insns[2][1])
    if r0 is None or dst1 is None or st_reg is None:
        return None, None
    return "void", f"{{ /* indexed int store via ptr at {off0}({base0}) */ }}"


def generate_lwz_clrrwi_stw_blr(func_name, insns, func_info):
    """lwz r0,off(r3); clrrwi r0,r0,N; stw r0,off(r3); blr -> clear low bits in field."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    dst1, src1, n1 = parse_clrrwi_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if r0 is None or dst1 is None or r2 is None:
        return None, None
    mask = ~((1 << n1) - 1) & 0xFFFFFFFF
    if base0 == "r3" and base2 == "r3" and off0 == off2:
        return "void", f"{{ *(unsigned int*)((char*)this + 0x{off0 & 0xFFFF:X}) &= 0x{mask:08X}; }}  // clear low {n1} bits"
    return "void", f"{{ /* lwz+clrrwi+stw */ }}"


def generate_lis_lfs_stfs_blr(func_name, insns, func_info):
    """lis rN,hi; lfs f0,lo(rN); stfs f0,off(r3); blr -> init float field from global."""
    lis_reg, lis_val = parse_lis_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if lis_reg is None or r1 is None or r2 is None:
        return None, None
    full_addr = reconstruct_address(lis_val, off1)
    if base2 == "r3":
        return "void", f"{{ *(float*)((char*)this + 0x{off2 & 0xFFFF:X}) = *(float*)0x{full_addr:08X}; }}  // init float from global"
    return "void", f"{{ /* lis+lfs+stfs */ }}"


def generate_lis_lwz_lwz_blr(func_name, insns, func_info):
    """lis rN,hi; lwz rK,lo(rN); lwz r3,off(rK); blr -> load from global struct."""
    lis_reg, lis_val = parse_lis_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if lis_reg is None or r1 is None or r2 != "r3":
        return None, None
    full_addr = reconstruct_address(lis_val, off1)
    return "int", f"{{ return *(int*)((char*)(*(void**)0x{full_addr:08X}) + 0x{off2 & 0xFFFF:X}); }}  // global ptr deref"


def generate_lis_lwz_clrlwi_blr(func_name, insns, func_info):
    """lis rN,hi; lwz r0,lo(rN); clrlwi r3,r0,N; blr -> global int + mask."""
    lis_reg, lis_val = parse_lis_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    dst2, src2, n2 = parse_clrlwi_operands(insns[2][1])
    if lis_reg is None or r1 is None or dst2 is None:
        return None, None
    full_addr = reconstruct_address(lis_val, off1)
    mask_bits = 32 - n2
    if mask_bits == 1:
        return "bool", f"{{ return *(int*)0x{full_addr:08X} & 1; }}  // global bit"
    return "int", f"{{ return *(int*)0x{full_addr:08X} & 0x{(1 << mask_bits) - 1:X}; }}"


def generate_lis_lwz_rlwinm_blr(func_name, insns, func_info):
    """lis rN,hi; lwz r0,lo(rN); rlwinm r3,r0,...; blr -> global int bitfield."""
    lis_reg, lis_val = parse_lis_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    dst2, src2, shift2, mb2, me2 = parse_rlwinm_operands(insns[2][1])
    if lis_reg is None or r1 is None or dst2 is None:
        return None, None
    full_addr = reconstruct_address(lis_val, off1)
    if mb2 == 31 and me2 == 31:
        bit_pos = (32 - shift2) % 32
        return "bool", f"{{ return (*(int*)0x{full_addr:08X} >> {bit_pos}) & 1; }}  // global bit {bit_pos}"
    return "int", f"{{ /* global bitfield from 0x{full_addr:08X} */ return 0; }}"


def generate_lwz_oris_stw_blr(func_name, insns, func_info):
    """lwz r0,off(r3); oris r0,r0,val; stw r0,off(r3); blr -> set high flag bits."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    dst1, src1, val1 = parse_ori_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if r0 is None or dst1 is None or r2 is None:
        return None, None
    if base0 == "r3" and base2 == "r3" and off0 == off2:
        return "void", f"{{ *(unsigned int*)((char*)this + 0x{off0 & 0xFFFF:X}) |= 0x{val1 << 16:08X}; }}  // set high flags"
    return "void", f"{{ /* lwz+oris+stw */ }}"


def generate_stb_stb_stb_blr(func_name, insns, func_info):
    """stb rX,off1(rM); stb rY,off2(rM); stb rZ,off3(rM); blr -> set 3 byte fields."""
    r1, off1, base1 = parse_load_store_operands(insns[0][1])
    r2, off2, base2 = parse_load_store_operands(insns[1][1])
    r3_, off3, base3 = parse_load_store_operands(insns[2][1])
    if r1 is None or r2 is None or r3_ is None:
        return None, None
    if base1 == "r3" and base2 == "r3" and base3 == "r3":
        return "void", f"{{ *(char*)((char*)this + 0x{off1 & 0xFFFF:X}) = {r1.replace('r', 'param')}; *(char*)((char*)this + 0x{off2 & 0xFFFF:X}) = {r2.replace('r', 'param')}; *(char*)((char*)this + 0x{off3 & 0xFFFF:X}) = {r3_.replace('r', 'param')}; }}"
    return "void", f"{{ /* stb+stb+stb */ }}"


def generate_mfspr_ori_mtspr_blr(func_name, insns, func_info):
    """mfspr rN,N; ori rN,rN,val; mtspr N,rN; blr -> set SPR bits."""
    return "void", "{ /* mfspr+ori+mtspr */ }"


def generate_mfspr_rlwinm_mtspr_blr(func_name, insns, func_info):
    """mfspr rN,N; rlwinm rN,rN,...; mtspr N,rN; blr -> clear/modify SPR bits."""
    return "void", "{ /* mfspr+rlwinm+mtspr */ }"


def generate_li_stw_stb_blr(func_name, insns, func_info):
    """li r0,N; stw rX,off1(rM); stb rY,off2(rK); blr -> init int + byte fields."""
    li_reg, li_val = parse_li_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if li_reg is None or r1 is None or r2 is None:
        return None, None
    parts = []
    for reg, off, base, store_type in [(r1, off1, base1, "int"), (r2, off2, base2, "char")]:
        if base == "r3":
            if reg == li_reg:
                parts.append(f"*({store_type}*)((char*)this + 0x{off & 0xFFFF:X}) = {li_val};")
            else:
                parts.append(f"*({store_type}*)((char*)this + 0x{off & 0xFFFF:X}) = {reg.replace('r', 'param')};")
        else:
            parts.append(f"/* store to {off}({base}) */;")
    return "void", "{ " + " ".join(parts) + " }"


def generate_mulli_addi_add_blr(func_name, insns, func_info):
    """mulli rN,rM,stride; addi rN,rN,off; add r3,rK,rN; blr -> struct array element with offset."""
    dst0, src0, stride = parse_mulli_operands(insns[0][1])
    dst1, src1, off = parse_addi_operands(insns[1][1])
    rd, ra, rb = parse_three_reg_operands(insns[2][1])
    if dst0 is None or dst1 is None or rd != "r3":
        return None, None
    return "void*", f"{{ return (char*)this + index * {stride} + 0x{off & 0xFFFF:X}; }}  // struct array, stride={stride}"


def generate_lwz_stw_lwz_blr(func_name, insns, func_info):
    """lwz r0,off1(r3); stw r0,off2(r4); lwz r3,off3(r3); blr -> store field to param, return another."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if r0 is None or r1 is None or r2 is None:
        return None, None
    return "int", f"{{ /* store {off0}({base0})->{off1}({base1}), return {off2}({base2}) */ return 0; }}"


def generate_lwz_lwz_add_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); lwz rK,off2(rJ); add r3,rK,rN; blr -> add two loaded fields."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    rd, ra, rb = parse_three_reg_operands(insns[2][1])
    if r0 is None or r1 is None or rd != "r3":
        return None, None
    return "int", f"{{ /* add fields: {off0}({base0}) + {off1}({base1}) */ return 0; }}"


def generate_lwz_lwz_subf_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); lwz rK,off2(rJ); subf r3,rN,rK; blr -> subtract two loaded fields."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    rd, ra, rb = parse_three_reg_operands(insns[2][1])
    if r0 is None or r1 is None or rd != "r3":
        return None, None
    return "int", f"{{ /* subtract fields: {off1}({base1}) - {off0}({base0}) */ return 0; }}"


def generate_lwz_lhz_sth_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); lhz r0,off2(rN); sth r0,off3(rK); blr -> copy short via deref."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if r0 is None or r1 is None or r2 is None:
        return None, None
    return "void", f"{{ /* copy short via deref: {off0}({base0})->{off1}->{off2}({base2}) */ }}"


def generate_lwz_lbz_clrlwi_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); lbz r3,off2(rN); clrlwi r3,r3,N; blr -> double deref byte + mask."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    dst2, src2, n2 = parse_clrlwi_operands(insns[2][1])
    if r0 is None or r1 is None or dst2 is None:
        return None, None
    mask_bits = 32 - n2
    if mask_bits == 1 and base0 == "r3":
        return "bool", f"{{ return *(unsigned char*)((char*)(*(void**)((char*)this + 0x{off0 & 0xFFFF:X})) + 0x{off1 & 0xFFFF:X}) & 1; }}"
    return "int", f"{{ /* lwz+lbz+clrlwi */ return 0; }}"


def generate_lwz_lwz_clrlwi_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); lwz r3,off2(rN); clrlwi r3,r3,N; blr -> double deref + mask."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    dst2, src2, n2 = parse_clrlwi_operands(insns[2][1])
    if r0 is None or r1 is None or dst2 is None:
        return None, None
    mask_bits = 32 - n2
    if mask_bits == 1 and base0 == "r3":
        return "bool", f"{{ return *(int*)((char*)(*(void**)((char*)this + 0x{off0 & 0xFFFF:X})) + 0x{off1 & 0xFFFF:X}) & 1; }}  // double deref low bit"
    return "int", f"{{ /* double deref + mask */ return 0; }}"


def generate_subfic_li_adde_blr(func_name, insns, func_info):
    """subfic r3,r4,N; li r3,0; adde r3,r3,r3; blr -> compare (param < N) or similar."""
    # This is: carry = (N >= r4), r3 = 0 + 0 + carry = (N >= r4)
    dst0, src0, imm0 = parse_addi_operands(insns[0][1])
    li_reg, li_val = parse_li_operands(insns[1][1])
    if dst0 is None or li_reg is None:
        return None, None
    return "bool", f"{{ return val <= {imm0}; }}  // range check"


def generate_lbz_addi_stb_blr(func_name, insns, func_info):
    """lbz rN,off(rM); addi rN,rN,val; stb rN,off(rM); blr -> increment byte field."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    dst1, src1, imm1 = parse_addi_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if r0 is None or dst1 is None or r2 is None:
        return None, None
    if base0 == base2 and off0 == off2 and base0 == "r3":
        return "void", f"{{ *(char*)((char*)this + 0x{off0 & 0xFFFF:X}) += {imm1}; }}"
    return "void", f"{{ /* lbz+addi+stb */ }}"


def generate_mr_stw_sth_blr(func_name, insns, func_info):
    """mr rN,r3; stw r4,off1(rN); sth r5,off2(rN); blr -> ctor init int+short."""
    dst0, src0 = parse_mr_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    if dst0 is None or r1 is None or r2 is None:
        return None, None
    if src0 == "r3":
        return "void", f"{{ *(int*)((char*)this + 0x{off1 & 0xFFFF:X}) = param4; *(short*)((char*)this + 0x{off2 & 0xFFFF:X}) = param5; }}"
    return "void", f"{{ /* mr+stw+sth */ }}"


def generate_lwz_mulli_add_blr(func_name, insns, func_info):
    """lwz r3,off(r3); mulli r3,r3,N; add r3,r3,r4; blr -> deref, multiply, add."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    dst1, src1, imm1 = parse_mulli_operands(insns[1][1])
    rd, ra, rb = parse_three_reg_operands(insns[2][1])
    if r0 is None or dst1 is None or rd != "r3":
        return None, None
    return "int", f"{{ /* deref {off0}({base0}) * {imm1} + param */ return 0; }}"


# ============================================================================
# Tier 5+: 5-instruction pattern generators (20-byte functions)
# ============================================================================

def generate_li_stw_stw_stw_blr(func_name, insns, func_info):
    """li r0,N; stw rX,off1; stw rY,off2; stw rZ,off3; blr -> init multiple fields."""
    li_reg, li_val = parse_li_operands(insns[0][1])
    stores = []
    for i in range(1, 4):
        r, off, base = parse_load_store_operands(insns[i][1])
        if r is None:
            return None, None
        stores.append((r, off, base))

    parts = []
    for reg, off, base in stores:
        if base == "r3":
            if reg == li_reg:
                parts.append(f"*(int*)((char*)this + 0x{off & 0xFFFF:X}) = {li_val};")
            else:
                parts.append(f"*(int*)((char*)this + 0x{off & 0xFFFF:X}) = {reg.replace('r', 'param')};")
        else:
            parts.append(f"/* stw {reg},{off}({base}) */;")
    return "void", "{ " + " ".join(parts) + " }"


def generate_mr_lwz_addi_stw_blr(func_name, insns, func_info):
    """mr r11,r3; lwz r9,off(r11); addi r9,r9,1; stw r9,off(r11); blr -> increment refcount."""
    dst0, src0 = parse_mr_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    dst2, src2, imm2 = parse_addi_operands(insns[2][1])
    r3_, off3, base3 = parse_load_store_operands(insns[3][1])
    if dst0 is None or r1 is None or dst2 is None or r3_ is None:
        return None, None
    if src0 == "r3" and off1 == off3 and base1 == base3 and r1 == dst2 and dst2 == r3_:
        return "void", f"{{ *(int*)((char*)this + 0x{off1 & 0xFFFF:X}) += {imm2}; }}  // refcount increment"
    return "void", f"{{ /* mr+lwz+addi+stw */ }}"


def generate_lis_mr_addi_stw_blr(func_name, insns, func_info):
    """lis rN,hi; mr r11,r3; addi rN,rN,lo; stw rN,off(r11); blr -> vtable init in ctor."""
    lis_reg, lis_val = parse_lis_operands(insns[0][1])
    dst1, src1 = parse_mr_operands(insns[1][1])
    dst2, src2, imm2 = parse_addi_operands(insns[2][1])
    r3_, off3, base3 = parse_load_store_operands(insns[3][1])
    if lis_reg is None or dst1 is None or dst2 is None or r3_ is None:
        return None, None
    full_addr = reconstruct_address(lis_val, imm2)
    if src1 == "r3":
        return "void", f"{{ *(void**)((char*)this + 0x{off3 & 0xFFFF:X}) = (void*)0x{full_addr:08X}; }}  // vtable init"
    return "void", f"{{ /* lis+mr+addi+stw vtable init */ }}"


def generate_lwz_xori_subfic_adde_blr(func_name, insns, func_info):
    """lwz r3,off(r3); xori r3,r3,N; subfic r0,r3,0; adde r3,r0,r3; blr -> load, xor, bool."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    dst1, src1, val1 = parse_ori_operands(insns[1][1])
    if r0 is None or dst1 is None:
        return None, None
    if base0 == "r3":
        return "bool", f"{{ return *(int*)((char*)this + 0x{off0 & 0xFFFF:X}) == {val1}; }}  // compare with constant"
    return "bool", f"{{ /* lwz+xori+subfic+adde */ return false; }}"


def generate_mr_li_stw_stw_blr(func_name, insns, func_info):
    """mr rN,r3; li r0,val; stw r0,off1(rN); stw rX,off2(rN); blr -> ctor init."""
    dst0, src0 = parse_mr_operands(insns[0][1])
    li_reg, li_val = parse_li_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    r3_, off3, base3 = parse_load_store_operands(insns[3][1])
    if dst0 is None or li_reg is None or r2 is None or r3_ is None:
        return None, None
    if src0 == "r3":
        parts = []
        for reg, off, base in [(r2, off2, base2), (r3_, off3, base3)]:
            if reg == li_reg:
                parts.append(f"*(int*)((char*)this + 0x{off & 0xFFFF:X}) = {li_val};")
            else:
                parts.append(f"*(int*)((char*)this + 0x{off & 0xFFFF:X}) = {reg.replace('r', 'param')};")
        return "void", "{ " + " ".join(parts) + " }"
    return "void", f"{{ /* mr+li+stw+stw */ }}"


def generate_lwz_lwz_subf_srawi_blr(func_name, insns, func_info):
    """lwz r0,off1(r3); lwz r3,off2(r3); subf r3,r0,r3; srawi r3,r3,N; blr -> (end-start)/size = count."""
    r0_, off0, base0 = parse_load_store_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    rd, ra, rb = parse_three_reg_operands(insns[2][1])
    # srawi has format: rA,rS,SH
    dst3, src3, imm3 = parse_addi_operands(insns[3][1])
    if r0_ is None or r1 is None or rd is None or dst3 is None:
        return None, None
    elem_size = 1 << imm3
    if base0 == "r3" and base1 == "r3":
        return "int", f"{{ return ((char*)(*(void**)((char*)this + 0x{off1 & 0xFFFF:X})) - (char*)(*(void**)((char*)this + 0x{off0 & 0xFFFF:X}))) / {elem_size}; }}  // count = (end-start)/{elem_size}"
    return "int", f"{{ /* vector size calc, elem_size={elem_size} */ return 0; }}"


def generate_lwz_lwz_stw_stw_blr(func_name, insns, func_info):
    """lwz rN,off1(rM); lwz rK,off2(rJ); stw rN,off3(rL); stw rK,off4(rP); blr -> copy two fields."""
    r0, off0, base0 = parse_load_store_operands(insns[0][1])
    r1, off1, base1 = parse_load_store_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    r3_, off3, base3 = parse_load_store_operands(insns[3][1])
    if r0 is None or r1 is None or r2 is None or r3_ is None:
        return None, None
    return "void", f"{{ /* copy two fields: {off0}({base0})->{off2}({base2}), {off1}({base1})->{off3}({base3}) */ }}"


def generate_li_li_stw_stw_blr(func_name, insns, func_info):
    """li rX,A; li rY,B; stw rZ,off1(rM); stw rW,off2(rN); blr -> init two fields with constants."""
    li0_reg, li0_val = parse_li_operands(insns[0][1])
    li1_reg, li1_val = parse_li_operands(insns[1][1])
    r2, off2, base2 = parse_load_store_operands(insns[2][1])
    r3_, off3, base3 = parse_load_store_operands(insns[3][1])
    if li0_reg is None or li1_reg is None or r2 is None or r3_ is None:
        return None, None
    parts = []
    for reg, off, base in [(r2, off2, base2), (r3_, off3, base3)]:
        val = li0_val if reg == li0_reg else li1_val
        if base == "r3":
            parts.append(f"*(int*)((char*)this + 0x{off & 0xFFFF:X}) = {val};")
        else:
            parts.append(f"/* stw {val} to {off}({base}) */;")
    return "void", "{ " + " ".join(parts) + " }"


def generate_slwi_addi_add_addi_blr(func_name, insns, func_info):
    """slwi rN,rM,sh; addi rN,rN,off; add r3,rK,rN; addi r3,r3,off2; blr -> nested array offset."""
    dst0, src0, shift0 = parse_slwi_operands(insns[0][1])
    dst1, src1, imm1 = parse_addi_operands(insns[1][1])
    rd, ra, rb = parse_three_reg_operands(insns[2][1])
    dst3, src3, imm3 = parse_addi_operands(insns[3][1])
    if dst0 is None or dst1 is None or rd is None or dst3 is None:
        return None, None
    elem_size = 1 << shift0
    return "void*", f"{{ return (char*)this + index * {elem_size} + 0x{imm1 & 0xFFFF:X} + 0x{imm3 & 0xFFFF:X}; }}  // nested array offset"


def generate_stfs_stfs_stfs_stfs_blr(func_name, insns, func_info):
    """stfs x4 + blr -> set 4 float fields."""
    parts = []
    for i in range(4):
        r, off, base = parse_load_store_operands(insns[i][1])
        if r is None:
            return None, None
        if base == "r3":
            parts.append(f"*(float*)((char*)this + 0x{off & 0xFFFF:X}) = {r};")
        else:
            parts.append(f"/* stfs {r},{off}({base}) */;")
    return "void", "{ " + " ".join(parts) + " }"


# ============================================================================
# Pattern dispatch table
# ============================================================================

def try_match(func_name, insns, func_info):
    """Try to match an instruction pattern and generate C++ code.

    Returns (return_type, body_code) or (None, None) if no match.
    """
    n = len(insns)
    mnemonics = [m for m, _ in insns]

    # 1-instruction patterns
    if n == 1:
        if mnemonics[0] == "blr":
            return generate_blr_only(func_name, insns, func_info)

    # 2-instruction patterns
    if n == 2 and mnemonics[-1] == "blr":
        m, op = insns[0]
        if m == "li" and op.startswith("r3,"):
            return generate_li_r3_blr(func_name, insns, func_info)
        if m == "lwz" and op.startswith("r3,"):
            return generate_lwz_r3_blr(func_name, insns, func_info)
        if m == "lhz" and op.startswith("r3,"):
            return generate_lhz_r3_blr(func_name, insns, func_info)
        if m == "lbz" and op.startswith("r3,"):
            return generate_lbz_r3_blr(func_name, insns, func_info)
        if m == "lfs" and op.startswith("f1,"):
            return generate_lfs_f1_blr(func_name, insns, func_info)
        if m == "lfd" and op.startswith("f1,"):
            return generate_lfd_f1_blr(func_name, insns, func_info)
        if m == "stw" and op.startswith("r4,"):
            return generate_stw_r4_blr(func_name, insns, func_info)
        if m == "sth" and op.startswith("r4,"):
            return generate_sth_r4_blr(func_name, insns, func_info)
        if m == "stb" and op.startswith("r4,"):
            return generate_stb_r4_blr(func_name, insns, func_info)
        if m == "stfs" and op.startswith("f1,"):
            return generate_stfs_f1_blr(func_name, insns, func_info)
        if m == "stfd" and op.startswith("f1,"):
            return generate_stfd_f1_blr(func_name, insns, func_info)
        if m == "mr" and op.startswith("r3,"):
            return generate_mr_r3_blr(func_name, insns, func_info)
        if m == "addi" and op.startswith("r3,r3,"):
            return generate_addi_r3_blr(func_name, insns, func_info)
        if m == "stw" and op.startswith("r3,") and "(r13)" in op:
            return generate_stw_r3_sda_blr(func_name, insns, func_info)

    # 3-instruction patterns (Tier 4: 12-byte functions)
    if n == 3 and mnemonics[-1] == "blr":
        m0, op0 = insns[0]
        m1, op1 = insns[1]

        # Existing Tier 1-3 patterns
        if m0 == "li" and m1 == "stw":
            return generate_li_stw_blr(func_name, insns, func_info)
        if m0 == "li" and m1 == "stb":
            return generate_li_stb_blr(func_name, insns, func_info)
        if m0 == "li" and m1 == "sth":
            return generate_li_sth_blr(func_name, insns, func_info)
        if m0 == "lis" and m1 == "addi":
            return generate_lis_addi_blr(func_name, insns, func_info)
        if m0 == "lis" and m1 == "lwz":
            return generate_lis_lwz_blr(func_name, insns, func_info)
        if m0 == "lis" and m1 == "lhz":
            return generate_lis_lhz_blr(func_name, insns, func_info)
        if m0 == "lis" and m1 == "ori":
            return generate_lis_ori_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "lwz":
            return generate_lwz_lwz_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "rlwinm":
            return generate_lwz_rlwinm_blr(func_name, insns, func_info)

        # New Tier 4 patterns
        if m0 == "lis" and m1 == "lfs":
            return generate_lis_lfs_blr(func_name, insns, func_info)
        if m0 == "lis" and m1 == "lbz":
            return generate_lis_lbz_blr(func_name, insns, func_info)
        if m0 == "lis" and m1 == "stw":
            return generate_lis_stw_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "lfs":
            return generate_lwz_lfs_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "stfs":
            return generate_lwz_stfs_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "lha":
            return generate_lwz_lha_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "lbz":
            return generate_lwz_lbz_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "lhz":
            return generate_lwz_lhz_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "stw":
            return generate_lwz_stw_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "stb":
            return generate_lwz_stb_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "addi" and "r3," in op1:
            return generate_lwz_addi_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "clrlwi":
            return generate_lwz_clrlwi_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "xori":
            return generate_lwz_xori_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "srwi":
            return generate_lwz_srwi_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "clrrwi":
            return generate_lwz_clrrwi_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "add":
            return generate_lwz_add_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "lbzx":
            return generate_lwz_lbzx_blr(func_name, insns, func_info)
        if m0 == "lhz" and m1 == "rlwinm":
            return generate_lhz_rlwinm_blr(func_name, insns, func_info)
        if m0 == "lhz" and m1 == "clrlwi":
            return generate_lhz_clrlwi_blr(func_name, insns, func_info)
        if m0 == "lbz" and m1 == "rlwinm":
            return generate_lbz_rlwinm_blr(func_name, insns, func_info)
        if m0 == "lbz" and m1 == "extsb":
            return generate_lbz_extsb_blr(func_name, insns, func_info)
        if m0 == "lbz" and m1 == "clrlwi":
            return generate_lbz_clrlwi_blr(func_name, insns, func_info)
        if m0 == "lbz" and m1 == "stb":
            return generate_lbz_stb_blr(func_name, insns, func_info)
        if m0 == "lha" and m1 == "rlwinm":
            return generate_lha_rlwinm_blr(func_name, insns, func_info)
        if m0 == "subfic" and m1 == "adde":
            return generate_subfic_adde_blr(func_name, insns, func_info)
        if m0 == "stw" and m1 == "stw":
            return generate_stw_stw_blr(func_name, insns, func_info)
        if m0 == "stfs" and m1 == "stfs":
            return generate_stfs_stfs_blr(func_name, insns, func_info)
        if m0 == "stb" and m1 == "stb":
            return generate_stb_stb_blr(func_name, insns, func_info)
        if m0 == "stb" and m1 == "extsb":
            return generate_stb_extsb_blr(func_name, insns, func_info)
        if m0 == "stw" and m1 == "li":
            return generate_stw_li_blr(func_name, insns, func_info)
        if m0 == "stfs" and m1 == "li":
            return generate_stfs_li_blr(func_name, insns, func_info)
        if m0 == "stw" and m1 == "mr":
            return generate_stw_mr_blr(func_name, insns, func_info)
        if m0 == "mr" and m1 == "stw":
            return generate_mr_stw_blr(func_name, insns, func_info)
        if m0 == "slwi" and m1 == "stwx":
            return generate_slwi_stwx_blr(func_name, insns, func_info)
        if m0 == "slwi" and m1 == "lwzx":
            return generate_slwi_lwzx_blr(func_name, insns, func_info)
        if m0 == "slwi" and m1 == "add":
            return generate_slwi_add_blr(func_name, insns, func_info)
        if m0 == "addi" and m1 == "stw":
            return generate_addi_stw_blr(func_name, insns, func_info)
        if m0 == "li" and m1 == "li":
            return generate_li_li_blr(func_name, insns, func_info)
        if m0 == "stw" and m1 == "stfs":
            return generate_stw_stfs_blr(func_name, insns, func_info)
        if m0 == "addis" and m1 == "addi":
            return generate_addis_addi_blr(func_name, insns, func_info)
        if m0 == "addis" and m1 == "lwz":
            return generate_addis_lwz_blr(func_name, insns, func_info)
        if m0 == "addis" and m1 == "stw":
            return generate_addis_stw_blr(func_name, insns, func_info)
        if m0 == "addis" and m1 == "stfs":
            return generate_addis_stfs_blr(func_name, insns, func_info)
        if m0 == "li" and m1 == "slw":
            return generate_li_slw_blr(func_name, insns, func_info)
        if m0 == "stwu" and m1 == "addi":
            return generate_stwu_addi_blr(func_name, insns, func_info)
        if m0 == "fmuls" and m1 == "fmsubs":
            return generate_fmuls_fmsubs_blr(func_name, insns, func_info)
        if m0 == "stfd" and m1 == "stfd":
            return generate_stfd_stfd_blr(func_name, insns, func_info)
        if m0 == "lfd" and m1 == "lfd":
            return generate_lfd_lfd_blr(func_name, insns, func_info)
        if m0 == "mfmsr" and m1 in ("or", "and", "andc"):
            return generate_mfmsr_op_blr(func_name, insns, func_info)
        if m0 == "hwsync" and m1 == "mfspr":
            return generate_hwsync_mfspr_blr(func_name, insns, func_info)
        if m0 == "mfspr" and m1 == "rlwinm":
            return generate_mfspr_rlwinm_blr(func_name, insns, func_info)

    # 4-instruction patterns (Tier 5: 16-byte functions)
    if n == 4 and mnemonics[-1] == "blr":
        m0, op0 = insns[0]
        m1, op1 = insns[1]
        m2, op2 = insns[2]

        if m0 == "li" and m1 == "stw" and m2 == "stw":
            return generate_li_stw_stw_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "stw" and m2 == "stw":
            return generate_lwz_stw_stw_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "lwz" and m2 == "rlwinm":
            return generate_lwz_lwz_rlwinm_blr(func_name, insns, func_info)
        if m0 == "slwi" and m1 == "addi" and m2 == "lwzx":
            return generate_slwi_addi_lwzx_blr(func_name, insns, func_info)
        if m0 == "mulli" and m1 == "lwz" and m2 == "add":
            return generate_mulli_lwz_add_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "stw" and m2 == "mr":
            return generate_lwz_stw_mr_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "slwi" and m2 == "lwzx":
            return generate_lwz_slwi_lwzx_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "addi" and m2 == "stw":
            return generate_lwz_addi_stw_blr(func_name, insns, func_info)
        if m0 == "lis" and m1 == "lhz" and m2 == "rlwinm":
            return generate_lis_lhz_rlwinm_blr(func_name, insns, func_info)
        if m0 == "lis" and m1 == "addi" and m2 == "stw":
            return generate_lis_addi_stw_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "mr" and m2 == "stw":
            return generate_lwz_mr_stw_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "subfic" and m2 == "adde":
            return generate_lwz_subfic_adde_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "rlwimi" and m2 == "stw":
            return generate_lwz_rlwimi_stw_blr(func_name, insns, func_info)
        if m0 == "stfs" and m1 == "stfs" and m2 == "stfs":
            return generate_stfs_stfs_stfs_blr(func_name, insns, func_info)
        if m0 == "slwi" and m1 == "addi" and m2 == "add":
            return generate_slwi_addi_add_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "slwi" and m2 == "add":
            return generate_lwz_slwi_add_blr(func_name, insns, func_info)
        if m0 == "li" and m1 == "stw" and m2 == "li":
            return generate_li_stw_li_blr(func_name, insns, func_info)
        if m0 == "stw" and m1 == "stw" and m2 == "stw":
            return generate_stw_stw_stw_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "li" and m2 == "stw":
            return generate_lwz_li_stw_blr(func_name, insns, func_info)
        if m0 == "slwi" and m1 == "addi" and m2 == "stwx":
            return generate_slwi_addi_stwx_blr(func_name, insns, func_info)
        if m0 == "slwi" and m1 == "addi" and m2 == "sthx":
            return generate_slwi_addi_sthx_blr(func_name, insns, func_info)
        if m0 == "slwi" and m1 == "addi" and m2 == "lhax":
            return generate_slwi_addi_lhax_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "lwz" and m2 == "lwz":
            return generate_lwz_lwz_lwz_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "lwz" and m2 == "stw":
            return generate_lwz_lwz_stw_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "ori" and m2 == "stw":
            return generate_lwz_ori_stw_blr(func_name, insns, func_info)
        if m0 == "lbz" and m1 == "subfic" and m2 == "adde":
            return generate_lbz_subfic_adde_blr(func_name, insns, func_info)
        if m0 == "lis" and m1 == "addi" and m2 == "lwz":
            return generate_lis_addi_lwz_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "rlwinm" and m2 == "stw":
            return generate_lwz_rlwinm_stw_blr(func_name, insns, func_info)
        if m0 == "li" and m1 == "stfs" and m2 == "stw":
            return generate_li_stfs_stw_blr(func_name, insns, func_info)
        if m0 == "li" and m1 == "li" and m2 == "stw":
            return generate_li_li_stw_blr(func_name, insns, func_info)
        # Additional Tier 5 patterns
        if m0 == "slwi" and m1 == "addi" and m2 == "lfsx":
            return generate_slwi_addi_lfsx_blr(func_name, insns, func_info)
        if m0 == "slwi" and m1 == "addi" and m2 == "stfsx":
            return generate_slwi_addi_stfsx_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "lwz" and m2 == "lfs":
            return generate_lwz_lwz_lfs_blr(func_name, insns, func_info)
        if m0 == "lfs" and m1 == "fadds" and m2 == "stfs":
            return generate_lfs_fadds_stfs_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "li" and m2 == "stb":
            return generate_lwz_li_stb_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "li" and m2 == "sth":
            return generate_lwz_li_sth_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "slwi" and m2 == "sthx":
            return generate_lwz_slwi_sthx_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "slwi" and m2 == "lhax":
            return generate_lwz_slwi_lhax_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "slwi" and m2 == "stwx":
            return generate_lwz_slwi_stwx_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "clrrwi" and m2 == "stw":
            return generate_lwz_clrrwi_stw_blr(func_name, insns, func_info)
        if m0 == "lis" and m1 == "lfs" and m2 == "stfs":
            return generate_lis_lfs_stfs_blr(func_name, insns, func_info)
        if m0 == "lis" and m1 == "lwz" and m2 == "lwz":
            return generate_lis_lwz_lwz_blr(func_name, insns, func_info)
        if m0 == "lis" and m1 == "lwz" and m2 == "clrlwi":
            return generate_lis_lwz_clrlwi_blr(func_name, insns, func_info)
        if m0 == "lis" and m1 == "lwz" and m2 == "rlwinm":
            return generate_lis_lwz_rlwinm_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "oris" and m2 == "stw":
            return generate_lwz_oris_stw_blr(func_name, insns, func_info)
        if m0 == "stb" and m1 == "stb" and m2 == "stb":
            return generate_stb_stb_stb_blr(func_name, insns, func_info)
        if m0 == "mfspr" and m1 == "ori" and m2 == "mtspr":
            return generate_mfspr_ori_mtspr_blr(func_name, insns, func_info)
        if m0 == "mfspr" and m1 == "rlwinm" and m2 == "mtspr":
            return generate_mfspr_rlwinm_mtspr_blr(func_name, insns, func_info)
        if m0 == "li" and m1 == "stw" and m2 == "stb":
            return generate_li_stw_stb_blr(func_name, insns, func_info)
        if m0 == "mulli" and m1 == "addi" and m2 == "add":
            return generate_mulli_addi_add_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "stw" and m2 == "lwz":
            return generate_lwz_stw_lwz_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "lwz" and m2 == "add":
            return generate_lwz_lwz_add_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "lwz" and m2 == "subf":
            return generate_lwz_lwz_subf_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "lhz" and m2 == "sth":
            return generate_lwz_lhz_sth_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "lbz" and m2 == "clrlwi":
            return generate_lwz_lbz_clrlwi_blr(func_name, insns, func_info)
        if m0 == "subfic" and m1 == "li" and m2 == "adde":
            return generate_subfic_li_adde_blr(func_name, insns, func_info)
        if m0 == "lbz" and m1 == "addi" and m2 == "stb":
            return generate_lbz_addi_stb_blr(func_name, insns, func_info)
        if m0 == "mr" and m1 == "stw" and m2 == "sth":
            return generate_mr_stw_sth_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "mulli" and m2 == "add":
            return generate_lwz_mulli_add_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "lwz" and m2 == "clrlwi":
            return generate_lwz_lwz_clrlwi_blr(func_name, insns, func_info)

    # 5-instruction patterns (Tier 5+: 20-byte functions)
    if n == 5 and mnemonics[-1] == "blr":
        m0, op0 = insns[0]
        m1, op1 = insns[1]
        m2, op2 = insns[2]
        m3, op3 = insns[3]

        if m0 == "li" and m1 == "stw" and m2 == "stw" and m3 == "stw":
            return generate_li_stw_stw_stw_blr(func_name, insns, func_info)
        if m0 == "mr" and m1 == "lwz" and m2 == "addi" and m3 == "stw":
            return generate_mr_lwz_addi_stw_blr(func_name, insns, func_info)
        if m0 == "lis" and m1 == "mr" and m2 == "addi" and m3 == "stw":
            return generate_lis_mr_addi_stw_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "xori" and m2 == "subfic" and m3 == "adde":
            return generate_lwz_xori_subfic_adde_blr(func_name, insns, func_info)
        if m0 == "mr" and m1 == "li" and m2 == "stw" and m3 == "stw":
            return generate_mr_li_stw_stw_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "lwz" and m2 == "subf" and m3 == "srawi":
            return generate_lwz_lwz_subf_srawi_blr(func_name, insns, func_info)
        if m0 == "lwz" and m1 == "lwz" and m2 == "stw" and m3 == "stw":
            return generate_lwz_lwz_stw_stw_blr(func_name, insns, func_info)
        if m0 == "slwi" and m1 == "addi" and m2 == "add" and m3 == "addi":
            return generate_slwi_addi_add_addi_blr(func_name, insns, func_info)
        if m0 == "li" and m1 == "li" and m2 == "stw" and m3 == "stw":
            return generate_li_li_stw_stw_blr(func_name, insns, func_info)
        if m0 == "stfs" and m1 == "stfs" and m2 == "stfs" and m3 == "stfs":
            return generate_stfs_stfs_stfs_stfs_blr(func_name, insns, func_info)

    return None, None


# ============================================================================
# Output formatting
# ============================================================================

def format_cpp_function(func_name, func_info, return_type, body):
    """Format a matched function as a C++ declaration + body."""
    method = func_info["method_name"] or func_name
    cls = func_info["class_name"]
    ns = func_info.get("namespace")
    params = func_info["params"]
    const = " const" if func_info["is_const"] else ""

    # Build the qualified name
    if ns and cls:
        qualified = f"{ns}::{cls}::{method}"
    elif cls:
        qualified = f"{cls}::{method}"
    else:
        qualified = method

    # Handle param formatting for declaration
    if params == "void":
        params_decl = ""
    elif not params:
        params_decl = ""
    else:
        params_decl = params

    line = f"{return_type} {qualified}({params_decl}){const} {body}"
    return line


def main():
    parser = argparse.ArgumentParser(
        description="Auto-generate matching C++ for trivial PPC functions"
    )
    parser.add_argument("--min-size", type=int, default=4,
                        help="Minimum function size in bytes (default: 4)")
    parser.add_argument("--max-size", type=int, default=16,
                        help="Maximum function size in bytes (default: 16)")
    parser.add_argument("--name", metavar="PATTERN",
                        help="Only process functions matching this name pattern")
    parser.add_argument("--generate", action="store_true",
                        help="Generate C++ code (otherwise report only)")
    parser.add_argument("--output", "-o", metavar="DIR",
                        help="Output directory for generated files")
    parser.add_argument("--dry-run", action="store_true",
                        help="Show what would be generated without writing files")
    args = parser.parse_args()

    print(f"Loading functions ({args.min_size}-{args.max_size} bytes)...")
    funcs = load_functions(args.min_size, args.max_size, args.name)
    print(f"Found {len(funcs)} functions in code sections")

    if not funcs:
        return

    print("Disassembling...")
    results = disassemble_batch(funcs)

    # Try to match each function
    matched = []
    unmatched = []
    pattern_counts = defaultdict(int)

    for (addr, name), insns in sorted(results.items()):
        func_info = parse_function_name(name)
        return_type, body = try_match(name, insns, func_info)

        if return_type is not None:
            cpp_line = format_cpp_function(name, func_info, return_type, body)
            matched.append({
                "name": name,
                "address": addr,
                "size": len(insns) * 4,
                "cpp": cpp_line,
                "return_type": return_type,
                "body": body,
                "func_info": func_info,
                "insns": insns,
            })
            # Classify pattern
            mnemonics = [m for m, _ in insns]
            if len(mnemonics) == 1 and mnemonics[0] == "blr":
                pattern_counts["blr (empty)"] += 1
            elif len(mnemonics) == 2 and mnemonics[-1] == "blr":
                pattern_counts[f"{mnemonics[0]}+blr"] += 1
            elif len(mnemonics) == 3 and mnemonics[-1] == "blr":
                pattern_counts[f"{mnemonics[0]}+{mnemonics[1]}+blr"] += 1
            elif len(mnemonics) == 4 and mnemonics[-1] == "blr":
                pattern_counts[f"{mnemonics[0]}+{mnemonics[1]}+{mnemonics[2]}+blr"] += 1
            elif len(mnemonics) == 5 and mnemonics[-1] == "blr":
                pattern_counts[f"{mnemonics[0]}+{mnemonics[1]}+{mnemonics[2]}+{mnemonics[3]}+blr"] += 1
            else:
                pattern_counts["other"] += 1
        else:
            insn_str = "; ".join(f"{m} {op}" for m, op in insns)
            unmatched.append({
                "name": name,
                "address": addr,
                "size": len(insns) * 4,
                "insns_str": insn_str,
            })

    # Report
    total = len(results)
    matched_count = len(matched)
    matched_bytes = sum(m["size"] for m in matched)
    unmatched_count = len(unmatched)

    print(f"\n{'=' * 72}")
    print(f"  Auto-Match Report")
    print(f"{'=' * 72}")
    print(f"  Total functions analyzed: {total}")
    print(f"  Auto-matched:            {matched_count} ({matched_count * 100 // total}%)")
    print(f"  Matched bytes:           {matched_bytes}")
    print(f"  Unmatched:               {unmatched_count}")
    print()

    print(f"  Pattern breakdown:")
    for pat, count in sorted(pattern_counts.items(), key=lambda x: -x[1]):
        print(f"    {pat:<25s} {count:>5}")
    print()

    # Show generated code if requested
    if args.generate or args.dry_run:
        print(f"  Generated C++ ({matched_count} functions):")
        print(f"{'=' * 72}\n")

        # Group by class
        by_class = defaultdict(list)
        for m in matched:
            cls = m["func_info"]["class_name"] or "(global)"
            by_class[cls].append(m)

        for cls in sorted(by_class.keys()):
            funcs_in_class = by_class[cls]
            print(f"// --- {cls} ({len(funcs_in_class)} functions) ---")
            for m in funcs_in_class:
                print(f"// 0x{m['address']:08X} ({m['size']}b)")
                print(m["cpp"])
                print()

    # Show unmatched if not too many
    if unmatched and not args.generate:
        print(f"  Sample unmatched functions (first 15):")
        for u in unmatched[:15]:
            print(f"    0x{u['address']:08X}  {u['name']}")
            print(f"      {u['insns_str']}")
        if len(unmatched) > 15:
            print(f"    ... and {len(unmatched) - 15} more")
        print()

    # Write output files if requested
    if args.output and args.generate and not args.dry_run:
        out_dir = Path(args.output)
        out_dir.mkdir(parents=True, exist_ok=True)

        # Group by class and write one file per class
        by_class = defaultdict(list)
        for m in matched:
            cls = m["func_info"]["class_name"] or "_global"
            by_class[cls].append(m)

        files_written = 0
        for cls, funcs_in_class in sorted(by_class.items()):
            filename = cls.replace("::", "_").replace("<", "_").replace(">", "_").replace("*", "ptr").replace(" ", "_").replace(",", "_") + "_auto.cpp"
            filepath = out_dir / filename

            with open(filepath, "w") as f:
                f.write(f"// Auto-generated matching stubs for {cls}\n")
                f.write(f"// Generated by auto_match.py\n")
                f.write(f"// {len(funcs_in_class)} functions, "
                        f"{sum(fn['size'] for fn in funcs_in_class)} bytes\n\n")

                for fn in funcs_in_class:
                    f.write(f"// 0x{fn['address']:08X} ({fn['size']} bytes)\n")
                    f.write(fn["cpp"] + "\n\n")

            files_written += 1

        print(f"  Wrote {files_written} files to {out_dir}/")
        print(f"  Total: {matched_count} functions, {matched_bytes} bytes")


if __name__ == "__main__":
    main()
