// FLAGS: -fno-schedule-insns
// 0x802FAAD4 EShader::IsSurface(unsigned) (24B)
// lwz r0,4(r3); li r3,1; and. r9,r0,r4; bnelr; li r3,0  -- (m_flags & mask) != 0
struct EShader {
    char pad[4];
    unsigned m_flags;       // 0x4
    int IsSurface(unsigned mask);
};

int EShader::IsSurface(unsigned mask) {
    if (m_flags & mask) return 1;
    return 0;
}
