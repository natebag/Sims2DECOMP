// 0x8034DC04 (60B) ENgcShader::ENgcShader(void)
// SI ctor — base EShader + explicit second vtable pointer at +0xF0.

extern char vt_ENgcShader[];

class EShader {
public:
    void* m_vt;
    EShader();
};

class ENgcShader : public EShader {
public:
    char pad[0xF0 - 4];
    void* m_vt_at_f0;

    ENgcShader();
};

ENgcShader::ENgcShader() {
    m_vt_at_f0 = (void*)vt_ENgcShader;
}
