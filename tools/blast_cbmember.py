#!/usr/bin/env python3
"""
Blast CBMemberTranslator thunks — generate matching .cpp files for all 334 thunks.

Uses the cracked PMF ABI recipe:
  - static thunk member function
  - PMF in CBFunctorBase at offset 0 (8 bytes), m_obj at offset 8
  - local var `obj = f.m_obj` to force CSE
  - // FLAGS: -fno-schedule-insns
  - PMF stored as single-arg type (the dispatch is identical regardless)
"""

import re
import subprocess
import sys
from pathlib import Path

REPO = Path(r"F:\coding\Decompiles\Sims 2")
DVD_MAP = REPO / "extracted" / "files" / "u2_ngc_release_dvd.map"
OUTPUT_DIR = REPO / "src" / "matched" / "cbmt_blast"
VERIFY = REPO / "tools" / "verify_match.sh"
BASH = r"C:\Program Files\Git\bin\bash.exe"

# Pattern: addr size 0 CBMemberTranslator...
ENTRY_RE = re.compile(
    r'^([0-9a-f]{8})\s+(0+78|0+90)\s+0\s+(CBMemberTranslator\S+)<(.+)>::thunk\((.+)\)$'
)


def parse_template(name, args_str, sig_str):
    """Parse template name and args into a structured form."""
    # name is like "CBMemberTranslator0", "CBMemberTranslator1", etc.
    kind = name[len('CBMemberTranslator'):]

    # Split template args at top level (respecting nested <>, parens)
    args = split_top_level(args_str)
    # Split thunk signature args
    sig_args = split_top_level(sig_str)

    return kind, args, sig_args


def split_top_level(s):
    """Split a comma-separated string at top level (depth 0)."""
    parts = []
    depth = 0
    cur = ''
    for ch in s:
        if ch in '<(':
            depth += 1
            cur += ch
        elif ch in '>)':
            depth -= 1
            cur += ch
        elif ch == ',' and depth == 0:
            parts.append(cur.strip())
            cur = ''
        else:
            cur += ch
    if cur.strip():
        parts.append(cur.strip())
    return parts


def extract_classes(args, sig_args):
    """Extract class names that need forward declaration."""
    classes = set()
    text = ' '.join(args + sig_args)
    # Find C++ identifiers that look like classes (start with capital, no spaces)
    # But skip primitive types and qualifiers
    for token in re.findall(r'[A-Za-z_][A-Za-z0-9_]*', text):
        if token in ('void', 'char', 'int', 'short', 'long', 'unsigned', 'signed',
                     'wchar_t', 'float', 'double', 'bool', 'const', 'volatile'):
            continue
        if token.startswith('CBMember') or token == 'CBFunctorBase':
            continue
        classes.add(token)
    return sorted(classes)


def gen_cpp(kind, addr, args, sig_args, full_template_args, full_sig):
    """Generate the C++ source for one thunk."""
    classes = extract_classes(args, sig_args)
    fwd_decls = '\n'.join(f'class {c};' for c in classes)

    # CBMemberTranslator0<T, M>::thunk(CBFunctorBase&)         → 0 extra args
    # CBMemberTranslator1<P1, T, M>::thunk(CBFunctorBase&, P1) → 1 extra arg
    # CBMemberTranslator2<P1, P2, T, M>::thunk(CBFunctorBase&, P1, P2)
    # CBMemberTranslator1wRet<R, P1, T, M>::thunk(CBFunctorBase&, P1) → returns R

    # Sig args: first is "CBFunctorBase &", rest are extra
    extra_sig = sig_args[1:]  # skip CBFunctorBase&

    # For CBMemberTranslator0, T is args[0], M is args[1]
    # For T1: P1=args[0], T=args[1], M=args[2]
    # For T2: P1=args[0], P2=args[1], T=args[2], M=args[3]
    # For T1wRet: R=args[0], P1=args[1], T=args[2], M=args[3]

    # UNIFIED APPROACH: declare PMF as 0-arg `void(T::*)()`, call as `(obj->*pmf)()`.
    # The 30-instruction dispatch is identical regardless of the actual method arity.
    # The thunk's external signature only matters for symbol mangling, not bytes.
    if kind == '0':
        M = args[1]
    elif kind == '1':
        M = args[2]
    elif kind == '2':
        M = args[3]
    elif kind == '1wRet':
        M = args[3]
    elif kind == '2wRet':
        M = args[4]
    else:
        return None
    ret = 'void'
    extras_decl = ''
    extras_call = ''
    pmf_arg_type = ''  # PMF is 0-arg

    # Determine the PMF holder class — search for "CLASS::*" anywhere in M
    m_class_match = re.search(r'\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*::\s*\*\s*\)', M)
    if not m_class_match:
        return None
    pmf_class = m_class_match.group(1)
    if pmf_class not in classes:
        classes.add(pmf_class)
        fwd_decls = '\n'.join(f'class {c};' for c in sorted(classes))

    # Build the source
    has_kind_letter = ''.join(c for c in kind if c.isalpha())
    template_kind_name = f'CBMemberTranslator{kind}'

    # Template declaration based on kind arity
    arity_map = {
        '0': '<class T, class M>',
        '1': '<class P1, class T, class M>',
        '2': '<class P1, class P2, class T, class M>',
        '1wRet': '<class R, class P1, class T, class M>',
        '2wRet': '<class R, class P1, class P2, class T, class M>',
    }
    template_decl = arity_map[kind]

    full_template_args_str = full_template_args
    return_kw = '' if ret == 'void' else 'return '

    # Use free function — avoids template specialization parser issues with
    # types like `unsigned wchar_t` that GCC 2.95 doesn't understand verbatim.
    # Symbol name doesn't matter: inject_matches.py uses // 0xADDR comment.
    src = f"""// FLAGS: -fno-schedule-insns
// {full_template_args}::thunk({full_sig}) at 0x{addr.upper()} (120 bytes)
// PMF ABI crack — generated by blast_cbmember.py
{fwd_decls}

class CBFunctorBase {{
public:
    void ({pmf_class}::*m_pmf)();
    {pmf_class}* m_obj;
}};

void cbmt_thunk_{addr.upper()}(CBFunctorBase& f) {{
    {pmf_class}* obj = f.m_obj;
    (obj->*f.m_pmf)();
}}
"""
    return src


def main():
    # Parse the DVD map
    entries = []
    with open(DVD_MAP, 'r') as f:
        for line in f:
            m = ENTRY_RE.match(line.strip())
            if not m:
                continue
            addr, size_hex, name, args_str, sig_str = m.groups()
            if size_hex != '00000078':
                continue  # skip 144-byte UIDialog variants for now
            entries.append((addr, name, args_str, sig_str))

    print(f'Found {len(entries)} CBMemberTranslator entries to blast', file=sys.stderr)

    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

    matched = 0
    failed = 0
    skipped = 0
    failed_list = []

    for i, (addr, name, args_str, sig_str) in enumerate(entries):
        kind, args, sig_args = parse_template(name, args_str, sig_str)

        full_template = f'{name}<{args_str}>'
        src = gen_cpp(kind, addr, args, sig_args, full_template, sig_str)
        if src is None:
            skipped += 1
            continue

        # Sanitize name for filename
        safe_name = re.sub(r'[^A-Za-z0-9_]', '_', name + '_' + args[0] if args else name)
        safe_name = safe_name[:80]
        out_file = OUTPUT_DIR / f'match_0x{addr.upper()}_{safe_name}.cpp'
        out_file.write_text(src)

        # Verify
        result = subprocess.run(
            [BASH, str(VERIFY), str(out_file.relative_to(REPO)).replace('\\', '/'),
             f'0x{addr.upper()}', '120'],
            capture_output=True, text=True, cwd=str(REPO)
        )
        if 'MATCH!' in result.stdout:
            matched += 1
            if i % 20 == 0:
                print(f'  [{i+1}/{len(entries)}] {addr}: MATCH', file=sys.stderr)
        else:
            failed += 1
            failed_list.append((addr, name, result.stdout[-300:] if result.stdout else result.stderr[-300:]))
            out_file.unlink()  # delete failed file
            if failed <= 5:
                print(f'  [{i+1}/{len(entries)}] {addr}: FAIL ({name})', file=sys.stderr)

    print(f'\n=== RESULTS ===', file=sys.stderr)
    print(f'  Matched: {matched}', file=sys.stderr)
    print(f'  Failed: {failed}', file=sys.stderr)
    print(f'  Skipped: {skipped}', file=sys.stderr)

    if failed_list:
        print(f'\n=== FIRST 5 FAILURES ===', file=sys.stderr)
        for addr, name, output in failed_list[:5]:
            print(f'\n{addr} {name}:', file=sys.stderr)
            print(output, file=sys.stderr)


if __name__ == '__main__':
    main()
