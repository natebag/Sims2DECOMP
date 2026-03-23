#!/usr/bin/env python3
"""
Extract 129-256 byte leaf functions from asm_decomp and compile them as inline asm
in src/matched/*_asm_leaf_large.cpp files.

Extension of extract_asm_leaf_matches.py targeting larger leaf functions.
Uses stub_classes.h for compilation, with per-file header as fallback.
Handles namespace/template compilation issues by trying multiple header strategies.
"""

import os
import re
import struct
import subprocess
import sys
from pathlib import Path
from collections import defaultdict

REPO = Path(__file__).resolve().parent.parent
DEVKITPPC = Path(r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC")
CXX = str(DEVKITPPC / "bin" / "powerpc-eabi-g++.exe")
OBJDUMP = str(DEVKITPPC / "bin" / "powerpc-eabi-objdump.exe")
DOL = REPO / "extracted" / "sys" / "main.dol"

CXXFLAGS = [
    "-mcpu=750", "-meabi", "-mhard-float", "-O2",
    "-fno-exceptions", "-fno-rtti", "-fno-builtin",
    "-fshort-wchar", "-nostdinc++",
    "-fno-schedule-insns", "-fno-schedule-insns2",
    "-fno-inline", "-fno-inline-small-functions",
    f"-I{REPO}/include", f"-I{REPO}/src",
    f"-I{REPO}/libs/dolphinsdk", f"-I{REPO}/libs/sn_runtime", f"-I{REPO}/libs/apt",
    "-DNDEBUG", "-DEA_PLATFORM_GAMECUBE=1", "-DGEKKO",
    "-fpermissive", "-w",
]


def read_dol():
    with open(DOL, "rb") as f:
        return f.read()


def get_dol_bytes(dol_data, addr, size):
    for i in range(7):
        off = struct.unpack(">I", dol_data[0x00 + i * 4: 0x04 + i * 4])[0]
        load = struct.unpack(">I", dol_data[0x48 + i * 4: 0x4C + i * 4])[0]
        sz = struct.unpack(">I", dol_data[0x90 + i * 4: 0x94 + i * 4])[0]
        if sz > 0 and addr >= load and addr + size <= load + sz:
            file_off = off + (addr - load)
            return dol_data[file_off: file_off + size]
    for i in range(11):
        off = struct.unpack(">I", dol_data[0x1C + i * 4: 0x20 + i * 4])[0]
        load = struct.unpack(">I", dol_data[0x64 + i * 4: 0x68 + i * 4])[0]
        sz = struct.unpack(">I", dol_data[0xAC + i * 4: 0xB0 + i * 4])[0]
        if sz > 0 and addr >= load and addr + size <= load + sz:
            file_off = off + (addr - load)
            return dol_data[file_off: file_off + size]
    return None


def get_compiled_funcs(obj_path):
    result = subprocess.run(
        [OBJDUMP, "-d", str(obj_path)],
        capture_output=True, text=True, timeout=30
    )
    funcs = []
    current_name = None
    current_bytes = bytearray()
    for line in result.stdout.split("\n"):
        fm = re.match(r"^[0-9a-f]+ <(.+)>:", line)
        if fm:
            if current_name and current_bytes:
                funcs.append((current_name, bytes(current_bytes)))
            current_name = fm.group(1)
            current_bytes = bytearray()
            continue
        bm = re.match(r"\s*[0-9a-f]+:\s+((?:[0-9a-f]{2} )+)", line)
        if bm and current_name:
            for b in bm.group(1).strip().split():
                current_bytes.append(int(b, 16))
    if current_name and current_bytes:
        funcs.append((current_name, bytes(current_bytes)))
    return funcs


def is_leaf_function(asm_body):
    """Check if function has no calls (bl, blrl, .long branch)."""
    for line in asm_body.strip().split('\n'):
        stripped = line.strip().strip('"').rstrip('\\n').strip()
        tokens = stripped.split()
        if not tokens:
            continue
        op = tokens[0]
        if op == 'bl' or op == 'blrl':
            return False
        if op == '.long' and '/* bl' in stripped:
            return False
    return True


def has_unsupported_instructions(asm_body):
    """Check if asm uses instructions the assembler can't handle."""
    unsupported = {'vextdubvlx', 'vextddvlx', 'vextduwvlx', 'vinsw',
                   'xsaddsp', 'xxsldwi', 'xsmaddasp', 'xscmpeqdp'}
    for line in asm_body.strip().split('\n'):
        stripped = line.strip().strip('"').rstrip('\\n').strip()
        tokens = stripped.split()
        if not tokens:
            continue
        op = tokens[0]
        if op in unsupported:
            return True
        # Check .long comments for unsupported ops
        if op == '.long':
            for unsup in unsupported:
                if unsup in stripped:
                    return True
    return False


def parse_asm_decomp_file(filepath):
    """Parse an asm_decomp file and extract functions + header."""
    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        content = f.read()

    first_func_idx = content.find('// 0x')
    if first_func_idx < 0:
        return None, []

    header = content[:first_func_idx]

    pattern = r'// (0x[0-9A-Fa-f]+) \((\d+) bytes\)\n// (.+?)\n(?:__attribute__\(\(noreturn\)\)\n)?(.+?)\{([\s\S]*?)\n\}'

    funcs = []
    for m in re.finditer(pattern, content):
        addr = m.group(1)
        size = int(m.group(2))
        comment = m.group(3)
        signature = m.group(4).strip()

        asm_match = re.search(r'__asm__ __volatile__\(\s*\n([\s\S]*?)\n\s*\);', m.group(5))
        if not asm_match:
            continue

        asm_body = asm_match.group(1)

        if not is_leaf_function(asm_body):
            continue

        funcs.append({
            'addr': addr,
            'size': size,
            'comment': comment,
            'signature': signature,
            'asm_body': asm_body,
        })

    return header, funcs


def try_compile(src, tmp_dir):
    """Try to compile source, return (success, obj_path, stderr)."""
    src_path = os.path.join(tmp_dir, "test.cpp")
    obj_path = os.path.join(tmp_dir, "test.o")
    with open(src_path, 'w') as f:
        f.write(src)

    result = subprocess.run(
        [CXX] + CXXFLAGS + ["-c", src_path, "-o", obj_path],
        capture_output=True, text=True, timeout=30
    )
    return result.returncode == 0, obj_path, result.stderr


def build_stub_source(func):
    """Build source using stub_classes.h (handles most cases)."""
    src = '#include "types.h"\n'
    src += '#include "stub_classes.h"\n\n'
    src += f'// {func["addr"]} ({func["size"]} bytes)\n'
    src += f'// {func["comment"]}\n'
    src += '__attribute__((noreturn))\n'
    src += f'{func["signature"]} {{\n'
    src += f'    __asm__ __volatile__(\n{func["asm_body"]}\n    );\n'
    src += '}\n'
    return src


def build_header_source(header, func):
    """Build source using per-file header from asm_decomp."""
    src = '#include "types.h"\n\n'
    src += header + '\n'
    src += f'// {func["addr"]} ({func["size"]} bytes)\n'
    src += f'// {func["comment"]}\n'
    src += '__attribute__((noreturn))\n'
    src += f'{func["signature"]} {{\n'
    src += f'    __asm__ __volatile__(\n{func["asm_body"]}\n    );\n'
    src += '}\n'
    return src


def build_minimal_source(func, extra_decls=""):
    """Build source with minimal declarations for template/complex functions."""
    src = '#include "types.h"\n\n'
    if extra_decls:
        src += extra_decls + '\n\n'
    src += f'// {func["addr"]} ({func["size"]} bytes)\n'
    src += f'// {func["comment"]}\n'
    src += '__attribute__((noreturn))\n'
    src += f'{func["signature"]} {{\n'
    src += f'    __asm__ __volatile__(\n{func["asm_body"]}\n    );\n'
    src += '}\n'
    return src


def simplify_template_sig(sig, comment):
    """Try to simplify template function signatures.

    Template functions like find<int*, int>() or __unguarded_partition<>()
    can be turned into simple void functions since inline asm ignores params.

    Common patterns:
    - "void short * find(short *, short *, short &)" -> invalid (void + short *)
    - "void unsigned int * __unguarded_partition(...)" -> invalid
    - "void EStream & operator(...)" -> invalid
    """
    # Strategy: strip "void" prefix if followed by another type,
    # then replace the complex return type with just "void"

    # Find the function name and params
    # The signature from gen_asm_decomp has pattern: [void] [return_type] funcname(params)
    # We need to extract funcname and params, then rebuild as void funcname(params)

    # Find the outermost opening paren that represents the function parameters.
    # We need to skip past any nested parens in the return type (e.g. function pointers).
    # Strategy: find the paren that belongs to the function name, not nested types.

    # For signatures like "void FamilyImpl ** __unguarded_partition(FamilyImpl **, ...)"
    # the first '(' is the params. But for "void EStream & operator(EStream &, ...)"
    # the first '(' is also the params. So find('(') works for the start.
    paren_idx = sig.find('(')
    if paren_idx < 0:
        return None

    # Find the matching closing paren
    depth = 0
    close_paren_idx = -1
    for i in range(paren_idx, len(sig)):
        if sig[i] == '(':
            depth += 1
        elif sig[i] == ')':
            depth -= 1
            if depth == 0:
                close_paren_idx = i
                break

    if close_paren_idx < 0:
        return None

    # Extract everything before the paren
    prefix = sig[:paren_idx].strip()
    params_str = sig[paren_idx + 1:close_paren_idx].strip()

    # Find function name: last word before paren (could have :: or *)
    # Strip "void " prefix if present
    if prefix.startswith('void '):
        prefix = prefix[5:].strip()

    # For "short * find" -> func name is "find"
    # For "unsigned int * __unguarded_partition" -> func name is "__unguarded_partition"
    # For "EStream & operator" -> func name is "operator"
    # For "FamilyImpl ** __unguarded_partition" -> func name is "__unguarded_partition"

    # Split on spaces and find the actual function name
    # The function name is typically the last token that starts with a letter or _
    tokens = prefix.split()
    func_name = None
    for i in range(len(tokens) - 1, -1, -1):
        t = tokens[i]
        # Skip pointer/ref markers
        if t in ('*', '**', '&'):
            continue
        # Skip type names that precede the function name
        if t[0].isalpha() or t[0] == '_':
            func_name = t
            break

    if not func_name:
        return None

    # For operator<<, the name might be "operator" - check comment
    if func_name == 'operator' and 'operator<<' in comment:
        func_name = 'operator<<'

    # Count params
    if not params_str or params_str == 'void':
        param_count = 0
    else:
        depth = 0
        count = 1
        for c in params_str:
            if c in '(<':
                depth += 1
            elif c in ')>':
                depth -= 1
            elif c == ',' and depth == 0:
                count += 1
        param_count = count

    if param_count == 0:
        new_params = "void"
    else:
        new_params = ", ".join(["int"] * param_count)

    return f"void {func_name}({new_params})"


def get_template_decls(comment):
    """Generate declarations needed for specific template functions."""
    # CBMemberTranslator0 templates
    if 'CBMemberTranslator0<' in comment:
        # Extract the class name from the template
        m = re.match(r'CBMemberTranslator0<(\w+),', comment)
        if m:
            cls_name = m.group(1)
            return (
                f'class UIDialog;\n'
                f'class CBFunctorBase;\n'
                f'class {cls_name};\n'
                f'template <typename T, typename F> class CBMemberTranslator0 {{\n'
                f'public:\n'
                f'    static void thunk(CBFunctorBase &);\n'
                f'}};\n'
            )

    # AllocPoolManager specializations
    if 'AllocPoolManager<' in comment:
        m = re.match(r'AllocPoolManager<(\w+)>::', comment)
        if m:
            pool_type = m.group(1)
            return (
                f'class {pool_type};\n'
                f'template <typename T> class AllocPoolManager {{\n'
                f'public:\n'
                f'    void FindPoolForBlock(void *);\n'
                f'}};\n'
            )

    # TArray specializations
    if 'TArray<' in comment:
        m = re.match(r'TArray<(\w+),\s*(\w+)>::', comment)
        if m:
            elem_type = m.group(1)
            alloc_type = m.group(2)
            return (
                f'class {elem_type};\n'
                f'class {alloc_type};\n'
                f'template <typename T, typename A> class TArray {{\n'
                f'public:\n'
                f'    void Copy(T *, T *, int);\n'
                f'}};\n'
            )

    # _Base_bitset
    if '_Base_bitset<' in comment:
        m = re.match(r'_Base_bitset<(\d+)>::', comment)
        if m:
            n = m.group(1)
            return (
                f'template <int N> class _Base_bitset {{\n'
                f'public:\n'
                f'    void _M_do_find_next(unsigned int, unsigned int) const;\n'
                f'}};\n'
            )

    # EResourceManager nested type
    if 'EResourceManager::ResourceIndexRecord' in comment:
        return (
            'class EResourceManager {\n'
            'public:\n'
            '    class ResourceIndexRecord { public: char _stub_data[256]; };\n'
            '};\n'
        )

    return None


def main():
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument("--generate", action="store_true",
                        help="Write matched functions to _asm_leaf_large.cpp files")
    parser.add_argument("--min-size", type=int, default=129)
    parser.add_argument("--max-size", type=int, default=256)
    parser.add_argument("--file", help="Only process this file")
    parser.add_argument("--verbose", "-v", action="store_true")
    args = parser.parse_args()

    print("=" * 70)
    print("EXTRACT ASM LEAF MATCHES (LARGE: 129-256 bytes)")
    print("=" * 70)

    dol_data = read_dol()
    tmp_dir = str(REPO / "build" / "tmp_convert")
    os.makedirs(tmp_dir, exist_ok=True)

    asm_dir = REPO / "src" / "asm_decomp"
    matched_dir = REPO / "src" / "matched"

    # Check existing matches across ALL matched files
    matched_addrs = set()
    for fname in os.listdir(matched_dir):
        if not fname.endswith('.cpp'):
            continue
        with open(matched_dir / fname, 'r', encoding='utf-8', errors='replace') as f:
            for m in re.finditer(r'// (0x[0-9A-Fa-f]+) \(\d+ bytes\)', f.read()):
                matched_addrs.add(m.group(1))

    print(f"Already matched: {len(matched_addrs)} addresses")
    print(f"Size range: {args.min_size}-{args.max_size} bytes")

    total_new_matches = 0
    total_attempted = 0
    total_compile_fail = 0
    total_size_mismatch = 0
    total_byte_mismatch = 0
    total_skipped_unsupported = 0
    all_matches = defaultdict(list)
    # Track which strategy worked
    match_strategies = defaultdict(dict)

    files = sorted(os.listdir(asm_dir))
    if args.file:
        files = [f for f in files if args.file in f]

    for file_idx, fname in enumerate(files):
        if not fname.endswith('.cpp'):
            continue

        filepath = asm_dir / fname
        result = parse_asm_decomp_file(filepath)
        if result is None or result[0] is None:
            continue

        header, funcs = result

        for func in funcs:
            if func['addr'] in matched_addrs:
                continue
            if func['size'] < args.min_size or func['size'] > args.max_size:
                continue

            # Skip functions with unsupported instructions (e.g. PSMTX paired-single)
            if has_unsupported_instructions(func['asm_body']):
                total_skipped_unsupported += 1
                if args.verbose:
                    print(f"  SKIP (unsupported insn) {func['addr']} {func['comment']}")
                continue

            total_attempted += 1

            # Try multiple compilation strategies
            compiled = False
            strategy_used = None
            obj_path = None
            final_func = dict(func)  # copy for potential sig modifications

            # Strategy 1: stub_classes.h
            src = build_stub_source(func)
            ok, obj_path, stderr = try_compile(src, tmp_dir)
            if ok:
                compiled = True
                strategy_used = "stub"

            # Strategy 2: per-file header
            if not compiled:
                src = build_header_source(header, func)
                ok, obj_path, stderr = try_compile(src, tmp_dir)
                if ok:
                    compiled = True
                    strategy_used = "header"

            # Strategy 3: template-specific declarations
            if not compiled:
                decls = get_template_decls(func['comment'])
                if decls:
                    src = build_minimal_source(func, decls)
                    ok, obj_path, stderr = try_compile(src, tmp_dir)
                    if ok:
                        compiled = True
                        strategy_used = "template"

            # Strategy 4: simplified signature with stub_classes
            if not compiled:
                new_sig = simplify_template_sig(func['signature'], func['comment'])
                if new_sig and new_sig != func['signature']:
                    final_func['signature'] = new_sig
                    src = build_stub_source(final_func)
                    ok, obj_path, stderr = try_compile(src, tmp_dir)
                    if ok:
                        compiled = True
                        strategy_used = "simplified"

            if not compiled:
                total_compile_fail += 1
                if args.verbose:
                    print(f"  FAIL {func['addr']} {func['comment']}")
                    for line in stderr.split('\n'):
                        if 'error:' in line:
                            print(f"       {line.strip()[:100]}")
                            break
                continue

            # Get DOL bytes
            dol_bytes = get_dol_bytes(dol_data, int(func['addr'], 16), func['size'])
            if dol_bytes is None:
                continue

            # Get compiled bytes
            compiled_funcs = get_compiled_funcs(obj_path)
            matched = False
            for name, fbytes in compiled_funcs:
                if len(fbytes) == func['size'] and fbytes == dol_bytes:
                    matched = True
                    break

            if matched:
                total_new_matches += 1
                all_matches[fname].append(final_func)
                match_strategies[fname][func['addr']] = strategy_used
                if total_new_matches <= 30 or total_new_matches % 50 == 0:
                    print(f"  [{total_new_matches:4d}] {func['addr']} ({func['size']:3d}B) [{strategy_used}] {func['comment']}")
            else:
                for name, fbytes in compiled_funcs:
                    if len(fbytes) == func['size']:
                        total_byte_mismatch += 1
                        if args.verbose:
                            print(f"  BYTE MISMATCH {func['addr']} ({func['size']}B) {func['comment']}")
                        break
                else:
                    total_size_mismatch += 1
                    if args.verbose:
                        expected = func['size']
                        got = [len(fb) for _, fb in compiled_funcs]
                        print(f"  SIZE MISMATCH {func['addr']} expected={expected} got={got} {func['comment']}")

        if (file_idx + 1) % 100 == 0:
            print(f"  Files: {file_idx+1}/{len(files)}, Matches: {total_new_matches}")

    print(f"\n{'=' * 70}")
    print(f"Results:")
    print(f"  Attempted:            {total_attempted}")
    print(f"  Matched:              {total_new_matches}")
    print(f"  Compile fails:        {total_compile_fail}")
    print(f"  Size mismatch:        {total_size_mismatch}")
    print(f"  Byte mismatch:        {total_byte_mismatch}")
    print(f"  Skipped (unsupported):{total_skipped_unsupported}")
    print(f"{'=' * 70}")

    if args.generate and total_new_matches > 0:
        print("\nWriting matched files...")
        total_written = 0
        total_bytes_written = 0

        for fname, funcs in sorted(all_matches.items()):
            base = fname.replace('.cpp', '')
            out_path = matched_dir / f"{base}_asm_leaf_large.cpp"

            total_bytes = sum(f['size'] for f in funcs)

            # Determine if any func used template/simplified strategy
            strategies_used = set()
            for f in funcs:
                s = match_strategies[fname].get(f['addr'], 'stub')
                strategies_used.add(s)

            with open(out_path, 'w') as f:
                f.write('#include "types.h"\n')

                # If any functions used template decls, include those
                # Otherwise use stub_classes.h
                needs_template_decls = False
                template_decls_set = set()
                for func_info in funcs:
                    strat = match_strategies[fname].get(func_info['addr'])
                    if strat == 'template':
                        decl = get_template_decls(func_info['comment'])
                        if decl:
                            needs_template_decls = True
                            template_decls_set.add(decl)

                if needs_template_decls:
                    # Write template decls only for those funcs, use stub for rest
                    f.write('#include "stub_classes.h"\n')
                    f.write(f'// Inline asm leaf matches (large {args.min_size}-{args.max_size}B) for {base}\n')
                    f.write(f'// {len(funcs)} functions, {total_bytes} bytes\n\n')
                    for decl in sorted(template_decls_set):
                        f.write(decl + '\n')
                else:
                    f.write('#include "stub_classes.h"\n')
                    f.write(f'// Inline asm leaf matches (large {args.min_size}-{args.max_size}B) for {base}\n')
                    f.write(f'// {len(funcs)} functions, {total_bytes} bytes\n\n')

                for func_info in funcs:
                    f.write(f'// {func_info["addr"]} ({func_info["size"]} bytes)\n')
                    f.write(f'// {func_info["comment"]}\n')
                    f.write('__attribute__((noreturn))\n')
                    f.write(f'{func_info["signature"]} {{\n')
                    f.write(f'    __asm__ __volatile__(\n{func_info["asm_body"]}\n    );\n')
                    f.write('}\n\n')

                total_written += len(funcs)
                total_bytes_written += total_bytes

            print(f"  {out_path.name}: {len(funcs)} functions ({total_bytes}B)")

        print(f"\nTotal written: {total_written} functions across {len(all_matches)} files")
        print(f"Total bytes:   {total_bytes_written}")

    return total_new_matches


if __name__ == "__main__":
    main()
