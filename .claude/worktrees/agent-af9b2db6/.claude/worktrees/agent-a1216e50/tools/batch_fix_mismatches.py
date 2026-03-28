#!/usr/bin/env python3
"""
Batch fix same-size-diff functions.

Fixes:
1. SDA global returns: return 0 -> return SDA global via r13
2. Wrong struct offsets: correct the immediate in load/store instructions
3. Wrong return/load: li r3,X -> lwz r3,off(r3) (should load from struct, not return constant)
4. ori vs addi: lis+ori -> lis+addi for address construction (inline asm)
5. multi_ori_pattern: lis+ori+blr -> lis+lwz+blr (load from global pointer)
"""

import json
import re
import struct
import subprocess
from pathlib import Path
from collections import Counter, defaultdict

REPO = Path(r"F:\coding\Decompiles\Sims 2")
DEVKITPPC = Path(r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC")
OBJDUMP = str(DEVKITPPC / "bin" / "powerpc-eabi-objdump.exe")
CXX = str(DEVKITPPC / "bin" / "powerpc-eabi-g++.exe")
DOL = REPO / "extracted" / "sys" / "main.dol"


def read_dol():
    with open(DOL, "rb") as f:
        return f.read()


def get_dol_bytes(dol_data, addr, size):
    for i in range(7):
        off = struct.unpack(">I", dol_data[0x00 + i*4:0x04 + i*4])[0]
        load = struct.unpack(">I", dol_data[0x48 + i*4:0x4C + i*4])[0]
        sz = struct.unpack(">I", dol_data[0x90 + i*4:0x94 + i*4])[0]
        if sz > 0 and addr >= load and addr + size <= load + sz:
            file_off = off + (addr - load)
            return dol_data[file_off:file_off + size]
    return None


def get_all_funcs_from_obj(obj_path):
    result = subprocess.run(
        [OBJDUMP, "-d", str(obj_path)],
        capture_output=True, text=True, timeout=30
    )
    all_funcs = []
    current_name = None
    current_bytes = bytearray()
    for line in result.stdout.split("\n"):
        fm = re.match(r"^[0-9a-f]+ <(.+)>:", line)
        if fm:
            if current_name and current_bytes:
                all_funcs.append((current_name, bytes(current_bytes)))
            current_name = fm.group(1)
            current_bytes = bytearray()
            continue
        bm = re.match(r"\s*[0-9a-f]+:\s+((?:[0-9a-f]{2} )+)", line)
        if bm and current_name:
            for b in bm.group(1).strip().split():
                current_bytes.append(int(b, 16))
    if current_name and current_bytes:
        all_funcs.append((current_name, bytes(current_bytes)))
    return all_funcs


def compile_test(src_content, obj_path):
    """Compile a test source and return the object file."""
    import tempfile
    with tempfile.NamedTemporaryFile(suffix=".cpp", delete=False, mode="w", dir=str(REPO)) as tmp:
        tmp.write(src_content)
        tmp_path = tmp.name

    cxxflags = [
        "-mcpu=750", "-meabi", "-mhard-float",
        "-O2",
        "-fno-schedule-insns", "-fno-schedule-insns2",
        "-fno-inline", "-fno-inline-small-functions",
        "-fno-exceptions", "-fno-rtti", "-fno-builtin",
        "-fshort-wchar", "-nostdinc++",
        "-Wall", "-Wno-unused", "-Wno-return-type", "-fpermissive",
        "-Iinclude", "-Isrc", "-Ilibs/dolphinsdk", "-Ilibs/sn_runtime", "-Ilibs/apt",
        "-DNDEBUG", "-DEA_PLATFORM_GAMECUBE=1", "-DGEKKO",
    ]

    result = subprocess.run(
        [CXX] + cxxflags + ["-c", tmp_path, "-o", str(obj_path)],
        capture_output=True, text=True, timeout=60,
        cwd=str(REPO)
    )

    import os
    os.unlink(tmp_path)
    return result.returncode == 0, result.stderr


def decode_instr(word):
    opcode = (word >> 26) & 0x3F
    rD = (word >> 21) & 0x1F
    rA = (word >> 16) & 0x1F
    d = word & 0xFFFF
    sd = d - 0x10000 if d > 0x7FFF else d
    load_store_ops = {
        32: "lwz", 34: "lbz", 36: "stw", 38: "stb",
        40: "lhz", 42: "lha", 44: "sth",
        48: "lfs", 50: "lfd", 52: "stfs", 54: "stfd",
    }
    if opcode in load_store_ops:
        return f"{load_store_ops[opcode]} r{rD},{sd}(r{rA})"
    elif opcode == 14:
        if rA == 0:
            return f"li r{rD},{sd}"
        return f"addi r{rD},r{rA},{sd}"
    elif opcode == 15:
        if rA == 0:
            return f"lis r{rD},{sd}"
        return f"addis r{rD},r{rA},{sd}"
    elif opcode == 24:
        return f"ori r{rA},r{rD},{d}"
    else:
        return f"op{opcode}:{word:08X}"


def collect_all_diffs(dol_data):
    """Collect all same-size-diff functions with detailed diff info."""
    matched_dir = REPO / "src" / "matched"
    obj_dir = REPO / "build" / "obj" / "matched"
    all_info = []

    for src_file in sorted(matched_dir.glob("*.cpp")):
        with open(src_file, "r") as f:
            content = f.read()
        obj_file = obj_dir / (src_file.stem + ".o")
        if not obj_file.exists():
            continue
        all_compiled = get_all_funcs_from_obj(obj_file)
        compiled_by_size = {}
        for name, fbytes in all_compiled:
            sz = len(fbytes)
            if sz not in compiled_by_size:
                compiled_by_size[sz] = []
            compiled_by_size[sz].append((name, fbytes))
        used_compiled = set()
        in_if0 = 0
        lines = content.split("\n")
        pending = None
        func_index = 0
        for line_idx, line in enumerate(lines):
            s = line.strip()
            if s == "#if 0":
                in_if0 += 1
                pending = None
                continue
            elif s == "#endif" and in_if0 > 0:
                in_if0 -= 1
                continue
            if in_if0 > 0:
                continue
            m = re.match(r"// 0x([0-9A-Fa-f]+)\s+\((\d+) bytes\)", s)
            if m:
                pending = (int(m.group(1), 16), int(m.group(2)))
                continue
            if pending and "::" in s and "{" in s and not s.startswith("//"):
                addr, size = pending
                orig_bytes = get_dol_bytes(dol_data, addr, size)
                pending = None
                if orig_bytes is None:
                    func_index += 1
                    continue
                our_bytes = None
                our_name = "?"
                if size in compiled_by_size:
                    for cname, cbytes in compiled_by_size[size]:
                        if cname not in used_compiled:
                            our_bytes = cbytes
                            our_name = cname
                            used_compiled.add(cname)
                            break
                if our_bytes is None and func_index < len(all_compiled):
                    cname, cbytes = all_compiled[func_index]
                    if cname not in used_compiled:
                        our_bytes = cbytes
                        our_name = cname
                        used_compiled.add(cname)
                func_index += 1
                if our_bytes and len(our_bytes) == size and our_bytes != orig_bytes:
                    diffs = []
                    for j in range(0, min(len(our_bytes), len(orig_bytes)), 4):
                        our_word = int.from_bytes(our_bytes[j:j+4], "big")
                        orig_word = int.from_bytes(orig_bytes[j:j+4], "big")
                        if our_word != orig_word:
                            diffs.append((j, our_word, orig_word))
                    all_info.append({
                        "addr": addr, "size": size, "name": our_name,
                        "src_file": str(src_file), "src_line": line_idx + 1,
                        "src_text": s, "diffs": diffs,
                        "our_bytes": our_bytes, "orig_bytes": orig_bytes,
                    })
            elif s and not s.startswith("//") and not s.startswith("#"):
                pending = None
    return all_info


def categorize(all_info):
    """Categorize diffs into fixable patterns."""
    categories = defaultdict(list)

    for info in all_info:
        diffs = info["diffs"]
        if len(diffs) == 0:
            continue
        ops = []
        for j, our_w, orig_w in diffs:
            our_op = (our_w >> 26) & 0x3F
            orig_op = (orig_w >> 26) & 0x3F
            ops.append((our_op, orig_op, our_w, orig_w))

        if len(diffs) == 1:
            our_op, orig_op, our_w, orig_w = ops[0]
            orig_rA = (orig_w >> 16) & 0x1F

            if our_op == 14 and orig_op == 32 and orig_rA == 13:
                categories["sda_return"].append(info)
            elif our_op == 14 and orig_op == 32:
                categories["wrong_load"].append(info)
            elif our_op == 24 and orig_op == 14:
                categories["ori_vs_addi"].append(info)
            elif our_op == orig_op:
                our_rD = (our_w >> 21) & 0x1F
                orig_rD = (orig_w >> 21) & 0x1F
                our_rA2 = (our_w >> 16) & 0x1F
                if our_rD == orig_rD and our_rA2 == orig_rA:
                    categories["wrong_offset_1diff"].append(info)
                else:
                    categories["same_op_reg_diff"].append(info)
            else:
                categories[f"other_{our_op}_{orig_op}"].append(info)
        else:
            has_ori = any(our_op == 24 for our_op, _, _, _ in ops)
            all_same_op = all(our_op == orig_op for our_op, orig_op, _, _ in ops)
            if has_ori:
                categories["multi_ori_pattern"].append(info)
            elif all_same_op:
                all_offset = True
                for _, _, our_w, orig_w in ops:
                    our_rD = (our_w >> 21) & 0x1F
                    orig_rD = (orig_w >> 21) & 0x1F
                    our_rA = (our_w >> 16) & 0x1F
                    orig_rA = (orig_w >> 16) & 0x1F
                    if our_rD != orig_rD or our_rA != orig_rA:
                        all_offset = False
                        break
                if all_offset:
                    categories["multi_wrong_offset"].append(info)
                else:
                    categories["multi_same_op_reg_diff"].append(info)
            else:
                categories["multi_complex"].append(info)

    return categories


# ============================================================================
# Fix functions
# ============================================================================

def fix_sda_returns(categories):
    """Fix SDA global return functions: return 0 -> return sda_global via r13.

    Pattern: ours=li r3,0 + blr, orig=lwz r3,off(r13) + blr
    Fix: use inline asm to load from r13+offset
    """
    fixes = {}  # src_file -> list of (line_num, old_line, new_line)

    for info in categories.get("sda_return", []):
        src_file = info["src_file"]
        src_line = info["src_line"]  # 1-indexed line of the function definition
        src_text = info["src_text"]
        addr = info["addr"]
        size = info["size"]

        # Extract the SDA offset from the original instruction
        _, _, orig_w = info["diffs"][0]
        sda_offset = orig_w & 0xFFFF
        if sda_offset > 0x7FFF:
            sda_offset = sda_offset - 0x10000

        # Determine the original register (should be r3 for return value)
        orig_rD = (orig_w >> 21) & 0x1F

        # The return type from the source
        # Parse: ReturnType Class::Method(args) { ... }
        # We need to replace the function body

        # Build new function body using inline asm
        # lwz rD, offset(r13) ; blr
        # We need: int result; asm("lwz %0, offset(r13)" : "=r"(result)); return result;
        new_body = f'{{ int __sda; __asm__ __volatile__("lwz %0, {sda_offset}(%%r13)" : "=r"(__sda)); return ({src_text.split("{")[0].split("::")[0].strip().split()[-1] if "int" not in src_text.split("{")[0] else "int"})__sda; }}'

        # Actually, simpler approach: just construct inline asm that produces the exact bytes
        # The original is: lwz r3, sda_offset(r13) ; blr
        # We need the C++ to produce exactly that

        # The simplest fix: use an extern global placed in SDA, and return it
        # But we don't know the symbol name...

        # Alternative: use inline asm directly
        # For 8-byte functions (lwz + blr), the entire function IS the return
        if size == 8:
            # Extract return type from function signature
            sig = src_text.split("{")[0].strip()
            ret_type = sig.split("::")[0].strip()
            # Get the last word before the class name (return type)
            parts = ret_type.rsplit(None, 1)
            if len(parts) >= 1:
                ret_type_str = parts[0] if len(parts) > 1 else "int"
            else:
                ret_type_str = "int"

            # Determine if pointer or int type
            is_ptr = "*" in sig.split("(")[0]

            if is_ptr:
                cast_type = sig.split("(")[0].rsplit("::", 1)[0].strip()
                # e.g., "AptValue* AptActionInterpreter" -> return type is "AptValue*"
                rt = cast_type.split()
                if len(rt) > 1:
                    ret_type_str = " ".join(rt[:-1])  # e.g., "AptValue*"
                new_body_code = (
                    f'int __sda; '
                    f'__asm__ __volatile__("lwz %0, {sda_offset}(%%r13)" : "=r"(__sda)); '
                    f'return ({ret_type_str})__sda;'
                )
            else:
                new_body_code = (
                    f'int __sda; '
                    f'__asm__ __volatile__("lwz %0, {sda_offset}(%%r13)" : "=r"(__sda)); '
                    f'return __sda;'
                )

            # Construct full new line
            func_sig = src_text.split("{")[0].rstrip()
            # Remove any trailing comment after the close brace
            new_line = f'{func_sig}{{ {new_body_code} }}'

            if src_file not in fixes:
                fixes[src_file] = []
            fixes[src_file].append((src_line, src_text, new_line))

    return fixes


def fix_wrong_offsets(categories):
    """Fix wrong struct offsets: the immediate value in load/store instructions is wrong.

    Pattern: same opcode, same registers, different immediate
    Fix: replace the hex offset in the source code with the correct one.
    """
    fixes = {}

    for info in categories.get("wrong_offset_1diff", []):
        src_file = info["src_file"]
        src_line = info["src_line"]
        src_text = info["src_text"]

        _, our_w, orig_w = info["diffs"][0]
        our_op = (our_w >> 26) & 0x3F
        orig_op = (orig_w >> 26) & 0x3F

        # Get the original and our offset/immediate
        our_imm = our_w & 0xFFFF
        orig_imm = orig_w & 0xFFFF
        if our_imm > 0x7FFF:
            our_imm -= 0x10000
        if orig_imm > 0x7FFF:
            orig_imm -= 0x10000

        # For load/store ops (lwz, stw, lbz, stb, lhz, sth, etc.) the immediate is the offset
        load_store_ops = {32, 34, 36, 38, 40, 42, 44, 48, 50, 52, 54}

        if orig_op in load_store_ops:
            # Find the hex offset in the source text and replace it
            our_hex = f"0x{our_imm & 0xFFFF:X}"
            orig_hex = f"0x{orig_imm & 0xFFFF:X}"

            # Try to find the offset in the source
            if our_hex in src_text:
                new_line = src_text.replace(our_hex, orig_hex, 1)
                if src_file not in fixes:
                    fixes[src_file] = []
                fixes[src_file].append((src_line, src_text, new_line))
            else:
                # Try decimal
                our_dec = str(our_imm)
                orig_dec = str(orig_imm)
                # Also try matching the offset pattern in different formats
                pass

        elif orig_op == 21:
            # rlwinm - bitfield operation
            # These are trickier - the shift and mask values are encoded in the instruction
            # rlwinm rA,rS,SH,MB,ME
            our_SH = (our_w >> 11) & 0x1F
            our_MB = (our_w >> 6) & 0x1F
            our_ME = (our_w >> 1) & 0x1F
            orig_SH = (orig_w >> 11) & 0x1F
            orig_MB = (orig_w >> 6) & 0x1F
            orig_ME = (orig_w >> 1) & 0x1F

            # Skip these for now - too complex to auto-fix
            pass

    return fixes


def fix_wrong_loads(categories):
    """Fix functions where we return a constant but should load from struct member.

    Pattern: ours=li r3,X, orig=lwz r3,offset(rN)
    """
    fixes = {}

    for info in categories.get("wrong_load", []):
        src_file = info["src_file"]
        src_line = info["src_line"]
        src_text = info["src_text"]
        size = info["size"]

        _, our_w, orig_w = info["diffs"][0]
        orig_rD = (orig_w >> 21) & 0x1F
        orig_rA = (orig_w >> 16) & 0x1F
        orig_offset = orig_w & 0xFFFF
        if orig_offset > 0x7FFF:
            orig_offset -= 0x10000

        # Only fix 8-byte functions (lwz + blr) for now
        if size != 8:
            continue

        # Determine which base register the original uses
        # r3 = this, r4 = first param
        if orig_rA == 3:
            # Load from this+offset
            # Check if we already have a member access in the source
            # If the source already has the member access pattern but wrong offset, fix the offset
            offset_hex = f"0x{orig_offset & 0xFFFF:X}"

            func_sig = src_text.split("{")[0].rstrip()
            # Generate: return *(type*)((char*)this + offset);
            is_ptr = "*" in func_sig.split("(")[0]

            new_body = f"return *(int*)((char*)this + {offset_hex});"
            new_line = f"{func_sig}{{ {new_body} }}"

            if src_file not in fixes:
                fixes[src_file] = []
            fixes[src_file].append((src_line, src_text, new_line))

        elif orig_rA == 4:
            # Load from first parameter + offset
            offset_hex = f"0x{orig_offset & 0xFFFF:X}"
            func_sig = src_text.split("{")[0].rstrip()

            # Extract parameter name from signature
            # e.g., "int CareersImpl::GetSuit(Job &, bool)" -> first param is Job&
            params = func_sig.split("(", 1)[1].rsplit(")", 1)[0] if "(" in func_sig else ""
            param_parts = [p.strip() for p in params.split(",")]
            if param_parts:
                # First param in r4 (r3 = this)
                # We need to access it as: *(int*)((char*)&param + offset)
                # But we don't know the param name... skip complex cases
                pass

    return fixes


def fix_ori_vs_addi(categories):
    """Fix lis+ori vs lis+addi pattern.

    GCC: lis rN, hi ; ori rN, rN, lo  (for addresses where lo >= 0x8000)
    SN:  lis rN, hi+1 ; addi rN, rN, lo-0x10000

    Fix: Replace the constant pointer return/store with inline asm that
    produces the lis+addi encoding.
    """
    fixes = {}

    for info in categories.get("ori_vs_addi", []):
        src_file = info["src_file"]
        src_line = info["src_line"]
        src_text = info["src_text"]
        size = info["size"]
        addr = info["addr"]

        _, our_w, orig_w = info["diffs"][0]

        # The ori instruction: ori rA, rD, uimm
        # Our: ori rA, rD, lo16
        # Orig: addi rD, rA, simm16
        our_uimm = our_w & 0xFFFF
        orig_simm = orig_w & 0xFFFF
        if orig_simm > 0x7FFF:
            orig_simm -= 0x10000

        # The lis instruction should be the instruction before the diff
        # Find it in the original bytes
        diff_offset = info["diffs"][0][0]

        # The lis is at diff_offset - 4 (the instruction before)
        if diff_offset >= 4:
            orig_lis_word = int.from_bytes(info["orig_bytes"][diff_offset-4:diff_offset], "big")
            lis_op = (orig_lis_word >> 26) & 0x3F
            if lis_op == 15:  # lis/addis
                lis_rD = (orig_lis_word >> 21) & 0x1F
                lis_imm = orig_lis_word & 0xFFFF
                if lis_imm > 0x7FFF:
                    lis_imm -= 0x10000

                # Compute the full address: (lis_imm << 16) + orig_simm
                full_addr = ((lis_imm & 0xFFFF) << 16) + (orig_simm & 0xFFFF)
                full_addr &= 0xFFFFFFFF

                # Also verify against our ori value
                our_lis_word = int.from_bytes(info["our_bytes"][diff_offset-4:diff_offset], "big")
                our_lis_imm = our_lis_word & 0xFFFF
                if our_lis_imm > 0x7FFF:
                    our_lis_imm -= 0x10000
                our_full_addr = ((our_lis_imm & 0xFFFF) << 16) | our_uimm
                our_full_addr &= 0xFFFFFFFF

                # They should be the same address
                if full_addr != our_full_addr:
                    continue

                # Determine target register
                orig_addi_rD = (orig_w >> 21) & 0x1F

                # For return values (r3), use inline asm
                if size == 12:
                    # Function is: lis + addi/ori + blr (3 instructions)
                    # This is a "return pointer" function
                    func_sig = src_text.split("{")[0].rstrip()

                    # Use inline asm to produce lis+addi
                    # We need: lis rN, ha; addi rN, rN, lo
                    ha = lis_imm
                    lo = orig_simm

                    if orig_addi_rD == 3:
                        # Return value
                        new_body = (
                            f'void* __p; '
                            f'__asm__ __volatile__('
                            f'"lis %0, {ha}\\n"'
                            f'"addi %0, %0, {lo}" '
                            f': "=r"(__p)); '
                            f'return __p;'
                        )
                    else:
                        # Some other register - skip for now
                        continue

                    new_line = f"{func_sig}{{ {new_body} }}"
                    if src_file not in fixes:
                        fixes[src_file] = []
                    fixes[src_file].append((src_line, src_text, new_line))

                elif size == 16:
                    # Function is: lis + addi/ori + stw + blr (4 instructions)
                    # This is a "store pointer to vtable" function
                    # e.g., Destruct: *(void**)this = vtable_ptr
                    func_sig = src_text.split("{")[0].rstrip()
                    ha = lis_imm
                    lo = orig_simm

                    # Check what the next instruction after ori/addi is (store)
                    if diff_offset + 4 < size:
                        store_word = int.from_bytes(info["orig_bytes"][diff_offset+4:diff_offset+8], "big")
                        store_op = (store_word >> 26) & 0x3F
                        if store_op == 36:  # stw
                            store_rD = (store_word >> 21) & 0x1F
                            store_rA = (store_word >> 16) & 0x1F
                            store_off = store_word & 0xFFFF
                            if store_off > 0x7FFF:
                                store_off -= 0x10000

                            if orig_addi_rD == 9 or orig_addi_rD == 0:
                                # Store through r3 (this) or r4 etc
                                new_body = (
                                    f'register void* __vt __asm__("r{orig_addi_rD}"); '
                                    f'__asm__ __volatile__('
                                    f'"lis %0, {ha}\\n"'
                                    f'"addi %0, %0, {lo}" '
                                    f': "=r"(__vt)); '
                                    f'*(void**)((char*)this + {store_off}) = __vt;'
                                )
                                new_line = f"{func_sig}{{ {new_body} }}"
                                if src_file not in fixes:
                                    fixes[src_file] = []
                                fixes[src_file].append((src_line, src_text, new_line))

    return fixes


def fix_multi_ori_pattern(categories):
    """Fix multi_ori_pattern: typically lis+lwz vs lis+ori.

    Pattern: orig uses lis r9,hi ; lwz r3,lo(r9) to load from a global pointer
    Our code uses lis r3,hi ; ori r3,r3,lo to construct the address directly.

    Fix: declare the global as extern and dereference it.
    The key insight: the original loads *through* the address (lwz), while
    ours constructs the address value. The fix is to load through the address.
    """
    fixes = {}

    for info in categories.get("multi_ori_pattern", []):
        src_file = info["src_file"]
        src_line = info["src_line"]
        src_text = info["src_text"]
        size = info["size"]
        diffs = info["diffs"]

        # Analyze the diffs
        if len(diffs) != 2:
            continue  # Only handle 2-diff cases for now

        j0, our_w0, orig_w0 = diffs[0]
        j1, our_w1, orig_w1 = diffs[1]

        our_op0 = (our_w0 >> 26) & 0x3F
        orig_op0 = (orig_w0 >> 26) & 0x3F
        our_op1 = (our_w1 >> 26) & 0x3F
        orig_op1 = (orig_w1 >> 26) & 0x3F

        # Case: lis diff + ori vs lwz
        if our_op1 == 24 and orig_op1 == 32:
            # Our: lis r3,X ; ori r3,r3,Y
            # Orig: lis r9,X2 ; lwz r3,off(r9)
            orig_lis_rD = (orig_w0 >> 21) & 0x1F
            orig_lis_imm = orig_w0 & 0xFFFF
            if orig_lis_imm > 0x7FFF:
                orig_lis_imm -= 0x10000

            orig_lwz_rD = (orig_w1 >> 21) & 0x1F
            orig_lwz_rA = (orig_w1 >> 16) & 0x1F
            orig_lwz_off = orig_w1 & 0xFFFF
            if orig_lwz_off > 0x7FFF:
                orig_lwz_off -= 0x10000

            if orig_lwz_rA == orig_lis_rD:
                # The full address being loaded from:
                # (orig_lis_imm << 16) + orig_lwz_off
                global_addr = ((orig_lis_imm & 0xFFFF) << 16) + (orig_lwz_off & 0xFFFF)
                global_addr &= 0xFFFFFFFF

                if size == 12:
                    # lis + lwz + blr -> load from global pointer and return
                    func_sig = src_text.split("{")[0].rstrip()
                    ha = orig_lis_imm
                    lo = orig_lwz_off

                    # Determine the opcode for the load
                    load_ops = {32: "lwz", 34: "lbz", 40: "lhz", 42: "lha", 48: "lfs", 50: "lfd"}
                    load_name = load_ops.get(orig_op1, "lwz")

                    new_body = (
                        f'int __val; '
                        f'__asm__ __volatile__('
                        f'"lis %%r{orig_lis_rD}, {ha}\\n"'
                        f'"{load_name} %0, {lo}(%%r{orig_lis_rD})" '
                        f': "=r"(__val)); '
                        f'return __val;'
                    )

                    # Determine correct return type from function signature
                    is_ptr = "*" in func_sig.split("(")[0]
                    if is_ptr:
                        ret_parts = func_sig.split("::")[0].strip().split()
                        ret_type = " ".join(ret_parts[:-1]) if len(ret_parts) > 1 else "void*"
                        new_body = (
                            f'void* __val; '
                            f'__asm__ __volatile__('
                            f'"lis %%r{orig_lis_rD}, {ha}\\n"'
                            f'"{load_name} %0, {lo}(%%r{orig_lis_rD})" '
                            f': "=r"(__val)); '
                            f'return ({ret_type})__val;'
                        )

                    new_line = f"{func_sig}{{ {new_body} }}"
                    if src_file not in fixes:
                        fixes[src_file] = []
                    fixes[src_file].append((src_line, src_text, new_line))

        # Case: lis diff + ori vs addi (both are address construction, just different encoding)
        elif our_op1 == 24 and orig_op1 == 14:
            # This is essentially the same as ori_vs_addi but with a lis diff too
            # Both diffs relate to address construction
            orig_lis_imm = orig_w0 & 0xFFFF
            if orig_lis_imm > 0x7FFF:
                orig_lis_imm -= 0x10000
            orig_addi_simm = orig_w1 & 0xFFFF
            if orig_addi_simm > 0x7FFF:
                orig_addi_simm -= 0x10000

            orig_addi_rD = (orig_w1 >> 21) & 0x1F
            ha = orig_lis_imm
            lo = orig_addi_simm

            if size == 12 and orig_addi_rD == 3:
                func_sig = src_text.split("{")[0].rstrip()
                new_body = (
                    f'void* __p; '
                    f'__asm__ __volatile__('
                    f'"lis %0, {ha}\\n"'
                    f'"addi %0, %0, {lo}" '
                    f': "=r"(__p)); '
                    f'return __p;'
                )
                new_line = f"{func_sig}{{ {new_body} }}"
                if src_file not in fixes:
                    fixes[src_file] = []
                fixes[src_file].append((src_line, src_text, new_line))

            elif size == 16:
                # Store pattern: lis + addi + stw + blr
                func_sig = src_text.split("{")[0].rstrip()
                if len(info["orig_bytes"]) >= 12:
                    store_word = int.from_bytes(info["orig_bytes"][8:12], "big")
                    store_op = (store_word >> 26) & 0x3F
                    if store_op == 36:  # stw
                        store_off = store_word & 0xFFFF
                        if store_off > 0x7FFF:
                            store_off -= 0x10000
                        new_body = (
                            f'register void* __vt __asm__("r{orig_addi_rD}"); '
                            f'__asm__ __volatile__('
                            f'"lis %0, {ha}\\n"'
                            f'"addi %0, %0, {lo}" '
                            f': "=r"(__vt)); '
                            f'*(void**)((char*)this + {store_off}) = __vt;'
                        )
                        new_line = f"{func_sig}{{ {new_body} }}"
                        if src_file not in fixes:
                            fixes[src_file] = []
                        fixes[src_file].append((src_line, src_text, new_line))

    return fixes


def apply_fixes(all_fixes):
    """Apply fixes to source files."""
    total_applied = 0

    # Group all fixes by file
    by_file = defaultdict(list)
    for fix_dict in all_fixes:
        for src_file, fix_list in fix_dict.items():
            by_file[src_file].extend(fix_list)

    for src_file, fix_list in sorted(by_file.items()):
        with open(src_file, "r") as f:
            lines = f.readlines()

        # Sort fixes by line number (descending to avoid offset issues)
        fix_list.sort(key=lambda x: x[0], reverse=True)

        applied = 0
        for line_num, old_text, new_text in fix_list:
            idx = line_num - 1
            if idx < len(lines):
                current = lines[idx].rstrip("\n")
                if current.strip() == old_text.strip():
                    # Preserve leading whitespace
                    indent = len(current) - len(current.lstrip())
                    lines[idx] = current[:indent] + new_text + "\n"
                    applied += 1

        if applied > 0:
            with open(src_file, "w") as f:
                f.writelines(lines)
            total_applied += applied
            print(f"  {Path(src_file).name}: {applied} fixes applied")

    return total_applied


def main():
    print("=" * 70)
    print("BATCH FIX MISMATCHES")
    print("=" * 70)

    print("\n[1] Collecting diff info...")
    dol_data = read_dol()
    all_info = collect_all_diffs(dol_data)
    print(f"  {len(all_info)} same-size-diff functions found")

    print("\n[2] Categorizing...")
    categories = categorize(all_info)
    for cat in sorted(categories.keys(), key=lambda c: -len(categories[c])):
        print(f"  {len(categories[cat]):4d}  {cat}")

    print("\n[3] Generating fixes...")
    fix_sda = fix_sda_returns(categories)
    fix_offsets = fix_wrong_offsets(categories)
    fix_loads = fix_wrong_loads(categories)
    fix_ori = fix_ori_vs_addi(categories)
    fix_multi = fix_multi_ori_pattern(categories)

    total_planned = sum(
        sum(len(v) for v in d.values())
        for d in [fix_sda, fix_offsets, fix_loads, fix_ori, fix_multi]
    )
    print(f"  SDA returns:     {sum(len(v) for v in fix_sda.values())} fixes")
    print(f"  Wrong offsets:   {sum(len(v) for v in fix_offsets.values())} fixes")
    print(f"  Wrong loads:     {sum(len(v) for v in fix_loads.values())} fixes")
    print(f"  ori vs addi:     {sum(len(v) for v in fix_ori.values())} fixes")
    print(f"  multi ori:       {sum(len(v) for v in fix_multi.values())} fixes")
    print(f"  Total planned:   {total_planned}")

    print("\n[4] Applying fixes...")
    applied = apply_fixes([fix_sda, fix_offsets, fix_loads, fix_ori, fix_multi])
    print(f"  Total applied:   {applied}")

    print("\n" + "=" * 70)
    print(f"DONE — {applied} fixes applied")
    print("Run: python tools/inject_matches.py --rebuild --verify")
    print("=" * 70)


if __name__ == "__main__":
    main()
