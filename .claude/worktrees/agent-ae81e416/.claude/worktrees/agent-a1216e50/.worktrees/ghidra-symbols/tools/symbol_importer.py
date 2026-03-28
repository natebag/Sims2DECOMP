# Sims 2 GameCube -- Ghidra Symbol Import Script
# @author Sims 2 GC Decomp Project
# @category Sims2
# @description Import 23K+ symbols from dtk symbols.txt and symbol_names.txt into Ghidra
#
# Usage:
#   1. Open Ghidra and import main.dol or u2_ngc_release_dvd.elf
#   2. Open the Script Manager (Window > Script Manager)
#   3. Add this script's directory to the Script Directories
#   4. Run "symbol_importer.py"
#
# The script reads:
#   - config/symbols.txt   (dtk format: sanitized names, addresses, types, sizes)
#   - config/symbol_names.txt (mapping: sanitized name -> original demangled C++ name)
#
# It creates:
#   - Functions at .init/.text addresses
#   - Data labels at .data/.rodata/.bss addresses
#   - Namespaces for C++ classes (e.g., ESimsApp::Init -> namespace ESimsApp)

import os
import re
import time

from ghidra.program.model.symbol import SourceType, Namespace
from ghidra.program.model.listing import CodeUnit


def get_project_root():
    """Find the project root by looking for config/symbols.txt relative to this script."""
    # Try the script's directory first (tools/ -> project root)
    script_dir = os.path.dirname(getSourceFile().getAbsolutePath())
    project_root = os.path.dirname(script_dir)

    symbols_path = os.path.join(project_root, "config", "symbols.txt")
    if os.path.isfile(symbols_path):
        return project_root

    # Fallback: ask user
    from ghidra.util import Msg
    Msg.showError(None, None, "Symbol Importer",
        "Cannot find config/symbols.txt.\n"
        "Make sure this script is in the tools/ directory of the project.")
    return None


def parse_symbols_txt(path):
    """Parse dtk symbols.txt into a list of symbol dicts.

    Format: name = section:0xADDR; // type:function size:0xNN scope:global
    """
    symbols = []
    # Pattern: name = .section:0xADDR; // attrs...
    pattern = re.compile(
        r'^(\S+)\s*=\s*(\.\w+):0x([0-9a-fA-F]+);\s*//\s*(.*)$'
    )

    with open(path, 'r') as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('//'):
                continue

            m = pattern.match(line)
            if not m:
                continue

            name = m.group(1)
            section = m.group(2)
            addr = int(m.group(3), 16)
            attrs_str = m.group(4)

            # Parse attributes
            attrs = {}
            for part in attrs_str.split():
                if ':' in part:
                    k, v = part.split(':', 1)
                    attrs[k] = v

            sym_type = attrs.get('type', 'object')
            size_str = attrs.get('size', '0')
            if size_str.startswith('0x') or size_str.startswith('0X'):
                size = int(size_str, 16)
            else:
                size = int(size_str)

            symbols.append({
                'sanitized_name': name,
                'section': section,
                'address': addr,
                'type': sym_type,
                'size': size,
            })

    return symbols


def parse_name_mapping(path):
    """Parse symbol_names.txt into a dict: address -> original demangled name.

    Format: 0xADDR  sanitized_name  =  Original::Demangled(Name)
    """
    mapping = {}  # addr -> demangled name

    if not os.path.isfile(path):
        return mapping

    pattern = re.compile(
        r'^0x([0-9a-fA-F]+)\s+\S+\s+=\s+(.+)$'
    )

    with open(path, 'r') as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('//'):
                continue

            m = pattern.match(line)
            if not m:
                continue

            addr = int(m.group(1), 16)
            demangled = m.group(2).strip()
            mapping[addr] = demangled

    return mapping


def extract_namespace_and_name(demangled):
    """Split a demangled C++ name into (namespace_parts, short_name).

    Examples:
        "ESimsApp::Init(void)" -> (["ESimsApp"], "Init")
        "BBI::InventoryItems::GetItem(int)" -> (["BBI", "InventoryItems"], "GetItem")
        "HandleBloomEvent(EAnimNote &, FrameEffectsManager *)" -> ([], "HandleBloomEvent")
        "{anonymous}::Foo()" -> ([], "Foo")
        "ESimsApp::~ESimsApp(void)" -> (["ESimsApp"], "~ESimsApp")
        "global constructors keyed to gRebootTimer" -> ([], "global_constructors_keyed_to_gRebootTimer")
    """
    # Strip parameter list: find the outermost '(' that is part of the function signature
    # Be careful with nested parens in types like "operator()"
    name_part = demangled

    # Find the function's parameter list start
    # Walk backwards from end to find matching parens
    paren_depth = 0
    param_start = -1
    for i in range(len(name_part) - 1, -1, -1):
        if name_part[i] == ')':
            paren_depth += 1
        elif name_part[i] == '(':
            paren_depth -= 1
            if paren_depth == 0:
                param_start = i
                break

    if param_start > 0:
        name_part = name_part[:param_start]

    # Handle {anonymous} namespace - strip it
    name_part = name_part.replace('{anonymous}::', '')

    # Handle "global constructors keyed to X" style names
    if name_part.startswith('global '):
        safe = name_part.replace(' ', '_')
        return ([], safe)

    # Split on :: for namespaces
    parts = name_part.split('::')

    if len(parts) == 1:
        return ([], parts[0].strip())

    ns_parts = [p.strip() for p in parts[:-1]]
    short_name = parts[-1].strip()

    return (ns_parts, short_name)


def make_ghidra_label(sanitized_name, demangled):
    """Create a Ghidra-safe label from the demangled name.

    Ghidra labels cannot contain: spaces, parens, angle brackets, commas, &, *
    We use the sanitized dtk name as a reliable fallback, but try to
    produce a cleaner version from the demangled name first.
    """
    if not demangled:
        return sanitized_name

    ns_parts, short_name = extract_namespace_and_name(demangled)

    # If we got a clean short name, use it (namespace is set separately)
    if short_name and re.match(r'^[~]?[A-Za-z_][A-Za-z0-9_]*$', short_name):
        return short_name

    # Fall back to sanitized name but strip namespace prefixes
    # (Ghidra handles namespaces separately)
    label = sanitized_name
    # Remove leading namespace__ prefixes if we're going to set namespace
    if ns_parts:
        prefix = '__'.join(ns_parts) + '__'
        if label.startswith(prefix):
            label = label[len(prefix):]

    return label


def get_or_create_namespace(program, ns_parts):
    """Get or create a nested namespace hierarchy.

    e.g., ["BBI", "InventoryItems"] creates BBI::InventoryItems
    """
    if not ns_parts:
        return program.getGlobalNamespace()

    symbol_table = program.getSymbolTable()
    parent = program.getGlobalNamespace()

    for part in ns_parts:
        # Skip empty or invalid parts
        if not part or not re.match(r'^[A-Za-z_][A-Za-z0-9_]*$', part):
            continue

        existing = symbol_table.getNamespace(part, parent)
        if existing is not None:
            parent = existing
        else:
            try:
                parent = symbol_table.createNameSpace(
                    parent, part, SourceType.IMPORTED
                )
            except Exception:
                # If namespace creation fails (e.g., name conflict), stay at parent
                pass

    return parent


# DTK section names -> whether they contain code
CODE_SECTIONS = {'.init', '.text'}
DATA_SECTIONS = {'.data2', '.data3', '.data4', '.data5', '.data6'}
BSS_SECTIONS = {'.bss', '.sbss', '.sbss2'}


def run():
    start_time = time.time()

    project_root = get_project_root()
    if not project_root:
        return

    symbols_path = os.path.join(project_root, "config", "symbols.txt")
    names_path = os.path.join(project_root, "config", "symbol_names.txt")

    println("=" * 60)
    println("  Sims 2 GC -- Ghidra Symbol Import")
    println("=" * 60)

    # Parse input files
    println("Parsing symbols.txt...")
    symbols = parse_symbols_txt(symbols_path)
    println("  Found %d symbols" % len(symbols))

    println("Parsing symbol_names.txt...")
    name_map = parse_name_mapping(names_path)
    println("  Found %d name mappings" % len(name_map))

    program = currentProgram
    listing = program.getListing()
    symbol_table = program.getSymbolTable()
    func_mgr = program.getFunctionManager()
    addr_factory = program.getAddressFactory()
    mem = program.getMemory()

    # Track stats
    functions_created = 0
    functions_existing = 0
    labels_created = 0
    labels_existing = 0
    namespaces_created = set()
    errors = 0
    skipped = 0

    total = len(symbols)
    report_interval = max(total // 20, 1)  # Report every 5%

    println("\nImporting %d symbols..." % total)

    for i, sym in enumerate(symbols):
        if i > 0 and i % report_interval == 0:
            pct = (i * 100) // total
            elapsed = time.time() - start_time
            println("  [%d%%] %d / %d symbols processed (%.1fs elapsed)" % (
                pct, i, total, elapsed))

        addr_val = sym['address']
        if addr_val == 0:
            skipped += 1
            continue

        # Create Ghidra address
        try:
            addr = addr_factory.getDefaultAddressSpace().getAddress(addr_val)
        except Exception:
            errors += 1
            continue

        # Check if address is in valid memory
        if not mem.contains(addr):
            skipped += 1
            continue

        sanitized = sym['sanitized_name']
        sym_type = sym['type']
        size = sym['size']
        section = sym['section']

        # Get demangled name if available
        demangled = name_map.get(addr_val, None)

        # Extract namespace info from demangled name
        if demangled:
            ns_parts, short_name = extract_namespace_and_name(demangled)
        else:
            ns_parts = []
            short_name = None

        # Determine the label to use
        if short_name and re.match(r'^[~]?[A-Za-z_][A-Za-z0-9_]*$', short_name):
            label = short_name
        else:
            label = sanitized

        # Get or create namespace
        namespace = get_or_create_namespace(program, ns_parts)
        if ns_parts:
            for p in ns_parts:
                namespaces_created.add(p)

        # Create function or data label
        if section in CODE_SECTIONS:
            # Code symbol -> create function
            existing_func = func_mgr.getFunctionAt(addr)
            if existing_func is not None:
                # Function exists, just rename it
                try:
                    existing_func.setName(label, SourceType.IMPORTED)
                    existing_func.setParentNamespace(namespace)
                except Exception:
                    pass
                functions_existing += 1
            else:
                # Create new function
                try:
                    func = createFunction(addr, label)
                    if func is not None:
                        try:
                            func.setName(label, SourceType.IMPORTED)
                            func.setParentNamespace(namespace)
                        except Exception:
                            pass
                        functions_created += 1
                    else:
                        # createFunction failed, add as label instead
                        try:
                            symbol_table.createLabel(
                                addr, label, namespace, SourceType.IMPORTED
                            )
                            labels_created += 1
                        except Exception:
                            errors += 1
                except Exception:
                    # Function creation failed entirely, try label
                    try:
                        symbol_table.createLabel(
                            addr, label, namespace, SourceType.IMPORTED
                        )
                        labels_created += 1
                    except Exception:
                        errors += 1
        else:
            # Data symbol -> create label
            existing = symbol_table.getPrimarySymbol(addr)
            if existing is not None and existing.getSource() == SourceType.IMPORTED:
                labels_existing += 1
            else:
                try:
                    symbol_table.createLabel(
                        addr, label, namespace, SourceType.IMPORTED
                    )
                    labels_created += 1
                except Exception:
                    errors += 1

        # Add plate comment with full demangled name (if different from label)
        if demangled and demangled != label:
            try:
                cu = listing.getCodeUnitAt(addr)
                if cu is not None:
                    cu.setComment(CodeUnit.PLATE_COMMENT, demangled)
            except Exception:
                pass

    # Done
    elapsed = time.time() - start_time
    println("")
    println("=" * 60)
    println("  Import Complete  (%.1f seconds)" % elapsed)
    println("=" * 60)
    println("  Functions created:   %d" % functions_created)
    println("  Functions renamed:   %d" % functions_existing)
    println("  Data labels created: %d" % labels_created)
    println("  Data labels existed: %d" % labels_existing)
    println("  Namespaces created:  %d" % len(namespaces_created))
    println("  Skipped (no mem):    %d" % skipped)
    println("  Errors:              %d" % errors)
    println("  Total processed:     %d / %d" % (
        functions_created + functions_existing + labels_created + labels_existing,
        total))
    println("=" * 60)

    # List top namespaces
    if namespaces_created:
        top_ns = sorted(namespaces_created)[:30]
        println("\n  Sample namespaces: %s" % ", ".join(top_ns))
        if len(namespaces_created) > 30:
            println("  ... and %d more" % (len(namespaces_created) - 30))


# Entry point for Ghidra script
run()
