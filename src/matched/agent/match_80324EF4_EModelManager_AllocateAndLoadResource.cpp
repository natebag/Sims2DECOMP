// EModelManager::AllocateAndLoadResource - 0x80324EF4 (88 bytes)
// TU: e_modelman
// Pattern B: Uses EResourceManager::Alloc, size 384 bytes
// Special: Load function is LoadModel, not Load

#include "types.h"

class EFile;
class EResourceManager;
class ERModel;

// External functions
extern EResourceManager* gResMgr_model;  // at 0x805EBC2C
void* EResourceManager_Alloc(EResourceManager* mgr, unsigned long size, unsigned int group);
void ERModel_ctor(ERModel* self);
void ERModel_LoadModel(ERModel* self, EFile* file);

class ERModel {
public:
    u32 m_vtable;      // 0x00
    u32 m_resourceId;  // 0x08
    // ... other fields (384 bytes total)
};

class EModelManager {
public:
    void* AllocateAndLoadResource(EFile* file, unsigned int typeId, unsigned int resourceId);
};

void* EModelManager::AllocateAndLoadResource(EFile* file, unsigned int typeId, unsigned int resourceId) {
    EResourceManager* mgr = (EResourceManager*)0x805EBC2C;
    
    // Allocate 384 bytes, group 8
    void* mem = EResourceManager_Alloc(mgr, 384, 8);
    ERModel* obj = (ERModel*)mem;
    
    ERModel_ctor(obj);
    obj->m_resourceId = resourceId;
    ERModel_LoadModel(obj, file);
    
    return obj;
}
