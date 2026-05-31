// FLAGS: -fno-schedule-insns
// 0x802FAB50 EShader::IsFacer(void) (24B)
// lwz r0,4(r3); li r3,1; andi. r9,r0,12; bnelr; li r3,0  -- (m_flags & 0xC) != 0
struct EShader {
    char pad[4];
    unsigned m_flags;       // 0x4
    int IsFacer();
};

int EShader::IsFacer() {
    if (m_flags & 0xC) return 1;
    return 0;
}
