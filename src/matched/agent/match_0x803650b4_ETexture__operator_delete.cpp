void EGrowPool_Free(void *pool, void *ptr);
extern char ETextureManager_instance[];

struct ETexture {
    void operator delete(void *ptr);
};

void ETexture::operator delete(void *ptr) {
    EGrowPool_Free(ETextureManager_instance, ptr);
}
