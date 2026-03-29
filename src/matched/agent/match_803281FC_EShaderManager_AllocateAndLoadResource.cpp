// EShaderManager::AllocateAndLoadResource - 0x803281FC (108 bytes)
// TU: e_shaderman
// Pattern B: Uses EResourceManager::Alloc, size 108 bytes
// Special: Uses vtable call for Load

#include "types.h"

class EFile;
class EResourceManager;
class ERShader;

extern EResourceManager* gResMgr_shader;  // at 0x805EBB7C
void* EResourceManager_Alloc(EResourceManager* mgr, unsigned long size, unsigned int group);
void ERShader_ctor(ERShader* self);

// ERShader layout
class ERShader {
public:
    u32* m_vtable;     // 0x00
    u32 m_resourceId;  // 0x08
    // Load method at vtable offset (likely +72 based on lha 72(9))
};

class EShaderManager {
public:
    void* AllocateAndLoadResource(EFile* file, unsigned int typeId, unsigned int resourceId);
};

void* EShaderManager::AllocateAndLoadResource(EFile* file, unsigned int typeId, unsigned int resourceId) {
    EResourceManager* mgr = (EResourceManager*)0x805EBB7C;
    void* mem = EResourceManager_Alloc(mgr, 108, 8);
    ERShader* obj = (ERShader*)mem;
    ERShader_ctor(obj);
    obj->m_resourceId = resourceId;
    
    // Vtable call for Load - offset 72 in vtable (lha 72(9))
    typedef void (*LoadFunc)(ERShader*, EFile*);
    LoadFunc load = (LoadFunc)obj->m_vtable[18];  // 72/4 = 18
    load(obj, file);
    
    return obj;
}
