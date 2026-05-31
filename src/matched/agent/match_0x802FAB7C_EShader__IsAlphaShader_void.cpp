// 0x802FAB7C EShader::IsAlphaShader(void) (68 B)

struct EShaderState {
    char pad_0000[0xc];
    unsigned int m_flags;
    char pad_0010[0x1c - 0x10];
    unsigned char m_mode1c;
    unsigned char m_mode1d;
    unsigned char pad_001e;
    unsigned char m_mode1f;
};

struct EShader {
    char pad_0000[0x64];
    EShaderState m_state;

    int IsAlphaShader();
};

int EShader::IsAlphaShader() {
    EShaderState* s = &m_state;
    int result = 0;
    if (s->m_flags & 0x40) {
        if (s->m_mode1c == 1 || s->m_mode1d == 1 || s->m_mode1f == 1) {
            result = 1;
        }
    }
    return result;
}
