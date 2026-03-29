// 0x803230C4 (92 bytes)
typedef unsigned int uint;

struct EFile;
struct EAHeap {
    void *Malloc(uint size, int flags);
};
EAHeap *MainHeap(void);

struct ERBinary {
    char _pad[28];
    ERBinary(void);
    void Load(EFile *file, uint flags);
};

inline void *operator new(uint, void *p) { return p; }

struct EBinaryManager {
    ERBinary *AllocateAndLoadResource(EFile *file, uint id1, uint id2);
};

ERBinary *EBinaryManager::AllocateAndLoadResource(EFile *file, uint id1, uint id2)
{
    EAHeap *heap = MainHeap();
    void *mem = heap->Malloc(28, 0);
    ERBinary *res = new(mem) ERBinary;
    *(uint *)((char *)res + 8) = id2;
    res->Load(file, id1);
    return res;
}
