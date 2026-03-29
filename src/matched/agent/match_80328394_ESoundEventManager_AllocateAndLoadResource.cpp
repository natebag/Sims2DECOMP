// ESoundEventManager::AllocateAndLoadResource - 0x80328394 (88 bytes)
// TU: e_soundeventman
// Pattern B: Uses EResourceManager::Alloc, size 52 bytes

#include "types.h"

class EFile;
class EResourceManager;
class ERSoundEvent;

// External functions
extern EResourceManager* gResMgr_soundevent;  // at 0x805EC06C
void* EResourceManager_Alloc(EResourceManager* mgr, unsigned long size, unsigned int group);
void ERSoundEvent_ctor(ERSoundEvent* self);
void ERSoundEvent_Load(ERSoundEvent* self, EFile* file);

class ERSoundEvent {
public:
    u32 m_vtable;      // 0x00
    u32 m_resourceId;  // 0x08
    // ... other fields (52 bytes total)
};

class ESoundEventManager {
public:
    void* AllocateAndLoadResource(EFile* file, unsigned int typeId, unsigned int resourceId);
};

void* ESoundEventManager::AllocateAndLoadResource(EFile* file, unsigned int typeId, unsigned int resourceId) {
    EResourceManager* mgr = (EResourceManager*)0x805EC06C;
    
    // Allocate 52 bytes, group 8
    void* mem = EResourceManager_Alloc(mgr, 52, 8);
    ERSoundEvent* obj = (ERSoundEvent*)mem;
    
    ERSoundEvent_ctor(obj);
    obj->m_resourceId = resourceId;
    ERSoundEvent_Load(obj, file);
    
    return obj;
}
