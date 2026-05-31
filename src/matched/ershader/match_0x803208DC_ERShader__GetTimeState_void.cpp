// 0x803208DC ERShader::GetTimeState(void) (40B)

struct ERShader {
    char _pad0[0x66];
    unsigned char m_66;   // 0x66 = 102
    unsigned char m_67;   // 0x67 = 103
    unsigned char GetTimeState();
};

unsigned char ERShader::GetTimeState() {
    return (unsigned char)(m_66 * 4 + m_67 / 15);
}
