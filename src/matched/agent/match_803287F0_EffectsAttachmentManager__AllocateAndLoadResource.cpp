typedef unsigned int uint;

struct EFile;
struct EAHeap;
struct EAHeap *MainHeap(void);
void *EAHeap_Malloc(struct EAHeap *heap, uint size, int align);

struct REffectsAttachment {
    void *m_vtable;
    uint m_field4;
    uint m_flags;
};

void *REffectsAttachment_ctor(void *p);
void REffectsAttachment_Load(struct REffectsAttachment *r, EFile *file, int flags);

struct EffectsAttachmentManager {
    REffectsAttachment *AllocateAndLoadResource(EFile *file, uint id, uint flags);
};

REffectsAttachment *EffectsAttachmentManager::AllocateAndLoadResource(EFile *file, uint id, uint flags)
{
    EAHeap *heap = MainHeap();
    void *mem = EAHeap_Malloc(heap, 36, 0);
    REffectsAttachment *res = (REffectsAttachment *)REffectsAttachment_ctor(mem);
    res->m_flags = flags;
    REffectsAttachment_Load(res, file, 0);
    return res;
}
