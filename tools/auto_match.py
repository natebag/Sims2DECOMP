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

    # 3-instruction patterns
    if n == 3 and mnemonics[-1] == "blr":
        m0, op0 = insns[0]
        m1, op1 = insns[1]

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
            filename = cls.replace("::", "_") + "_auto.cpp"
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
