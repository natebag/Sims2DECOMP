// 0x803287F0 (84 bytes)
typedef unsigned int uint;

struct EFile;
struct EAHeap {
    void *Malloc(uint size, int flags);
};
EAHeap *MainHeap(void);

struct REffectsAttachment {
    void *m_vtable;
    uint m_field_004;
    uint m_field_008;
    REffectsAttachment(void);
    void Load(EFile *file);
};

inline void *operator new(uint, void *p) { return p; }

struct EffectsAttachmentManager {
    REffectsAttachment *AllocateAndLoadResource(EFile *file, uint id1, uint id2);
};

REffectsAttachment *EffectsAttachmentManager::AllocateAndLoadResource(EFile *file, uint id1, uint id2)
{
    EAHeap *heap = MainHeap();
    void *mem = heap->Malloc(36, 0);
    REffectsAttachment *res = new(mem) REffectsAttachment;
    res->m_field_008 = id2;
    res->Load(file);
    return res;
}
