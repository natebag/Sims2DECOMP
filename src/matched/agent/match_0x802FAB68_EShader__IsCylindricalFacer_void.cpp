// FLAGS: -fno-schedule-insns
// 0x802FAB68 EShader::IsCylindricalFacer(void) (12B)
// lwz r3,0x4(r3); rlwinm r3,r3,29,31,31; blr — bit 3 of m_flags
struct EShader {
    char pad[4];
    int m_flags;  // offset 4
    int IsCylindricalFacer() const;
};
int EShader::IsCylindricalFacer() const {
    return (m_flags >> 3) & 1;
}
