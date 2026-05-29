#!/usr/bin/env python3
"""Wave-5 batch converter: agent inject_before stubs -> NEW class dirs + semantic .cpp"""
import os, re
from collections import defaultdict

agent_dir = 'src/matched/agent'
matched_dir = 'src/matched'

# Reserved lanes - don't touch
RESERVED = {'InteractorModule', 'INVTarget', 'BString2', 'BString', 'EString', 'EString2', 'EAStringC', 'AptString'}

# Classes/patterns to skip (not real standalone classes)
SKIP_CLASSES = {
    'operator_',       # not a class
}

# Skip nested InteractorModule subclasses (SonnetWorker2 lane)
def is_reserved(cls):
    if cls in RESERVED:
        return True
    if cls in SKIP_CLASSES:
        return True
    if cls.startswith('InteractorModule__'):
        return True
    return False

# Arg suffixes to strip from function names (longest first)
ARG_SUFFIXES = sorted([
    '_void', '_float', '_int', '_unsigned', '_bool', '_char', '_short',
    '_double', '_long', '_ptr', '_ref', '_const', '_ERC', '_void_void',
    '_int_int', '_float_float', '_unsigned_int', '_char_ptr',
    '_EAnimNote', '_SoundManager', '_ESimsCam',
], key=len, reverse=True)


def get_class(fname):
    m = re.match(r'match_0x[0-9A-Fa-f]+_([A-Za-z0-9_]+)__', fname)
    return m.group(1) if m else None


def extract_func_name(base, class_name):
    m = re.match(r'match_0x[0-9A-Fa-f]+_[^_]+__(.+)', base)
    if not m:
        return None
    func_raw = m.group(1)

    # Skip ctors/dtors: same name as class, or ClassName_void, _ClassName, dtor, ~
    if (func_raw == class_name or
            func_raw.lower() == class_name.lower() or
            func_raw.lower() == class_name.lower() + '_void' or
            func_raw.startswith('_' + class_name) or
            func_raw == 'dtor' or func_raw.startswith('~')):
        return None

    # Strip arg suffix
    func_name = func_raw
    for suffix in ARG_SUFFIXES:
        if func_raw.endswith(suffix):
            func_name = func_raw[:-len(suffix)]
            break
    func_name = func_name.rstrip('_')
    if not func_name:
        return None
    return func_name


agent_files = sorted([f for f in os.listdir(agent_dir) if f.endswith('.cpp')])

class_files = defaultdict(list)
for f in agent_files:
    cls = get_class(f)
    if cls:
        class_files[cls].append(f)

converted = 0
skipped_ctor = 0
skipped_reserved = 0
skipped_has_dir = 0  # already has dir (handled in wave-4)
dirs_created = 0
add_list = []
rm_list = []

for cls in sorted(class_files.keys()):
    if is_reserved(cls):
        skipped_reserved += len(class_files[cls])
        continue

    dir_name = cls.lower()
    dir_path = os.path.join(matched_dir, dir_name)

    if os.path.isdir(dir_path):
        # Already has dir - wave-4 territory, skip
        skipped_has_dir += len(class_files[cls])
        continue

    # Create the new directory
    os.makedirs(dir_path, exist_ok=True)
    dirs_created += 1

    for fname in class_files[cls]:
        base = fname[:-4]  # strip .cpp
        src_path = os.path.join(agent_dir, fname)

        # Read source file
        with open(src_path, 'r', encoding='utf-8') as fh:
            content = fh.read()

        func_name = extract_func_name(base, cls)
        if not func_name:
            skipped_ctor += 1
            continue

        # Parse header comment/ASMPROC/extern lines
        lines = content.splitlines()
        comment_lines = []
        extern_lines = []

        for line in lines:
            stripped = line.strip()
            if stripped.startswith('// 0x') or stripped.startswith('// FLAGS:') or stripped.startswith('// ASMPROC'):
                comment_lines.append(line)
            elif stripped.startswith('extern "C" void _s'):
                # Only helper declarations, not old f_ADDR() stubs
                extern_lines.append(line)

        # Build output
        out_lines = comment_lines[:]
        out_lines.append('')
        if extern_lines:
            out_lines += extern_lines
            out_lines.append('')
        out_lines.append('struct ' + cls + ' {')
        out_lines.append('    void ' + func_name + '();')
        out_lines.append('};')
        out_lines.append('')
        out_lines.append('void ' + cls + '::' + func_name + '() {')
        out_lines.append('}')

        new_content = '\n'.join(out_lines) + '\n'

        # Write to class dir
        dest_path = os.path.join(dir_path, fname)
        with open(dest_path, 'w', encoding='utf-8', newline='\n') as fh:
            fh.write(new_content)

        add_list.append(dest_path.replace(os.sep, '/'))
        rm_list.append(src_path.replace(os.sep, '/'))
        converted += 1

print('Dirs created: ' + str(dirs_created))
print('Converted: ' + str(converted))
print('Skipped ctors: ' + str(skipped_ctor))
print('Skipped reserved: ' + str(skipped_reserved))
print('Skipped has-dir (wave-4): ' + str(skipped_has_dir))

# Write pathspec files
with open('.git/sw1_wave5_add.txt', 'w', encoding='utf-8', newline='\n') as fh:
    fh.write('\n'.join(add_list) + '\n')

with open('.git/sw1_wave5_rm.txt', 'w', encoding='utf-8', newline='\n') as fh:
    fh.write('\n'.join(rm_list) + '\n')

print('')
print('Pathspec files written:')
print('  .git/sw1_wave5_add.txt (' + str(len(add_list)) + ' files)')
print('  .git/sw1_wave5_rm.txt (' + str(len(rm_list)) + ' files)')
