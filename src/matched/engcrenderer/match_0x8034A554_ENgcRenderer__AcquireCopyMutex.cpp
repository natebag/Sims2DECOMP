/* ENgcRenderer::AcquireCopyMutex(void) at 0x8034A554 (64B) */

struct IMutex_ACM {
    virtual void f0() = 0;         // vtable slot 1 (offset 8)
    virtual void Acquire(int) = 0; // vtable slot 2 (offset 16)
};

extern char g_sCopyMutex_ACM[16];

struct ENgcRenderer_ACM {
    void AcquireCopyMutex();
};

void ENgcRenderer_ACM::AcquireCopyMutex() {
    ((IMutex_ACM*)g_sCopyMutex_ACM)->Acquire(-1);
}
