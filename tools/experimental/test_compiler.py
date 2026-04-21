import os
import re
import subprocess
import tempfile

src = """/* 0x801dcdb4 R2LTarget::OldGridIndexToRecordIndex (52B) */
/* FLAGS: -fno-schedule-insns */

class R2LTarget {
public:
    char pad[0x9C];
    int m_recordCount;
    char pad2[0x8];
    int m_oldGridIndex;

    int OldGridIndexToRecordIndex(int index);
};

int R2LTarget::OldGridIndexToRecordIndex(int index) {
    int pos = m_oldGridIndex;
    int result = index + pos * 6;
    if (pos < 0) goto fail;
    if (result < 0) goto fail;
    if (result < m_recordCount) return result;
fail:
    return -1;
}
"""

# Strip comments like verify_match.sh does
src_clean = re.sub(r'/\*.*?\*/', '', src, flags=re.DOTALL)
src_clean = re.sub(r'//.*', '', src_clean)

versions = [
    ("v35", "compiler/alt_versions/v35/cc1plus.exe"),
    ("v37", "compiler/alt_versions/v37/cc1plus.exe"),
    ("v381", "compiler/alt_versions/v381/cc1plus.exe"),
    ("v393", "compiler/ProDGforNGCv393/Disk1/data1/Build_Tools_Bin/cc1plus.exe"),
]

flags = "-quiet -O2 -fno-schedule-insns -msdata=eabi -G 8"

for name, v in versions:
    print(f"\n=== {name} ===")
    with tempfile.NamedTemporaryFile(mode='w', suffix='.cpp', delete=False, encoding='ascii') as f:
        f.write(src_clean)
        src_path = f.name
    with tempfile.NamedTemporaryFile(mode='w', suffix='.s', delete=False, encoding='ascii') as f:
        asm_path = f.name
    try:
        result = subprocess.run([v, src_path, "-o", asm_path] + flags.split(), capture_output=True, text=True)
        if result.returncode != 0:
            print("COMPILE FAILED:", result.stderr[:500])
        else:
            with open(asm_path) as f:
                lines = f.readlines()
            for i, line in enumerate(lines):
                if "OldGridIndexToRecordIndex" in line:
                    for j in range(i, min(i+20, len(lines))):
                        print(lines[j].rstrip())
                    break
    finally:
        os.unlink(src_path)
        if os.path.exists(asm_path):
            os.unlink(asm_path)
