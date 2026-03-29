// EffectsAttachmentManager::AllocateAndLoadResource - 0x803287F0 (84 bytes)
// TU: effects_attachmentman
// Pattern A: Uses MainHeap() + EAHeap::Malloc

#include "types.h"

class EFile;
class EAHeap;
class REffectsAttachment;

// External functions
EAHeap* MainHeap(void);
void* EAHeap_Malloc(EAHeap* heap, unsigned int size, int flags);
void REffectsAttachment_ctor(REffectsAttachment* self);
void REffectsAttachment_Load(REffectsAttachment* self, EFile* file);

class REffectsAttachment {
public:
    u32 m_vtable;      // 0x00
    u32 m_resourceId;  // 0x08
    // ... other fields (36 bytes total)
};

class EffectsAttachmentManager {
public:
    void* AllocateAndLoadResource(EFile* file, unsigned int typeId, unsigned int resourceId);
};

void* EffectsAttachmentManager::AllocateAndLoadResource(EFile* file, unsigned int typeId, unsigned int resourceId) {
    // Get main heap
    EAHeap* heap = MainHeap();
    
    // Allocate 36 bytes for REffectsAttachment object
    void* mem = EAHeap_Malloc(heap, 36, 0);
    REffectsAttachment* obj = (REffectsAttachment*)mem;
    
    // Call constructor
    REffectsAttachment_ctor(obj);
    
    // Store the file pointer and resource ID
    // obj->m_file = file;  // stored at some offset
    obj->m_resourceId = resourceId;  // at offset 8
    
    // Load the resource
    REffectsAttachment_Load(obj, file);
    
    return obj;
}
