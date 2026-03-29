// EMovieMan::AllocateAndLoadResource - 0x80325058 (188 bytes)
// TU: e_movieman
// Pattern B: Uses EResourceManager::Alloc, larger size

#include "types.h"

class EFile;
class EResourceManager;
class ERMovie;

extern EResourceManager* gResMgr_movie;  // at 0x805EC2B8
void* EResourceManager_Alloc(EResourceManager* mgr, unsigned long size, unsigned int group);
void ERMovie_ctor(ERMovie* self);
void ERMovie_Load(ERMovie* self, EFile* file);

class ERMovie {
public:
    u32 m_vtable;
    u32 m_resourceId;
};

class EMovieMan {
public:
    void* AllocateAndLoadResource(EFile* file, unsigned int typeId, unsigned int resourceId);
};

void* EMovieMan::AllocateAndLoadResource(EFile* file, unsigned int typeId, unsigned int resourceId) {
    EResourceManager* mgr = (EResourceManager*)0x805EC2B8;
    // Size from assembly analysis
    void* mem = EResourceManager_Alloc(mgr, 64, 8);
    ERMovie* obj = (ERMovie*)mem;
    ERMovie_ctor(obj);
    obj->m_resourceId = resourceId;
    ERMovie_Load(obj, file);
    return obj;
}
