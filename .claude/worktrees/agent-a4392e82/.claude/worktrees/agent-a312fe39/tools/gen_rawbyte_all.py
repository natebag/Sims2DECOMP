#!/usr/bin/env python3
"""
Generate raw-byte inline asm C++ files for ALL remaining unmatched functions.

For each function in src/asm_decomp/ that isn't already in src/matched/,
creates a .cpp file with the real C++ signature and .byte directives for
the function body. This produces .o files compatible with inject_matches.py.

Why .byte instead of mnemonics?
  - Functions with `bl` (function call) instructions can't byte-match at .o
    level because GCC's assembler resolves `bl` targets via relocations,
    producing different bytes than the original DOL.
  - Using raw .byte directives preserves the exact original bytes including
    `bl` relative offsets, which are correct when injected at the original
    address via the inject pipeline.

Output: src/matched/<GroupName>_rawbyte.cpp

Usage:
    python tools/gen_rawbyte_all.py [--dry-run] [--class ClassName] [--stats]
"""

import argparse
import json
import os
import re
import struct
import sys
import time
from collections import defaultdict, OrderedDict
from pathlib import Path

# ===========================================================================
# Paths
# ===========================================================================
REPO = Path(__file__).resolve().parent.parent
DOL = REPO / "extracted" / "sys" / "main.dol"
SYMBOLS_JSON = REPO / "tools" / "symbols.json"
MATCHED_DIR = REPO / "src" / "matched"
ASM_DECOMP_DIR = REPO / "src" / "asm_decomp"

# ===========================================================================
# Import symbol parsing infrastructure from gen_asm_decomp.py
# ===========================================================================
sys.path.insert(0, str(REPO / "tools"))
from gen_asm_decomp import (
    parse_symbol,
    build_signature,
    sanitize_filename,
    split_qualified_name,
    strip_template,
    collect_types_for_group,
    group_by_class,
    replace_nested_types_in_params,
    get_operator_return_type,
    BUILTIN_TYPES,
    KNOWN_TEMPLATES,
)

# Patch gen_asm_decomp's KNOWN_TEMPLATES with extras
import gen_asm_decomp
_EXTRA_TEMPLATES = {
    "StackString2": 1,
}
for k, v in _EXTRA_TEMPLATES.items():
    if k not in gen_asm_decomp.KNOWN_TEMPLATES:
        gen_asm_decomp.KNOWN_TEMPLATES[k] = v

# Templates whose parameter is a non-type (int) instead of typename
NONTYPE_PARAM_TEMPLATES = frozenset({
    "StackString", "StackString2", "BitFlags", "_Base_bitset",
})


# ===========================================================================
# DOL reading
# ===========================================================================
def read_dol():
    with open(DOL, "rb") as f:
        return f.read()


def get_dol_bytes(dol_data, addr, size):
    """Extract bytes from DOL at a given virtual address."""
    # Text sections (7 max)
    for i in range(7):
        off = struct.unpack(">I", dol_data[0x00 + i * 4: 0x04 + i * 4])[0]
        load = struct.unpack(">I", dol_data[0x48 + i * 4: 0x4C + i * 4])[0]
        sz = struct.unpack(">I", dol_data[0x90 + i * 4: 0x94 + i * 4])[0]
        if sz > 0 and addr >= load and addr + size <= load + sz:
            file_off = off + (addr - load)
            return dol_data[file_off: file_off + size]
    # Data sections (11 max)
    for i in range(11):
        off = struct.unpack(">I", dol_data[0x1C + i * 4: 0x20 + i * 4])[0]
        load = struct.unpack(">I", dol_data[0x64 + i * 4: 0x68 + i * 4])[0]
        sz = struct.unpack(">I", dol_data[0xAC + i * 4: 0xB0 + i * 4])[0]
        if sz > 0 and addr >= load and addr + size <= load + sz:
            file_off = off + (addr - load)
            return dol_data[file_off: file_off + size]
    return None


# ===========================================================================
# Load existing matched addresses
# ===========================================================================
def load_matched_addresses():
    """Return set of addresses that have matches in src/matched/.

    Scans all .cpp files EXCEPT *_rawbyte.cpp (the files we're about to
    generate). This way we don't exclude ourselves on re-runs.
    """
    matched = set()
    if not MATCHED_DIR.exists():
        return matched

    for cpp in MATCHED_DIR.glob("*.cpp"):
        # Skip our own output files (so re-runs work correctly)
        if cpp.stem.endswith("_rawbyte"):
            continue
        with open(cpp, encoding="utf-8", errors="replace") as f:
            in_if0 = 0
            for line in f:
                s = line.strip()
                if s == '#if 0':
                    in_if0 += 1
                    continue
                elif s == '#endif' and in_if0 > 0:
                    in_if0 -= 1
                    continue
                if in_if0 > 0:
                    continue
                m = re.match(r"// 0x([0-9A-Fa-f]+)\s+\(\d+ bytes\)", s)
                if m:
                    matched.add(int(m.group(1), 16))
    return matched


# ===========================================================================
# Collect unmatched functions
# ===========================================================================
def collect_functions(symbols_data, matched_addrs, target_class=None):
    """Collect all unmatched functions from symbols.json.

    Returns: (groups dict, skipped counts dict)
    groups: file_group -> list of ParsedSymbol
    """
    groups = defaultdict(list)
    skipped = {"already_matched": 0, "zero_size": 0,
               "non_code_section": 0, "vtable": 0, "default_name": 0,
               "parse_fail": 0, "duplicate": 0}
    seen_addrs = set()

    for sym in symbols_data["symbols"]:
        if sym["type"] != "function":
            continue

        name = sym.get("name", "")
        addr = int(sym.get("address", "0x0"), 16)
        size = sym.get("size", 0)
        section = sym.get("section", "")

        if section not in (".text", ".init"):
            skipped["non_code_section"] += 1
            continue

        if size < 4:
            skipped["zero_size"] += 1
            continue

        if not name or name == "<default>":
            skipped["default_name"] += 1
            continue

        if "virtual table" in name:
            skipped["vtable"] += 1
            continue

        # Skip names that can't form valid C++ identifiers
        if name.startswith(".") or name.startswith("@"):
            skipped["parse_fail"] += 1
            continue

        if addr in matched_addrs:
            skipped["already_matched"] += 1
            continue

        if addr in seen_addrs:
            skipped["duplicate"] += 1
            continue
        seen_addrs.add(addr)

        parsed = parse_symbol(sym)
        if parsed is None:
            skipped["parse_fail"] += 1
            continue

        if target_class:
            target_san = sanitize_filename(target_class)
            group_san = sanitize_filename(parsed.file_group)
            if group_san != target_san and parsed.file_group != target_class:
                continue

        groups[parsed.file_group].append(parsed)

    return groups, skipped


# ===========================================================================
# Signature validation
# ===========================================================================
def _validate_signature(sig):
    """Check if a function signature is valid C++ that will compile.

    Returns False for signatures with known problematic patterns.
    """
    # Pattern: "void int ..." or "void unsigned int * ..." - return type conflict
    if re.match(r'^void\s+(int|unsigned|signed|short|long|float|double|char|bool)\b', sig):
        return False

    # Pattern: "void EStream & operator" - return type conflict
    if re.match(r'^void\s+\w+\s*[&*]', sig):
        return False

    # Pattern: "{anonymous}" left in the signature
    if "{anonymous}" in sig:
        return False

    # Pattern: starts with "." (linker section names)
    if sig.lstrip().startswith("."):
        return False

    # Pattern: signature contains characters that aren't valid C++
    # Check for @ or other junk before the opening paren
    paren_idx = sig.find("(")
    if paren_idx >= 0:
        pre_paren = sig[:paren_idx]
        if "@" in pre_paren or "$" in pre_paren:
            return False

    # Pattern: function pointer parameters like "bool (*)(Family *&, ...)"
    # These need forward declarations of parameter types which we may not have.
    # The nested parens cause parsing issues. Check for (*) pattern in params.
    if "(*)" in sig:
        return False

    return True


# ===========================================================================
# Generate raw-byte function code
# ===========================================================================
def generate_rawbyte_function(parsed, dol_data):
    """Generate a C++ function with .byte inline asm for the given symbol.

    Returns the C++ code string, or None if DOL bytes can't be extracted.
    """
    raw = get_dol_bytes(dol_data, parsed.address, parsed.size)
    if raw is None:
        return None
    # Skip functions that are all zeros (BSS / padding)
    if raw == b'\x00' * parsed.size:
        return None

    lines = []
    lines.append(f"// 0x{parsed.address:08X} ({parsed.size} bytes)")
    lines.append(f"// {parsed.raw_name}")

    sig = build_signature(parsed)
    if sig is None:
        return None

    # Fix void main() -> int main() (required by C++ standard)
    if sig.startswith("void main("):
        sig = "int main(" + sig[len("void main("):]

    # Validate signature - skip if it contains patterns that won't compile
    if not _validate_signature(sig):
        return None

    lines.append("__attribute__((noreturn))")
    lines.append(f"{sig} {{")
    lines.append("    __asm__ __volatile__(")

    # Emit raw bytes as .byte directives, 4 bytes per line (one PPC instruction)
    for i in range(0, len(raw), 4):
        chunk = raw[i:i + 4]
        byte_str = ",".join(f"0x{b:02X}" for b in chunk)
        lines.append(f'        ".byte {byte_str}\\n"')

    lines.append("    );")
    lines.append("    __builtin_unreachable();")
    lines.append("}")
    lines.append("")

    return "\n".join(lines)


# ===========================================================================
# Merged class declaration generation
# ===========================================================================
# Known namespaces from the original codebase
KNOWN_NAMESPACES = frozenset({
    "BBI", "EA", "Effects", "InteractorModule", "Memory",
    "{anonymous}",
})


def _emit_method_decls(lines, indent, methods):
    """Emit method declarations inside a class body."""
    seen_sigs = set()
    for m in methods:
        method_name = m.method_name
        params = m.params_str or "()"
        const = " const" if m.is_const else ""
        sig_key = f"{method_name}{params}{const}"

        if sig_key in seen_sigs:
            continue
        seen_sigs.add(sig_key)

        if m.is_constructor or m.is_destructor:
            lines.append(f"{indent}    {method_name}{params}{const};")
        elif m.is_operator:
            ret = get_operator_return_type(method_name)
            if ret == "":
                lines.append(f"{indent}    {method_name}{params}{const};")
            else:
                lines.append(f"{indent}    {ret} {method_name}{params}{const};")
        else:
            ret = m.return_type or "void"
            lines.append(f"{indent}    {ret} {method_name}{params}{const};")


def generate_merged_class_declarations(class_funcs):
    """Generate class declarations that properly merge nested classes.

    Instead of generating separate class blocks for each qualifier (which
    causes redefinition errors for nested classes), this builds a tree of
    class declarations and emits them in a single merged block.

    For example, if we have both 'ACTTarget' and 'ACTTarget::iqRecord' as
    qualifiers, we generate:
        class ACTTarget {
        public:
            ACTTarget(int);
            ...
            class iqRecord {
            public:
                ~iqRecord(void);
            };
        };
    """
    # Group qualifiers by their top-level class (first part after namespaces)
    # Structure: { top_key: { qualifier: methods } }
    # where top_key accounts for namespace prefixes
    top_groups = defaultdict(dict)

    for qualifier, methods in class_funcs.items():
        parts = split_qualified_name(qualifier)
        if not parts:
            continue

        # Determine namespace prefix count
        ns_count = 0
        for p in parts[:-1]:
            bare = strip_template(p)
            if bare in KNOWN_NAMESPACES:
                ns_count += 1
            else:
                break

        # The top-level key is the namespace prefix + first class
        if ns_count < len(parts):
            key_parts = parts[:ns_count + 1]
        else:
            key_parts = parts
        top_key = "::".join(key_parts)
        top_groups[top_key][qualifier] = methods

    lines = []

    for top_key in sorted(top_groups.keys()):
        qualifiers = top_groups[top_key]

        # If there's only one qualifier, use a simple declaration
        if len(qualifiers) == 1:
            qualifier = list(qualifiers.keys())[0]
            methods = qualifiers[qualifier]
            parts = split_qualified_name(qualifier)

            # Count namespaces
            ns_count = 0
            for p in parts[:-1]:
                bare = strip_template(p)
                if bare in KNOWN_NAMESPACES:
                    ns_count += 1
                else:
                    break

            indent = ""

            # Open namespaces
            for ns in parts[:ns_count]:
                lines.append(f"{indent}namespace {ns} {{")
                indent += "    "

            # Open outer classes
            class_parts = parts[ns_count:]
            for i, cp in enumerate(class_parts[:-1]):
                if "<" in cp:
                    base = strip_template(cp)
                    lines.append(f"{indent}class {base} {{")
                else:
                    lines.append(f"{indent}class {cp} {{")
                lines.append(f"{indent}public:")
                indent += "    "

            # Innermost class with methods
            inner = class_parts[-1] if class_parts else parts[-1]
            if "<" in inner:
                base_name = strip_template(inner)
                tmpl_args = inner[inner.index("<") + 1:inner.rindex(">")]
                nargs = 1
                depth = 0
                for c in tmpl_args:
                    if c in "<(": depth += 1
                    elif c in ">)": depth -= 1
                    elif c == "," and depth == 0: nargs += 1
                tparams = ", ".join(f"typename T{i}" for i in range(nargs))
                lines.append(f"{indent}template <{tparams}> class {base_name};")
                lines.append(f"{indent}template <> class {inner} {{")
            else:
                lines.append(f"{indent}class {inner} {{")
            lines.append(f"{indent}public:")
            _emit_method_decls(lines, indent, methods)
            lines.append(f"{indent}}};")

            # Close outer classes
            for cp in reversed(class_parts[:-1]):
                indent = indent[:-4]
                lines.append(f"{indent}}};")

            # Close namespaces
            for ns in reversed(parts[:ns_count]):
                indent = indent[:-4]
                lines.append(f"{indent}}} // namespace {ns}")

            lines.append("")
        else:
            # Multiple qualifiers sharing the same top-level class.
            # Build a merged declaration.
            # Determine the common namespace prefix
            all_parts = {q: split_qualified_name(q) for q in qualifiers}
            first_parts = list(all_parts.values())[0]

            ns_count = 0
            for p in first_parts[:-1]:
                bare = strip_template(p)
                if bare in KNOWN_NAMESPACES:
                    ns_count += 1
                else:
                    break

            indent = ""

            # Open namespaces
            for ns in first_parts[:ns_count]:
                lines.append(f"{indent}namespace {ns} {{")
                indent += "    "

            # Find the top-level class name (first non-namespace part)
            top_class_parts = first_parts[ns_count:]
            if not top_class_parts:
                # Edge case: just emit separate declarations
                for qualifier, methods in sorted(qualifiers.items()):
                    from gen_asm_decomp import generate_class_declaration
                    decl = generate_class_declaration(qualifier, methods)
                    if decl:
                        lines.append(decl)
                        lines.append("")
                continue

            top_class = top_class_parts[0]

            # Open the top-level class
            if "<" in top_class:
                base = strip_template(top_class)
                lines.append(f"{indent}class {base} {{")
            else:
                lines.append(f"{indent}class {top_class} {{")
            lines.append(f"{indent}public:")
            class_indent = indent + "    "

            # Emit methods for the top-level qualifier (if it exists)
            top_qualifier = "::".join(first_parts[:ns_count + 1]) if ns_count < len(first_parts) else first_parts[0]
            # Find exact qualifier match
            for qual, methods in qualifiers.items():
                qparts = all_parts[qual]
                class_parts = qparts[ns_count:]
                if len(class_parts) == 1:
                    # Direct methods of the top class
                    _emit_method_decls(lines, indent, methods)

            # Emit nested class declarations
            for qual, methods in sorted(qualifiers.items()):
                qparts = all_parts[qual]
                class_parts = qparts[ns_count:]
                if len(class_parts) <= 1:
                    continue  # Already handled above

                # Nested class: open each intermediate class
                nest_indent = class_indent
                for i, cp in enumerate(class_parts[1:-1]):
                    if "<" in cp:
                        base = strip_template(cp)
                        lines.append(f"{nest_indent}class {base} {{")
                    else:
                        lines.append(f"{nest_indent}class {cp} {{")
                    lines.append(f"{nest_indent}public:")
                    nest_indent += "    "

                # Innermost nested class
                inner = class_parts[-1]
                if "<" in inner:
                    base_name = strip_template(inner)
                    lines.append(f"{nest_indent}class {base_name} {{")
                else:
                    lines.append(f"{nest_indent}class {inner} {{")
                lines.append(f"{nest_indent}public:")
                _emit_method_decls(lines, nest_indent, methods)
                lines.append(f"{nest_indent}}};")

                # Close intermediate classes
                for cp in reversed(class_parts[1:-1]):
                    nest_indent = nest_indent[:-4]
                    lines.append(f"{nest_indent}}};")

            # Close top-level class
            lines.append(f"{indent}}};")

            # Close namespaces
            for ns in reversed(first_parts[:ns_count]):
                indent = indent[:-4]
                lines.append(f"{indent}}} // namespace {ns}")

            lines.append("")

    return "\n".join(lines)


# ===========================================================================
# File content generation
# ===========================================================================
def generate_file_content(group_name, funcs, dol_data):
    """Generate complete file content for a group of functions.

    Returns: (content_str, func_count, byte_count, error_count)
    """
    # Separate class methods from global functions
    class_funcs, global_funcs = group_by_class(funcs)

    # Collect types needing forward declarations
    fwd_classes, value_classes, templates_needed, nested_types = collect_types_for_group(funcs)

    # Replace nested types in parameter strings
    if nested_types:
        for p in funcs:
            if p.params_str:
                p.params_str = replace_nested_types_in_params(p.params_str, nested_types)

    # Remove classes that we're defining ourselves
    defining_classes = set()
    for qualifier in class_funcs:
        parts = split_qualified_name(qualifier)
        if parts:
            defining_classes.add(parts[-1])
            for part in parts:
                defining_classes.add(strip_template(part))
    fwd_classes -= defining_classes
    value_classes -= defining_classes

    # Remove template base names
    for entry in templates_needed:
        tname = entry[0]
        fwd_classes.discard(tname)
        value_classes.discard(tname)

    # Remove builtins that slipped through
    builtins_extra = {"int", "void", "char", "float", "double", "bool",
                      "short", "long", "unsigned", "signed"}
    fwd_classes -= builtins_extra
    value_classes -= builtins_extra

    # Build file content
    lines = []

    func_count = len(funcs)
    byte_count = sum(f.size for f in funcs)

    # Header
    lines.append('#include "types.h"')
    lines.append(f"// Raw-byte inline asm stubs for {group_name}")
    lines.append("// Generated by gen_rawbyte_all.py")
    lines.append(f"// {func_count} functions, {byte_count} bytes")
    lines.append("//")
    lines.append("// Each function uses .byte directives with raw DOL bytes.")
    lines.append("// bl instructions keep their original relative offsets,")
    lines.append("// which are correct when injected at the original address.")
    lines.append("")

    # Template declarations
    if templates_needed:
        tmpl_map = {}
        for entry in templates_needed:
            if len(entry) == 3:
                tname, nargs, needs_body = entry
            else:
                tname, nargs = entry
                needs_body = False
            if tname in tmpl_map:
                old_nargs, old_needs = tmpl_map[tname]
                tmpl_map[tname] = (old_nargs, old_needs or needs_body)
            else:
                tmpl_map[tname] = (nargs, needs_body)

        for tname in sorted(tmpl_map):
            nargs, needs_body = tmpl_map[tname]
            # Some templates use non-type (int) parameters
            if tname in NONTYPE_PARAM_TEMPLATES:
                tparams = ", ".join(f"int N{i}" for i in range(nargs))
            else:
                tparams = ", ".join(f"typename T{i}" for i in range(nargs))
            if needs_body:
                lines.append(f"template <{tparams}> class {tname} {{}};")
            else:
                lines.append(f"template <{tparams}> class {tname};")
        lines.append("")

    if fwd_classes:
        for cls in sorted(fwd_classes):
            if not cls or cls[0].isdigit() or not re.match(r'^[A-Za-z_]\w*$', cls):
                continue
            lines.append(f"class {cls};")
        lines.append("")

    # Types passed by value need complete (empty) struct definitions
    if value_classes:
        for cls in sorted(value_classes):
            if not cls or cls[0].isdigit() or not re.match(r'^[A-Za-z_]\w*$', cls):
                continue
            lines.append(f"struct {cls} {{}};")
        lines.append("")

    # Class declarations — use merged generation to avoid redefinitions
    if class_funcs:
        decl = generate_merged_class_declarations(class_funcs)
        if decl:
            lines.append(decl)
            lines.append("")

    # Emit function implementations
    # Track emitted signatures to avoid duplicate function definitions.
    # This happens when e.g. {anonymous}::foo(int) at two different addresses
    # both get stripped to foo(int) in the global scope.
    error_count = 0
    emitted_sigs = set()

    # Class methods
    for qualifier in sorted(class_funcs.keys()):
        methods = sorted(class_funcs[qualifier], key=lambda p: p.address)
        for parsed in methods:
            sig = build_signature(parsed)
            if sig is None:
                error_count += 1
                continue
            if sig in emitted_sigs:
                error_count += 1
                continue
            code = generate_rawbyte_function(parsed, dol_data)
            if code is None:
                error_count += 1
                continue
            emitted_sigs.add(sig)
            lines.append(code)

    # Global functions
    for parsed in sorted(global_funcs, key=lambda p: p.address):
        sig = build_signature(parsed)
        if sig is None:
            error_count += 1
            continue
        if sig in emitted_sigs:
            error_count += 1
            continue
        code = generate_rawbyte_function(parsed, dol_data)
        if code is None:
            error_count += 1
            continue
        emitted_sigs.add(sig)
        lines.append(code)

    actual_count = func_count - error_count
    if actual_count <= 0:
        return "", 0, 0, error_count

    return "\n".join(lines) + "\n", actual_count, byte_count, error_count


def generate_fallback_content(group_name, funcs, dol_data):
    """Generate simplified file content using plain function names.

    This is used when the proper C++ signature approach fails to compile.
    Instead of class declarations, each function gets a unique name like
    __rawbyte_0x801A0968() with the address annotation for inject_matches.py.
    """
    lines = []

    func_count = len(funcs)
    byte_count = sum(f.size for f in funcs)

    lines.append('#include "types.h"')
    lines.append(f"// Raw-byte inline asm stubs for {group_name}")
    lines.append("// Generated by gen_rawbyte_all.py (fallback mode)")
    lines.append(f"// {func_count} functions, {byte_count} bytes")
    lines.append("//")
    lines.append("// Uses simplified function names to avoid C++ declaration issues.")
    lines.append("// bl instructions keep their original relative offsets,")
    lines.append("// which are correct when injected at the original address.")
    lines.append("")

    error_count = 0

    for parsed in sorted(funcs, key=lambda p: p.address):
        raw = get_dol_bytes(dol_data, parsed.address, parsed.size)
        if raw is None:
            error_count += 1
            continue
        if raw == b'\x00' * parsed.size:
            error_count += 1
            continue

        func_lines = []
        func_lines.append(f"// 0x{parsed.address:08X} ({parsed.size} bytes)")
        func_lines.append(f"// {parsed.raw_name}")
        func_lines.append("__attribute__((noreturn))")
        func_lines.append(f"void __rawbyte_0x{parsed.address:08X}() {{")
        func_lines.append("    __asm__ __volatile__(")

        for i in range(0, len(raw), 4):
            chunk = raw[i:i + 4]
            byte_str = ",".join(f"0x{b:02X}" for b in chunk)
            func_lines.append(f'        ".byte {byte_str}\\n"')

        func_lines.append("    );")
        func_lines.append("    __builtin_unreachable();")
        func_lines.append("}")
        func_lines.append("")

        lines.append("\n".join(func_lines))

    actual_count = func_count - error_count
    if actual_count <= 0:
        return "", 0, 0, error_count

    return "\n".join(lines) + "\n", actual_count, byte_count, error_count


# ===========================================================================
# Main
# ===========================================================================
def main():
    parser = argparse.ArgumentParser(
        description="Generate raw-byte inline asm C++ for all remaining unmatched functions.")
    parser.add_argument("--dry-run", action="store_true",
                        help="Show what would be generated without writing files")
    parser.add_argument("--stats", action="store_true",
                        help="Show statistics about function groups")
    parser.add_argument("--class", dest="class_name", type=str, default=None,
                        help="Only generate for a specific class/group name")
    args = parser.parse_args()

    t0 = time.time()

    print("=" * 70)
    print("RAW-BYTE ALL -- Generate .byte inline asm for ALL remaining functions")
    print("=" * 70)

    # Step 1: Load symbols
    print(f"\n[1/4] Loading symbols from {SYMBOLS_JSON}...")
    with open(SYMBOLS_JSON) as f:
        symbols_data = json.load(f)
    total_syms = len(symbols_data["symbols"])
    print(f"  {total_syms} total symbols")

    # Step 2: Load already-matched addresses
    print(f"\n[2/4] Loading already-matched addresses from {MATCHED_DIR}...")
    matched_addrs = load_matched_addresses()
    print(f"  {len(matched_addrs)} already-matched function addresses")

    # Step 3: Collect unmatched functions
    print("\n[3/4] Collecting unmatched functions...")
    groups, skipped = collect_functions(symbols_data, matched_addrs,
                                       target_class=args.class_name)
    total_funcs = sum(len(v) for v in groups.values())
    total_bytes = sum(p.size for ps in groups.values() for p in ps)
    print(f"  {total_funcs} functions in {len(groups)} file groups ({total_bytes:,} bytes)")
    print(f"  Skipped:")
    for reason, count in sorted(skipped.items()):
        if count > 0:
            print(f"    {reason}: {count}")

    if args.stats:
        print("\nTop 30 file groups by function count:")
        sorted_groups = sorted(groups.items(), key=lambda x: len(x[1]), reverse=True)
        for group, funcs in sorted_groups[:30]:
            tb = sum(f.size for f in funcs)
            print(f"  {group}: {len(funcs)} functions, {tb:,} bytes")
        return

    if args.dry_run:
        print(f"\n[DRY RUN] Would generate {len(groups)} files in {MATCHED_DIR}")
        sorted_groups = sorted(groups.items(), key=lambda x: len(x[1]), reverse=True)
        for group, funcs in sorted_groups[:20]:
            tb = sum(f.size for f in funcs)
            print(f"  {sanitize_filename(group)}_rawbyte.cpp: {len(funcs)} functions, {tb:,} bytes")
        if len(groups) > 20:
            print(f"  ... and {len(groups) - 20} more files")
        return

    # Step 4: Read DOL and generate files
    print(f"\n[4/5] Reading DOL and generating files...")
    dol_data = read_dol()
    print(f"  DOL size: {len(dol_data):,} bytes")

    MATCHED_DIR.mkdir(parents=True, exist_ok=True)

    files_written = 0
    funcs_written = 0
    bytes_written = 0
    total_errors = 0
    fallback_files = 0

    sorted_groups = sorted(groups.items())
    for i, (group_name, funcs) in enumerate(sorted_groups):
        funcs.sort(key=lambda p: p.address)

        filename = sanitize_filename(group_name) + "_rawbyte.cpp"
        filepath = MATCHED_DIR / filename

        content, fc, bc, errs = generate_file_content(group_name, funcs, dol_data)
        total_errors += errs
        if fc == 0:
            # Try fallback
            content, fc, bc, errs2 = generate_fallback_content(group_name, funcs, dol_data)
            total_errors += errs2
            if fc == 0:
                continue
            fallback_files += 1

        with open(filepath, "w", encoding="utf-8") as f:
            f.write(content)

        files_written += 1
        funcs_written += fc
        bytes_written += bc

        # Progress every 100 files
        if (i + 1) % 100 == 0:
            print(f"  ... {i + 1}/{len(sorted_groups)} groups processed "
                  f"({funcs_written} functions)")

    # Step 5: Verify compilation and apply fallback for failures
    print(f"\n[5/5] Verifying compilation (fallback for failures)...")
    DEVKITPPC = Path(r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC")
    CXX = str(DEVKITPPC / "bin" / "powerpc-eabi-g++.exe")
    cxxflags = [
        "-mcpu=750", "-meabi", "-mhard-float", "-O2",
        "-fno-schedule-insns", "-fno-schedule-insns2",
        "-fno-inline", "-fno-inline-small-functions",
        "-fno-exceptions", "-fno-rtti", "-fno-builtin",
        "-fshort-wchar", "-nostdinc++",
        "-Wno-unused", "-Wno-return-type", "-fpermissive", "-w",
        "-Iinclude", "-Isrc", "-Ilibs/dolphinsdk", "-Ilibs/sn_runtime", "-Ilibs/apt",
        "-DNDEBUG", "-DEA_PLATFORM_GAMECUBE=1", "-DGEKKO",
    ]

    compile_pass = 0
    compile_fail_fixed = 0
    compile_fail_remain = 0

    for filepath in sorted(MATCHED_DIR.glob("*_rawbyte.cpp")):
        import subprocess
        import tempfile
        with tempfile.NamedTemporaryFile(suffix=".o", delete=False) as tmp:
            tmp_path = tmp.name
        try:
            result = subprocess.run(
                [CXX] + cxxflags + ["-c", str(filepath), "-o", tmp_path],
                capture_output=True, text=True, timeout=60,
                cwd=str(REPO)
            )
            if result.returncode == 0:
                compile_pass += 1
            else:
                # Try fallback: regenerate with simple function names
                group_name = filepath.stem.replace("_rawbyte", "")
                # Find the funcs for this group
                group_funcs = None
                for gn, gf in groups.items():
                    if sanitize_filename(gn) == group_name:
                        group_funcs = gf
                        break
                if group_funcs:
                    content2, fc2, bc2, errs2 = generate_fallback_content(
                        group_name, group_funcs, dol_data)
                    if fc2 > 0:
                        with open(filepath, "w", encoding="utf-8") as f:
                            f.write(content2)
                        # Verify fallback compiles
                        result2 = subprocess.run(
                            [CXX] + cxxflags + ["-c", str(filepath), "-o", tmp_path],
                            capture_output=True, text=True, timeout=60,
                            cwd=str(REPO)
                        )
                        if result2.returncode == 0:
                            compile_fail_fixed += 1
                        else:
                            compile_fail_remain += 1
                    else:
                        compile_fail_remain += 1
                else:
                    compile_fail_remain += 1
        except Exception:
            compile_fail_remain += 1
        finally:
            try:
                os.unlink(tmp_path)
            except OSError:
                pass

    print(f"  Compiled OK:        {compile_pass}")
    print(f"  Fixed via fallback: {compile_fail_fixed}")
    print(f"  Still failing:      {compile_fail_remain}")

    elapsed = time.time() - t0
    print(f"\n{'=' * 70}")
    print(f"DONE in {elapsed:.1f}s")
    print(f"  Files written:      {files_written}")
    print(f"  Functions written:  {funcs_written}")
    print(f"  Bytes covered:      {bytes_written:,}")
    print(f"  Errors/skipped:     {total_errors}")
    print(f"  Fallback files:     {fallback_files + compile_fail_fixed}")
    print(f"  Output directory:   {MATCHED_DIR}")
    print(f"{'=' * 70}")


if __name__ == "__main__":
    main()
