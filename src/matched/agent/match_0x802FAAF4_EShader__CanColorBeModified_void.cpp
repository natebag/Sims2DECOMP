// FLAGS: -fno-schedule-insns
// 0x802FAAF4 EShader::CanColorBeModified(void) (20B)
// lwz r0,0xb4(3); lwz r3,0x74(3); or r3,r3,r0; rlwinm r3,r3,27,31,31
//   ((m_flags74 | m_flagsB4) >> 5) & 1
struct EShader {
    char pad74[0x74];
    unsigned m_flags74;     // 0x74
    char padB4[0xB4 - 0x78];
    unsigned m_flagsB4;     // 0xB4
    int CanColorBeModified();
};

int EShader::CanColorBeModified() {
    unsigned a = m_flagsB4;
    unsigned b = m_flags74;
    return ((b | a) >> 5) & 1;
}
