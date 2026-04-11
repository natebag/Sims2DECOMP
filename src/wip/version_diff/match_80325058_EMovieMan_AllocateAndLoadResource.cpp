// EMovieMan::AllocateAndLoadResource - 0x80325058 (188 bytes)
// TU: e_movieman
// Pattern B: Uses EResourceManager::Alloc

typedef unsigned int uint;
typedef unsigned long ulong;

class EFile;
class EResourceManager;

// Inline placement new
inline void* operator new(uint, void* p) { return p; }

// Inline ERMovie struct for verification
class ERMovie {
public:
    void** _vtable;
    uint _pad_004;
    uint m_resourceId;  // offset 0x008
    
    ERMovie(EFile*, uint, uint, uint);
};

extern EResourceManager* gResMgr_movie;  // at 0x805EC2B8
void* EResourceManager_Alloc(EResourceManager* mgr, ulong size, uint group);

class EMovieMan {
public:
    void* AllocateAndLoadResource(EFile* file, uint typeId, uint resourceId);
};

void* EMovieMan::AllocateAndLoadResource(EFile* file, uint typeId, uint resourceId) {
    EResourceManager* mgr = (EResourceManager*)0x805EC2B8;
    void* mem = EResourceManager_Alloc(mgr, 40, 0);
    ERMovie* obj = new(mem) ERMovie(file, typeId, 0, resourceId);
    obj->m_resourceId = resourceId;
    return obj;
}
