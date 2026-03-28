#!/usr/bin/env python3
"""
gen_headers.py - Generate forward declaration headers for Sims 2 GC decomp.

Strategy: Maximum pragmatism for compilation.
- All classes as top-level forward declarations and class bodies
- Nested type references (Parent::Child) replaced with int in params
- Enums as proper enum types to allow overloading
- Templates forward-declared
- No namespaces in generated header (classes in EA/BBI/Memory emitted flat)
"""

import os
import re
from collections import defaultdict

PROJECT_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC_DIR = os.path.join(PROJECT_ROOT, "src")
INCLUDE_DIR = os.path.join(PROJECT_ROOT, "include")
OUTPUT_HEADER = os.path.join(INCLUDE_DIR, "stub_classes.h")

BUILTIN_TYPES = {
    "void", "int", "char", "short", "long", "float", "double", "bool",
    "unsigned", "signed", "size_t", "wchar_t",
    "u8", "u16", "u32", "u64", "s8", "s16", "s32", "s64", "f32", "f64",
    "BOOL",
}

TEMPLATE_NAMES = {
    "TArray", "TNodeList", "TRedBlackTree", "AllocPoolManager",
    "byte_key_map", "TTreeTable", "AptSharedPtr", "TRect",
    "BitFlags", "VECTOR", "vector", "allocator", "CBFunctor1wRet",
    "list", "StackString", "CBFunctor1", "CBFunctor2",
    "basic_string", "char_traits",
}

VALUE_TYPES = {
    "EVec2", "EVec3", "EVec4", "EMat4", "EBound3", "EBoundSphere",
    "CTilePt", "FTilePt", "FTileRect", "EHeadOrient", "TileWallsSegment",
}

# Names that will be typedef'd (not forward-declared as class)
TYPEDEF_NAMES = {
    "ObjEntryPoint", "TreeReturnCode", "StringHandle", "UIScreenID",
    "AptValueType", "ECTRL_CMD", "OVERALL_GAME_STATE", "EA_EVENT", "SCID",
    "EFontMatrixType", "EFontAlignX", "EFontAlignY", "AptMaskRenderOperation",
}


def parse_all_cpp():
    """Parse all .cpp files."""
    class_methods = defaultdict(list)
    for root, dirs, files in os.walk(SRC_DIR):
        for fname in sorted(files):
            if not fname.endswith(".cpp"):
                continue
            # Skip auto-generated matched stubs (have incorrect return types)
            if fname.endswith("_auto.cpp"):
                continue
            with open(os.path.join(root, fname), "r", encoding="utf-8", errors="replace") as fh:
                for line in fh:
                    line = line.strip()
                    if not line or line.startswith("//") or line.startswith("/*"):
                        continue
                    if "{" not in line or "(" not in line:
                        continue
                    # Skip initializer lists (lines starting with ':')
                    if line.startswith(":"):
                        continue
                    parsed = _parse(line)
                    if parsed:
                        ns, cls, ret, mname, params, is_const, is_dtor, is_ctor = parsed
                        class_methods[(ns, cls)].append(
                            (ret, mname, params, is_const, is_dtor, is_ctor)
                        )
    return class_methods


def _extract_balanced_parens(s, start):
    """Extract content between balanced parentheses starting at index 'start' (the opening paren).
    Returns (content, end_index) or (None, -1) if unbalanced."""
    if s[start] != '(':
        return (None, -1)
    depth = 0
    i = start
    while i < len(s):
        if s[i] == '(':
            depth += 1
        elif s[i] == ')':
            depth -= 1
            if depth == 0:
                return (s[start + 1:i], i)
        i += 1
    return (None, -1)


def _parse(line):
    """Parse a function definition line."""
    # Must end with { (or { })
    if '{' not in line:
        return None

    # Find Class::Method( or Class::~Dtor( pattern
    # Also handles Class::operator XXX(

    # Try to find ClassName::MethodName( pattern
    m = re.search(r'(\w+(?:::\w+)*)::~?(\w+)\s*\(', line)
    if not m:
        # Try operator
        m = re.search(r'(\w+(?:::\w+)*)::operator\s*(.+?)\s*\(', line)
        if not m:
            return None
        full_class = m.group(1)
        op_part = m.group(2).strip()
        paren_start = m.end() - 1  # position of (
        params, paren_end = _extract_balanced_parens(line, paren_start)
        if params is None:
            return None
        # Get return type (everything before the class name)
        ret = line[:m.start()].strip()
        if ret.startswith("//"):
            return None
        # Check for const after )
        after = line[paren_end + 1:].strip()
        is_const = after.startswith("const")
        ns, cls = _split(full_class)
        return (ns, cls, ret, "operator " + op_part, params.strip(), is_const, False, False)

    full_class = m.group(1)
    method_name = m.group(2)
    is_dtor = line[m.start():m.end()].find("~") >= 0

    paren_start = m.end() - 1  # position of (
    params, paren_end = _extract_balanced_parens(line, paren_start)
    if params is None:
        return None

    # Get return type (everything before the class:: part)
    ret = line[:m.start()].strip()

    # Check for const and { after )
    after = line[paren_end + 1:].strip()
    is_const = False
    if after.startswith("const"):
        is_const = True

    # Must have { somewhere after
    if '{' not in after:
        return None

    ns, cls = _split(full_class)

    if ret.startswith("//") or ret.startswith("/*"):
        return None

    # Reject if ret contains C keywords (not a function definition)
    if ret in ("if", "while", "for", "switch", "return", "else", "case"):
        return None
    # Reject if ret starts with a keyword
    if re.match(r"^(if|while|for|switch|return|else|case|do|goto|break|continue)\b", ret):
        return None

    if is_dtor:
        return (ns, cls, "", "~" + method_name, params.strip(), is_const, True, False)

    if method_name == cls and (not ret or ret in ("void", cls)):
        return (ns, cls, "", method_name, params.strip(), False, False, True)

    # If ret is empty but it's not a constructor, skip (missing return type)
    if not ret:
        return None

    return (ns, cls, ret, method_name, params.strip(), is_const, False, False)


def _split(name):
    parts = name.split("::")
    if len(parts) == 1:
        return (None, parts[0])
    return ("::".join(parts[:-1]), parts[-1])


def _dedup(methods):
    """Deduplicate methods."""
    seen = set()
    result = []
    for entry in methods:
        ret, name, params, is_const, is_dtor, is_ctor = entry
        norm_name = re.sub(r"\s+", " ", name).strip()
        norm_name = re.sub(r"(new|delete)\s+\[\]", r"\1[]", norm_name)
        # Normalize conversion operators: "operator char *" == "operator char*"
        if norm_name.startswith("operator "):
            op_part = norm_name[len("operator "):]
            op_part = re.sub(r"\s*([*&])", r"\1", op_part)
            norm_name = "operator " + op_part
        norm_params = _sanitize_params(params)
        # Normalize typedefs for dedup
        norm_params = norm_params.replace("u32", "unsigned int").replace("u16", "unsigned short").replace("u8", "unsigned char")
        norm_params = norm_params.replace("s32", "int").replace("s16", "short").replace("s8", "signed char")
        norm_params = norm_params.replace("f32", "float").replace("f64", "double")
        # Further normalize for dedup
        dp = re.sub(r"\s+", " ", norm_params).strip()
        # Normalize (void) to empty
        if dp == "void":
            dp = ""
        # Remove param names for dedup
        parts = []
        for p in dp.split(","):
            p = p.strip()
            if not p:
                continue
            words = p.split()
            if (len(words) >= 2 and words[-1].isidentifier()
                    and words[-1][0].islower()
                    and words[-1] not in ("int", "char", "short", "long", "float",
                                          "double", "bool", "void", "unsigned",
                                          "signed", "wchar_t")):
                p = " ".join(words[:-1])
            parts.append(p.strip())
        dp = ", ".join(parts)
        dp = re.sub(r"\s*([*&])\s*", r"\1 ", dp).strip()
        # Key is (name, normalized_params, const) - NOT return type
        # First entry wins when return types differ
        key = (norm_name, dp, is_const)
        if key not in seen:
            seen.add(key)
            result.append(entry)
    return result


def _sanitize_params(params, **kwargs):
    """Replace ALL nested type references with int."""
    params = params.replace("unsigned wchar_t", "wchar_t")
    params = re.sub(r"\b\w+::\w+(?:::\w+)*", "int", params)
    return params


def _sanitize_ret(ret, **kwargs):
    """Sanitize return type."""
    ret = ret.replace("unsigned wchar_t", "wchar_t")
    # Replace Parent::Child but preserve pointer/ref qualifiers
    def _repl(m):
        full_match = m.group(0)
        # Check if followed by * or &
        end_pos = m.end()
        return "int"
    ret = re.sub(r"\b\w+::\w+(?:::\w+)*", _repl, ret)
    if ret.startswith("//"):
        ret = "void"
    return ret


# Conversion operator detection
_REGULAR_OPS = {
    "new", "new[]", "delete", "delete[]",
    "=", "==", "!=", "<", ">", "<=", ">=",
    "+", "-", "*", "/", "%",
    "+=", "-=", "*=", "/=", "%=",
    "++", "--",
    "<<", ">>", "<<=", ">>=",
    "&", "|", "^", "~", "!",
    "&=", "|=", "^=", "&&", "||",
    "[]", "()", "->", "->*", ",",
}


def _is_conversion_op(name):
    if not name.startswith("operator "):
        return False
    op = name[len("operator "):].strip()
    # Normalize spaces
    op_normalized = re.sub(r"\s+", "", op)
    if op_normalized in {"new", "new[]", "delete", "delete[]"}:
        return False
    if op in _REGULAR_OPS:
        return False
    if op_normalized in {"new", "new[]", "delete", "delete[]",
                         "=", "==", "!=", "<", ">", "<=", ">=",
                         "+", "-", "*", "/", "%",
                         "+=", "-=", "*=", "/=", "%=",
                         "++", "--", "<<", ">>", "<<=", ">>=",
                         "&", "|", "^", "~", "!", "&=", "|=", "^=",
                         "&&", "||", "[]", "()", "->", "->*", ","}:
        return False
    # It's a conversion op if it looks like a type
    if re.match(r"^(const\s+)?(unsigned\s+)?(char|int|bool|float|double|short|long|void|wchar_t)\s*[*&]*$", op):
        return True
    if re.match(r"^[A-Z]\w*\s*[*&]*$", op):
        return True
    return False


def generate_header(class_methods):
    """Generate stub_classes.h."""
    lines = []
    lines.append("#ifndef STUB_CLASSES_H")
    lines.append("#define STUB_CLASSES_H")
    lines.append("")
    lines.append("// Auto-generated by tools/gen_headers.py")
    lines.append("// DO NOT EDIT - regenerate with: python tools/gen_headers.py")
    lines.append("")

    # ==========================================================================
    # Enums
    # ==========================================================================
    enum_names = set()
    for methods in class_methods.values():
        for ret, mname, params, *_ in methods:
            for text in [ret, params]:
                for word in re.findall(r"\be([A-Z]\w+)\b", text):
                    enum_names.add("e" + word)
    # Known enums
    enum_names.update({
        "eTrackFlags", "eAnimatedObjectType", "eBodyPartS2C", "eBodyPartTypeS2C",
        "eAnimType", "eAnimState", "eTrackType", "eBlendType", "eBlendMode",
        "eGameState", "eMURequest", "eMotiveIndex", "eLotType", "eLightType",
        "eResourceType", "eGestureType", "eSimAge", "eGoal", "eRoomType",
        "eEffectType", "eWallType", "eFloorType", "eObjectType", "eSkinType",
        "eCameraMode", "eRoutingMode", "eFollowMode", "ePortalMode",
        "eTweakType", "eRegion", "eDirection", "eOrientation", "eLOD",
        "eRenderLayer", "eUIScreenType", "eUIAlignment", "eUIControlType",
        "eSortOrder", "eSoundCategory", "eHeapArea", "ePrimitiveType",
        "eWallShaderType", "eEventType", "eInstanceFlag",
    })

    lines.append("// Enum types")
    for name in sorted(enum_names):
        lines.append(f"enum {name} {{ _{name}_dummy = 0 }};")
    lines.append("")

    # ==========================================================================
    # Typedefs
    # ==========================================================================
    lines.append("// Typedefs")
    tds = {
        "ObjEntryPoint": "int", "TreeReturnCode": "short",
        "StringHandle": "unsigned int", "UIScreenID": "int",
        "AptValueType": "int", "ECTRL_CMD": "int",
        "OVERALL_GAME_STATE": "int", "EA_EVENT": "int", "SCID": "int",
        "EFontMatrixType": "int", "EFontAlignX": "int", "EFontAlignY": "int",
        "AptMaskRenderOperation": "int",
    }
    for name, typ in sorted(tds.items()):
        lines.append(f"typedef {typ} {name};")
    lines.append("")

    # ==========================================================================
    # Templates
    # ==========================================================================
    lines.append("// Templates")
    tmpl_decls = {
        "AllocPoolManager": "template <typename T> class AllocPoolManager;",
        "AptSharedPtr": "template <typename T> class AptSharedPtr;",
        "BitFlags": "template <typename T> class BitFlags;",
        "CBFunctor1wRet": "template <typename A, typename R> class CBFunctor1wRet;",
        "TArray": "template <typename T, typename A = int> class TArray;",
        "TNodeList": "template <typename T> class TNodeList;",
        "TRect": "template <typename T> class TRect;",
        "TRedBlackTree": "template <typename K, typename V> class TRedBlackTree;",
        "TTreeTable": "template <typename T> class TTreeTable;",
        "VECTOR": "template <typename T> class VECTOR;",
        "allocator": "template <typename T> class allocator;",
        "byte_key_map": "template <int N, typename V> class byte_key_map;",
        "vector": "template <typename T, typename A> class vector;",
        "list": "template <typename T, typename A> class list;",
        "StackString": "template <int N> class StackString;",
        "CBFunctor1": "template <typename A> class CBFunctor1;",
        "CBFunctor2": "template <typename A, typename B> class CBFunctor2;",
        "basic_string": "template <typename C, typename T, typename A> class basic_string;",
        "char_traits": "template <typename T> class char_traits;",
    }
    for _, decl in sorted(tmpl_decls.items()):
        lines.append(decl)
    lines.append("")

    # ==========================================================================
    # Forward declarations for ALL classes
    # (Not typedefs, not templates, not value types, not enums)
    # ==========================================================================
    lines.append("// Forward class declarations")
    all_classes = set()
    for ns, cls in class_methods.keys():
        all_classes.add(cls)
    # Also from param types
    for methods in class_methods.values():
        for ret, mname, params, *_ in methods:
            for text in [ret, params]:
                for word in re.findall(r"\b([A-Z]\w+)\b", text):
                    if (word not in BUILTIN_TYPES and word not in enum_names
                            and word not in tds and word not in TEMPLATE_NAMES
                            and word not in VALUE_TYPES):
                        all_classes.add(word)

    all_classes -= set(tds.keys())
    all_classes -= TEMPLATE_NAMES
    all_classes -= VALUE_TYPES
    all_classes -= set(enum_names)
    all_classes -= {"NDEBUG", "EOF", "DEFINED", "NULL", "TRUE", "FALSE", "BOOL"}

    for cls in sorted(all_classes):
        lines.append(f"class {cls};")
    lines.append("")

    # ==========================================================================
    # Misc forward declarations
    # ==========================================================================
    lines.append("// Misc forward declarations")
    lines.append("struct structDrawCBparams;")
    lines.append("struct fontFXcommand;")
    lines.append("struct levelraininfo;")
    lines.append("struct lua_State;")
    lines.append("struct XPrimParam;")
    lines.append("")
    lines.append("// Underscore-prefixed types (GX SDK, C runtime, etc.)")
    lines.append("struct _AptScriptFunctionState;")
    lines.append("struct __sFILE;")
    lines.append("struct _GXRenderModeObj;")
    lines.append("typedef int _GXPrimitive;")
    lines.append("typedef int _GXTevStageID;")
    lines.append("struct _GXTexObj;")
    lines.append("struct __va_list_tag;")
    lines.append("")
    lines.append("// Lowercase types from effects/particle system")
    lines.append("struct psystem;")
    lines.append("struct pemitter;")
    lines.append("struct pemitterinfo;")
    lines.append("template <typename A, typename B> struct pair;")
    lines.append("")
    lines.append("// Additional lowercase types")
    lines.append("typedef int tColor;")
    lines.append("typedef int tRelationshipType;")
    lines.append("struct vert2;")
    lines.append("class cRCPEventHandler;")
    lines.append("class cAudioWorldCoord;")
    lines.append("typedef int tWantType;")
    lines.append("typedef int tFundsPlayerNumber;")
    lines.append("struct particle;")
    lines.append("struct PVector4;")
    lines.append("")

    # ==========================================================================
    # Value type definitions
    # ==========================================================================
    lines.append("// Value type definitions")
    vdefs = [
        ("EVEC2", "struct EVec2 { float x, y; };"),
        ("EVEC3", "struct EVec3 { float x, y, z; };"),
        ("EVEC4", "struct EVec4 { float x, y, z, w; };"),
        ("EMAT4", "class EMat4 { public: float m[4][4]; };"),
        ("EBOUND3", "struct EBound3 { EVec3 min, max; };"),
        ("EBOUNDSPHERE", "struct EBoundSphere { EVec3 center; float radius; };"),
        ("CTILEPT", "struct CTilePt { short x, y; };"),
        ("FTILEPT", "struct FTilePt { float x, y; };"),
        ("FTILERECT", "struct FTileRect { float x1, y1, x2, y2; };"),
        ("EHEADORIENT", "struct EHeadOrient { char _data[0x78]; };"),
        ("TILEWALLSSEGMENT", "struct TileWallsSegment { int _data[4]; };"),
    ]
    for guard, defn in vdefs:
        lines.append(f"#ifndef {guard}_DEFINED")
        lines.append(f"#define {guard}_DEFINED")
        lines.append(defn)
        lines.append("#endif")
    lines.append("")

    # ==========================================================================
    # Collect all Parent::Child type references for nested type declarations
    # ==========================================================================
    nested_types_map = {}  # parent_class -> set of nested type names
    for methods in class_methods.values():
        for ret, mname, params, *_ in methods:
            for text in [ret, params]:
                for m in re.finditer(r"\b(\w+)::(\w+)", text):
                    parent, child = m.group(1), m.group(2)
                    if parent not in BUILTIN_TYPES:
                        if parent not in nested_types_map:
                            nested_types_map[parent] = set()
                        nested_types_map[parent].add(child)

    # The set of parent classes that have nested types we'll declare
    known_parents = set(nested_types_map.keys())

    # ==========================================================================
    # Class bodies
    # ==========================================================================
    lines.append("// === Class declarations ===")
    lines.append("")

    sorted_keys = sorted(class_methods.keys(), key=lambda k: (k[0] or "", k[1]))
    emitted = set()

    # Emit ALL classes as top-level (simple approach - all nested refs replaced with int)
    for ns, cls in sorted_keys:
        if cls in emitted or cls in VALUE_TYPES:
            emitted.add(cls)
            continue
        emitted.add(cls)
        # Merge methods from all namespace variants
        all_methods = []
        for (ns2, cls2), methods in class_methods.items():
            if cls2 == cls:
                all_methods.extend(methods)
        methods = _dedup(all_methods)
        _emit_class(lines, cls, methods)

    lines.append("")
    lines.append("#endif // STUB_CLASSES_H")
    lines.append("")
    return "\n".join(lines)


def _emit_class(lines, cls, methods, known_parents=None, nested_types=None, indent=""):
    """Emit a class declaration."""
    if known_parents is None:
        known_parents = set()
    if nested_types is None:
        nested_types = set()

    # Filter nested types to valid identifiers
    real_nested = {n for n in nested_types
                   if n[0:1].isupper() and n != "operator" and not n.startswith("~")}

    lines.append(f"{indent}class {cls} {{")
    lines.append(f"{indent}public:")

    # Declare nested types
    for nt in sorted(real_nested):
        lines.append(f"{indent}    typedef int {nt};")

    for ret, name, params, is_const, is_dtor, is_ctor in methods:
        params = _sanitize_params(params, known_parents=known_parents)
        # Fix method name issues
        name = name.replace("unsigned wchar_t", "wchar_t")
        # Skip malformed operator declarations
        if name == "operator" or name == "operator ":
            continue
        # Force correct return types for operator new/delete
        norm_op = re.sub(r"\s+", "", name)
        if norm_op in ("operatornew", "operatornew[]"):
            ret = "void*"
        if norm_op in ("operatordelete", "operatordelete[]"):
            ret = "void"
        if is_dtor or is_ctor:
            lines.append(f"{indent}    {name}({params});")
        elif _is_conversion_op(name):
            const_str = " const" if is_const else ""
            lines.append(f"{indent}    {name}({params}){const_str};")
        else:
            ret_clean = _sanitize_ret(ret, known_parents=known_parents) if ret else "void"
            const_str = " const" if is_const else ""
            lines.append(f"{indent}    {ret_clean} {name}({params}){const_str};")

    lines.append(f"{indent}    char _stub_data[256];")
    lines.append(f"{indent}}};")
    lines.append("")


def update_types_h():
    """Ensure types.h does NOT include stub_classes.h (to avoid conflicts
    with files that have their own proper headers)."""
    types_h = os.path.join(INCLUDE_DIR, "types.h")
    with open(types_h, "r") as f:
        content = f.read()
    if "stub_classes.h" in content:
        content = content.replace('#include "stub_classes.h"\n\n', '')
        content = content.replace('#include "stub_classes.h"\n', '')
        with open(types_h, "w") as f:
            f.write(content)
        print("  Removed stub_classes.h from types.h")


def main():
    print("=== Sims 2 GC Decomp Header Generator ===")
    class_methods = parse_all_cpp()
    total = sum(len(v) for v in class_methods.values())
    print(f"  {len(class_methods)} classes, {total} methods")

    content = generate_header(class_methods)
    os.makedirs(INCLUDE_DIR, exist_ok=True)
    with open(OUTPUT_HEADER, "w") as f:
        f.write(content)
    print(f"  Written {OUTPUT_HEADER} ({len(content)} bytes, {content.count(chr(10))} lines)")

    update_types_h()
    print("Done!")


if __name__ == "__main__":
    main()
