#!/usr/bin/env python3
"""
Mass stub generator for ALL remaining unmatched functions in the Sims 2 GC decomp.

Strategy:
1. Read all symbols from symbols.json
2. Scan non-stub source files to find already-decompiled functions
3. Generate stub files for everything not already decompiled
4. Stubs are written to *_stubs.cpp files grouped by class/namespace

The generator completely replaces all *_stubs.cpp files each run,
ensuring they are always in sync with symbols.json.
"""

import json
import os
import re
from collections import defaultdict
from pathlib import Path


# ─── Configuration ────────────────────────────────────────────────────

# Map class name prefixes to src/ subdirectories
CLASS_TO_DIR = {
    # Core engine
    'ESimsApp': 'core', 'EGlobal': 'core', 'EController': 'core',
    'EControllerManager': 'core', 'EString': 'core', 'EString2': 'core',
    'EMat4': 'core', 'EVec3': 'core', 'EVec4': 'core', 'EStorable': 'core',
    'EResource': 'core', 'EResourceManager': 'core', 'EResourceLoaderImpl': 'core',
    'EOrHouse': 'core', 'ERoom': 'core', 'EIFloor': 'core', 'EIWallPart': 'core',
    'EIStaticModel': 'core', 'EEngine': 'core', 'EApp': 'core',
    'GameData': 'core', 'GameState': 'core', 'PlayerCheats': 'core',
    'QuickStringSet': 'core', 'ChainResFile': 'core', 'NghResFile': 'core',
    'IFFResFile2': 'core', 'ObjectFolderImpl': 'core', 'NeighborhoodImpl': 'core',
    'cFixedWorldImpl': 'core', 'CDirtyXml': 'core',
    'LoadingScreenStateMachine': 'core', 'EyeToyManager': 'core',
    'FastAllocPool': 'core', 'AutomationNS': 'core', 'ELiveMode': 'core',
    'StringBuffer': 'core', 'StringBuffer2': 'core',
    # Sim AI
    'ESim': 'sim', 'SimModel': 'sim', 'TreeSim': 'sim', 'TreeSimImpl': 'sim',
    'ISimInstance': 'sim', 'AwarenessManager': 'sim', 'CASTarget': 'sim',
    'CasSimDescriptionS2C': 'sim', 'CasSimPartsS2C': 'sim',
    'cXPersonImpl': 'sim', 'EdithVariableSet': 'sim', 'ISimsObjectModel': 'sim',
    # Objects
    'cXObjectImpl': 'objects', 'cXMTObjectImpl': 'objects',
    'ObjectModuleImpl': 'objects', 'ObjSelector': 'objects',
    # Build mode
    'InteractorModule': 'build_mode', 'DirectControlTweakTool': 'build_mode',
    'BlendingTweakTool': 'build_mode', 'MiscTweakTool': 'build_mode',
    # Rendering
    'ERModel': 'render', 'ERShader': 'render', 'ERFont': 'render',
    'ERTQuantize4D': 'render', 'ERTQuantize': 'render', 'ENgcRC': 'render',
    'ENgcRenderer': 'render', 'E3DWindow': 'render', 'EWindow': 'render',
    'ESubModelShader': 'render', 'ETexture': 'render',
    # Camera
    'ESimsCam': 'camera',
    # UI / APT
    'AptDate': 'ui', 'AptCIH': 'ui', 'AptMathObj': 'ui', 'AptArray': 'ui',
    'AptString': 'ui', 'AptViewer': 'ui', 'AptActionInterpreter': 'ui',
    'AptCharacterInst': 'ui', 'HUDTarget': 'ui', 'DlgWrapper': 'ui',
    'UIReflow': 'ui', 'WrapperPaneBase': 'ui', 'O2TTarget': 'ui',
    'E2ETarget': 'ui', 'M2MTarget': 'ui', 'MMUTarget': 'ui', 'FAMTarget': 'ui',
    'LoadGameTarget': 'ui', 'SaveGameTarget': 'ui', 'PCTTarget': 'ui',
    'CUIWindow': 'ui', 'CUIPropertySheet': 'ui', 'ScrollingTextBox': 'ui',
    'ActionMenu': 'ui',
    # Effects
    'Effects': 'effects', 'REffectsEmitter': 'effects',
    # Audio
    'ENgcAudio': 'audio',
    # Inventory
    'BBI': 'inventory', 'INVTarget': 'inventory',
    # Save
    'ENgcMemoryCard': 'save',
    # Animation
    'EAnimController': 'animation', 'SAnimator2': 'animation',
    # Skin
    'SkinCompositor': 'skin',
    # EA lib
    'EA': 'libs',
}

# Pattern-based directory assignment
DIR_PATTERNS = [
    (re.compile(r'^Apt'), 'ui'), (re.compile(r'^apt'), 'ui'),
    (re.compile(r'^CUI'), 'ui'), (re.compile(r'^Dlg'), 'ui'),
    (re.compile(r'^UI'), 'ui'), (re.compile(r'^Wrapper'), 'ui'),
    (re.compile(r'^Scrolling'), 'ui'), (re.compile(r'^HUD'), 'ui'),
    (re.compile(r'Target$'), 'ui'),
    (re.compile(r'^ENgcR'), 'render'), (re.compile(r'^ER[A-Z]'), 'render'),
    (re.compile(r'^EI[A-Z]'), 'render'), (re.compile(r'^E3D'), 'render'),
    (re.compile(r'^ETexture'), 'render'), (re.compile(r'^EWindow'), 'render'),
    (re.compile(r'^ESubModel'), 'render'),
    (re.compile(r'^ESim'), 'sim'), (re.compile(r'^Cas'), 'sim'),
    (re.compile(r'^CAS'), 'sim'), (re.compile(r'^Tree'), 'sim'),
    (re.compile(r'^ISim'), 'sim'), (re.compile(r'^cXP'), 'sim'),
    (re.compile(r'^cXO'), 'objects'), (re.compile(r'^cXMT'), 'objects'),
    (re.compile(r'^Object'), 'objects'), (re.compile(r'^Obj'), 'objects'),
    (re.compile(r'^BBI'), 'inventory'), (re.compile(r'^INV'), 'inventory'),
    (re.compile(r'^Interactor'), 'build_mode'),
    (re.compile(r'^Wall'), 'build_mode'),
    (re.compile(r'^Effect'), 'effects'), (re.compile(r'^REffect'), 'effects'),
    (re.compile(r'^Anim'), 'animation'), (re.compile(r'^EAnim'), 'animation'),
    (re.compile(r'^SAnim'), 'animation'),
    (re.compile(r'^Skin'), 'skin'),
    (re.compile(r'^Ambient'), 'audio'), (re.compile(r'^Sound'), 'audio'),
    (re.compile(r'^Game'), 'core'), (re.compile(r'^ENgc'), 'core'),
    (re.compile(r'^EResource'), 'core'), (re.compile(r'^EController'), 'core'),
    (re.compile(r'^EMat'), 'core'), (re.compile(r'^EVec'), 'core'),
    (re.compile(r'^EString'), 'core'), (re.compile(r'^EGlobal'), 'core'),
    (re.compile(r'^EApp'), 'core'), (re.compile(r'^EA[A-Z]'), 'libs'),
    (re.compile(r'^Neighbor'), 'core'), (re.compile(r'^cFixed'), 'core'),
    (re.compile(r'^Chain'), 'core'), (re.compile(r'^Ngh'), 'core'),
    (re.compile(r'^IFF'), 'core'), (re.compile(r'^Quick'), 'core'),
    (re.compile(r'^CDirty'), 'core'), (re.compile(r'^Loading'), 'core'),
    (re.compile(r'^EyeToy'), 'core'), (re.compile(r'^Player'), 'core'),
    (re.compile(r'^Save'), 'save'), (re.compile(r'^MemCard'), 'save'),
    (re.compile(r'^Motive'), 'sim'), (re.compile(r'^Behavior'), 'sim'),
    (re.compile(r'^Routing'), 'sim'), (re.compile(r'^Action'), 'ui'),
    (re.compile(r'^_Bs_'), 'core'), (re.compile(r'^BString'), 'core'),
    (re.compile(r'^Automation'), 'core'), (re.compile(r'^Direct'), 'build_mode'),
    (re.compile(r'^Blending'), 'build_mode'), (re.compile(r'^Misc'), 'core'),
    (re.compile(r'^TArray'), 'templates'), (re.compile(r'^list'), 'templates'),
    (re.compile(r'^vector'), 'templates'), (re.compile(r'^deque'), 'templates'),
    (re.compile(r'^basic_string'), 'templates'),
    (re.compile(r'^_Rb_tree'), 'templates'),
    (re.compile(r'^__node_alloc'), 'templates'),
    (re.compile(r'^EStream'), 'core'), (re.compile(r'^Memory'), 'core'),
    (re.compile(r'^Recon'), 'save'), (re.compile(r'^String'), 'core'),
    (re.compile(r'^CB'), 'core'),
]


def get_dir_for_class(class_name):
    """Determine the src/ subdirectory for a given class name."""
    base_name = class_name.split('<')[0] if '<' in class_name else class_name
    if base_name in CLASS_TO_DIR:
        return CLASS_TO_DIR[base_name]
    for pattern, directory in DIR_PATTERNS:
        if pattern.match(base_name):
            return directory
    return 'core'


def load_symbols(path):
    with open(path) as f:
        return json.load(f)


def scan_non_stub_files(src_dir):
    """Scan non-stub .cpp files to find function names that are already decompiled.
    Returns the set of all names captured by the progress tracker regexes."""
    decompiled = set()
    if not os.path.exists(src_dir):
        return decompiled

    # Same patterns as progress.py
    patterns = [
        re.compile(r'^[A-Za-z_][\w:*&<> ]+\s+(\w[\w:]+)\s*\(', re.MULTILINE),
        re.compile(r'^(?:[\w*& ]+\s+)?([A-Za-z_~][\w]*(?:<[^()]*>)?(?:::~?[\w]+)+)\s*\(', re.MULTILINE),
        re.compile(r'^(?:[\w*& ]+\s+)?([A-Za-z_][\w]*<[^()]*>::operator[^\s(]+)\s*\(', re.MULTILINE),
        re.compile(r'^([\w*&<>, ]+\s+operator[<>=!]+<[^()]*>)\s*\(', re.MULTILINE),
        re.compile(r'^(?:[\w*& ]+\s+)?(\w[\w:]*::operator\s*(?:new|delete|\[\]))\s*\(', re.MULTILINE),
        re.compile(r'^([\w<>,*& ]+\s+[\w_]+<[^()]*>)\s*\(', re.MULTILINE),
        re.compile(r'^(?:[\w*& ]+\s+)?(\w[\w:]*::operator\s*[^\s(]+)\s*\(', re.MULTILINE),
        re.compile(r'^[\w*& ]+\s+(operator[<>=!+\-*/^&|~\[\]]+)\s*\(', re.MULTILINE),
        re.compile(r'^(?:void|int|unsigned|bool|float|double|char|short|long|signed)\s+([\w_]+<[^>]*(?:\([^)]*\))?[^>]*>)\s*\(', re.MULTILINE),
    ]

    for root, dirs, files in os.walk(src_dir):
        for fname in files:
            if not fname.endswith('.cpp'):
                continue
            # SKIP stub files — we will regenerate them
            if fname.endswith('_stubs.cpp'):
                continue
            fpath = os.path.join(root, fname)
            with open(fpath, 'r', encoding='utf-8', errors='replace') as fh:
                content = fh.read()
                for pat in patterns:
                    decompiled.update(pat.findall(content))

    return decompiled


def should_skip_symbol(name):
    """Return True if this symbol should not get a stub."""
    if not name:
        return True
    if 'virtual table' in name:
        return True
    if 'typeinfo' in name.lower():
        return True
    if '__sinit' in name:
        return True
    if '__static_initialization_and_destruction' in name:
        return True
    if name.startswith('global constructors keyed to'):
        return True
    if name.startswith('global destructors keyed to'):
        return True
    if '(' not in name:
        return True
    return False


def is_function_matched(name, decompiled_set):
    """Check if a symbol is already matched by progress tracker logic."""
    func_qual = name.split('(')[0].strip() if name else ''
    func_short = func_qual.split('::')[-1] if func_qual else ''
    return func_qual in decompiled_set or func_short in decompiled_set


def find_first_open_paren(name):
    """Find the first '(' that starts the parameter list (not inside templates).

    Handles all operator overload cases:
    - 'operator<<<int, ...>(' -- operator<< with template <int,...>
    - 'operator<=(char *, ...' -- operator<= with param list
    - 'EMat4::operator=(EMat4 &)' -- operator= with params
    - 'operator new(unsigned int)' -- word-based operators
    """
    # Strategy: find all candidate '(' positions, pick the right one.
    # For non-operator functions, it's straightforward depth tracking.
    # For operator functions, we need special handling.

    # Check for operator keyword (preceded by ::, space, or start of string)
    op_idx = -1
    for m in re.finditer(r'(?:^|::|(?<=\s))operator', name):
        op_idx = m.end()  # position right after 'operator'

    if op_idx < 0:
        # No operator - standard depth tracking
        depth = 0
        for i, c in enumerate(name):
            if c == '<':
                depth += 1
            elif c == '>':
                depth -= 1
            elif c == '(' and depth == 0:
                return i
        return -1

    # Has operator keyword. Determine the operator symbol length.
    # After 'operator', we might have:
    # - Symbolic: = == != < > <= >= << >> <<< (with template) + - * / [] () new delete
    # - Then optionally template args: <...>
    # - Then the parameter list: (...)

    # Find what comes after 'operator':
    rest = name[op_idx:]

    # Skip optional whitespace
    j = 0
    while j < len(rest) and rest[j] == ' ':
        j += 1

    # Word-based operators: new, delete, new[], delete[]
    word_op = re.match(r'(new\s*\[\]|delete\s*\[\]|new|delete)\s*', rest[j:])
    if word_op:
        # Parameter list starts right after the operator word
        param_start = op_idx + j + word_op.end()
        # Find the ( from there
        for i in range(param_start, len(name)):
            if name[i] == '(':
                return i
        return -1

    # Symbolic operators: figure out how many symbol chars belong to the operator
    # The key insight: operator<< has exactly 2 '<' chars
    # operator<<< is operator<< followed by template <
    # operator<= has 1 '<' and 1 '='
    # operator= has 1 '='
    # operator[] has '[]'

    # Match the operator symbols
    sym_match = re.match(r'([<>=!+\-*/^&|~]+|\[\]|\(\))', rest[j:])
    if sym_match:
        op_sym = sym_match.group(1)
        after_sym_pos = op_idx + j + sym_match.end()

        # Special case: operator<< or operator>> followed by template <
        # If op_sym is '<<' or '>>' and next char is '<', that < starts template args
        # If op_sym is '<<<', it's really operator<< + template <, so trim to <<

        # For operators containing < or >: the operator part is at most 2 chars of < or >
        # operator< (1 char), operator<< (2 chars), operator> (1), operator>> (2)
        # operator<= (2 chars: < =), operator>= (2 chars: > =)
        if len(op_sym) > 2 and op_sym.startswith('<<'):
            # It's operator<< plus template < chars
            op_sym = '<<'
            after_sym_pos = op_idx + j + 2
        elif len(op_sym) > 2 and op_sym.startswith('>>'):
            op_sym = '>>'
            after_sym_pos = op_idx + j + 2

        # Now from after_sym_pos, track depth for template args, then find (
        depth = 0
        for i in range(after_sym_pos, len(name)):
            c = name[i]
            if c == '<':
                depth += 1
            elif c == '>':
                depth -= 1
            elif c == '(' and depth == 0:
                return i
        return -1

    # Fallback: just find first ( after operator position
    for i in range(op_idx, len(name)):
        if name[i] == '(':
            return i
    return -1


def split_on_spaces(s):
    """Split string on spaces, preserving content inside angle brackets."""
    tokens = []
    current = ''
    depth = 0
    for c in s:
        if c == '<':
            depth += 1
            current += c
        elif c == '>':
            depth -= 1
            current += c
        elif c == ' ' and depth == 0:
            if current:
                tokens.append(current)
            current = ''
        else:
            current += c
    if current:
        tokens.append(current)
    return tokens


def strip_return_type(qual):
    """Strip leading return type from a qualified name if present.
    Returns (return_type_str, core_name).

    Handles tricky cases like:
    - 'ERoomWall::operator new' -> ('', 'ERoomWall::operator new')
    - 'void ERoomWall::operator new' -> ('void', 'ERoomWall::operator new')
    - 'void* ERoomWall::operator new' -> ('void*', 'ERoomWall::operator new')
    - 'EStream & operator<<<int, ...>' -> ('EStream &', 'operator<<<int, ...>')
    - 'Memory::HandleNode * ReconSaveObject<...>' -> ('Memory::HandleNode *', 'ReconSaveObject<...>')
    """
    tokens = split_on_spaces(qual)
    if len(tokens) <= 1:
        return ('', qual)

    # Merge 'operator' with following token(s) since 'operator new', 'operator delete',
    # 'operator[]', 'operator<<', etc. are single entities
    # Also merge '{anonymous}' with the following token if it looks like a qualified name
    merged = []
    i = 0
    while i < len(tokens):
        t = tokens[i]
        # Check if this token ends with '::operator' or IS 'operator'
        if t == 'operator' or t.endswith('::operator'):
            # Merge with next token if available
            if i + 1 < len(tokens):
                merged.append(t + ' ' + tokens[i+1])
                i += 2
                continue
        # Merge {anonymous} with following identifier (namespace-like usage)
        if t == '{anonymous}' and i + 1 < len(tokens):
            next_t = tokens[i+1]
            if next_t and (next_t[0].isalpha() or next_t[0] == '_' or next_t[0] == '~'):
                merged.append(t + ' ' + next_t)
                i += 2
                continue
        merged.append(t)
        i += 1
    tokens = merged

    if len(tokens) <= 1:
        return ('', qual)

    # Walk from end to find the function name token
    func_start = len(tokens) - 1
    while func_start > 0:
        t = tokens[func_start]
        if t in ('*', '&', 'const'):
            func_start -= 1
        else:
            break

    ret_part = ' '.join(tokens[:func_start])
    core_part = ' '.join(tokens[func_start:])
    return (ret_part, core_part)


def get_class_from_core_name(core_name):
    """Extract the top-level class name from a core function name like 'Foo::Bar::Baz'."""
    depth = 0
    last_sep = -1
    for i in range(len(core_name)):
        c = core_name[i]
        if c == '<':
            depth += 1
        elif c == '>':
            depth -= 1
        elif c == ':' and i + 1 < len(core_name) and core_name[i+1] == ':' and depth == 0:
            last_sep = i

    if last_sep < 0:
        return None

    class_part = core_name[:last_sep]
    top_class = class_part.split('<')[0].split('::')[0]
    return top_class


def is_constructor_or_destructor(core_name):
    """Check if a method is a ctor/dtor based on its core name."""
    depth = 0
    last_sep = -1
    for i in range(len(core_name)):
        c = core_name[i]
        if c == '<':
            depth += 1
        elif c == '>':
            depth -= 1
        elif c == ':' and i + 1 < len(core_name) and core_name[i+1] == ':' and depth == 0:
            last_sep = i

    if last_sep < 0:
        return False

    method_name = core_name[last_sep+2:]
    class_part = core_name[:last_sep]

    # Collect class name components
    class_names = set()
    depth = 0
    current = ''
    for c in class_part:
        if c == '<':
            depth += 1
            current += c
        elif c == '>':
            depth -= 1
            current += c
        elif c == ':' and depth == 0:
            if current:
                class_names.add(current.split('<')[0])
            current = ''
        else:
            current += c
    if current:
        class_names.add(current.split('<')[0])

    if method_name in class_names or method_name.lstrip('~') in class_names:
        return True
    if method_name.startswith('~'):
        return True
    return False


def classify_function(name):
    """Classify a function into (category, group_name).
    Categories: 'class', 'template_class', 'anonymous', 'free', 'free_template', 'free_operator'
    """
    paren_idx = find_first_open_paren(name)
    if paren_idx < 0:
        # Can't find params -- treat as unclassifiable free function
        # but still check for {anonymous} at top level
        qual = name.split('(')[0].strip() if '(' in name else name
        if qual.startswith('{anonymous}') or ':: {anonymous}' in qual:
            return ('anonymous', '{anonymous}')
        return ('free', 'free_functions')

    qual = name[:paren_idx].strip()
    _, core_name = strip_return_type(qual)

    # Check for {anonymous} ONLY at the top level of the name (not inside template args)
    # {anonymous}::Func -> anonymous
    # AddUnitTest<{anonymous}::Test>::Method -> template_class (anonymous is inside <>)
    top_level_anon = False
    depth = 0
    for i, c in enumerate(core_name):
        if c == '<':
            depth += 1
        elif c == '>':
            depth -= 1
        elif c == '{' and depth == 0 and core_name[i:].startswith('{anonymous}'):
            top_level_anon = True
            break

    if top_level_anon:
        return ('anonymous', '{anonymous}')

    if '::' in core_name:
        depth = 0
        last_sep = -1
        for i in range(len(core_name)):
            c = core_name[i]
            if c == '<':
                depth += 1
            elif c == '>':
                depth -= 1
            elif c == ':' and i + 1 < len(core_name) and core_name[i+1] == ':' and depth == 0:
                last_sep = i

        if last_sep >= 0:
            class_part = core_name[:last_sep]
            if '<' in class_part.split('::')[0]:
                return ('template_class', class_part)
            top_class = class_part.split('::')[0]
            return ('class', top_class)

    if core_name.startswith('operator'):
        # Check if '<' is a template bracket or part of operator name (like <=, <<)
        # Template brackets come AFTER the operator symbol: operator<<<int,...>
        # But operator<= has no template
        op_match = re.match(r'operator\s*([<>=!+\-*/^&|~\[\]]+)', core_name)
        if op_match:
            op_sym = op_match.group(1)
            # For << or >>: the operator is 2 chars, rest might be template
            # operator<<<int,...> -> operator<< + template <int,...>
            # operator<= -> operator<= (no template)
            if '<' in op_sym:
                # Count consecutive < at start of op_sym
                num_lt = 0
                for c in op_sym:
                    if c == '<':
                        num_lt += 1
                    else:
                        break
                # Operator part is at most 2 < chars (operator< or operator<<)
                actual_op_len = min(num_lt, 2)
                # If there are more < chars, those are template brackets
                if num_lt > actual_op_len:
                    return ('free_template', 'free_template_functions')
                # Check remaining part of op_sym after < chars
                rest_sym = op_sym[num_lt:]
                if rest_sym:  # e.g. <= has '=' after '<'
                    pass  # no template, just operator<=
                else:
                    # Just operator< or operator<< with no template
                    pass
            elif '>' in op_sym:
                num_gt = 0
                for c in op_sym:
                    if c == '>':
                        num_gt += 1
                    else:
                        break
                actual_op_len = min(num_gt, 2)
                if num_gt > actual_op_len:
                    return ('free_template', 'free_template_functions')
            # Check if there's a template < after the matched operator symbols
            after_op = op_match.end()
            remaining = core_name[after_op:]
            if remaining.startswith('<'):
                return ('free_template', 'free_template_functions')
        return ('free_operator', 'free_operators')

    if '<' in core_name:
        return ('free_template', 'free_template_functions')
    return ('free', 'free_functions')


def format_stub(sym, dedup_set):
    """Generate a stub string for a symbol. Returns (stub, sig_key) or (None, None)."""
    name = sym['name']
    address = sym.get('address', '0x00000000')
    size = sym.get('size', 0)

    paren_idx = find_first_open_paren(name)
    if paren_idx < 0:
        return None, None

    qual_name = name[:paren_idx].strip()
    params_str = name[paren_idx:]

    ret_prefix, core_name = strip_return_type(qual_name)
    is_anon = '{anonymous}' in core_name

    if is_anon:
        # Strip {anonymous}:: or {anonymous} prefix
        anon_core = core_name.replace('{anonymous}::', '').replace('{anonymous} ', '').replace('{anonymous}', '')
        if not anon_core:
            return None, None
        if ret_prefix:
            sig = f"{ret_prefix} {anon_core}{params_str}"
        else:
            sig = f"void {anon_core}{params_str}"
        sig_key = anon_core

    elif '::' in core_name:
        # Class method
        if is_constructor_or_destructor(core_name):
            ret_type = ''
        elif ret_prefix:
            ret_type = ret_prefix
        elif 'operator new' in core_name:
            ret_type = 'void*'
        elif 'operator delete' in core_name:
            ret_type = 'void'
        elif 'operator[]' in core_name:
            ret_type = 'void*'
        elif 'operator==' in core_name or 'operator!=' in core_name:
            ret_type = 'bool'
        elif 'operator<' in core_name or 'operator>' in core_name:
            ret_type = 'bool'
        elif 'operator' in core_name:
            ret_type = 'void'
        else:
            ret_type = 'void'

        if ret_type:
            sig = f"{ret_type} {core_name}{params_str}"
        else:
            sig = f"{core_name}{params_str}"
        sig_key = core_name

    elif core_name.startswith('operator') or '<' in core_name:
        # Free operator or template
        if ret_prefix:
            sig = f"{ret_prefix} {core_name}{params_str}"
        else:
            sig = f"void {core_name}{params_str}"
        sig_key = core_name

    else:
        # Regular free function
        if ret_prefix:
            sig = f"{ret_prefix} {core_name}{params_str}"
        else:
            sig = f"void {core_name}{params_str}"
        sig_key = core_name

    # Dedup
    if sig_key in dedup_set:
        return None, None
    dedup_set.add(sig_key)

    # Body - determine based on the return type portion of the signature
    # Extract just the return type part (everything before the function name)
    # Use ret_prefix which was extracted by strip_return_type
    actual_ret = ret_prefix.strip() if ret_prefix else ''
    if not actual_ret or actual_ret == 'void':
        body = ' '
    elif 'void*' in actual_ret or 'void *' in actual_ret or actual_ret.endswith('*'):
        body = '\n    return 0;\n'
    elif actual_ret == 'bool':
        body = '\n    return false;\n'
    elif actual_ret in ('int', 'float', 'double', 'short', 'long', 'char') or \
         actual_ret.startswith('unsigned') or actual_ret.startswith('signed'):
        body = '\n    return 0;\n'
    else:
        body = ' '

    return f"// {address} | {size} bytes\n{sig} {{{body}}}\n", sig_key


def make_safe_filename(name):
    """Convert a class/group name to a safe filename component."""
    base = name.split('<')[0]
    base = base.replace('::', '_')
    base = re.sub(r'[^a-zA-Z0-9_]', '', base)
    base = base.lower()
    return base or 'misc'


def main():
    project_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    os.chdir(project_root)

    print("Loading symbols...")
    data = load_symbols('tools/symbols.json')
    all_symbols = data['symbols']
    functions = [s for s in all_symbols if s.get('type') == 'function' and s.get('size', 0) > 0]
    print(f"  Total functions: {len(functions)}")

    print("Scanning non-stub source files...")
    decompiled = scan_non_stub_files('src')
    print(f"  Already decompiled names: {len(decompiled)}")

    # Collect functions that need stubs
    need_stubs = []
    for sym in functions:
        name = sym.get('name', '')
        if should_skip_symbol(name):
            continue
        if is_function_matched(name, decompiled):
            continue
        need_stubs.append(sym)

    print(f"  Functions needing stubs: {len(need_stubs)}")

    # Delete all existing _stubs.cpp files (we'll regenerate them)
    deleted = 0
    for root, dirs, files_list in os.walk('src'):
        for fname in files_list:
            if fname.endswith('_stubs.cpp'):
                os.remove(os.path.join(root, fname))
                deleted += 1
    print(f"  Deleted {deleted} old stub files")

    # Group functions
    groups = defaultdict(list)
    for sym in need_stubs:
        name = sym['name']
        category, group_name = classify_function(name)

        if category == 'anonymous':
            groups[('core', 'anonymous_stubs')].append(sym)
        elif category in ('class', 'template_class'):
            if category == 'template_class':
                base = group_name.split('<')[0]
                d = get_dir_for_class(base)
                fn = make_safe_filename(group_name) + '_stubs'
            else:
                d = get_dir_for_class(group_name)
                fn = make_safe_filename(group_name) + '_stubs'
            groups[(d, fn)].append(sym)
        elif category == 'free_template':
            groups[('templates', 'free_template_stubs')].append(sym)
        elif category == 'free_operator':
            groups[('core', 'free_operator_stubs')].append(sym)
        else:
            groups[('core', 'free_function_stubs')].append(sym)

    print(f"  Groups: {len(groups)}")

    total_stubs = 0
    files_written = 0

    for (directory, fname_base), syms in sorted(groups.items()):
        syms.sort(key=lambda s: s.get('address', '0x00000000'))

        dedup_set = set()
        stubs = []
        for sym in syms:
            stub, sig_key = format_stub(sym, dedup_set)
            if stub:
                stubs.append(stub)

        if not stubs:
            continue

        out_dir = os.path.join('src', directory)
        out_path = os.path.join(out_dir, f'{fname_base}.cpp')
        os.makedirs(out_dir, exist_ok=True)

        group_label = fname_base.replace('_stubs', '').replace('_', ' ').title()

        lines = [
            f'// {fname_base}.cpp - Stub implementations for {group_label}',
            f'// Auto-generated from symbols.json - {len(stubs)} functions',
            f'// These are stub implementations to register progress.',
            f'// Each function needs proper decompilation to match the original binary.',
            f'',
            f'#include "types.h"',
            f'',
        ]
        for stub in stubs:
            lines.append(stub)

        with open(out_path, 'w', encoding='utf-8') as fh:
            fh.write('\n'.join(lines))

        total_stubs += len(stubs)
        files_written += 1
        if len(stubs) >= 10:
            print(f"  {out_path}: {len(stubs)} stubs")

    print(f"\n{'='*60}")
    print(f"  Total stubs generated: {total_stubs}")
    print(f"  Stub files written:    {files_written}")
    print(f"{'='*60}")


if __name__ == '__main__':
    main()
