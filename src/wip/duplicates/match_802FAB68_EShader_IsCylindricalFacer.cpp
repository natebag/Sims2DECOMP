// 0x802FAB68 (12 bytes) - EShader::IsCylindricalFacer(void) const
// lwz r3, 4(r3); rlwinm r3,r3,29,31,31; blr  =>  (m_flags >> 3) & 1

struct EShader_CF {
    char pad[0x04];
    int m_flags;
    int IsCylindricalFacer() const;
};
int EShader_CF::IsCylindricalFacer() const {
    return (m_flags >> 3) & 1;
}
