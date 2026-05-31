// FLAGS: -fno-schedule-insns
// 0x802FABD4 EShader::IsValid(void) (28B)
// lwz r3,0xe4(3); xor with 0x900DBEEF; (== 0) idiom subfic/adde  -- m_magic == 0x900DBEEF
struct EShader {
    char pad[0xE4];
    unsigned m_magic;       // 0xE4
    int IsValid();
};

int EShader::IsValid() {
    return m_magic == 0x900DBEEF;
}
