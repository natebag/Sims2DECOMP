// 0x80328AB0 (84 bytes)
typedef unsigned int uint;

struct EFile;
struct EAHeap {
    void *Malloc(uint size, int flags);
};
EAHeap *MainHeap(void);

struct REffectsSequencer {
    char _pad[20];
    REffectsSequencer(void);
    void Load(EFile *file);
};

inline void *operator new(uint, void *p) { return p; }

struct EffectsSequencerManager {
    REffectsSequencer *AllocateAndLoadResource(EFile *file, uint id1, uint id2);
};

REffectsSequencer *EffectsSequencerManager::AllocateAndLoadResource(EFile *file, uint id1, uint id2)
{
    EAHeap *heap = MainHeap();
    void *mem = heap->Malloc(20, 0);
    REffectsSequencer *res = new(mem) REffectsSequencer;
    *(uint *)((char *)res + 8) = id2;
    res->Load(file);
    return res;
}
