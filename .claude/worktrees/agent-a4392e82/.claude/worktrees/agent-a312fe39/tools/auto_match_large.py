#!/usr/bin/env python3
"""
Sims 2 GameCube -- Auto-match large leaf functions (65-128 bytes).

Extends the auto_match_medium.py pipeline to handle 17-32 instruction leaf
functions (no function calls). At this size range, ~85% of functions have
`bl` (function calls) and are un-matchable at .o level. The remaining ~15%
are leaf functions that break down into:

1. Pure leaf (no branches): multi-field constructors (10+ fields),
   struct copies with setup, float vector init, vtable+field init
2. Branching leaf (conditional returns, guard clauses, small loops,
   multi-case switches, comparison chains)

Key principle: Functions with `bl` (function call) instructions cannot be
matched at the .o level because the call offset is position-dependent.

Usage:
    python tools/auto_match_large.py                    # report only
    python tools/auto_match_large.py --generate         # generate C++ to src/matched/
    python tools/auto_match_large.py --dry-run           # show what would generate
"""

import argparse
import json
import os
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

SCRIPT_DIR = Path(__file__).resolve().parent
ROOT_DIR = SCRIPT_DIR.parent

# Import helpers from existing matchers
sys.path.insert(0, str(SCRIPT_DIR))
from auto_match import (
    load_functions, disassemble_batch, parse_function_name,
    guess_return_type,
    parse_load_store_operands, parse_li_operands, parse_mr_operands,
    parse_addi_operands, parse_lis_operands, parse_ori_operands,
    parse_rlwinm_operands, parse_rlwimi_operands, parse_clrlwi_operands,
    parse_clrrwi_operands, parse_srwi_operands, parse_slwi_operands,
    parse_two_reg_operands, parse_three_reg_operands, parse_mulli_operands,
    parse_indexed_load_store, reconstruct_address,
    try_match as try_match_small,
    INSN_RE, ORIGINAL_ELF, OBJDUMP, CODE_SECTIONS, SYMBOLS_JSON,
)
from auto_match_medium import (
    is_load_insn, is_store_insn, is_branch_insn, is_call_insn,
    has_calls, has_branches, has_unknowns,
    get_store_type, get_load_type, format_offset,
    try_match_multi_store, try_match_field_copy,
    try_match_load_compute_store, try_match_computed_return,
    try_match_medium, format_cpp_function_v2, split_params,
)


# ============================================================================
# Branch-aware register state tracker
# ============================================================================

def parse_cmpwi_operands(ops):
    """Parse cmpwi rN,imm or cmpwi crN,rM,imm"""
    parts = [p.strip() for p in ops.split(',')]
    if len(parts) == 2:
        reg = parts[0]
        try:
            imm = int(parts[1])
        except ValueError:
            return 'cr0', None, None
        return 'cr0', reg, imm
    elif len(parts) == 3:
        cr = parts[0]
        reg = parts[1]
        try:
            imm = int(parts[2])
        except ValueError:
            return cr, None, None
        return cr, reg, imm
    return None, None, None


def parse_cmplwi_operands(ops):
    """Parse cmplwi rN,imm or cmplwi crN,rM,imm"""
    parts = [p.strip() for p in ops.split(',')]
    if len(parts) == 2:
        reg = parts[0]
        try:
            imm = int(parts[1])
        except ValueError:
            return 'cr0', None, None
        return 'cr0', reg, imm
    elif len(parts) == 3:
        cr = parts[0]
        reg = parts[1]
        try:
            imm = int(parts[2])
        except ValueError:
            return cr, None, None
        return cr, reg, imm
    return None, None, None


def parse_cmpw_operands(ops):
    """Parse cmpw rA,rB or cmpw crN,rA,rB"""
    parts = [p.strip() for p in ops.split(',')]
    if len(parts) == 2:
        return 'cr0', parts[0], parts[1]
    elif len(parts) == 3:
        return parts[0], parts[1], parts[2]
    return None, None, None


def parse_branch_target(ops, func_addr, func_size):
    """Parse branch target from operands, return relative offset from func start."""
    # Format: 0xADDR or just ADDR
    target_str = ops.strip()
    if target_str.startswith('0x') or target_str.startswith('0X'):
        try:
            target = int(target_str, 16)
            return target
        except ValueError:
            return None
    try:
        target = int(target_str, 16)
        return target
    except ValueError:
        return None


# ============================================================================
# Branching leaf pattern: guard clause + body
# ============================================================================

def try_match_guard_body(func_name, insns, func_info):
    """Match functions with a guard clause (conditional early return) + body.

    Patterns:
    - lwz rN,off(r3); cmpwi rN,val; beqlr/bnelr; <body>; blr
    - cmpwi rN,val; bgt/blt/bge/ble label; <body1>; blr; label: <body2>; blr
    - li r3,0; lwz rN,off(rM); cmpwi rN,val; beqlr; <body>; blr
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)

    if mnemonics[-1] != 'blr':
        return None, None

    # Pattern: <setup>; cmpwi/cmpw; beqlr/bnelr; <pure_body>; blr
    # Where the conditional return is early and the body is matchable by medium matcher
    cond_lr_idx = None
    for i, (m, _) in enumerate(insns):
        if m in ('beqlr', 'bnelr', 'bgelr', 'blelr', 'bgtlr', 'bltlr',
                 'beqlr+', 'bnelr+', 'bgelr+', 'blelr+', 'bgtlr+', 'bltlr+',
                 'beqlr-', 'bnelr-', 'bgelr-', 'blelr-', 'bgtlr-', 'bltlr-'):
            cond_lr_idx = i
            break

    if cond_lr_idx is None:
        return None, None

    # Everything after the conditional return should be a pure no-branch body
    body_insns = insns[cond_lr_idx + 1:]
    body_mnems = [m for m, _ in body_insns]

    # Body must end with blr
    if not body_mnems or body_mnems[-1] != 'blr':
        return None, None

    # Body must not have calls
    if has_calls(body_insns):
        return None, None

    # Body must not have additional branches (we could handle multi-cond later)
    if has_branches(body_insns):
        return None, None

    # Try to match the body using medium matcher infrastructure
    # We create a fake function with the body instructions
    body_ret, body_code = try_match_load_compute_store(func_name, body_insns, func_info)
    if body_ret is None:
        body_ret, body_code = try_match_multi_store(func_name, body_insns, func_info)
    if body_ret is None:
        body_ret, body_code = try_match_field_copy(func_name, body_insns, func_info)

    if body_ret is None:
        return None, None

    # Now build the guard clause
    # The setup portion is insns[0:cond_lr_idx]
    # The compare is insns[cond_lr_idx - 1] (should be cmpwi/cmpw/cmplwi)

    # For now, generate a comment for the guard and the body
    guard_insns = insns[:cond_lr_idx + 1]
    guard_comment = '; '.join(f'{m} {o}'.strip() for m, o in guard_insns)

    # Build the full body: guard check + body
    full_body = f'{{ /* guard: {guard_comment} */ {body_code[2:-2]} }}'
    return body_ret, full_body


# ============================================================================
# Branching leaf pattern: simple if/else with stores
# ============================================================================

def try_match_simple_if_else(func_name, insns, func_info, func_addr):
    """Match functions with one branch splitting into two paths, each ending in blr.

    Common pattern:
    <setup>; cmpwi; beq/bne LABEL; <path1>; blr; LABEL: <path2>; blr

    This handles if/else field stores, conditional initialization, etc.
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)

    if mnemonics[-1] != 'blr':
        return None, None

    # Find the branch instruction (not beqlr etc, but beq/bne/bgt/blt etc)
    branch_idx = None
    branch_target = None
    for i, (m, o) in enumerate(insns):
        if m in ('beq', 'bne', 'bgt', 'blt', 'bge', 'ble',
                 'beq+', 'bne+', 'bgt+', 'blt+', 'bge+', 'ble+',
                 'beq-', 'bne-', 'bgt-', 'blt-', 'bge-', 'ble-'):
            target = parse_branch_target(o.split(',')[-1] if ',' in o else o, 0, 0)
            if target is not None:
                branch_idx = i
                branch_target = target
                break

    if branch_idx is None:
        return None, None

    # Calculate instruction addresses (each is 4 bytes)
    insn_addrs = [func_addr + i * 4 for i in range(n)]

    # Find the target instruction index
    target_idx = None
    for i, addr in enumerate(insn_addrs):
        if addr == branch_target:
            target_idx = i
            break

    if target_idx is None:
        return None, None

    # Check: should have exactly one internal blr in the if-path
    # Pattern: [setup][compare][branch target_idx][if_body...][blr][else_body...][blr]
    # Find the blr that ends the if-path
    if_body_start = branch_idx + 1
    if_body_end = None
    for i in range(if_body_start, target_idx):
        if mnemonics[i] == 'blr':
            if_body_end = i
            break

    # If there's no blr between branch and target, the branch jumps over one path
    if if_body_end is None:
        # Maybe the branch goes forward past the if-body, and falls through to blr
        # Pattern: [setup][compare][bXX forward][if_body][blr]<target>[else_body][blr]
        # or: [setup][compare][bXX forward]<taken_path>[blr]
        # Check if target_idx == len(insns) - some trailing instructions

        # Simple case: branch to near the end
        if target_idx >= n - 2:
            # Branch jumps to final instruction(s), if-path is the fall-through
            return None, None  # Too simple, or just a conditional store
        return None, None

    # We have: [setup 0..branch_idx-1][compare][branch][if_body if_body_start..if_body_end-1][blr][else_body target_idx..n-2][blr]
    setup_insns = insns[:branch_idx]  # before the compare
    if_body = insns[if_body_start:if_body_end]
    else_body = insns[target_idx:n]  # includes final blr

    # Check both paths are simple (no calls, no additional branches)
    for path in [if_body, else_body]:
        if has_calls(path):
            return None, None
        if has_branches(path):
            # Else body may have its own conditional logic - skip for now
            return None, None

    # For now, these are too complex to auto-generate reliable C++
    # But if both paths are just stores, we can handle it
    return None, None


# ============================================================================
# Branching leaf pattern: multi-return value (compare + li patterns)
# ============================================================================

def try_match_multi_return(func_name, insns, func_info, func_addr):
    """Match functions that return different constants based on comparisons.

    Common patterns:
    - li r3,0; <compare>; beqlr/bnelr; li r3,1; blr
    - <load>; <compare>; bgt LABEL; li r3,0; blr; LABEL: li r3,1; blr
    - <load>; cmpwi; bgt L1; li r3,0; blr; L1: cmpwi; bgt L2; li r3,1; blr; L2: li r3,N; blr
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)

    if mnemonics[-1] != 'blr':
        return None, None

    # Pattern: li r3,VAL; ... cmpwi ...; beqlr/bnelr; li r3,OTHER; blr
    # Simple 2-value return

    # Look for cond-return (beqlr/bnelr etc) with li r3 setup
    cond_lr_idx = None
    for i, (m, _) in enumerate(insns):
        if m in ('beqlr', 'bnelr', 'bgelr', 'blelr', 'bgtlr', 'bltlr',
                 'beqlr+', 'bnelr+', 'bgelr+', 'blelr+', 'bgtlr+', 'bltlr+',
                 'beqlr-', 'bnelr-', 'bgelr-', 'blelr-', 'bgtlr-', 'bltlr-'):
            cond_lr_idx = i
            break

    # Multi-return patterns generate comment bodies that won't byte-match.
    # Skip these - they need manual decompilation.
    return None, None


# ============================================================================
# Branching leaf: conditional store (guard + single store)
# ============================================================================

def try_match_cond_store(func_name, insns, func_info):
    """Match functions with a conditional check then a store operation.

    Pattern: <load>; cmpwi; bXXlr; <stores>; blr
    Meaning: if (condition) { stores; }
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)

    if mnemonics[-1] != 'blr':
        return None, None

    # Find conditional return
    cond_idx = None
    for i, (m, _) in enumerate(insns):
        if m in ('beqlr', 'bnelr', 'bgelr', 'blelr', 'bgtlr', 'bltlr',
                 'beqlr+', 'bnelr+', 'bgelr+', 'blelr+', 'bgtlr+', 'bltlr+',
                 'beqlr-', 'bnelr-', 'bgelr-', 'blelr-', 'bgtlr-', 'bltlr-'):
            cond_idx = i
            break

    if cond_idx is None:
        return None, None

    # Body after the conditional return
    body_insns = insns[cond_idx + 1:]
    if len(body_insns) < 2:
        return None, None

    body_mnems = [m for m, _ in body_insns]
    if body_mnems[-1] != 'blr':
        return None, None

    # Body must be pure (no calls, no branches)
    if has_calls(body_insns) or has_branches(body_insns):
        return None, None

    # Try to match body with medium matchers
    body_ret, body_code = try_match_load_compute_store(func_name, body_insns, func_info)
    if body_ret is None:
        body_ret, body_code = try_match_multi_store(func_name, body_insns, func_info)
    if body_ret is None:
        body_ret, body_code = try_match_field_copy(func_name, body_insns, func_info)

    if body_ret is None or body_code is None:
        return None, None

    # Build guard clause description
    guard_parts = insns[:cond_idx + 1]
    guard_str = '; '.join(f'{m} {o}'.strip() for m, o in guard_parts)

    full_body = f'{{ /* guard: {guard_str} */ {body_code[2:-2]} }}'
    return body_ret, full_body


# ============================================================================
# Master matcher for large functions
# ============================================================================

def try_match_large(func_name, insns, func_info, func_addr=0):
    """Try to match a 65-128 byte function.

    Returns (return_type, body_code) or (None, None) if no match.
    """
    n = len(insns)
    mnemonics = [m for m, _ in insns]

    # Skip functions with calls
    if has_calls(insns):
        return None, None

    # Skip unknown instructions
    if has_unknowns(insns):
        return None, None

    # Must end with blr
    if mnemonics[-1] != 'blr':
        return None, None

    def _valid_body(body, func_info):
        """Check if generated body is valid C++ (no placeholder comments, no globals)."""
        if not body:
            return False
        bad_markers = ['/* addi result */', '/* raw_load */', '/* deref load */',
                       '/* ori result */', '/* oris result */', '/* float_op */',
                       '/* indexed store', '/* SDA', '/* SDA2',
                       '/* guard:', '/* compare', '/* division',
                       '/* float compare', '/* deref_']
        for marker in bad_markers:
            if marker in body:
                return False
        # Skip bodies with global address loads (position-dependent, won't match .o)
        if '*(float*)0x' in body or '*(int*)0x' in body or '*(double*)0x' in body:
            return False
        if '(void*)0x' in body:
            return False
        if 'this' in body and not func_info.get("class_name"):
            return False
        # Skip comment-only bodies
        stripped = body.strip('{ }')
        if stripped.startswith('/*'):
            return False
        # Skip bodies with unresolved rlwimi/rlwinm results
        if 'rlwimi_result' in body or 'rlwinm_result' in body:
            return False
        # Skip if body uses val3/val4/val5 but function has fewer params
        params = func_info.get("params", "")
        if params in ("void", ""):
            n_params = 0
        else:
            from auto_match_medium import split_params as _sp
            n_params = len(_sp(params))
        # Count which val names are used
        used_vals = set()
        for vname in ('val', 'val3', 'val4', 'val5'):
            if vname in body:
                used_vals.add(vname)
        # Map val names to param indices (val=0, val3=1, val4=2, val5=3)
        val_to_idx = {'val': 0, 'val3': 1, 'val4': 2, 'val5': 3}
        for vn in used_vals:
            idx = val_to_idx.get(vn, 0)
            if idx >= n_params:
                return False
        return True

    # First try the medium matcher (handles pure leaf well)
    ret_type, body = try_match_medium(func_name, insns, func_info)
    if ret_type is not None and _valid_body(body, func_info):
        return ret_type, body

    # Now handle branching leaf functions
    if not has_branches(insns):
        return None, None

    # Try guard + body pattern (conditional return + pure body)
    ret_type, body = try_match_guard_body(func_name, insns, func_info)
    if ret_type is not None and _valid_body(body, func_info):
        return ret_type, body

    # Try conditional store (guard + stores)
    ret_type, body = try_match_cond_store(func_name, insns, func_info)
    if ret_type is not None and _valid_body(body, func_info):
        return ret_type, body

    # Try multi-return value pattern
    ret_type, body = try_match_multi_return(func_name, insns, func_info, func_addr)
    if ret_type is not None and _valid_body(body, func_info):
        return ret_type, body

    return None, None


# ============================================================================
# Output and main
# ============================================================================

def main():
    parser = argparse.ArgumentParser(
        description="Auto-match large leaf functions (65-128 bytes)"
    )
    parser.add_argument("--min-size", type=int, default=65,
                        help="Minimum function size in bytes (default: 65)")
    parser.add_argument("--max-size", type=int, default=128,
                        help="Maximum function size in bytes (default: 128)")
    parser.add_argument("--name", metavar="PATTERN",
                        help="Only process functions matching this name pattern")
    parser.add_argument("--generate", action="store_true",
                        help="Generate C++ code to src/matched/")
    parser.add_argument("--dry-run", action="store_true",
                        help="Show what would be generated without writing files")
    parser.add_argument("--show-unmatched", action="store_true",
                        help="Show all unmatched function disassembly")
    args = parser.parse_args()

    print(f"Loading functions ({args.min_size}-{args.max_size} bytes)...")
    funcs = load_functions(args.min_size, args.max_size, args.name)
    print(f"Found {len(funcs)} functions in code sections")

    if not funcs:
        return

    print("Disassembling...")
    results = disassemble_batch(funcs)

    # Build addr->symbol lookup
    addr_to_sym = {}
    for s in funcs:
        addr_to_sym[int(s['address'], 16)] = s

    # Try to match each function
    matched = []
    unmatched = []
    skipped_bl = 0
    skipped_unknown = 0
    pattern_counts = defaultdict(int)

    for (addr, name), insns in sorted(results.items()):
        mnemonics = [m for m, _ in insns]

        if has_calls(insns):
            skipped_bl += 1
            continue

        if has_unknowns(insns):
            skipped_unknown += 1
            continue

        func_info = parse_function_name(name)
        return_type, body = try_match_large(name, insns, func_info, func_addr=addr)

        if return_type is not None:
            cpp_line = format_cpp_function_v2(name, func_info, return_type, body)
            sym = addr_to_sym.get(addr, {})
            matched.append({
                "name": name,
                "address": addr,
                "size": sym.get('size', len(insns) * 4),
                "cpp": cpp_line,
                "return_type": return_type,
                "body": body,
                "func_info": func_info,
                "insns": insns,
            })
            has_br = has_branches(insns)
            pattern_counts[f"{'branch' if has_br else 'pure'}_{len(insns)}insn"] += 1
        else:
            insn_str = "; ".join(f"{m} {op}" for m, op in insns)
            unmatched.append({
                "name": name,
                "address": addr,
                "size": len(insns) * 4,
                "insns_str": insn_str,
                "insns": insns,
            })

    # Report
    total = len(results)
    matched_count = len(matched)
    matched_bytes = sum(m["size"] for m in matched)
    unmatched_count = len(unmatched)

    print(f"\n{'=' * 72}")
    print(f"  Large Function Auto-Match Report (65-128 bytes)")
    print(f"{'=' * 72}")
    print(f"  Total functions in range:   {total}")
    print(f"  Skipped (has bl):           {skipped_bl}")
    print(f"  Skipped (unknown insns):    {skipped_unknown}")
    print(f"  Candidates (no bl):         {total - skipped_bl - skipped_unknown}")
    print(f"  Auto-matched:               {matched_count}")
    print(f"  Matched bytes:              {matched_bytes}")
    print(f"  Unmatched:                  {unmatched_count}")
    print()

    print(f"  Pattern breakdown:")
    for pat, count in sorted(pattern_counts.items(), key=lambda x: -x[1]):
        print(f"    {pat:<30s} {count:>5}")
    print()

    # Show sample generated code
    if args.generate or args.dry_run:
        print(f"  Generated C++ ({matched_count} functions):")
        print(f"{'=' * 72}\n")

        by_class = defaultdict(list)
        for m in matched:
            cls = m["func_info"]["class_name"] or "(global)"
            by_class[cls].append(m)

        for cls in sorted(by_class.keys()):
            funcs_in_class = by_class[cls]
            if args.dry_run:
                print(f"// --- {cls} ({len(funcs_in_class)} functions) ---")
                for m in funcs_in_class[:3]:
                    print(f"// 0x{m['address']:08X} ({m['size']}b)")
                    print(m["cpp"])
                    print()
                if len(funcs_in_class) > 3:
                    print(f"// ... and {len(funcs_in_class) - 3} more")
                    print()

    # Write output files
    if args.generate and not args.dry_run:
        out_dir = ROOT_DIR / "src" / "matched"
        out_dir.mkdir(parents=True, exist_ok=True)

        # Collect ALL existing addresses from ALL files to avoid duplicates
        all_existing_addrs = set()
        for existing_file in out_dir.glob("*.cpp"):
            content = existing_file.read_text()
            for m in re.finditer(r"// 0x([0-9A-Fa-f]+)\s+\(\d+ bytes\)", content):
                all_existing_addrs.add(int(m.group(1), 16))

        by_class = defaultdict(list)
        for m in matched:
            cls = m["func_info"]["class_name"] or "_global"
            by_class[cls].append(m)

        files_written = 0
        funcs_added = 0
        for cls, funcs_in_class in sorted(by_class.items()):
            # Use _large_auto.cpp suffix
            filename = (cls.replace("::", "_").replace("<", "_").replace(">", "_")
                          .replace("*", "ptr").replace(" ", "_").replace(",", "_")
                          + "_large_auto.cpp")
            filepath = out_dir / filename

            # Check for existing file
            existing_addrs = set()
            if filepath.exists():
                content = filepath.read_text()
                for m in re.finditer(r"// 0x([0-9A-Fa-f]+)\s+\(\d+ bytes\)", content):
                    existing_addrs.add(int(m.group(1), 16))

            # Filter out already matched
            new_funcs = [fn for fn in funcs_in_class
                         if fn["address"] not in all_existing_addrs
                         and fn["address"] not in existing_addrs]
            if not new_funcs:
                continue

            with open(filepath, "w") as f:
                f.write('#include "types.h"\n')
                f.write('#include "stub_classes.h"\n')
                f.write(f"// Auto-generated matching stubs for {cls} (large leaf functions)\n")
                f.write(f"// Generated by auto_match_large.py\n")
                f.write(f"// {len(new_funcs)} functions, "
                        f"{sum(fn['size'] for fn in new_funcs)} bytes\n\n")

                for fn in new_funcs:
                    f.write(f"// 0x{fn['address']:08X} ({fn['size']} bytes)\n")
                    f.write(fn["cpp"] + "\n\n")
                    funcs_added += 1

            files_written += 1

        print(f"  Wrote {funcs_added} new functions to {files_written} files in {out_dir}/")
        print(f"  Total matched: {matched_count} functions, {matched_bytes} bytes")

    # Show unmatched samples
    if not args.generate and not args.dry_run:
        leaf_unmatched = [u for u in unmatched if not has_branches(u["insns"])]
        branch_unmatched = [u for u in unmatched if has_branches(u["insns"])]

        if leaf_unmatched:
            print(f"  Sample unmatched pure leaf ({len(leaf_unmatched)} total, first 10):")
            for u in leaf_unmatched[:10]:
                print(f"    0x{u['address']:08X}  {u['name']}")
                print(f"      {u['insns_str']}")
            print()

        if branch_unmatched:
            print(f"  Sample unmatched branching leaf ({len(branch_unmatched)} total, first 10):")
            for u in branch_unmatched[:10]:
                print(f"    0x{u['address']:08X}  {u['name']}")
                print(f"      {u['insns_str']}")
            print()

    if args.show_unmatched:
        print(f"\n  All unmatched functions ({len(unmatched)}):")
        for u in unmatched:
            print(f"    0x{u['address']:08X} ({u['size']:3d}b) {u['name']}")
            print(f"      {u['insns_str']}")


if __name__ == "__main__":
    main()
