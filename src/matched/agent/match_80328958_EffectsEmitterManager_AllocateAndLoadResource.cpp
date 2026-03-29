// 0x80328958 (84 bytes)
typedef unsigned int uint;

struct EFile;
struct EAHeap {
    void *Malloc(uint size, int flags);
};
EAHeap *MainHeap(void);

struct REffectsEmitter {
    char _pad[36];
    REffectsEmitter(void);
    void Load(EFile *file);
};

inline void *operator new(uint, void *p) { return p; }

struct EffectsEmitterManager {
    REffectsEmitter *AllocateAndLoadResource(EFile *file, uint id1, uint id2);
};

REffectsEmitter *EffectsEmitterManager::AllocateAndLoadResource(EFile *file, uint id1, uint id2)
{
    EAHeap *heap = MainHeap();
    void *mem = heap->Malloc(36, 0);
    REffectsEmitter *res = new(mem) REffectsEmitter;
    *(uint *)((char *)res + 8) = id2;
    res->Load(file);
    return res;
}
