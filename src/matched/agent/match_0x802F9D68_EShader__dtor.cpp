// 0x802F9D68 (96B) EShader::~EShader(void)
// Variant L: SI deleting-dtor — vtable@+0xf0 + RemoveFromUpdateList + magic 0xDEADBEEF stamp + EResourceManager::Free.

extern char vt_EShader[];
extern char g_eshaderHeap[16];

void EShader_RemoveFromUpdateList(void* obj);
void EResourceManager_Free(void* mgr, void* p);

struct EShader {
    char pad_0_e3[228];
    int m_magic_e4;
    char pad_e8_ef[8];
    void* m_vt_at_f0;
    void dtor(int flag);
};

void EShader::dtor(int flag) {
    m_vt_at_f0 = vt_EShader;
    EShader_RemoveFromUpdateList(this);
    m_magic_e4 = 0xDEADBEEF;
    if (flag & 1) {
        EResourceManager_Free(g_eshaderHeap, this);
    }
}
