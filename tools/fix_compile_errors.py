#!/usr/bin/env python3
"""
Fix compilation errors in src/matched/*.cpp files systematically.

Categories of fixes:
1. Missing #include directives
2. Return type mismatches in stub_classes.h (void vs bool/int)
3. Parameter type mismatches in stub_classes.h
4. Redefinition errors (disable duplicates with #if 0)
5. Missing class/method declarations in stub_classes.h
6. Other fixable issues
"""

import re
import subprocess
import sys
from pathlib import Path
from collections import defaultdict

REPO = Path(__file__).resolve().parent.parent
DEVKITPPC = Path(r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC")
CXX = str(DEVKITPPC / "bin" / "powerpc-eabi-g++.exe")
MATCHED_SRC = REPO / "src" / "matched"
STUB_CLASSES = REPO / "include" / "stub_classes.h"
MATCHED_OBJ = REPO / "build" / "obj" / "matched"

CXXFLAGS = [
    "-mcpu=750", "-meabi", "-mhard-float",
    "-O2", "-fno-schedule-insns", "-fno-schedule-insns2",
    "-fno-inline", "-fno-inline-small-functions",
    "-fno-exceptions", "-fno-rtti", "-fno-builtin",
    "-fshort-wchar", "-nostdinc++",
    "-Wall", "-Wno-unused", "-Wno-return-type", "-fpermissive",
    "-Iinclude", "-Isrc", "-Ilibs/dolphinsdk", "-Ilibs/sn_runtime", "-Ilibs/apt",
    "-DNDEBUG", "-DEA_PLATFORM_GAMECUBE=1", "-DGEKKO",
]


def try_compile(src_path):
    """Try to compile a file. Returns (success, stderr)."""
    obj = MATCHED_OBJ / (src_path.stem + ".o")
    result = subprocess.run(
        [CXX] + CXXFLAGS + ["-c", str(src_path), "-o", str(obj)],
        capture_output=True, text=True, timeout=60,
        cwd=str(REPO)
    )
    return result.returncode == 0, result.stderr


def get_failing_files():
    """Get list of files that fail to compile."""
    MATCHED_OBJ.mkdir(parents=True, exist_ok=True)
    failing = {}
    for src in sorted(MATCHED_SRC.glob("*.cpp")):
        obj = MATCHED_OBJ / (src.stem + ".o")
        if obj.exists() and obj.stat().st_mtime > src.stat().st_mtime:
            continue
        ok, stderr = try_compile(src)
        if not ok:
            failing[src] = stderr
    return failing


def fix_missing_includes():
    """Fix 1: Add missing #include directives."""
    count = 0
    for cpp in sorted(MATCHED_SRC.glob("*.cpp")):
        content = cpp.read_text(errors="replace")
        if "#include" not in content[:200]:
            # Check if file references class methods (uses ::)
            if "::" in content:
                new_content = '#include "types.h"\n#include "stub_classes.h"\n' + content
                cpp.write_text(new_content)
                count += 1
                # Touch to invalidate obj cache
                obj = MATCHED_OBJ / (cpp.stem + ".o")
                if obj.exists():
                    obj.unlink()
    return count


def fix_stub_classes_return_types():
    """Fix 2: Update return types in stub_classes.h to match source files.

    Many functions are declared as void in stub_classes.h but the source
    uses bool or int. Since the rawbyte/asm files use the correct signature,
    update stub_classes.h to match.
    """
    stub_content = STUB_CLASSES.read_text(errors="replace")
    lines = stub_content.split("\n")

    # First, collect all the mismatches from compiler errors
    mismatches = []
    for src in sorted(MATCHED_SRC.glob("*.cpp")):
        obj = MATCHED_OBJ / (src.stem + ".o")
        if obj.exists() and obj.stat().st_mtime > src.stat().st_mtime:
            continue
        ok, stderr = try_compile(src)
        if ok:
            continue

        # Parse "no declaration matches" errors
        for line in stderr.split("\n"):
            m = re.search(r"no declaration matches '(.*?)'", line)
            if m:
                decl = m.group(1)
                mismatches.append(decl)

    # Parse the mismatched declarations to build fix rules
    # Format: "bool ClassName::MethodName(params) const"
    fixes_applied = 0
    for decl in mismatches:
        # Parse: "return_type Class::Method(params) [const]"
        dm = re.match(r'(\w[\w\s\*&]*?)\s+(\w[\w:]*?)::(\w+)\((.*?)\)(\s*const)?$', decl)
        if not dm:
            continue
        ret_type, class_name, method_name, params, const_qual = dm.groups()
        const_qual = const_qual.strip() if const_qual else ""

        # Find the method in stub_classes.h and update its return type
        # Pattern: "    void MethodName(..." or "    int MethodName(..."
        # within the class definition
        in_class = False
        class_depth = 0
        for i, line in enumerate(lines):
            stripped = line.strip()

            # Track class scope
            if re.match(rf'^class\s+{re.escape(class_name)}\s*{{', stripped) or \
               re.match(rf'^class\s+{re.escape(class_name)}\s*:', stripped):
                in_class = True
                class_depth = 0
                continue

            if in_class:
                class_depth += line.count('{') - line.count('}')
                if class_depth < 0:
                    in_class = False
                    continue

                # Look for the method declaration
                # Match: "    void MethodName(" or "    int MethodName(" etc
                mm = re.match(
                    rf'^(\s+)(\w[\w\s\*&]*?)\s+({re.escape(method_name)})\s*\((.*?)\)(.*?);',
                    line
                )
                if mm:
                    indent, old_ret, mname, old_params, old_suffix = mm.groups()
                    # Check if this is the right method (rough param match)
                    if old_ret.strip() != ret_type.strip():
                        new_line = f"{indent}{ret_type} {mname}({old_params}){old_suffix};"
                        lines[i] = new_line
                        fixes_applied += 1
                        break

    if fixes_applied > 0:
        STUB_CLASSES.write_text("\n".join(lines))

    return fixes_applied


def fix_stub_classes_add_methods():
    """Fix 3: Add missing methods to existing classes in stub_classes.h."""
    stub_content = STUB_CLASSES.read_text(errors="replace")
    lines = stub_content.split("\n")

    # Collect "no declaration matches" where we need to add the method
    additions = defaultdict(list)  # class_name -> [(return_type, method_name, params, const)]

    for src in sorted(MATCHED_SRC.glob("*.cpp")):
        obj = MATCHED_OBJ / (src.stem + ".o")
        if obj.exists() and obj.stat().st_mtime > src.stat().st_mtime:
            continue
        ok, stderr = try_compile(src)
        if ok:
            continue

        for line in stderr.split("\n"):
            m = re.search(r"no declaration matches '(.*?)'", line)
            if m:
                decl = m.group(1)
                dm = re.match(r'(\w[\w\s\*&]*?)\s+(\w[\w:]*?)::(\w+)\((.*?)\)(\s*const)?$', decl)
                if dm:
                    ret_type, class_name, method_name, params, const_qual = dm.groups()
                    const_qual = const_qual.strip() if const_qual else ""
                    additions[class_name].append((ret_type, method_name, params, const_qual))

    # Now add methods to classes
    fixes = 0
    for class_name, methods in additions.items():
        # Find the class closing brace
        in_class = False
        class_depth = 0
        insert_line = -1

        for i, line in enumerate(lines):
            stripped = line.strip()
            if re.match(rf'^class\s+{re.escape(class_name)}\s*{{', stripped) or \
               re.match(rf'^class\s+{re.escape(class_name)}\s*:', stripped):
                in_class = True
                class_depth = 0
                continue

            if in_class:
                class_depth += line.count('{') - line.count('}')
                if class_depth < 0:
                    insert_line = i  # Line with };
                    in_class = False
                    break

        if insert_line > 0:
            for ret_type, method_name, params, const_qual in methods:
                const_str = " const" if const_qual else ""
                new_method = f"    {ret_type} {method_name}({params}){const_str};"
                lines.insert(insert_line, new_method)
                insert_line += 1
                fixes += 1

    if fixes > 0:
        STUB_CLASSES.write_text("\n".join(lines))

    return fixes


def fix_redefinitions():
    """Fix 4: Wrap duplicate function definitions in #if 0."""
    count = 0
    for src in sorted(MATCHED_SRC.glob("*.cpp")):
        obj = MATCHED_OBJ / (src.stem + ".o")
        if obj.exists() and obj.stat().st_mtime > src.stat().st_mtime:
            continue
        ok, stderr = try_compile(src)
        if ok:
            continue

        if "redefinition of" not in stderr:
            continue

        # Find which functions are redefined
        redefined_funcs = set()
        for line in stderr.split("\n"):
            m = re.search(r"redefinition of '(.*?)'", line)
            if m:
                redefined_funcs.add(m.group(1))

        if not redefined_funcs:
            continue

        content = src.read_text(errors="replace")
        lines = content.split("\n")
        new_lines = []

        # Find the second (duplicate) definition and wrap it in #if 0
        seen_funcs = set()
        i = 0
        while i < len(lines):
            line = lines[i]

            # Check for annotation
            am = re.match(r'\s*// 0x([0-9A-Fa-f]+)\s+\(\d+ bytes\)', line)
            if am:
                # Look at the next non-comment, non-empty line
                j = i + 1
                while j < len(lines) and (not lines[j].strip() or lines[j].strip().startswith("//")):
                    j += 1

                if j < len(lines):
                    func_line = lines[j]
                    # Check if this function is a redefinition
                    is_redef = False
                    for rf in redefined_funcs:
                        # Extract function name from redefined signature
                        # rf is like "BString::find(const char*, unsigned int) const"
                        if rf.split("(")[0].split("::")[-1] in func_line:
                            if rf in seen_funcs:
                                is_redef = True
                            seen_funcs.add(rf)
                            break

                    if is_redef:
                        new_lines.append("#if 0  // duplicate definition")
                        # Add all lines until end of function
                        while i < len(lines):
                            new_lines.append(lines[i])
                            if lines[i].strip() == "}":
                                new_lines.append("#endif")
                                i += 1
                                break
                            i += 1
                        continue

            new_lines.append(line)
            i += 1

        if len(new_lines) != len(lines):
            src.write_text("\n".join(new_lines))
            count += 1
            obj = MATCHED_OBJ / (src.stem + ".o")
            if obj.exists():
                obj.unlink()

    return count


def fix_endif_without_if():
    """Fix 5: Fix #endif without #if issues."""
    count = 0
    for src in sorted(MATCHED_SRC.glob("*.cpp")):
        content = src.read_text(errors="replace")

        # Count #if and #endif
        if_count = len(re.findall(r'^\s*#if\b', content, re.MULTILINE))
        endif_count = len(re.findall(r'^\s*#endif\b', content, re.MULTILINE))

        if endif_count > if_count:
            # Find and remove extra #endif
            lines = content.split("\n")
            depth = 0
            new_lines = []
            for line in lines:
                stripped = line.strip()
                if re.match(r'#if\b', stripped):
                    depth += 1
                    new_lines.append(line)
                elif stripped == '#endif' or stripped.startswith('#endif '):
                    if depth > 0:
                        depth -= 1
                        new_lines.append(line)
                    else:
                        new_lines.append("// " + line + "  // removed: unmatched #endif")
                        count += 1
                else:
                    new_lines.append(line)

            src.write_text("\n".join(new_lines))
            obj = MATCHED_OBJ / (src.stem + ".o")
            if obj.exists():
                obj.unlink()

    return count


def fix_missing_class_declarations():
    """Fix 6: Add missing class declarations to stub_classes.h."""
    stub_content = STUB_CLASSES.read_text(errors="replace")

    # Find classes that need to be added
    missing_classes = set()
    for src in sorted(MATCHED_SRC.glob("*.cpp")):
        obj = MATCHED_OBJ / (src.stem + ".o")
        if obj.exists() and obj.stat().st_mtime > src.stat().st_mtime:
            continue
        ok, stderr = try_compile(src)
        if ok:
            continue

        for m in re.finditer(r"'(\w+)' has not been declared", stderr):
            cls = m.group(1)
            # Check if it's actually a class (not a variable)
            if cls[0].isupper() or cls.startswith("_"):
                # Check if it exists anywhere in stub_classes.h
                if f"class {cls} " not in stub_content and f"class {cls}\n" not in stub_content:
                    missing_classes.add(cls)

    if not missing_classes:
        return 0

    # For each missing class, scan the source files to find what methods it needs
    class_methods = defaultdict(list)  # class_name -> [(ret_type, method_name, params, const)]

    for cls in missing_classes:
        for src in sorted(MATCHED_SRC.glob("*.cpp")):
            content = src.read_text(errors="replace")
            # Find method definitions like: void ClassName::Method(...)
            for m in re.finditer(
                rf'(\w[\w\s\*&]*?)\s+{re.escape(cls)}::(\w+)\s*\((.*?)\)(\s*const)?\s*{{',
                content
            ):
                ret_type = m.group(1).strip()
                method_name = m.group(2)
                params = m.group(3)
                const = " const" if m.group(4) else ""
                sig = (ret_type, method_name, params, const)
                if sig not in class_methods[cls]:
                    class_methods[cls].append(sig)

    # Build class declarations
    additions = []
    for cls in sorted(missing_classes):
        additions.append(f"class {cls};")
    additions.append("")

    for cls in sorted(missing_classes):
        additions.append(f"class {cls} {{")
        additions.append(f"public:")
        additions.append(f"    char _pad[0x1000];")
        for ret_type, method_name, params, const in class_methods.get(cls, []):
            additions.append(f"    {ret_type} {method_name}({params}){const};")
        additions.append(f"}};")
        additions.append("")

    # Insert before the final #endif
    lines = stub_content.split("\n")
    # Find last #endif
    for i in range(len(lines) - 1, -1, -1):
        if lines[i].strip() == "#endif":
            for j, add_line in enumerate(additions):
                lines.insert(i + j, add_line)
            break

    STUB_CLASSES.write_text("\n".join(lines))
    return len(missing_classes)


def fix_register_scope():
    """Fix 7: Fix register variable scope issues in call_converted files.

    These files use register variables like:
        register int r4 __asm__("r4") = val;
    but the variable name 'r4' conflicts with asm constraints.
    Fix by renaming to __r4, etc.
    """
    count = 0
    for src in sorted(MATCHED_SRC.glob("*.cpp")):
        obj = MATCHED_OBJ / (src.stem + ".o")
        if obj.exists() and obj.stat().st_mtime > src.stat().st_mtime:
            continue
        ok, stderr = try_compile(src)
        if ok:
            continue

        # Check for register scope errors
        reg_errors = set()
        for line in stderr.split("\n"):
            m = re.search(r"'(r\d+)' was not declared in this scope", line)
            if m:
                reg_errors.add(m.group(1))

        if not reg_errors:
            continue

        content = src.read_text(errors="replace")
        # The issue is typically in inline asm where r4 is used as a C variable
        # but it's actually a register reference in the asm constraint
        # Check if the file already declares these registers
        for reg in reg_errors:
            # Add declaration if missing
            if f"register int {reg}" not in content and f"register unsigned int {reg}" not in content:
                # Find where to insert - after the opening brace of the function
                # This is tricky; for now, let's see if we can add a register decl
                pass

        count += 1  # Just count for now

    return count


def fix_invalid_casts():
    """Fix 8: Fix invalid cast errors (EVec3 to char* etc).

    The _med_auto files use (char*) casts on EVec3 references,
    but since EVec3 is a struct, need to use (char*)& instead.
    """
    count = 0
    for src in sorted(MATCHED_SRC.glob("*.cpp")):
        obj = MATCHED_OBJ / (src.stem + ".o")
        if obj.exists() and obj.stat().st_mtime > src.stat().st_mtime:
            continue
        ok, stderr = try_compile(src)
        if ok:
            continue

        if "invalid cast" not in stderr:
            continue

        content = src.read_text(errors="replace")
        # Fix: (char*)varname -> (char*)&varname for struct types
        # Pattern: (char*)identifier + offset
        # The issue is things like: *(int*)((char*)val + 0x0) where val is EVec3&
        # Fix: *(int*)((char*)&val + 0x0)

        # Find all parameters that are struct references
        new_content = content
        # For EVec3& val patterns, we need (char*)&val not (char*)val
        for struct_type in ["EVec3", "EMat4", "EVec4", "EQuat"]:
            # Find parameters of this type
            for pm in re.finditer(rf'{struct_type}\s*&\s*(\w+)', content):
                param_name = pm.group(1)
                # Replace (char*)param_name with (char*)&param_name
                new_content = new_content.replace(
                    f"(char*){param_name}",
                    f"(char*)&{param_name}"
                )

        if new_content != content:
            src.write_text(new_content)
            count += 1
            obj = MATCHED_OBJ / (src.stem + ".o")
            if obj.exists():
                obj.unlink()

    return count


def fix_template_specializations():
    """Fix 9: Fix template specialization errors in TArray files.

    These files try to specialize template member functions but the syntax is wrong.
    Since these are rawbyte files, they don't need proper C++ semantics — they just
    need the right symbol name. Convert them to use explicit template instantiation.
    """
    count = 0
    for src in sorted(MATCHED_SRC.glob("TArray_*_branch_auto.cpp")):
        obj = MATCHED_OBJ / (src.stem + ".o")
        if obj.exists() and obj.stat().st_mtime > src.stat().st_mtime:
            continue
        ok, stderr = try_compile(src)
        if ok:
            continue

        if "specializing member" not in stderr:
            continue

        content = src.read_text(errors="replace")
        # These files have template member functions that can't be specialized this way.
        # The simplest fix is to make them non-template free functions with the mangled name.
        # But that changes the symbol. Instead, just wrap the problematic code.

        # Find the function definition and check if it's a rawbyte function
        if ".byte" in content:
            # It's a rawbyte function — the symbol name comes from the C++ signature
            # The issue is that GCC doesn't allow out-of-line member specialization
            # without the enclosing specialization.
            # Wrap in #if 0 to skip for now.
            new_content = content.replace("// Generated by", "// FIXME: template specialization issue\n// Generated by")
            count += 1

    return count


def fix_static_data_member():
    """Fix 10: Fix 'not a static data member' errors.

    These are typically functions that return values but are written as if they're
    data members. E.g.:
        unsigned int CasSceneDefault::GetRoomModelId = ...
    should be:
        unsigned int CasSceneDefault::GetRoomModelId() { ... }
    """
    count = 0
    for src in sorted(MATCHED_SRC.glob("*.cpp")):
        obj = MATCHED_OBJ / (src.stem + ".o")
        if obj.exists() and obj.stat().st_mtime > src.stat().st_mtime:
            continue
        ok, stderr = try_compile(src)
        if ok:
            continue

        if "is not a static data member" not in stderr:
            continue

        content = src.read_text(errors="replace")
        # The pattern is typically: return_type Class::Method <newline> { ... }
        # But it's missing the () after Method
        # Check the actual content
        # CasSceneDefault::GetRoomModelId looks like it should have ()

        # Actually let's look at what these files contain
        count += 1

    return count


def main():
    print("=" * 70)
    print("FIX COMPILE ERRORS — Systematic fixes for src/matched/*.cpp")
    print("=" * 70)

    MATCHED_OBJ.mkdir(parents=True, exist_ok=True)

    # Step 1: Fix missing includes
    print("\n[1] Fixing missing #include directives...")
    n = fix_missing_includes()
    print(f"  Fixed {n} files")

    # Step 2: Fix #endif without #if
    print("\n[2] Fixing #endif without #if...")
    n = fix_endif_without_if()
    print(f"  Fixed {n} occurrences")

    # Step 3: Fix invalid casts (EVec3 to char*)
    print("\n[3] Fixing invalid casts...")
    n = fix_invalid_casts()
    print(f"  Fixed {n} files")

    # Step 4: Fix return types in stub_classes.h
    print("\n[4] Fixing return types in stub_classes.h...")
    n = fix_stub_classes_return_types()
    print(f"  Fixed {n} return types")

    # Step 5: Add missing methods to stub_classes.h
    print("\n[5] Adding missing methods to stub_classes.h...")
    n = fix_stub_classes_add_methods()
    print(f"  Added {n} methods")

    # Step 6: Add missing class declarations
    print("\n[6] Adding missing class declarations...")
    n = fix_missing_class_declarations()
    print(f"  Added {n} classes")

    # After all stub_classes.h changes, invalidate all objs
    print("\n  Invalidating obj cache after stub_classes.h changes...")
    for obj in MATCHED_OBJ.glob("*.o"):
        obj.unlink()

    # Now recompile and check remaining errors
    print("\n[7] Recompiling all files...")
    failing = get_failing_files()
    print(f"  Remaining errors: {len(failing)}")

    # Show categorized remaining errors
    from collections import Counter
    cats = Counter()
    for src, stderr in failing.items():
        for line in stderr.split("\n"):
            if "error:" in line:
                msg = line.split("error:")[1].strip()
                if "no declaration matches" in msg:
                    cats["no declaration matches"] += 1
                elif "has not been declared" in msg:
                    cats["has not been declared"] += 1
                elif "redefinition" in msg:
                    cats["redefinition"] += 1
                elif "not a member of" in msg:
                    cats["not a member of"] += 1
                elif "was not declared" in msg:
                    cats["not declared in scope"] += 1
                elif "invalid cast" in msg:
                    cats["invalid cast"] += 1
                elif "specializing member" in msg:
                    cats["template specialization"] += 1
                else:
                    cats["other"] += 1
                break

    print("  Error breakdown:")
    for cat, count in cats.most_common():
        print(f"    {count:4d}  {cat}")


if __name__ == "__main__":
    main()
