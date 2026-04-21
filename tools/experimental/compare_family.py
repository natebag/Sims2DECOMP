import json, subprocess, sys, re

def get_disasm(addr):
    try:
        result = subprocess.run([sys.executable, 'tools/disasm_func.py', addr], capture_output=True, text=True)
        lines = result.stdout.split('\n')
        # Skip header lines, get just the instruction mnemonics
        asm_lines = []
        for line in lines:
            if not line.strip() or line.startswith('//') or line.startswith('Symbol references'):
                continue
            # Line format: "addr:\tbytes\tmnemonic operands"
            parts = line.split('\t')
            if len(parts) >= 3:
                asm_lines.append(parts[2].strip())
        return asm_lines
    except Exception as e:
        return []

def normalize_mnemonics(asm_lines):
    """Extract just mnemonics, ignoring operands and constants"""
    mnems = []
    for line in asm_lines:
        # First word is the mnemonic
        mnem = line.split()[0] if line.split() else ''
        mnems.append(mnem)
    return mnems

# Check promising groups
groups_to_check = {
    'CasSimRendererDynamic': ['0x801701dc', '0x8017021c', '0x80170244', '0x80170278', '0x801702ac'],
    'BBI::InventoryItem': ['0x8004a0c4', '0x8004a104', '0x8004a214', '0x8004a2a4', '0x8004a2e0'],
    'Behavior': ['0x800ab9b4', '0x800ab9f4', '0x800ad17c'],
    'O2TTarget': ['0x801cef60', '0x801cf028', '0x801cf054', '0x801ceac0', '0x801cebe8'],
    'TileWalls': ['0x80146998', '0x801469b0', '0x80146a9c', '0x80146914', '0x80146ff8'],
    'NghResFile': ['0x800d43fc', '0x800d53e4', '0x800d541c', '0x800d5484', '0x800d6c08'],
    'cSimulatorImpl': ['0x80140924', '0x80141324', '0x80141a5c', '0x80141a8c', '0x80141b28'],
    'CasSimPartsS2C': ['0x8016cd30', '0x8016cd58', '0x8016d508', '0x8016d534'],
}

for group_name, addrs in groups_to_check.items():
    print(f"\n=== {group_name} ===")
    mnems_list = []
    for addr in addrs:
        asm = get_disasm(addr)
        mnems = normalize_mnemonics(asm)
        mnems_list.append((addr, mnems, asm))
    
    # Compare all pairs
    if len(mnems_list) >= 2:
        base = mnems_list[0][1]
        matches = sum(1 for _, mnems, _ in mnems_list if mnems == base)
        print(f"  Functions with identical mnemonic sequence: {matches}/{len(mnems_list)}")
        for addr, mnems, asm in mnems_list:
            match_str = "MATCH" if mnems == base else "DIFF"
            print(f"  {addr}: {match_str} ({len(mnems)} insns)")
