#!/usr/bin/env python3
"""
Generate inline-asm C++ files for ALL unmatched functions.

Reads symbols.json for every function in .text/.init, skips functions that
already have matches (in src/matched/), and generates C++ files with proper
function signatures + inline asm bodies into src/asm_decomp/.

Each function gets a proper C++ class/method signature with the body
implemented as inline asm matching the original instructions:

    // 0x800A9270 (76 bytes)
    __attribute__((noreturn))
    AmbientSoundPlayer::AmbientSoundPlayer() {
        __asm__ __volatile__(
            "lis\\tr11,-32706\\n"
            "mr\\tr9,r3\\n"
            ...
            "blr\\n"
        );
        __builtin_unreachable();
    }

Functions are grouped by class into files like:
    src/asm_decomp/ESimsApp.cpp
    src/asm_decomp/BBI_InventoryItem.cpp
    src/asm_decomp/__global__.cpp

Each file is self-contained with its own forward declarations and minimal
class stubs — no dependency on stub_classes.h (which may not declare all
methods).

Usage:
    python tools/gen_asm_decomp.py [--dry-run] [--class ClassName] [--stats]
"""

import argparse
import json
import os
import re
import subprocess
import sys
import time
from collections import defaultdict, OrderedDict
from pathlib import Path

# ===========================================================================
# Paths
# ===========================================================================
REPO = Path(__file__).resolve().parent.parent
OBJDUMP = r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC\bin\powerpc-eabi-objdump.exe"
ELF = str(REPO / "extracted" / "files" / "u2_ngc_release_dvd.elf")
SYMBOLS_JSON = REPO / "tools" / "symbols.json"
MATCHED_DIR = REPO / "src" / "matched"
ASM_DECOMP_DIR = REPO / "src" / "asm_decomp"

# Types built into the language or defined in types.h — no forward decl needed
BUILTIN_TYPES = frozenset({
    "void", "int", "char", "short", "long", "float", "double", "bool",
    "unsigned", "signed", "size_t", "wchar_t",
    "u8", "u16", "u32", "u64", "s8", "s16", "s32", "s64", "f32", "f64",
    "BOOL",
    # Common C type combinations that appear in parameter lists
    "unsigned int", "unsigned char", "unsigned short", "unsigned long",
    "signed int", "signed char", "signed short", "signed long",
    "long long", "unsigned long long",
    "unsigned wchar_t",
    "char *", "void *", "int *", "float *", "double *",
})

# Known template names that need template<...> forward declarations
KNOWN_TEMPLATES = {
    "vector": 2, "list": 2, "allocator": 1, "basic_string": 3,
    "char_traits": 1, "pair": 2,
    "TArray": 2, "TNodeList": 1, "TRedBlackTree": 2,
    "AllocPoolManager": 1, "byte_key_map": 2, "TTreeTable": 1,
    "AptSharedPtr": 1, "TRect": 1, "BitFlags": 1, "VECTOR": 1,
    "CBFunctor1": 1, "CBFunctor1wRet": 2, "CBFunctor2": 2,
    "CBMemberTranslator0": 3, "CBMemberTranslator1": 3,
    "CBMemberTranslator1wRet": 4, "CBMemberTranslator2": 4,
    "StackString": 1,
    "_Base_bitset": 1, "_Deque_base": 2,
    "ObjectDataFactoryQuickData": 1, "ObjectDataFactoryIFF": 1,
    "ObjectDataFactoryDatabase": 1,
    "__node_alloc": 2,
    "Rb_tree": 5, "_Rb_tree": 5,
    "Select1st": 1, "less": 1,
    "deque": 2,
}


# ===========================================================================
# Load existing matches from src/matched/
# ===========================================================================
def load_matched_addresses():
    """Return set of addresses that have matches in src/matched/.

    Includes rawbyte, inline asm, auto_match, ctor — everything.
    These are functions we do NOT need to generate into asm_decomp.
    """
    matched = set()
    if not MATCHED_DIR.exists():
        return matched

    for cpp in MATCHED_DIR.glob("*.cpp"):
        with open(cpp, encoding="utf-8", errors="replace") as f:
            for line in f:
                m = re.match(r"// 0x([0-9A-Fa-f]+)\s+\(\d+ bytes\)", line.strip())
                if m:
                    matched.add(int(m.group(1), 16))
    return matched


# ===========================================================================
# Bulk disassembly — one pass over the entire ELF
# ===========================================================================
def bulk_disassemble(start_addr, end_addr):
    """Disassemble a range from the ELF.

    Returns dict: addr_int -> (raw_hex, mnemonic, operands)
    raw_hex is the 4-byte hex string like "48 2c d5 f1"
    """
    result = subprocess.run(
        [OBJDUMP, "-d",
         f"--start-address=0x{start_addr:08x}",
         f"--stop-address=0x{end_addr:08x}",
         ELF],
        capture_output=True, text=True, timeout=120
    )
    insn_map = {}
    for line in result.stdout.split("\n"):
        line = line.strip()
        if not line or ":" not in line or line[0:1] != "8":
            continue
        colon_idx = line.index(":")
        addr_hex = line[:colon_idx].strip()
        rest = line[colon_idx + 1:].strip()
        if not rest or rest.startswith("<"):
            continue
        try:
            addr_int = int(addr_hex, 16)
        except ValueError:
            continue
        # Parse raw bytes + mnemonic from: "48 2c d5 f1 \tbl      0x802e3af0"
        parts = rest.split("\t")
        if len(parts) >= 2:
            raw_hex = parts[0].strip()
            insn_text = "\t".join(parts[1:]).strip()
            insn_parts = insn_text.split(None, 1)
            mn = insn_parts[0] if insn_parts else ""
            ops = insn_parts[1] if len(insn_parts) > 1 else ""
            insn_map[addr_int] = (raw_hex, mn, ops)
        else:
            # Fallback: just the raw hex, no mnemonic
            insn_map[addr_int] = (rest.strip(), "", "")
    return insn_map


def get_function_insns(insn_map, func_addr, func_size):
    """Extract ordered (addr, raw_hex, mnemonic, operands) tuples for a function."""
    insns = []
    addr = func_addr
    end = func_addr + func_size
    while addr < end:
        entry = insn_map.get(addr)
        if entry is None:
            insns.append((addr, "00 00 00 00", ".long", f"0x00000000  /* gap at 0x{addr:08x} */"))
        else:
            raw_hex, mn, ops = entry
            insns.append((addr, raw_hex, mn, ops))
        addr += 4
    return insns


# ===========================================================================
# Symbol name parsing
# ===========================================================================
class ParsedSymbol:
    """Parsed function symbol with all parts needed for C++ declaration."""
    __slots__ = (
        "raw_name", "address", "size",
        "class_name", "method_name", "full_qualifier",
        "namespace_parts", "class_parts",
        "params_str", "is_const", "is_constructor", "is_destructor",
        "is_global", "is_operator", "is_static_init",
        "is_global_ctor_dtor", "is_anonymous_ns",
        "return_type", "file_group",
        "has_return_prefix", "is_variadic",
    )

    def __init__(self):
        for s in self.__slots__:
            setattr(self, s, None)
        self.is_const = False
        self.is_constructor = False
        self.is_destructor = False
        self.is_global = False
        self.is_operator = False
        self.is_static_init = False
        self.is_global_ctor_dtor = False
        self.is_anonymous_ns = False
        self.has_return_prefix = False
        self.is_variadic = False
        self.return_type = "void"
        self.namespace_parts = []
        self.class_parts = []


def sanitize_filename(name):
    """Convert a class/namespace name to a safe filename.

    Truncates to 100 chars max to avoid OS path length limits.
    """
    name = name.replace("::", "_")
    name = name.replace("<", "_L_")
    name = name.replace(">", "_R_")
    name = name.replace(",", "_")
    name = name.replace(" ", "_")
    name = name.replace("*", "ptr")
    name = name.replace("&", "ref")
    name = name.replace("(", "_")
    name = name.replace(")", "_")
    name = re.sub(r"[^A-Za-z0-9_]", "_", name)
    name = re.sub(r"_+", "_", name)
    name = name.strip("_")
    # Truncate long names (e.g. deeply nested template instantiations)
    if len(name) > 100:
        # Use a hash suffix to ensure uniqueness
        import hashlib
        h = hashlib.md5(name.encode()).hexdigest()[:8]
        name = name[:90] + "_" + h
    return name or "unnamed"


def split_qualified_name(name):
    """Split 'A::B::C' into ['A', 'B', 'C'], respecting template/paren brackets."""
    parts = []
    current = []
    depth = 0
    paren_depth = 0
    i = 0
    while i < len(name):
        c = name[i]
        if c == "<":
            depth += 1
            current.append(c)
        elif c == ">":
            depth -= 1
            current.append(c)
        elif c == "(":
            paren_depth += 1
            current.append(c)
        elif c == ")":
            paren_depth -= 1
            current.append(c)
        elif c == ":" and i + 1 < len(name) and name[i + 1] == ":" and depth == 0 and paren_depth == 0:
            parts.append("".join(current))
            current = []
            i += 2
            continue
        else:
            current.append(c)
        i += 1
    if current:
        parts.append("".join(current))
    return parts


def strip_template(name):
    """Strip template parameters: 'Foo<int>' -> 'Foo'."""
    idx = name.find("<")
    return name[:idx] if idx >= 0 else name


def find_param_list_start(name):
    """Find the index of the opening paren of the parameter list.

    Handles:
    - operator() by skipping it
    - operator<< / operator<<= by not treating < as template brackets
    - Template args like Foo<int>::Bar(...)
    Returns the index or None.
    """
    depth = 0
    i = 0
    while i < len(name):
        c = name[i]

        # Check if we're at an 'operator' keyword followed by operator chars
        # If so, skip the operator chars to avoid misinterpreting < > ( as brackets
        if c == "o" and name[i:].startswith("operator"):
            op_start = i + len("operator")
            # Skip any whitespace
            j = op_start
            while j < len(name) and name[j] == " ":
                j += 1
            # Check what operator it is
            if j < len(name) and name[j] == "(":
                # operator() — skip the () pair
                paren_d = 1
                j += 1
                while j < len(name) and paren_d > 0:
                    if name[j] == "(":
                        paren_d += 1
                    elif name[j] == ")":
                        paren_d -= 1
                    j += 1
                i = j
                continue
            elif j < len(name) and name[j] in "<>=!+-*/&|^%~[]":
                # Operator with symbols — skip all operator chars
                while j < len(name) and name[j] in "<>=!+-*/&|^%~[]":
                    j += 1
                i = j
                continue
            elif j < len(name) and name[j].isalpha():
                # conversion operator like "operator bool" — skip to paren
                while j < len(name) and (name[j].isalnum() or name[j] in " _*&"):
                    j += 1
                i = j
                continue
            else:
                i = j
                continue

        if c == "<":
            depth += 1
        elif c == ">":
            depth -= 1
            if depth < 0:
                depth = 0  # Safety
        elif c == "(" and depth == 0:
            return i
        i += 1
    return None


def parse_symbol(sym):
    """Parse a symbol dict from symbols.json into a ParsedSymbol."""
    p = ParsedSymbol()
    name = sym.get("name", "<default>")
    p.raw_name = name
    p.address = int(sym["address"], 16)
    p.size = sym.get("size", 0)

    if not name or name == "<default>":
        return None

    # "global constructors/destructors keyed to ..."
    if name.startswith("global constructors keyed to ") or name.startswith("global destructors keyed to "):
        p.is_global_ctor_dtor = True
        p.is_global = True
        p.method_name = sanitize_filename(name)
        p.params_str = "()"
        p.return_type = "void"
        p.file_group = "__static_init__"
        return p

    # "__static_initialization_and_destruction_0"
    if name == "__static_initialization_and_destruction_0":
        p.is_static_init = True
        p.is_global = True
        p.method_name = name
        p.params_str = "()"
        p.return_type = "void"
        p.file_group = "__static_init__"
        return p

    working_name = name

    # Fix non-standard types
    working_name = working_name.replace("unsigned wchar_t", "unsigned short")

    # Detect "void {anonymous}::..." return type prefix
    if working_name.startswith("void "):
        p.has_return_prefix = True
        p.return_type = "void"
        working_name = working_name[5:]

    # Handle {anonymous} namespace
    if "{anonymous}" in working_name:
        p.is_anonymous_ns = True
        working_name = working_name.replace("{anonymous}::", "")

    # Check for variadic (ends with ",...")
    if working_name.rstrip(")").rstrip().endswith(",..."):
        p.is_variadic = True

    # Find parameter list
    paren_idx = find_param_list_start(working_name)

    if paren_idx is not None:
        before_paren = working_name[:paren_idx]
        params_and_rest = working_name[paren_idx:]

        p.is_const = params_and_rest.rstrip().endswith(" const")
        if p.is_const:
            params_and_rest = params_and_rest.rstrip()[:-6].rstrip()
        p.params_str = fixup_params(params_and_rest)
    else:
        before_paren = working_name
        p.params_str = "()"

    # Parse qualified name
    parts = split_qualified_name(before_paren)

    if len(parts) >= 2:
        p.method_name = parts[-1]
        p.full_qualifier = "::".join(parts[:-1])
        p.class_name = parts[-2]

        bare_class = strip_template(p.class_name)
        bare_method = strip_template(p.method_name)
        if bare_method == bare_class:
            p.is_constructor = True
            p.return_type = None
        elif p.method_name.startswith("~"):
            p.is_destructor = True
            p.return_type = None

        if "operator" in p.method_name:
            p.is_operator = True

        p.is_global = False
        p.file_group = sanitize_filename(parts[0])
    else:
        p.method_name = parts[0] if parts else name
        p.is_global = True
        if p.method_name.startswith("operator"):
            p.is_operator = True
        p.file_group = "__global__"

    return p


# ===========================================================================
# Type extraction from parameter lists
# ===========================================================================
def extract_param_types(params_str):
    """Extract individual parameter type strings from a parameter list.

    Input: "(EVec3 &, int, cXObject *)"
    Output: ["EVec3 &", "int", "cXObject *"]
    """
    # Remove outer parens
    s = params_str.strip()
    if s.startswith("("):
        s = s[1:]
    if s.endswith(")"):
        s = s[:-1]
    s = s.strip()
    if not s or s == "void":
        return []
    # Remove trailing ... for variadic
    if s.endswith(",..."):
        s = s[:-4].rstrip(", ")
    elif s.endswith("..."):
        s = s[:-3].rstrip(", ")

    # Split by comma, respecting template/paren depth
    types = []
    current = []
    depth = 0
    for c in s:
        if c in "<(":
            depth += 1
            current.append(c)
        elif c in ">)":
            depth -= 1
            current.append(c)
        elif c == "," and depth == 0:
            types.append("".join(current).strip())
            current = []
        else:
            current.append(c)
    if current:
        t = "".join(current).strip()
        if t:
            types.append(t)
    return types


def get_base_type(type_str):
    """Extract the base type name from a full type string.

    "const EVec3 &" -> "EVec3"
    "cXObject *" -> "cXObject"
    "unsigned int" -> None (builtin)
    "vector<int, allocator<int> > &" -> "vector<int, allocator<int> >"
    """
    s = type_str.strip()
    # Remove leading const
    if s.startswith("const "):
        s = s[6:]
    # Remove trailing const
    if s.endswith(" const"):
        s = s[:-6]
    # Remove trailing & and *
    s = s.rstrip("& *").strip()
    # Remove leading "unsigned " / "signed " for builtins
    if s in BUILTIN_TYPES:
        return None
    # Check if it starts with unsigned/signed + builtin
    for prefix in ("unsigned ", "signed "):
        if s.startswith(prefix):
            rest = s[len(prefix):]
            if rest in ("int", "char", "short", "long", "long long", "wchar_t"):
                return None
    if s in ("long long",):
        return None
    if not s:
        return None
    return s


def extract_all_types_from_params(params_str):
    """Extract ALL type names from a parameter list, including types inside templates.

    For "vector<ERAmbientSound *, allocator<ERAmbientSound *> > &", returns:
    ["vector<ERAmbientSound *, allocator<ERAmbientSound *> >", "ERAmbientSound", "allocator"]
    """
    types = []
    param_types = extract_param_types(params_str)
    for pt in param_types:
        base = get_base_type(pt)
        if base:
            types.append(base)
            # Also extract types from inside template args
            if "<" in base:
                inner = base[base.index("<") + 1:base.rindex(">")]
                inner_types = extract_param_types(f"({inner})")
                for it in inner_types:
                    inner_base = get_base_type(it)
                    if inner_base:
                        types.append(inner_base)
    return types


def classify_type(type_name):
    """Classify a type for forward declaration purposes.

    Returns: ("class", "TypeName") or ("template", "Name", nargs) or
             ("nested", "Parent::Child") or ("builtin", None)
    """
    if not type_name:
        return ("builtin", None)

    # Check for nested types (contains :: but not at top level of a template)
    # We need to be careful: "vector<int, allocator<int>>" has :: inside template
    top_parts = split_qualified_name(type_name)
    if len(top_parts) > 1:
        # Check if the first part is a template (like CBMemberTranslator1<...>)
        base = strip_template(top_parts[0])
        if base in KNOWN_TEMPLATES:
            return ("template_inst", type_name)
        return ("nested", type_name)

    # Check for template instantiation
    if "<" in type_name:
        base = strip_template(type_name)
        if base in KNOWN_TEMPLATES:
            return ("template_inst", type_name)
        return ("template_unknown", type_name)

    return ("class", type_name)


def is_pass_by_value(type_str):
    """Check if a type is passed by value (not by pointer or reference)."""
    s = type_str.strip()
    # Remove trailing const
    if s.endswith(" const"):
        s = s[:-6].strip()
    # Check if it ends with * or &
    return not s.endswith("*") and not s.endswith("&")


def fixup_params(params_str):
    """Fix parameter types that aren't valid C++.

    - 'unsigned wchar_t' -> 'unsigned short' (GCC extension)
    """
    if params_str:
        params_str = params_str.replace("unsigned wchar_t", "unsigned short")
    return params_str


def collect_types_for_group(funcs):
    """Collect all types that need forward declarations for a group of functions.

    Returns:
        fwd_classes: set of class names to forward-declare (only used by ptr/ref)
        value_classes: set of class names that need struct {} definitions (passed by value)
        templates_needed: set of (name, nargs) template forward declarations
        nested_types: set of nested type strings (A::B) — these get replaced with int
    """
    fwd_classes = set()
    value_classes = set()
    templates_needed = set()
    nested_types = set()

    for parsed in funcs:
        all_types = extract_all_types_from_params(parsed.params_str or "()")
        param_types = extract_param_types(parsed.params_str or "()")

        # Also extract types from the class qualifier (for template specializations)
        if parsed.full_qualifier and "<" in parsed.full_qualifier:
            # Extract template args from qualifier
            q = parsed.full_qualifier
            while "<" in q:
                start = q.index("<")
                # Find matching >
                depth = 0
                end = start
                for ci in range(start, len(q)):
                    if q[ci] == "<":
                        depth += 1
                    elif q[ci] == ">":
                        depth -= 1
                        if depth == 0:
                            end = ci
                            break
                inner = q[start + 1:end]
                # Extract types from inner template args
                inner_types = extract_all_types_from_params(f"({inner})")
                all_types.extend(inner_types)
                q = q[end + 1:]

        for base in all_types:
            if base is None:
                continue
            kind = classify_type(base)
            # Check if this specific type occurrence is by-value
            # (only matters for the top-level params, not inner template types)
            by_value = False
            for pt in param_types:
                pt_base = get_base_type(pt)
                if pt_base == base:
                    by_value = is_pass_by_value(pt)
                    break

            if kind[0] == "class":
                if by_value:
                    value_classes.add(kind[1])
                else:
                    fwd_classes.add(kind[1])
            elif kind[0] in ("template_inst", "template_unknown"):
                tbase = strip_template(base)
                if tbase in KNOWN_TEMPLATES:
                    nargs = KNOWN_TEMPLATES[tbase]
                    if by_value:
                        # Template instantiation passed by value needs full definition
                        templates_needed.add((tbase, nargs, True))  # True = needs body
                    else:
                        templates_needed.add((tbase, nargs, False))
                else:
                    if by_value:
                        value_classes.add(tbase)
                    else:
                        fwd_classes.add(tbase)
            elif kind[0] == "nested":
                nested_types.add(kind[1])

    # If a class is used both by value and by reference, it needs struct definition
    fwd_classes -= value_classes

    return fwd_classes, value_classes, templates_needed, nested_types


# ===========================================================================
# Class/namespace declaration generation
# ===========================================================================
def group_by_class(funcs):
    """Group functions by their full qualifier (class::namespace path).

    Returns: OrderedDict mapping full_qualifier -> list of ParsedSymbol
    Also returns a separate list for global functions.
    """
    class_funcs = defaultdict(list)
    global_funcs = []

    for p in funcs:
        if p.is_global:
            global_funcs.append(p)
        else:
            class_funcs[p.full_qualifier].append(p)

    return class_funcs, global_funcs


def generate_class_declaration(qualifier, methods):
    """Generate a minimal class declaration for the given methods.

    qualifier: e.g. "ESimsCam" or "BBI::InventoryItem" or "InteractorModule::WallPainter"
    methods: list of ParsedSymbol

    For multi-part qualifiers like "BBI::InventoryItem", we check if
    "BBI" is a known namespace or if it should be treated as a namespace.
    Known namespaces: BBI, EA, Effects, InteractorModule, Memory, Renderer, UI.
    Everything else is treated as a flat class hierarchy.
    """
    parts = split_qualified_name(qualifier)
    if not parts:
        return ""

    # Known namespaces from the original codebase
    KNOWN_NAMESPACES = frozenset({
        "BBI", "EA", "Effects", "InteractorModule", "Memory",
        "{anonymous}",
    })

    lines = []
    indent = ""

    # Determine how many leading parts are namespaces
    ns_count = 0
    for p in parts[:-1]:
        bare = strip_template(p)
        if bare in KNOWN_NAMESPACES:
            ns_count += 1
        else:
            break  # Stop at first non-namespace

    ns_parts = parts[:ns_count]
    # Remaining parts form the class hierarchy
    class_parts = parts[ns_count:]

    if not class_parts:
        # Shouldn't happen, but handle gracefully
        class_parts = [parts[-1]]
        ns_parts = parts[:-1]

    # Open namespaces
    for ns in ns_parts:
        lines.append(f"{indent}namespace {ns} {{")
        indent += "    "

    # For nested classes like "Allocator::GeneralAllocator", we need:
    # class Allocator { public: class GeneralAllocator { ... }; };
    # But this gets complicated. Simpler: just declare the innermost class
    # and use fully-qualified definitions.
    # If there's more than one class part, we need to nest them.
    def _emit_class_with_template_check(name, indent, methods_list, lines):
        """Emit a class declaration, handling template specializations."""
        if "<" in name:
            # Template specialization: e.g. "AllocPoolManager<FastAllocPool>"
            base_name = strip_template(name)
            # Count template args to declare the primary template
            # Extract template args from between < >
            tmpl_args = name[name.index("<") + 1:name.rindex(">")]
            # Count comma-separated args (respecting nested templates)
            nargs = 1
            depth = 0
            for c in tmpl_args:
                if c in "<(":
                    depth += 1
                elif c in ">)":
                    depth -= 1
                elif c == "," and depth == 0:
                    nargs += 1
            tparams = ", ".join(f"typename T{i}" for i in range(nargs))
            lines.append(f"{indent}template <{tparams}> class {base_name};")
            lines.append(f"{indent}template <> class {name} {{")
        else:
            lines.append(f"{indent}class {name} {{")
        lines.append(f"{indent}public:")
        _emit_method_decls(lines, indent, methods_list)
        lines.append(f"{indent}}};")

    if len(class_parts) == 1:
        class_name = class_parts[0]
        _emit_class_with_template_check(class_name, indent, methods, lines)
    else:
        # Nested class: open each wrapper class
        for i, cp in enumerate(class_parts[:-1]):
            if "<" in cp:
                base = strip_template(cp)
                # Just use the base name — nested templates are too complex
                lines.append(f"{indent}class {base} {{")
            else:
                lines.append(f"{indent}class {cp} {{")
            lines.append(f"{indent}public:")
            indent += "    "

        # Innermost class with methods
        inner_class = class_parts[-1]
        _emit_class_with_template_check(inner_class, indent, methods, lines)

        # Close wrapper classes
        for cp in reversed(class_parts[:-1]):
            indent = indent[:-4]
            lines.append(f"{indent}}};")

    # Close namespaces
    for ns in reversed(ns_parts):
        indent = indent[:-4]
        lines.append(f"{indent}}} // namespace {ns}")

    return "\n".join(lines)


def _emit_method_decls(lines, indent, methods):
    """Emit method declarations inside a class body."""
    # Deduplicate: same method signature shouldn't appear twice
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


def replace_nested_types_in_params(params_str, nested_types):
    """Replace nested types (Parent::Child) in parameter lists with int.

    This is needed because nested types can't be forward-declared from outside
    the class, and we don't want to fully define parent classes.
    """
    result = params_str
    for nt in sorted(nested_types, key=len, reverse=True):
        # Replace the nested type with int, preserving pointers/refs
        result = result.replace(nt + " *", "int *")
        result = result.replace(nt + " &", "int &")
        result = result.replace(nt, "int")
    return result


# ===========================================================================
# Branch / instruction processing
# ===========================================================================

# PPC branch mnemonics (conditional, internal to function)
COND_BRANCH_MN = frozenset({
    "beq", "bne", "bge", "blt", "ble", "bgt",
    "beq+", "bne+", "bge+", "blt+", "ble+", "bgt+",
    "beq-", "bne-", "bge-", "blt-", "ble-", "bgt-",
    "bnl", "bng", "bns", "bso",
    "bdnz", "bdnz+", "bdnz-", "bdz", "bdz+", "bdz-",
    "b",  # unconditional branch (often local jumps)
})

# Call mnemonics (external — to other functions)
CALL_MN = frozenset({"bl", "bla"})

# Returns / special
RETURN_MN = frozenset({
    "blr", "beqlr", "bnelr", "bgelr", "bltlr", "blelr", "bgtlr",
    "bctr", "bctrl",
    "beqlr+", "bnelr+", "bgelr+", "bltlr+", "blelr+", "bgtlr+",
    "beqlr-", "bnelr-", "bgelr-", "bltlr-", "blelr-", "bgtlr-",
})


def strip_reg_prefix(operands):
    """Convert objdump register names (r0, f0) to GAS numeric form (0, 0).

    GAS inline asm wants numeric registers: 'stw 0,4(3)' not 'stw r0,4(r3)'.
    """
    # Replace rN with N for GPR (but not 'r' inside words like 'blr')
    result = re.sub(r'\br(\d+)\b', r'\1', operands)
    # Replace fN with N for FPR
    result = re.sub(r'\bf(\d+)\b', r'\1', result)
    # Replace crN with N for CR fields (but leave 'cr' in words like 'crand')
    # Actually, crN in conditions should stay as-is for GAS — skip this
    return result


def parse_branch_target(operands):
    """Extract absolute branch target address from operands.

    Handles:
        "0x80016510"
        "0x80016510 <symbol+0x40>"
        "4,0x80016510"  (conditional with CR field)
    """
    # Strip <...> annotation
    ops = re.sub(r"\s*<[^>]+>", "", operands).strip()
    # Try to find a hex address
    m = re.search(r"0x([0-9a-fA-F]+)", ops)
    if m:
        return int(m.group(1), 16)
    return None


def build_addr_to_symbol(symbols_data):
    """Build mapping from address -> mangled-compatible symbol name for bl targets."""
    addr_map = {}
    for s in symbols_data["symbols"]:
        if s["type"] != "function":
            continue
        name = s.get("name", "")
        if not name or name == "<default>":
            continue
        addr = int(s["address"], 16)
        if addr not in addr_map:
            addr_map[addr] = name
    return addr_map


def mangle_symbol_for_asm(name):
    """Convert a C++ symbol name to something we can use in asm bl targets.

    Since we can't easily replicate GCC's name mangling, we use the symbol
    name as-is and rely on the linker to resolve it. For inline asm, we
    reference the function by its label in the skeleton .s file, which uses
    a mangled form derived from the map file.

    The simplest approach: emit bl as a raw .long word (4 bytes of the
    original instruction).
    """
    # This is too complex for general use. Instead, we'll use raw instruction bytes.
    pass


# ===========================================================================
# C++ code generation
# ===========================================================================
def raw_hex_to_long(raw_hex):
    """Convert raw hex bytes like '48 2c d5 f1' to a .long value '0x482cd5f1'."""
    bytes_str = raw_hex.replace(" ", "")
    return f"0x{bytes_str}"


def generate_function_code(parsed, insns, addr_to_sym, dol_data=None):
    """Generate C++ code for a single function with inline asm.

    Handles:
    - Internal branches → local labels (.L_XXXXXXXX)
    - External bl/b → .long with raw instruction bytes (preserves exact encoding)
    - Register prefix stripping for GAS
    """
    if not insns:
        return None

    lines = []
    func_addr = parsed.address
    func_end = func_addr + parsed.size

    lines.append(f"// 0x{parsed.address:08X} ({parsed.size} bytes)")
    lines.append(f"// {parsed.raw_name}")

    sig = build_signature(parsed)
    if sig is None:
        return None

    lines.append("__attribute__((noreturn))")
    lines.append(f"{sig} {{")
    lines.append("    __asm__ __volatile__(")

    # First pass: identify internal branch targets
    internal_targets = set()
    for addr, raw, mn, ops in insns:
        if mn in COND_BRANCH_MN:
            target = parse_branch_target(ops)
            if target is not None and func_addr <= target < func_end:
                internal_targets.add(target)

    # Second pass: generate asm lines
    for addr, raw, mn, ops in insns:
        # Emit label if this address is a branch target
        if addr in internal_targets:
            label = f".L_{addr:08X}"
            lines.append(f'        "{label}:\\n"')

        # Clean up operands
        ops_clean = re.sub(r"\s*<[^>]+>", "", ops).strip()

        # Handle different instruction types
        if mn in COND_BRANCH_MN:
            target = parse_branch_target(ops)
            if target is not None and func_addr <= target < func_end:
                # Internal branch — use label
                label = f".L_{target:08X}"
                ops_stripped = re.sub(r"\s*<[^>]+>", "", ops).strip()
                cr_match = re.match(r"(\d+),\s*0x[0-9a-fA-F]+", ops_stripped)
                if cr_match:
                    cr_field = cr_match.group(1)
                    asm_line = f"{mn}\t{cr_field},{label}"
                else:
                    asm_line = f"{mn}\t{label}"
                lines.append(f'        "{asm_line}\\n"')
            else:
                # External conditional branch or unconditional b to outside —
                # emit as .long to preserve exact encoding
                long_val = raw_hex_to_long(raw)
                sym_name = addr_to_sym.get(target, "") if target else ""
                comment = f"  /* {mn} {ops_clean}"
                if sym_name:
                    comment += f" [{sym_name}]"
                comment += " */"
                lines.append(f'        ".long {long_val}{comment}\\n"')

        elif mn in CALL_MN:
            # bl/bla — external function call
            # Emit as .long with raw bytes to preserve exact encoding
            target = parse_branch_target(ops)
            long_val = raw_hex_to_long(raw)
            sym_name = addr_to_sym.get(target, "") if target else ""
            comment = f"  /* {mn} "
            if sym_name:
                comment += sym_name
            else:
                comment += ops_clean
            comment += " */"
            lines.append(f'        ".long {long_val}{comment}\\n"')

        elif mn in RETURN_MN:
            asm_line = strip_reg_prefix(f"{mn}\t{ops_clean}" if ops_clean else mn)
            lines.append(f'        "{asm_line}\\n"')

        else:
            # Check for instructions the GAS assembler won't understand
            # (VSX instructions decoded by objdump that are actually Gekko
            # paired-single instructions, etc.)
            if mn.startswith("xs") or "vs" in ops_clean or mn.startswith("xv") or mn.startswith("lxv") or mn.startswith("stxv"):
                # Emit as raw .long
                long_val = raw_hex_to_long(raw)
                lines.append(f'        ".long {long_val}  /* {mn} {ops_clean} */\\n"')
            else:
                # Normal instruction — strip register prefixes
                ops_asm = strip_reg_prefix(ops_clean)
                # Escape for C string
                ops_asm = ops_asm.replace("\\", "\\\\").replace("%", "%%")
                asm_line = f"{mn}\t{ops_asm}" if ops_asm else mn
                lines.append(f'        "{asm_line}\\n"')

    lines.append("    );")
    lines.append("    __builtin_unreachable();")
    lines.append("}")
    lines.append("")

    return "\n".join(lines)


def get_operator_return_type(method_name):
    """Get the correct return type for operator overloads."""
    if method_name == "operator new" or method_name == "operator new[]":
        return "void*"
    elif method_name == "operator delete" or method_name == "operator delete[]":
        return "void"
    elif method_name == "operator=":
        return "void"  # close enough for asm stubs
    elif method_name in ("operator==", "operator!=", "operator<",
                         "operator>", "operator<=", "operator>="):
        return "void"
    elif method_name == "operator[]":
        return "void"
    elif method_name in ("operator<<", "operator>>"):
        return "void"
    elif method_name in ("operator+", "operator-", "operator*", "operator/"):
        return "void"
    elif method_name in ("operator+=", "operator-=", "operator*=", "operator/="):
        return "void"
    elif method_name == "operator()":
        return "void"
    elif method_name.startswith("operator "):
        # conversion operators like "operator bool", "operator int"
        return ""  # no explicit return type for conversion operators
    return "void"


def build_signature(parsed):
    """Build a C++ function signature from parsed symbol info."""
    if parsed.is_global_ctor_dtor:
        return f"void __{parsed.method_name}()"

    if parsed.is_static_init:
        return f"void {parsed.method_name}()"

    params = parsed.params_str or "()"

    if parsed.is_global:
        method = parsed.method_name
        # Template-specialized function names can't be defined as standalone functions
        # Strip template args for the definition (mangling won't match but it's asm anyway)
        if "<" in method and not method.startswith("operator"):
            method = strip_template(method)
        if parsed.is_operator:
            ret = get_operator_return_type(method)
        else:
            ret = parsed.return_type or "void"
        return f"{ret} {method}{params}"

    qualifier = parsed.full_qualifier
    method = parsed.method_name
    const = " const" if parsed.is_const else ""

    if parsed.is_constructor or parsed.is_destructor:
        return f"{qualifier}::{method}{params}{const}"
    elif parsed.is_operator:
        ret = get_operator_return_type(method)
        if ret == "":
            # Conversion operator — no return type
            return f"{qualifier}::{method}{params}{const}"
        return f"{ret} {qualifier}::{method}{params}{const}"
    else:
        ret = parsed.return_type or "void"
        return f"{ret} {qualifier}::{method}{params}{const}"


# ===========================================================================
# File generation
# ===========================================================================
def generate_file_content(group_name, funcs, insn_map, addr_to_sym):
    """Generate complete file content for a group of functions.

    Includes:
    - types.h include
    - Forward declarations for parameter types
    - Minimal class declarations
    - Function implementations with inline asm
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

    # Remove classes that we're defining ourselves (to avoid fwd decl + def conflict)
    defining_classes = set()
    for qualifier in class_funcs:
        parts = split_qualified_name(qualifier)
        if parts:
            defining_classes.add(parts[-1])
            for part in parts:
                defining_classes.add(strip_template(part))
    fwd_classes -= defining_classes
    value_classes -= defining_classes

    # Also remove template base names
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

    # Header
    lines.append('#include "types.h"')
    lines.append(f"// Auto-generated inline asm decomp stubs for {group_name}")
    lines.append("// Generated by gen_asm_decomp.py")

    func_count = len(funcs)
    byte_count = sum(f.size for f in funcs)
    lines.append(f"// {func_count} functions, {byte_count} bytes")
    lines.append("//")
    lines.append("// Each function has its original C++ signature with the body as inline PPC asm.")
    lines.append("// These can be incrementally replaced with real C++ as decompilation progresses.")
    lines.append("")

    # Template declarations
    if templates_needed:
        # Merge: if any usage needs body, emit with body
        tmpl_map = {}  # name -> (nargs, needs_body)
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

    # Class declarations for methods we're defining
    for qualifier in sorted(class_funcs.keys()):
        methods = class_funcs[qualifier]
        decl = generate_class_declaration(qualifier, methods)
        if decl:
            lines.append(decl)
            lines.append("")

    # Now emit function implementations
    error_count = 0

    # Class methods
    for qualifier in sorted(class_funcs.keys()):
        methods = sorted(class_funcs[qualifier], key=lambda p: p.address)
        for parsed in methods:
            insns = get_function_insns(insn_map, parsed.address, parsed.size)
            if not insns:
                error_count += 1
                continue
            code = generate_function_code(parsed, insns, addr_to_sym)
            if code is None:
                error_count += 1
                continue
            lines.append(code)

    # Global functions
    for parsed in sorted(global_funcs, key=lambda p: p.address):
        insns = get_function_insns(insn_map, parsed.address, parsed.size)
        if not insns:
            error_count += 1
            continue
        code = generate_function_code(parsed, insns, addr_to_sym)
        if code is None:
            error_count += 1
            continue
        lines.append(code)

    return "\n".join(lines) + "\n", func_count - error_count, byte_count, error_count


# ===========================================================================
# Main
# ===========================================================================
def collect_functions(symbols_data, matched_addrs, target_class=None):
    """Collect all functions that need asm decomp stubs."""
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

        if addr in matched_addrs:
            skipped["already_matched"] += 1
            continue

        # Skip duplicate addresses (same function listed twice)
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


def generate_all(args):
    """Main entry point."""
    t0 = time.time()

    print(f"Loading symbols from {SYMBOLS_JSON}...")
    with open(SYMBOLS_JSON) as f:
        symbols_data = json.load(f)

    print(f"Loading matched addresses from {MATCHED_DIR}...")
    matched_addrs = load_matched_addresses()
    print(f"  {len(matched_addrs)} already-matched function addresses")

    print("Collecting functions to generate...")
    groups, skipped = collect_functions(symbols_data, matched_addrs,
                                       target_class=args.class_name)
    total_funcs = sum(len(v) for v in groups.values())
    total_bytes = sum(p.size for ps in groups.values() for p in ps)
    print(f"  {total_funcs} functions in {len(groups)} file groups ({total_bytes} bytes)")
    print(f"  Skipped: {skipped}")

    if args.stats:
        print("\nTop 30 file groups by function count:")
        sorted_groups = sorted(groups.items(), key=lambda x: len(x[1]), reverse=True)
        for group, funcs in sorted_groups[:30]:
            tb = sum(f.size for f in funcs)
            print(f"  {group}: {len(funcs)} functions, {tb} bytes")
        return

    if args.dry_run:
        print(f"\n[DRY RUN] Would generate {len(groups)} files in {ASM_DECOMP_DIR}")
        sorted_groups = sorted(groups.items(), key=lambda x: len(x[1]), reverse=True)
        for group, funcs in sorted_groups[:20]:
            print(f"  {sanitize_filename(group)}.cpp: {len(funcs)} functions")
        if len(groups) > 20:
            print(f"  ... and {len(groups) - 20} more files")
        return

    # Bulk disassemble
    print("\nDisassembling .init section...")
    init_insns = bulk_disassemble(0x80003100, 0x800034C0)
    print(f"  {len(init_insns)} instructions")

    print("Disassembling .text section...")
    text_insns = bulk_disassemble(0x800034C0, 0x803CA900)
    print(f"  {len(text_insns)} instructions")

    all_insns = {}
    all_insns.update(init_insns)
    all_insns.update(text_insns)
    print(f"Total disassembled instructions: {len(all_insns)}")

    # Build address -> symbol name map for bl target resolution
    print("Building symbol address map...")
    addr_to_sym = build_addr_to_symbol(symbols_data)
    print(f"  {len(addr_to_sym)} symbol addresses")

    # Create output directory
    ASM_DECOMP_DIR.mkdir(parents=True, exist_ok=True)

    # Generate files
    print(f"\nGenerating files in {ASM_DECOMP_DIR}...")
    files_written = 0
    funcs_written = 0
    bytes_written = 0
    total_errors = 0

    sorted_groups = sorted(groups.items())
    for group_name, funcs in sorted_groups:
        funcs.sort(key=lambda p: p.address)

        filename = sanitize_filename(group_name) + ".cpp"
        filepath = ASM_DECOMP_DIR / filename

        content, fc, bc, errs = generate_file_content(group_name, funcs, all_insns, addr_to_sym)
        if fc == 0:
            total_errors += errs
            continue

        with open(filepath, "w", encoding="utf-8") as f:
            f.write(content)

        files_written += 1
        funcs_written += fc
        bytes_written += bc
        total_errors += errs

    elapsed = time.time() - t0
    print(f"\nDone in {elapsed:.1f}s!")
    print(f"  Files written: {files_written}")
    print(f"  Functions written: {funcs_written}")
    print(f"  Bytes covered: {bytes_written}")
    print(f"  Errors: {total_errors}")
    print(f"  Output: {ASM_DECOMP_DIR}")


def main():
    parser = argparse.ArgumentParser(
        description="Generate inline-asm C++ files for all unmatched functions")
    parser.add_argument("--dry-run", action="store_true",
                        help="Show what would be generated without writing files")
    parser.add_argument("--stats", action="store_true",
                        help="Show statistics about function groups")
    parser.add_argument("--class", dest="class_name", type=str, default=None,
                        help="Only generate for a specific class/group name")
    args = parser.parse_args()
    generate_all(args)


if __name__ == "__main__":
    main()
