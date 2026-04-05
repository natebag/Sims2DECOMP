#!/usr/bin/env python3
"""
Compiler flag fuzzer - try different SN ProDG flag combinations
to find what produces matching output for VERSION_DIFF functions.
"""

import subprocess
import os
import sys
from pathlib import Path

# Current flags being used
CURRENT_FLAGS = "-O2 -msdata=eabi -G 8 -fno-elide-constructors -quiet"

# Flag variations to test
FLAG_MATRICES = {
    "optimization": [
        "-O1",
        "-O2", 
        "-Os",
        "-O3",
    ],
    "scheduling": [
        "-fno-schedule-insns",
        "-fno-schedule-insns2",
        "-fschedule-insns -fno-schedule-insns2",
        "-fno-schedule-insns -fschedule-insns2",
    ],
    "codegen": [
        "-fno-exceptions",
        "-fno-rtti",
        "-fno-inline",
        "-finline-functions",
        "-fno-strength-reduce",
        "-fno-strict-aliasing",
    ],
    "register": [
        "-ffixed-r11",
        "-fcall-saved-r11",
    ],
    "blocks": [
        "-fno-reorder-blocks",
    ],
}

# Test function - GetLanguage (8 bytes)
TEST_SOURCE = """
int GetLanguage(int value) {
    return value >> 9;
}
"""

# Expected bytes for 0x800BCD04 (GetLanguage)
EXPECTED_BYTES = "7c6346704e800020"

def compile_with_flags(flags, output_file="test.o"):
    """Compile source with given flags and extract bytes."""
    compiler = Path("compiler/ProDGforNGCv393/Disk1/data1/Build_Tools_Bin/cc1plus.exe")
    
    # Write test source
    with open("test.cpp", "w") as f:
        f.write(TEST_SOURCE)
    
    # Compile
    try:
        cmd = [str(compiler), "-o", output_file, "test.cpp"] + flags.split()
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
        
        if result.returncode != 0:
            return None, f"Compile error: {result.stderr}"
        
        # Extract bytes from object file using objdump
        objdump = Path("compiler/ProDGforNGCv393/Disk1/data1/Build_Tools_Bin/powerpc-eabi-objdump.exe")
        if not objdump.exists():
            objdump = Path("compiler/ProDGforNGCv393/Disk1/data1/Build_Tools_Bin/objdump.exe")
        
        result = subprocess.run(
            [str(objdump), "-d", output_file],
            capture_output=True, text=True, timeout=10
        )
        
        # Parse output to find function bytes
        output = result.stdout
        return output, None
        
    except Exception as e:
        return None, str(e)

def test_single_flags():
    """Test each flag category individually."""
    print("=" * 70)
    print("FLAG FUZZER - Testing individual flag variations")
    print("=" * 70)
    print(f"\nTarget: GetLanguage @ 0x800BCD04")
    print(f"Expected bytes: {EXPECTED_BYTES}")
    print()
    
    results = []
    
    for category, flags_list in FLAG_MATRICES.items():
        print(f"\n--- Testing {category} flags ---")
        
        for flag in flags_list:
            test_flags = f"{CURRENT_FLAGS} {flag}"
            output, error = compile_with_flags(test_flags)
            
            if error:
                print(f"  {flag}: ERROR - {error}")
                continue
            
            # Check if output matches expected
            # (This is simplified - real implementation would parse objdump output)
            print(f"  {flag}: Compiled OK")
            print(f"    Output preview: {output[:200] if output else 'None'}...")
            results.append((category, flag, output))
    
    return results

def test_flag_combinations():
    """Test promising flag combinations."""
    print("\n" + "=" * 70)
    print("Testing flag combinations")
    print("=" * 70)
    
    combinations = [
        "-O1 -fno-schedule-insns -fno-schedule-insns2",
        "-Os -fno-schedule-insns",
        "-O2 -fno-reorder-blocks",
        "-O2 -fno-schedule-insns -fno-strength-reduce",
        "-O1 -ffixed-r11",
        "-Os -fno-inline",
        "-O2 -fno-strict-aliasing -fno-schedule-insns",
    ]
    
    for combo in combinations:
        print(f"\n  Testing: {combo}")
        output, error = compile_with_flags(combo)
        
        if error:
            print(f"    ERROR: {error}")
        else:
            print(f"    Compiled OK")
            print(f"    Output: {output[:300] if output else 'None'}...")

if __name__ == "__main__":
    print("SN ProDG Compiler Flag Fuzzer")
    print("Testing variations to find VERSION_DIFF fixes\n")
    
    # Test individual flags
    results = test_single_flags()
    
    # Test combinations
    test_flag_combinations()
    
    print("\n" + "=" * 70)
    print("Flag fuzzing complete")
    print("=" * 70)
