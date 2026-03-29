// EEdithTreeSetMan::AllocateAndLoadResource - 0x80324A6C (92 bytes)
// TU: e_edithtreesetman
// Pattern B: Uses EResourceManager::Alloc, size ~40 bytes

#include "types.h"

class EFile;
class EResourceManager;
class EREdithTreeSet;

extern EResourceManager* gResMgr_edith;  // at 0x805EB5B4
void* EResourceManager_Alloc(EResourceManager* mgr, unsigned long size, unsigned int group);
void EREdithTreeSet_ctor(EREdithTreeSet* self);
void EREdithTreeSet_Load(EREdithTreeSet* self, EFile* file);

class EREdithTreeSet {
public:
    u32 m_vtable;
    u32 m_resourceId;
};

class EEdithTreeSetMan {
public:
    void* AllocateAndLoadResource(EFile* file, unsigned int typeId, unsigned int resourceId);
};

void* EEdithTreeSetMan::AllocateAndLoadResource(EFile* file, unsigned int typeId, unsigned int resourceId) {
    EResourceManager* mgr = (EResourceManager*)0x805EB5B4;
    void* mem = EResourceManager_Alloc(mgr, 40, 8);
    EREdithTreeSet* obj = (EREdithTreeSet*)mem;
    EREdithTreeSet_ctor(obj);
    obj->m_resourceId = resourceId;
    EREdithTreeSet_Load(obj, file);
    return obj;
}
