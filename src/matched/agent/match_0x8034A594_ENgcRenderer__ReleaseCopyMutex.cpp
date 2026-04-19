/* ENgcRenderer::ReleaseCopyMutex(void) at 0x8034A594 (60B) */

struct IMutex_RCM {
    virtual void f0() = 0;          // vtable slot 1 (offset 8)
    virtual void f1() = 0;          // vtable slot 2 (offset 16)
    virtual void Release() = 0;     // vtable slot 3 (offset 24)
};

extern char g_sCopyMutex_RCM[16];

struct ENgcRenderer_RCM {
    void ReleaseCopyMutex();
};

void ENgcRenderer_RCM::ReleaseCopyMutex() {
    ((IMutex_RCM*)g_sCopyMutex_RCM)->Release();
}
