// FLAGS: -fno-schedule-insns
// 0x80320750 ERShader::IsDayNightShader(void) (12B)
// lwz r3,0x58(3); rlwinm r3,r3,27,31,31; blr  -- (m_flags >> 5) & 1
struct ERShader {
    char pad[0x58];
    unsigned m_flags;       // 0x58
    int IsDayNightShader();
};

int ERShader::IsDayNightShader() {
    return (m_flags >> 5) & 1;
}
