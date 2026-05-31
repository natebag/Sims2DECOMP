// FLAGS: -fno-schedule-insns
// 0x80320854 ERShader::IsStateChangePending(void) (12B)
// lwz r3,0x58(3); rlwinm r3,r3,30,31,31; blr  -- (m_flags >> 2) & 1
struct ERShader {
    char pad[0x58];
    unsigned m_flags;       // 0x58
    int IsStateChangePending();
};

int ERShader::IsStateChangePending() {
    return (m_flags >> 2) & 1;
}
