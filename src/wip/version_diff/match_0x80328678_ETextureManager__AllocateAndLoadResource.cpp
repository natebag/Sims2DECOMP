typedef unsigned int uint;

struct EFile;

void *EGrowPool_Alloc(void *pool, uint size, int align);
void *ERTexture_ctor(void *);
extern char ETextureManager_instance[];

struct ERTextureVtable {
    char _pad[0x48];
    short thisAdjust;
    void (*Load)(void *, EFile *);
};

struct ERTexture {
    ERTextureVtable *m_vtable;
    uint m_field4;
    uint m_flags;
};

struct ETextureManager {
    ERTexture *AllocateAndLoadResource(EFile *file, uint id, uint flags);
};

ERTexture *ETextureManager::AllocateAndLoadResource(EFile *file, uint id, uint flags) {
    void *mem = EGrowPool_Alloc(ETextureManager_instance, 24, 8);
    ERTexture *tex = (ERTexture *)ERTexture_ctor(mem);
    tex->m_flags = flags;
    ERTextureVtable *vt = tex->m_vtable;
    short adj = vt->thisAdjust;
    void (*fn)(void *, EFile *) = vt->Load;
    fn((char *)tex + adj, file);
    return tex;
}
