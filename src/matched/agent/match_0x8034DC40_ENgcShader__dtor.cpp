// 0x8034DC40 (88B) ENgcShader::~ENgcShader(void)
// Vtable-at-+0xf0 SI deleting-dtor with custom heap (g_shaderHeap-style).

extern char vt_ENgcShader[];
extern char g_shaderHeap[];
void HeapStaticFree(char* heap, void* p);

class ENgcShaderBase {
public:
    void* m_base_vt;
    ~ENgcShaderBase();
};

class ENgcShader : public ENgcShaderBase {
public:
    char  pad[0xf0 - 4];
    void* m_vt_at_f0;

    ~ENgcShader();
    static void operator delete(void* p);
};

inline void ENgcShader::operator delete(void* p) {
    HeapStaticFree(g_shaderHeap, p);
}

ENgcShader::~ENgcShader() {
    m_vt_at_f0 = vt_ENgcShader;
}
