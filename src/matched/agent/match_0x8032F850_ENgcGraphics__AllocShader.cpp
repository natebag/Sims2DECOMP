// 0x8032F850 (52B) ENgcGraphics::AllocShader(void)
// Placement new — allocate via EResourceManager singleton, then ctor.

typedef unsigned int size_t;

class EResourceManager {
public:
    void* Alloc(unsigned long size, unsigned int flags);
};

class ENgcShader {
public:
    char pad[244];
    ENgcShader();
};

extern char s_ngc_shader_rm[];

inline void* operator new(size_t, void* p) { return p; }

class ENgcGraphics {
public:
    ENgcShader* AllocShader();
};

ENgcShader* ENgcGraphics::AllocShader() {
    return new (((EResourceManager*)s_ngc_shader_rm)->Alloc(244, 8)) ENgcShader();
}
