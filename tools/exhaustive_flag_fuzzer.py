#!/usr/bin/env python3
"""
Exhaustive flag fuzzer for SN ProDG cc1plus.exe
Tests ALL -f flags to find which ones affect code generation.
"""

import subprocess
import os
import sys
from pathlib import Path

# Test function - ERLevel::GetSunLight with store scheduling issues
# NO // comments - GCC 2.95 preprocessor is buggy
TEST_SOURCE = '''
struct EVec3 {
    int x, y, z;
};

struct EDirLight {
    int field_00, field_04, field_08, field_0C;
};

class ERLevel {
public:
    char pad[24652];
    EVec3 m_sunLight;
    char pad2[8];
    EVec3 m_ambient;
    EVec3 m_fogColor;
    
    void GetSunLight(EVec3& out, EDirLight& light);
};

void ERLevel::GetSunLight(EVec3& out, EDirLight& light) {
    out.x = m_sunLight.x;
    out.y = m_sunLight.y;
    out.z = m_sunLight.z;
    light.field_00 = m_fogColor.x;
    light.field_04 = m_fogColor.y;
    light.field_08 = m_fogColor.z;
    light.field_0C = m_ambient.x;
}
'''

# All -f flags from cc1plus --help (subset that makes sense to test)
FLAGS_TO_TEST = [
    # Scheduling flags (most important)
    "-fno-schedule-insns",
    "-fno-schedule-insns2",
    "-fschedule-insns",
    "-fschedule-insns2",
    "-fsched-interblock",
    "-fsched-spec",
    "-fsched-spec-load",
    "-fsched-spec-load-dangerous",
    
    # Optimization flags
    "-fno-strength-reduce",
    "-fno-inline",
    "-fno-inline-functions",
    "-fno-omit-frame-pointer",
    "-fno-defer-pop",
    "-fno-caller-saves",
    "-fno-rerun-loop-opt",
    "-fno-rerun-cse-after-loop",
    "-fno-gcse",
    "-fno-delayed-branch",
    "-fno-cse-follow-jumps",
    "-fno-cse-skip-blocks",
    "-fno-expensive-optimizations",
    "-fno-thread-jumps",
    "-fno-peephole",
    "-fno-force-mem",
    "-fno-force-addr",
    "-fno-function-cse",
    "-fno-keep-inline-functions",
    "-fno-unroll-loops",
    "-fno-unroll-all-loops",
    "-fno-move-all-movables",
    "-fno-reduce-all-givs",
    "-fno-regmove",
    "-fno-optimize-register-move",
    
    # Code generation
    "-fno-exceptions",
    "-fno-rtti",
    "-fno-strict-aliasing",
    "-fno-pcc-struct-return",
    "-fno-reg-struct-return",
    "-fno-default-single-float",
    "-fno-float-store",
    "-fno-fast-math",
    
    # Register allocation
    "-ffixed-r11",
    "-fcall-saved-r11",
    "-fcall-used-r11",
    
    # Memory/model
    "-fno-volatile",
    "-fno-volatile-global",
    "-fno-volatile-static",
    "-fno-pack-struct",
    "-fno-common",
    "-fno-data-sections",
    "-fno-function-sections",
    
    # Misc
    "-fno-ident",
    "-fno-leading-underscore",
    "-fno-verbose-asm",
    "-fno-instrument-functions",
    "-fno-check-memory-usage",
    "-fno-prefix-function-name",
    "-fno-dump-unnumbered",
    "-fno-inhibit-size-directive",
    "-fno-gnu-linker",
    "-fno-shared-data",
    "-fno-stack-check",
    "-fno-pic",
    "-fno-branch-count-reg",
    "-fno-pretend-float",
    "-fno-profile-arcs",
    "-fno-test-coverage",
    "-fno-branch-probabilities",
    "-fno-asynchronous-exceptions",
    "-fno-sjlj-exceptions",
    "-fno-new-exceptions",
    "-fno-writable-strings",
]

def test_flag(flag):
    """Test a single flag and report if it changes output."""
    compiler = Path("compiler/ProDGforNGCv393/Disk1/data1/Build_Tools_Bin/cc1plus.exe")
    
    # Ensure build directory exists
    os.makedirs("build/verify", exist_ok=True)
    
    # Write test source
    with open("build/verify/test_flag.cpp", "w") as f:
        f.write(TEST_SOURCE)
    
    base_flags = "-quiet -O2 -fno-elide-constructors -msdata=eabi -G 8"
    
    try:
        # Compile with base flags
        cmd_base = [str(compiler), "build/verify/test_flag.cpp", "-o", "build/verify/base.s"] + base_flags.split()
        subprocess.run(cmd_base, capture_output=True, timeout=30)
        
        # Compile with test flag
        cmd_test = [str(compiler), "build/verify/test_flag.cpp", "-o", "build/verify/test.s"] + (base_flags + " " + flag).split()
        result = subprocess.run(cmd_test, capture_output=True, timeout=30)
        
        if result.returncode != 0:
            return None, f"Compile failed"
        
        # Compare outputs
        try:
            with open("build/verify/base.s", "r") as f:
                base_asm = f.read()
            with open("build/verify/test.s", "r") as f:
                test_asm = f.read()
        except:
            return None, "Missing output"
        
        # Compare assembly
        if base_asm != test_asm:
            return True, "Output differs"
        return False, "No change"
        
    except Exception as e:
        return None, str(e)

def main():
    print("=" * 70)
    print("EXHAUSTIVE FLAG FUZZER")
    print("=" * 70)
    print(f"\nTesting {len(FLAGS_TO_TEST)} flags...\n")
    
    interesting_flags = []
    failed_flags = []
    
    for i, flag in enumerate(FLAGS_TO_TEST, 1):
        print(f"[{i}/{len(FLAGS_TO_TEST)}] Testing {flag}...", end=" ")
        sys.stdout.flush()
        changed, msg = test_flag(flag)
        
        if changed is None:
            print("FAILED")
            failed_flags.append((flag, msg))
        elif changed:
            print("CHANGES OUTPUT")
            interesting_flags.append(flag)
        else:
            print("no change")
    
    print("\n" + "=" * 70)
    print("RESULTS")
    print("=" * 70)
    
    if interesting_flags:
        print(f"\n{len(interesting_flags)} flags CHANGED the output:")
        for flag in interesting_flags:
            print(f"  - {flag}")
    else:
        print("\nNo flags changed the output (other than -fno-schedule-insns2)")
    
    if failed_flags:
        print(f"\n{len(failed_flags)} flags FAILED")
    
    print("\n" + "=" * 70)

if __name__ == "__main__":
    main()
