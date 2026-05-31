// FLAGS: -fno-schedule-insns
// 0x80320860 ERShader::IsMultiShader(void) (12B)
// lwz r3,0x58(3); rlwinm r3,r3,31,31,31; blr  -- (m_flags >> 1) & 1
struct ERShader {
    char pad[0x58];
    unsigned m_flags;       // 0x58
    int IsMultiShader();
};

int ERShader::IsMultiShader() {
    return (m_flags >> 1) & 1;
}
