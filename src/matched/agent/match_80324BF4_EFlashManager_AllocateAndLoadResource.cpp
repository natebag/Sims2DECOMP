// EFlashManager::AllocateAndLoadResource - 0x80324BF4 (96 bytes)
// TU: e_flashman
// Pattern B: Uses EResourceManager::Alloc, size 24 bytes
// Special: Load takes 2 params (EFile*, unsigned int flags)

#include "types.h"

class EFile;
class EResourceManager;
class ERFlash;

// External functions
extern EResourceManager* gResMgr_flash;  // at 0x805E79FC (approx)
void* EResourceManager_Alloc(EResourceManager* mgr, unsigned long size, unsigned int group);
void ERFlash_ctor(ERFlash* self);
void ERFlash_Load(ERFlash* self, EFile* file, unsigned int flags);

class ERFlash {
public:
    u32 m_vtable;      // 0x00
    u32 m_resourceId;  // 0x08
    // ... other fields (24 bytes total)
};

class EFlashManager {
public:
    void* AllocateAndLoadResource(EFile* file, unsigned int typeId, unsigned int resourceId);
};

void* EFlashManager::AllocateAndLoadResource(EFile* file, unsigned int typeId, unsigned int resourceId) {
    // Get resource manager
    EResourceManager* mgr = (EResourceManager*)0x805E79FC;  // Address from lis/addi in asm
    
    // Allocate 24 bytes for ERFlash object, group 8
    void* mem = EResourceManager_Alloc(mgr, 24, 8);
    ERFlash* obj = (ERFlash*)mem;
    
    // Call constructor
    ERFlash_ctor(obj);
    
    // Store resource ID at offset 8
    obj->m_resourceId = resourceId;
    
    // Load the resource (passes typeId as second Load param)
    ERFlash_Load(obj, file, typeId);
    
    return obj;
}
