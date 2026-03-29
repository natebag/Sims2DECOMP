void *EGrowPool_Alloc(void *pool, unsigned int size, int align);
extern char ETextureManager_instance[];

struct ETexture {
    void *operator new(unsigned int size);
};

void *ETexture::operator new(unsigned int size) {
    return EGrowPool_Alloc(ETextureManager_instance, size, 8);
}
