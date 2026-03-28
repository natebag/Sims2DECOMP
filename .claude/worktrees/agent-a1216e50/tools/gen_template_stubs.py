#!/usr/bin/env python3
"""
Generate stub C++ source files for all TArray and STL template instantiations.
Reads symbols.json and outputs .cpp files in src/templates/ and headers in include/templates/.

The progress tracker regex patterns are defined in tools/progress.py.
See count_decompiled_functions() for the full set of patterns used.

Key rules for function definitions:
  - For Class<T>::Method: write "void Class<T>::Method(params) {" -> captured by pat_template
  - For Class<T>::operator=: write "Class<T>::operator=(params) {" (NO return type) -> captured by pat_template_op
  - For constructors:  write "Class<T>::Class(params) {" -> captured by pat_template
  - For destructors:   write "Class<T>::~Class(params) {" -> captured by pat_template
  - For free functions: write "void FuncName(params) {" -> captured by pat_simple
  - For operator<<: write "EStream & operator<<<T, A>(params) {" -> captured by pat_free_op
  - For global template funcs like "unsigned int CopyTArray<T, A>": write as-is with (params) -> captured by pat_free_op or other
"""

import json
import re
from pathlib import Path
from collections import defaultdict


def parse_symbol_name(name):
    """Parse a symbol name into components.
    Returns (func_qual, params_str) where func_qual is everything before the param '('.

    Handles operator<< and operator>> which use < as part of the operator name,
    not as template delimiters.
    """
    # Special handling for operator<< and operator>> templates
    op_match = re.search(r'operator(<<|>>)', name)
    if op_match:
        op_end = op_match.end()
        if op_end < len(name) and name[op_end] == '<':
            # After operator<</>> there's a template param list <...>
            depth = 0
            for i in range(op_end, len(name)):
                if name[i] == '<':
                    depth += 1
                elif name[i] == '>':
                    depth -= 1
                if depth == 0:
                    return name[:i + 1].strip(), name[i + 1:]
        # operator<</>> without template params
        idx = name.find('(', op_end)
        if idx >= 0:
            return name[:idx].strip(), name[idx:]
        return name.strip(), "()"

    # General case: find first ( not inside <>
    depth = 0
    for i, ch in enumerate(name):
        if ch == '<':
            depth += 1
        elif ch == '>':
            depth -= 1
        elif ch == '(' and depth == 0:
            return name[:i].strip(), name[i:]
    return name.strip(), "()"


def split_class_method(func_qual):
    """Split a qualified name into (class_name, method_name).
    Returns (None, func_qual) for free functions.
    """
    # Find the last :: not inside <>
    last_sep = -1
    depth = 0
    for i, ch in enumerate(func_qual):
        if ch == '<':
            depth += 1
        elif ch == '>':
            depth -= 1
        elif ch == ':' and i + 1 < len(func_qual) and func_qual[i+1] == ':' and depth == 0:
            last_sep = i

    if last_sep >= 0:
        return func_qual[:last_sep], func_qual[last_sep+2:]
    return None, func_qual


def bare_class_name(class_name):
    """Get bare class name without template params. TArray<int, X> -> TArray"""
    idx = class_name.find('<')
    return class_name[:idx] if idx >= 0 else class_name


def format_func_def(func_qual, params_str):
    """Format a function definition line that will be captured by the progress tracker regex.

    Returns the line WITHOUT the opening brace.
    """
    class_name, method_name = split_class_method(func_qual)
    bare = bare_class_name(class_name) if class_name else None

    # Case 1: Constructor - no return type
    if class_name and method_name == bare:
        return f"{func_qual}{params_str}"

    # Case 2: Destructor - no return type
    if class_name and method_name == f"~{bare}":
        return f"{func_qual}{params_str}"

    # Case 3: operator= on a template class - no return type (to avoid regex issues with template return types)
    if class_name and method_name == 'operator=' and '<' in class_name:
        return f"{func_qual}{params_str}"

    # Case 4: Template class methods (non-operator) - add "void" return type
    if class_name and '<' in class_name:
        return f"void {func_qual}{params_str}"

    # Case 5: Free functions with return type embedded in name
    # e.g. "EStream & operator<<<int, TArrayERCharacterAllocator>"
    # e.g. "unsigned int CopyTArray<BSplineVolume, TArrayERModelAllocator>"
    # These already have the return type as part of the name, write as-is
    if not class_name and (' ' in func_qual or '&' in func_qual):
        return f"{func_qual}{params_str}"

    # Case 6: Simple class methods or free functions - add "void" return type
    if class_name:
        return f"void {func_qual}{params_str}"
    else:
        return f"void {func_qual}{params_str}"


def verify_func_captured(func_def_line, func_qual):
    """Verify that a function definition line would be captured by the progress tracker."""
    pat_simple = re.compile(r'^[A-Za-z_][\w:*&<> ]+\s+(\w[\w:]+)\s*\(')
    pat_template = re.compile(r'^(?:[\w*& ]+\s+)?([A-Za-z_~][\w]*(?:<[^()]*>)?(?:::~?[\w]+)+)\s*\(')
    pat_template_op = re.compile(r'^(?:[\w*& ]+\s+)?([A-Za-z_][\w]*<[^()]*>::operator[^\s(]+)\s*\(')
    pat_free_op = re.compile(r'^([\w*&<>, ]+\s+operator[<>=!]+<[^()]*>)\s*\(')
    pat_free_template = re.compile(r'^([\w<>,*& ]+\s+[\w_]+<[^()]*>)\s*\(')

    captured_names = set()
    for pat in [pat_simple, pat_template, pat_template_op, pat_free_op, pat_free_template]:
        m = pat.match(func_def_line)
        if m:
            captured_names.add(m.group(1))

    # Check if func_qual matches any captured name
    func_short = func_qual.split('::')[-1] if '::' in func_qual else func_qual
    if func_qual in captured_names or func_short in captured_names:
        return True

    return False


def collect_all_symbols(funcs):
    """Collect all TArray and STL template symbols."""
    stl_keywords = ['__node_alloc', 'allocator<', '_Deque_base', '_Rb_tree', 'vector<',
                    'pair<', 'basic_string', '_List_base', 'list<', '_Base_bitset',
                    'deque<', 'stack<', '_Rb_global', '_String_base', 'byte_key_map']

    tarray_syms = {}
    stl_syms = {}

    for f in funcs:
        name = f.get('name', '')
        func_qual, params_str = parse_symbol_name(name)

        if 'TArray' in name:
            if func_qual not in tarray_syms:
                tarray_syms[func_qual] = params_str
        elif any(k in name for k in stl_keywords):
            if func_qual not in stl_syms:
                stl_syms[func_qual] = params_str

    return tarray_syms, stl_syms


def group_by_class(symbols):
    """Group symbols by their class name. Returns {class_name: [(method, params, func_qual)]}."""
    classes = defaultdict(list)
    for func_qual, params_str in symbols.items():
        class_name, method_name = split_class_method(func_qual)
        key = class_name if class_name else '__global__'
        classes[key].append((method_name, params_str, func_qual))
    return classes


def generate_file(lines, out_path):
    """Write lines to file."""
    with open(out_path, 'w', encoding='utf-8') as f:
        f.write('\n'.join(lines))


def generate_stubs(symbols, header_include, file_prefix, project_root, category_fn=None):
    """Generate stub .cpp files from a symbols dict.

    Args:
        symbols: {func_qual: params_str}
        header_include: include directive for the header
        file_prefix: prefix for output filenames
        project_root: Path to project root
        category_fn: optional function(class_name) -> category_name for splitting files
    """
    classes = group_by_class(symbols)

    if category_fn:
        # Split into multiple files by category
        categorized = defaultdict(lambda: defaultdict(list))
        for cls, methods in classes.items():
            cat = category_fn(cls)
            categorized[cat][cls] = methods
    else:
        categorized = {'all': classes}

    total_funcs = 0
    unmatched = []

    for cat, cat_classes in sorted(categorized.items()):
        lines = []
        lines.append(f"// {file_prefix}_{cat}_stubs.cpp - Template instantiation stubs ({cat})")
        lines.append("// Auto-generated stub implementations for progress tracking")
        lines.append("// These need to be byte-matched against the original DOL")
        lines.append("")
        lines.append(f'#include "{header_include}"')
        lines.append("")

        func_count = 0
        for cls in sorted(cat_classes.keys()):
            methods = cat_classes[cls]
            if cls != '__global__':
                lines.append(f"// {'=' * 70}")
                lines.append(f"// {cls}")
                lines.append(f"// {'=' * 70}")
                lines.append("")

            for method_name, params_str, func_qual in sorted(methods, key=lambda x: x[0]):
                func_def = format_func_def(func_qual, params_str)

                # Verify it will be captured
                if not verify_func_captured(func_def, func_qual):
                    unmatched.append((func_qual, func_def))

                lines.append(f"// {func_qual}{params_str}")
                lines.append(f"{func_def} {{")

                # Stub body
                class_name, mname = split_class_method(func_qual)
                bare = bare_class_name(class_name) if class_name else None
                if class_name and mname.startswith('~'):
                    lines.append("    // TODO: stub destructor")
                elif class_name and mname == bare:
                    lines.append("    // TODO: stub constructor")
                elif mname == 'operator=':
                    lines.append("    // TODO: stub assignment")
                    if class_name:
                        lines.append("    return *this;")
                else:
                    lines.append("    // TODO: stub")

                lines.append("}")
                lines.append("")
                func_count += 1

        total_funcs += func_count

        out_name = f"{file_prefix}_{cat}_stubs.cpp" if category_fn else f"{file_prefix}_stubs.cpp"
        out_path = project_root / "src" / "templates" / out_name
        generate_file(lines, out_path)

    return total_funcs, unmatched


def categorize_stl(cls):
    """Categorize an STL class name into a file category."""
    if cls == '__global__':
        return 'global'
    if '__node_alloc' in cls:
        return 'node_alloc'
    if '_Deque_base' in cls or 'deque<' in cls or 'stack<' in cls:
        return 'deque'
    if '_Rb_tree' in cls or '_Rb_global' in cls:
        return 'rb_tree'
    if 'vector<' in cls:
        return 'vector'
    if '_List_base' in cls or 'list<' in cls:
        return 'list'
    if 'basic_string' in cls or '_String_base' in cls:
        return 'string'
    if '_Base_bitset' in cls:
        return 'bitset'
    if 'byte_key_map' in cls:
        return 'byte_key_map'
    return 'other'


def categorize_tarray(cls):
    """All TArray classes go in one file."""
    if cls == '__global__':
        return 'global'
    return 'classes'


def generate_type_headers(funcs, project_root):
    """Generate forward declaration headers."""
    # TArray types header
    lines = []
    lines.append("#ifndef TARRAY_TYPES_H")
    lines.append("#define TARRAY_TYPES_H")
    lines.append("")
    lines.append("// Forward declarations for all types used as TArray template parameters")
    lines.append("// Auto-generated from symbol map")
    lines.append("")
    lines.append('#include "types.h"')
    lines.append("")
    lines.append("// Forward class/struct declarations")

    tarray_elements = [
        'BSplineVolume', 'EAnimEvent', 'EAnimNodeDataPos', 'EAnimNote',
        'EBound3', 'ECharacterNode', 'EFontPage', 'EILight', 'ENCamera',
        'ENCameraPoint', 'ENDummy', 'ENDummyPoint', 'ENLattice',
        'ENLatticePoints', 'ERModel', 'ESMSStrip', 'EString', 'EString2',
        'ESubModel', 'ESubModelShader', 'EVec3', 'SimsLightInfo',
        'SndEvtHitPatch',
    ]

    for t in sorted(set(tarray_elements)):
        lines.append(f"struct {t};")

    lines.append("")
    lines.append("// EFileSystem nested type")
    lines.append("struct EFileSystem { struct FileCreator; };")
    lines.append("")
    lines.append("// Stream class")
    lines.append("class EStream;")
    lines.append("")
    lines.append("// Allocator types")
    lines.append("struct TArrayDefaultAllocator;")
    lines.append("struct TArrayERModelAllocator;")
    lines.append("struct TArrayERAnimAllocator;")
    lines.append("struct TArrayERCharacterAllocator;")
    lines.append("struct TArrayERSoundEventAllocator;")
    lines.append("")
    lines.append("// TArray template class")
    lines.append("template <typename T, typename Allocator>")
    lines.append("class TArray {")
    lines.append("public:")
    lines.append("    T* m_data;")
    lines.append("    int m_size;")
    lines.append("    int m_capacity;")
    lines.append("")
    lines.append("    TArray(void);")
    lines.append("    TArray(TArray &other);")
    lines.append("    ~TArray(void);")
    lines.append("")
    lines.append("    void Init(void);")
    lines.append("    void Destruct(T *items, int count);")
    lines.append("    void Construct(T *items, int count);")
    lines.append("    void Copy(T *dst, T *src, int count);")
    lines.append("    void CopyReverse(T *dst, T *src, int count);")
    lines.append("    void SetSize(int size, int grow);")
    lines.append("    void Deallocate(void);")
    lines.append("    void Add(T &item);")
    lines.append("    void Insert(T *pos, int index, int count);")
    lines.append("    TArray &operator=(TArray &other);")
    lines.append("    void DeleteAll(void);")
    lines.append("    void FreeAll(void);")
    lines.append("    void SafeDeleteAll(void);")
    lines.append("};")
    lines.append("")
    lines.append("#endif // TARRAY_TYPES_H")

    out_path = project_root / "include" / "templates" / "tarray_types.h"
    generate_file(lines, out_path)

    # STL types header
    lines = []
    lines.append("#ifndef STL_TYPES_H")
    lines.append("#define STL_TYPES_H")
    lines.append("")
    lines.append("// Forward declarations for all types used in STL template instantiations")
    lines.append("// Auto-generated from symbol map")
    lines.append("")
    lines.append('#include "types.h"')
    lines.append("")

    stl_types = [
        'ACTTarget', 'AmbientScorePlayer', 'AptAuxIDToChar', 'AttachmentNode',
        'AttachmentNodeV1', 'BString', 'BString2', 'CTilePt',
        'CasGenetics', 'CasListener', 'CasSimDescriptionS2C',
        'ChainResFile', 'ConsoleAutoRefCount', 'DiagonalNode',
        'ECTRL_CMD', 'EOrderTableData', 'ERAmbientSound', 'ERDataset',
        'ERModel', 'ERShader', 'ERSoundEvent', 'ERTexture',
        'EResourceManager', 'EResourceMap', 'EString',
        'EdithVariableSet', 'FAMTarget', 'FamilyMember', 'FileRec',
        'IFFResList', 'IFFResNode', 'INVTarget', 'IPoint', 'IRect',
        'ISmartDataFactory', 'InteractorModule',
        'LogInteractionSample', 'MMUTarget', 'MotiveInc',
        'NamespaceSelector', 'Neighbor', 'ObjSelector',
        'ObjectDataID', 'ObjectRecord', 'ObjectSlot',
        'PassiveInfluenceObject', 'PassiveInfluencePerson',
        'PassiveInfluenceTarget', 'PenaltyRect', 'PersDataPair',
        'PrimitiveSample', 'ReconBuffer', 'RelArray', 'RelInt',
        'ResFile', 'Room', 'RouteGoal', 'RoutingSlot',
        'ScoredInteraction', 'SimTickSample', 'SlotDescriptor',
        'SlotLoader', 'SndInstruction', 'SoundEventInfo', 'SpriteSlot',
        'StackElem', 'StackString', 'StateMachineStatus',
        'TreeTableAdQuickData', 'TreeTableEntryQuickData',
        'XObjLang', 'XRoute', 'cBoxX', 'cHitControlGroup',
        'cTrack', 'cXObject', 'cXObjectImpl', 'iResFile',
        'lua_State', 'model_dat',
    ]

    lines.append("// Forward class/struct declarations")
    for t in sorted(set(stl_types)):
        lines.append(f"struct {t};")
    lines.append("")

    lines.append("// Nested type forward declarations")
    lines.append("namespace AutomationNS { struct LuaTable; }")
    lines.append("struct ERDataset { struct ResourceInfo; };")
    lines.append("struct EResourceManager { struct ResourceIndexRecord; };")
    lines.append("struct CasGenetics { struct Grandparent; };")
    lines.append("struct ISmartDataFactory { struct tDataProvider; };")
    lines.append("")
    lines.append("namespace InteractorModule {")
    lines.append("    struct FloorData;")
    lines.append("    struct WallData;")
    lines.append("    struct WallPaperData;")
    lines.append("    struct Interactor;")
    lines.append("    struct InteractorInfo;")
    lines.append("    struct InteractorType;")
    lines.append("    struct InteractorResourceSet;")
    lines.append("    struct InvStock;")
    lines.append("    struct PatternSellCount;")
    lines.append("    struct FenceSellCount;")
    lines.append("    struct PlacementObject { struct ContainerInfo; };")
    lines.append("    struct InteractorManager { struct ActiveInteractor; };")
    lines.append("    struct InteractorInputManager { struct InteractorCommand; };")
    lines.append("}")
    lines.append("")
    lines.append("struct FAMTarget { struct FAM_STATE; };")
    lines.append("struct MMUTarget { struct MMU_MENU_STATE; };")
    lines.append("struct ACTTarget { struct iqRecord; };")
    lines.append("")
    lines.append("// STL-like types (SN Systems / Metrowerks STL)")
    lines.append("template <typename T> struct allocator {};")
    lines.append("template <typename T> struct char_traits {};")
    lines.append("template <typename T> struct less {};")
    lines.append("template <typename T> struct greater {};")
    lines.append("template <typename T> struct equal_to {};")
    lines.append("template <typename T> struct _Identity {};")
    lines.append("template <typename T> struct _Select1st {};")
    lines.append("template <typename T, typename U> struct _Nonconst_traits {};")
    lines.append("")
    lines.append("struct _Rb_tree_node_base;")
    lines.append("template <typename T> struct _Rb_tree_node;")
    lines.append("template <typename T, typename Traits> struct _Rb_tree_iterator;")
    lines.append("")
    lines.append("template <typename T1, typename T2> struct pair { T1 first; T2 second; };")
    lines.append("")
    lines.append("template <bool b, int n> struct __node_alloc;")
    lines.append("template <unsigned int N> struct _Base_bitset;")
    lines.append("")
    lines.append("template <typename T, typename Alloc> struct vector;")
    lines.append("template <typename T, typename Alloc> struct list;")
    lines.append("template <typename T, typename Alloc> struct deque;")
    lines.append("template <typename T, typename Container> struct stack;")
    lines.append("")
    lines.append("template <typename Key, typename Value, typename KeyOfValue,")
    lines.append("          typename Compare, typename Alloc>")
    lines.append("struct _Rb_tree;")
    lines.append("")
    lines.append("template <bool b> struct _Rb_global;")
    lines.append("")
    lines.append("template <typename T, typename Alloc> struct _Deque_base;")
    lines.append("template <typename T, typename Alloc> struct _List_base;")
    lines.append("template <typename T, typename Alloc> struct _String_base;")
    lines.append("")
    lines.append("template <typename Char, typename Traits, typename Alloc>")
    lines.append("struct basic_string;")
    lines.append("")
    lines.append("template <unsigned int N, typename T, typename Alloc> struct byte_key_map;")
    lines.append("")
    lines.append("struct basic_string_ref;")
    lines.append("struct basic_string_ref2;")
    lines.append("")
    lines.append("namespace EA { namespace UnitTest { struct Test; } }")
    lines.append("")
    lines.append("#endif // STL_TYPES_H")

    out_path = project_root / "include" / "templates" / "stl_types.h"
    generate_file(lines, out_path)


def main():
    project_root = Path(__file__).parent.parent

    with open(project_root / 'tools' / 'symbols.json') as f:
        data = json.load(f)

    funcs = [s for s in data['symbols'] if s.get('type') == 'function' and s.get('size', 0) > 0]

    # Collect symbols
    tarray_syms, stl_syms = collect_all_symbols(funcs)
    print(f"TArray unique qualified names: {len(tarray_syms)}")
    print(f"STL unique qualified names: {len(stl_syms)}")

    # Generate headers
    generate_type_headers(funcs, project_root)
    print("Generated type headers in include/templates/")

    # Clean output directory
    out_dir = project_root / "src" / "templates"
    for f in out_dir.glob("*.cpp"):
        f.unlink()

    # Generate TArray stubs
    tarray_count, tarray_unmatched = generate_stubs(
        tarray_syms, "templates/tarray_types.h", "tarray",
        project_root, categorize_tarray)
    print(f"Generated TArray stubs: {tarray_count} functions")

    # Generate STL stubs
    stl_count, stl_unmatched = generate_stubs(
        stl_syms, "templates/stl_types.h", "stl",
        project_root, categorize_stl)
    print(f"Generated STL stubs: {stl_count} functions")

    all_unmatched = tarray_unmatched + stl_unmatched
    if all_unmatched:
        print(f"\nWARNING: {len(all_unmatched)} functions won't be captured by progress tracker regex:")
        for func_qual, func_def in all_unmatched:
            print(f"  func_qual: {func_qual}")
            print(f"  func_def:  {func_def}")
            print()

    print(f"\nTotal: {tarray_count + stl_count} unique function stubs")


if __name__ == '__main__':
    main()
