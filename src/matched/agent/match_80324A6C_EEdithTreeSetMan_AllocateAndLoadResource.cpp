// 0x80324A6C (92 bytes)
typedef unsigned int uint;

struct EFile;
struct EAHeap {
    void *Malloc(uint size, int flags);
};
EAHeap *MainHeap(void);

struct EREdithTreeSet {
    char _pad[32];
    EREdithTreeSet(void);
    void Load(EFile *file, uint flags);
};

inline void *operator new(uint, void *p) { return p; }

struct EEdithTreeSetMan {
    EREdithTreeSet *AllocateAndLoadResource(EFile *file, uint id1, uint id2);
};

EREdithTreeSet *EEdithTreeSetMan::AllocateAndLoadResource(EFile *file, uint id1, uint id2)
{
    EAHeap *heap = MainHeap();
    void *mem = heap->Malloc(32, 0);
    EREdithTreeSet *res = new(mem) EREdithTreeSet;
    *(uint *)((char *)res + 8) = id2;
    res->Load(file, id1);
    return res;
}
