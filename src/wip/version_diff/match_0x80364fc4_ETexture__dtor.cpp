void EGrowPool_Free(void *pool, void *ptr);

struct ETexture {
    char _p[0x20];
    unsigned int m_sentinel;
    int *m_vtable;
    void dtor(int flags);
};

extern int __vt__8ETexture[];
extern char ETextureManager_instance[];

void ETexture::dtor(int flags) {
    m_sentinel = 0xDEADBEEF;
    m_vtable = __vt__8ETexture;
    if (flags & 1) {
        EGrowPool_Free(ETextureManager_instance, this);
    }
}
