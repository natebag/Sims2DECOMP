// FLAGS: -fno-schedule-insns
// 0x80223FD0 InteractorModule::WallManipulator::GetFenceShaderID(void) (32 B)
// lwz 0,0xc4(3); andi. 9,0,256; beq 0f; lwz 9,0xd8(3); lwz 3,0x0(9); blr; 0:; li 3,0; blr
// if isFenceMode (bit 8 of m_flags), return *m_fenceShaderRef; else return 0.
// Key: negate condition (if NOT set → return 0) to get beq+fall-through-true layout.
namespace InteractorModule {
class WallManipulator {
public:
    char pad[0xC4];
    int m_flags;       // at 0xC4 — bit 8 = isFenceMode
    char pad2[0x10];   // 0xC8..0xD7
    int* m_fenceShaderRef; // at 0xD8 — pointer; *ptr = shader ID

    int GetFenceShaderID() const;
};
int WallManipulator::GetFenceShaderID() const {
    if (!(m_flags & 256)) return 0;
    return *m_fenceShaderRef;
}
}
