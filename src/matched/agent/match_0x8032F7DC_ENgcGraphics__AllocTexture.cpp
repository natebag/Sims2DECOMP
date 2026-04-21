// 0x8032F7DC (52B) ENgcGraphics::AllocTexture(void)
// Placement new — allocate via resource-manager singleton, then ctor.

typedef unsigned int size_t;

class EResourceManager {
public:
    void* Alloc(unsigned long size, unsigned int flags);
};

class ENgcTexture {
public:
    char pad[44];
    ENgcTexture();
};

extern char s_ngc_texture_rm[];

inline void* operator new(size_t, void* p) { return p; }

class ENgcGraphics {
public:
    ENgcTexture* AllocTexture();
};

ENgcTexture* ENgcGraphics::AllocTexture() {
    return new (((EResourceManager*)s_ngc_texture_rm)->Alloc(44, 8)) ENgcTexture();
}
