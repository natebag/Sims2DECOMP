#!/usr/bin/env python3
"""Verify a decompiled function matches the DOL with relocation-aware comparison."""
import struct
import subprocess
import sys
import os
import re

def main():
    if len(sys.argv) < 4:
        print("Usage: verify_reloc.py <source.cpp> <hex_address> <size>")
        sys.exit(1)

    src = sys.argv[1]
    func_addr = int(sys.argv[2], 0)
    func_size = int(sys.argv[3])

    DEVKITPPC = "F:/coding/Decompiles/Tools/devkitPro/devkitPPC"
    OBJDUMP = os.path.join(DEVKITPPC, "bin", "powerpc-eabi-objdump.exe")
    SN_BIN = "compiler/ProDGforNGCv393/Disk1/data1/Build_Tools_Bin"
    SN_CC1PLUS = os.path.join(SN_BIN, "cc1plus.exe")
    SN_AS = os.path.join(SN_BIN, "NgcAs.exe")
    DOL_PATH = "extracted/sys/main.dol"
    MAP_PATH = "extracted/files/u2_ngc_release_dvd.map"
    GAS = os.path.join(DEVKITPPC, "bin", "powerpc-eabi-as.exe")

    os.makedirs("build/verify", exist_ok=True)
    basename = os.path.splitext(os.path.basename(src))[0]
    obj_path = f"build/verify/{basename}.o"
    asm_path = f"build/verify/{basename}.s"

    # Step 1: Compile
    if os.path.isfile(SN_CC1PLUS):
        clean_src = f"build/verify/{basename}_clean.cpp"
        with open(src, 'r') as f:
            code = f.read()
        # Strip comments
        code = re.sub(r'//.*', '', code)
        code = re.sub(r'/\*.*?\*/', '', code, flags=re.DOTALL)
        with open(clean_src, 'w') as f:
            f.write(code)
        print(f"Compiling with SN Systems ProDG...")
        r = subprocess.run([SN_CC1PLUS, clean_src, "-o", asm_path, "-quiet", "-O2"],
                          capture_output=True, text=True)
        if r.returncode != 0:
            print(f"COMPILE FAILED:\n{r.stderr}")
            sys.exit(1)
        r = subprocess.run([SN_AS, asm_path, "-o", obj_path],
                          capture_output=True, text=True)
        if r.returncode != 0:
            # Fallback to devkitPPC assembler
            r = subprocess.run([GAS, "-mgekko", "-mregnames", asm_path, "-o", obj_path],
                              capture_output=True, text=True)
            if r.returncode != 0:
                print(f"ASSEMBLE FAILED:\n{r.stderr}")
                sys.exit(1)
    else:
        CXX = os.path.join(DEVKITPPC, "bin", "powerpc-eabi-g++.exe")
        cxx = CXX
        flags = "-mcpu=750 -meabi -mhard-float -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline -fno-inline-small-functions -fno-exceptions -fno-rtti -fno-builtin -fshort-wchar -fpermissive -Wno-unused -Wno-return-type".split()
        print(f"Compiling with devkitPPC GCC...")
        r = subprocess.run([cxx] + flags + ["-c", src, "-o", obj_path],
                          capture_output=True, text=True)
        if r.returncode != 0:
            print(f"COMPILE FAILED:\n{r.stderr}")
            sys.exit(1)

    # Step 2: Extract .text bytes
    r = subprocess.run([OBJDUMP, "-s", "-j", ".text", obj_path],
                      capture_output=True, text=True)
    hex_str = ""
    found = False
    for line in r.stdout.split('\n'):
        if 'Contents of section .text' in line:
            found = True
            continue
        if found and line.strip():
            # Each line: " 0000 9421fff8 7c0802a6 9001000c 81230008  .!..|........#.."
            # Extract the 4 hex columns (columns 1-4 after the address)
            parts = line.split()
            if len(parts) >= 2:
                for p in parts[1:]:
                    if len(p) == 8 and all(c in '0123456789abcdef' for c in p):
                        hex_str += p
                    else:
                        break  # Stop at ASCII representation

    obj_bytes = bytearray.fromhex(hex_str)[:func_size]

    # Step 3: Extract relocations
    r = subprocess.run([OBJDUMP, "-r", obj_path],
                      capture_output=True, text=True)
    relocs = []
    for line in r.stdout.split('\n'):
        line = line.strip()
        if not line or not line[0].isdigit():
            continue
        parts = line.split()
        if len(parts) >= 3:
            try:
                offset = int(parts[0], 16)
                rtype = parts[1]
                value_str = parts[2]
                if '+' in value_str:
                    sym, addend_str = value_str.rsplit('+', 1)
                    addend = int(addend_str, 16)
                else:
                    sym = value_str
                    addend = 0
                relocs.append((offset, rtype, sym, addend))
            except:
                pass

    # Step 4: Build symbol map from MAP (both by demangled name and by function basename)
    sym_map = {}
    sym_by_basename = {}  # for fuzzy matching mangled names
    with open(MAP_PATH, 'r', errors='replace') as f:
        for line in f:
            parts = line.strip().split()
            if len(parts) >= 4:
                try:
                    a = int(parts[0], 16)
                    name = ' '.join(parts[3:])
                    sym_map[name] = a
                    # Extract just the function name for fuzzy matching
                    # e.g. "NghResFile::findListByResType(unsigned int)" -> "findListByResType"
                    if '::' in name:
                        base = name.split('::')[-1].split('(')[0]
                    else:
                        base = name.split('(')[0]
                    if base not in sym_by_basename:
                        sym_by_basename[base] = []
                    sym_by_basename[base].append((name, a))
                except:
                    pass

    def resolve_mangled(mangled):
        """Try to resolve a GCC 2.95 mangled name to an address using the map."""
        # Direct lookup
        if mangled in sym_map:
            return sym_map[mangled]
        # Try SN-style namespace mangling: _5Globs.pNghResFile -> Globs::pNghResFile
        if '.' in mangled:
            parts = mangled.split('.')
            # First part: _NClassName (where N is length)
            first = parts[0]
            if first.startswith('_'):
                rest = first[1:]
                i = 0
                ns_len = 0
                while i < len(rest) and rest[i].isdigit():
                    ns_len = ns_len * 10 + int(rest[i])
                    i += 1
                if ns_len > 0 and i + ns_len <= len(rest):
                    ns_name = rest[i:i+ns_len]
                    member = '.'.join(parts[1:])
                    full_name = ns_name + '::' + member
                    if full_name in sym_map:
                        return sym_map[full_name]
        # Try to extract the function name from mangled form
        # GCC 2.95 mangles as: FuncName__ClassNameArgs
        # e.g. findListByResType__10NghResFileUi -> NghResFile::findListByResType
        if '__' in mangled:
            func_part = mangled.split('__')[0]
            if func_part in sym_by_basename:
                candidates = sym_by_basename[func_part]
                if len(candidates) == 1:
                    return candidates[0][1]
                # Try to match class name too
                rest = mangled[len(func_part)+2:]
                # Extract class name (digit prefix = length)
                i = 0
                class_len = 0
                while i < len(rest) and rest[i].isdigit():
                    class_len = class_len * 10 + int(rest[i])
                    i += 1
                if class_len > 0 and i + class_len <= len(rest):
                    class_name = rest[i:i+class_len]
                    args_part = rest[i+class_len:]  # remaining part encodes arguments
                    # Count encoded args (rough heuristic)
                    num_encoded_args = 0
                    j = 0
                    while j < len(args_part):
                        if args_part[j] in 'iflvsSUcCjJdDb':
                            num_encoded_args += 1
                            j += 1
                        elif args_part[j] == 'P' or args_part[j] == 'R':
                            num_encoded_args += 1
                            # Skip the type after P/R
                            j += 1
                            while j < len(args_part) and args_part[j].isdigit():
                                j += 1
                            while j < len(args_part) and args_part[j].isalpha():
                                j += 1
                        else:
                            j += 1
                    matching = []
                    for cand_name, cand_addr in candidates:
                        if class_name + '::' + func_part in cand_name:
                            matching.append((cand_name, cand_addr))
                    if len(matching) == 1:
                        return matching[0][1]
                    # Multiple overloads: try to match by arg types
                    # Build a simple signature fingerprint from the mangled args
                    arg_fingerprint = args_part
                    for cand_name, cand_addr in matching:
                        paren_start = cand_name.find('(')
                        paren_end = cand_name.rfind(')')
                        if paren_start >= 0 and paren_end >= 0:
                            params = cand_name[paren_start+1:paren_end]
                            # Build expected mangled args from demangled params
                            expected_mangled = ''
                            for param in [p.strip() for p in params.split(',')]:
                                if param == 'int': expected_mangled += 'i'
                                elif param == 'short': expected_mangled += 's'
                                elif param == 'char': expected_mangled += 'c'
                                elif param == 'float': expected_mangled += 'f'
                                elif param == 'bool': expected_mangled += 'b'
                                elif param == 'unsigned int': expected_mangled += 'Ui'
                                elif param == 'unsigned short': expected_mangled += 'Us'
                                elif param == 'unsigned char': expected_mangled += 'Uc'
                                elif param == 'void': pass
                                elif param.endswith('*'):
                                    expected_mangled += 'P'
                                    base = param[:-1].strip()
                                    if base == 'char': expected_mangled += 'c'
                                    elif base == 'void': expected_mangled += 'v'
                                    else: expected_mangled += str(len(base)) + base
                                elif param.endswith('&'):
                                    expected_mangled += 'R'
                                    base = param[:-1].strip()
                                    expected_mangled += str(len(base)) + base
                                else:
                                    expected_mangled += str(len(param)) + param
                            if arg_fingerprint == expected_mangled:
                                return cand_addr
                    # Fallback: try arg count
                    for cand_name, cand_addr in matching:
                        paren_start = cand_name.find('(')
                        paren_end = cand_name.rfind(')')
                        if paren_start >= 0 and paren_end >= 0:
                            params = cand_name[paren_start+1:paren_end]
                            if params == 'void' or params == '':
                                cand_args = 0
                            else:
                                cand_args = params.count(',') + 1
                            if cand_args == num_encoded_args:
                                return cand_addr
                    # Last resort: return last match
                    if matching:
                        return matching[-1][1]
        # Vtable: __vt__NClassName -> "ClassName virtual table"
        if mangled.startswith('__vt__'):
            rest = mangled[6:]
            i = 0
            while i < len(rest) and rest[i].isdigit():
                i += 1
            if i > 0:
                class_name = rest[i:]
                vt_name = class_name + ' virtual table'
                if vt_name in sym_map:
                    return sym_map[vt_name]
        # Constructor: just the class name repeated
        # e.g. __9_c2DArray -> _c2DArray::_c2DArray
        if mangled.startswith('__'):
            rest = mangled[2:]
            i = 0
            class_len = 0
            while i < len(rest) and rest[i].isdigit():
                class_len = class_len * 10 + int(rest[i])
                i += 1
            if class_len > 0 and i + class_len <= len(rest):
                class_name = rest[i:i+class_len]
                # Try constructor
                ctor_name = class_name + '::' + class_name
                for name, addr in sym_map.items():
                    if ctor_name in name:
                        return addr
                # Try destructor
                dtor_name = class_name + '::~' + class_name
                for name, addr in sym_map.items():
                    if dtor_name in name:
                        return addr
        return None

    # Step 5: Apply relocations
    warnings = []
    for offset, rtype, sym, addend in relocs:
        if offset >= func_size:
            continue
        if sym == '.text':
            target_addr = func_addr + addend
        elif sym in sym_map:
            target_addr = sym_map[sym]
        else:
            resolved = resolve_mangled(sym)
            if resolved is not None:
                target_addr = resolved
            else:
                warnings.append(f"WARNING: Unknown symbol '{sym}'")
                continue

        instr_addr = func_addr + offset
        if rtype == 'R_PPC_REL14':
            displacement = target_addr - instr_addr
            old = struct.unpack('>I', obj_bytes[offset:offset+4])[0]
            old_masked = old & 0xFFFF0003
            new_val = old_masked | (displacement & 0x0000FFFC)
            struct.pack_into('>I', obj_bytes, offset, new_val)
        elif rtype == 'R_PPC_REL24':
            displacement = target_addr - instr_addr
            old = struct.unpack('>I', obj_bytes[offset:offset+4])[0]
            old_masked = old & 0xFC000003
            new_val = old_masked | (displacement & 0x03FFFFFC)
            struct.pack_into('>I', obj_bytes, offset, new_val)
        elif rtype == 'R_PPC_EMB_SDA21':
            # SDA-relative access (r13-based)
            # r13 base for this DOL is 0x80505920
            R13_BASE = 0x80505920
            sda_offset = (target_addr - R13_BASE) & 0xFFFFFFFF
            if sda_offset > 0x7FFF:
                sda_offset = sda_offset - 0x10000 if sda_offset >= 0x8000 else sda_offset
            # Signed 16-bit offset
            sda_offset_s16 = target_addr - R13_BASE
            old = struct.unpack('>I', obj_bytes[offset:offset+4])[0]
            # Keep opcode and rD (bits 0-10), set rA=r13 (bits 11-15), offset in bits 16-31
            rD = (old >> 21) & 0x1F
            opcode = (old >> 26) & 0x3F
            new_val = (opcode << 26) | (rD << 21) | (13 << 16) | (sda_offset_s16 & 0xFFFF)
            struct.pack_into('>I', obj_bytes, offset, new_val)
        elif rtype == 'R_PPC_ADDR16_HA':
            val = (target_addr + 0x8000) >> 16
            # Offset points to the halfword within the instruction
            instr_offset = offset & ~1  # Align to halfword boundary
            old = struct.unpack('>H', obj_bytes[offset:offset+2])[0]
            new_val = val & 0xFFFF
            struct.pack_into('>H', obj_bytes, offset, new_val)
        elif rtype == 'R_PPC_ADDR16_LO':
            val = target_addr & 0xFFFF
            old = struct.unpack('>H', obj_bytes[offset:offset+2])[0]
            new_val = val & 0xFFFF
            struct.pack_into('>H', obj_bytes, offset, new_val)

    compiled_hex = obj_bytes[:func_size].hex()

    # Step 6: Extract DOL bytes
    with open(DOL_PATH, 'rb') as f:
        dol = f.read()
    dol_hex = ''
    for i in range(7):
        off = struct.unpack('>I', dol[i*4:i*4+4])[0]
        addr = struct.unpack('>I', dol[0x48+i*4:0x48+i*4+4])[0]
        sz = struct.unpack('>I', dol[0x90+i*4:0x90+i*4+4])[0]
        if addr <= func_addr < addr + sz:
            foff = off + (func_addr - addr)
            dol_raw = dol[foff:foff+func_size]
            dol_hex = ''.join(f'{b:02x}' for b in dol_raw)
            break

    # Step 7: Compare
    for w in warnings:
        print(w)
    print(f"DOL:      {dol_hex}")
    print(f"Compiled: {compiled_hex}")
    print()

    if dol_hex == compiled_hex:
        print(f"MATCH! Function at 0x{func_addr:08X} ({func_size} bytes) matches perfectly.")
        sys.exit(0)
    else:
        diffs = []
        for i in range(0, min(len(dol_hex), len(compiled_hex)), 8):
            d = dol_hex[i:i+8]
            c = compiled_hex[i:i+8]
            if d != c:
                diffs.append(f"  offset 0x{i//2:02X}: DOL={d} compiled={c}")
        print("MISMATCH")
        for d in diffs:
            print(d)

        # Show disassembly for debugging
        r = subprocess.run([OBJDUMP, "-d", obj_path], capture_output=True, text=True)
        print(f"\nCompiled disassembly:\n{r.stdout}")
        sys.exit(1)


if __name__ == '__main__':
    main()
