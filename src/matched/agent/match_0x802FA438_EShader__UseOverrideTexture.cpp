// EShader::UseOverrideTexture(unsigned char) - 0x802FA438 (60 bytes)
//
// Tech #73 application — flags-bit gate + byte-bound check + multi-store.
//
// FLAGS: -msdata=eabi -G 8

struct EShader {
    char pad_0[4];
    unsigned int m_flags;
    char pad_8[0x88 - 8];
    unsigned char m_byte_88;
    char pad_89[0xec - 0x89];
    unsigned char m_byte_ec;

    int UseOverrideTexture(unsigned char idx);
};

int EShader::UseOverrideTexture(unsigned char idx) {
    unsigned int flags = m_flags;
    if ((flags & 0x04000000) == 0) return 0;
    if (m_byte_88 <= idx) return 0;
    unsigned int new_flags = flags | 0x02000000;
    m_byte_ec = idx;
    m_flags = new_flags;
    return 1;
}
