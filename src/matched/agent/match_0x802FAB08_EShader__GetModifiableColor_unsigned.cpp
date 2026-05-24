// FLAGS: -fno-schedule-insns
// 0x802FAB08 EShader::GetModifiableColor(unsigned) (16B)
// rlwinm r4,r4,2,0,29; addi r3,r3,64; lwzx r3,r3,r4; blr
struct EShader {
    char pad[64];
    int m_colors[8];  // offset 64
    int GetModifiableColor(unsigned idx) const;
};
int EShader::GetModifiableColor(unsigned idx) const {
    return m_colors[idx];
}
