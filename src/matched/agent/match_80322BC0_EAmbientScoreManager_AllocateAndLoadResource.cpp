// 0x80322BC0 (88 bytes)
typedef unsigned int uint;

struct EFile;
struct EAHeap {
    void *Malloc(uint size, int flags);
};
EAHeap *MainHeap(void);

struct ERAmbientScore {
    void *m_vtable;
    uint m_field_004;
    uint m_field_008;
    ERAmbientScore(void);
    void Load(EFile *file, uint flags);
};

inline void *operator new(uint, void *p) { return p; }

struct EAmbientScoreManager {
    ERAmbientScore *AllocateAndLoadResource(EFile *file, uint id1, uint id2);
};

ERAmbientScore *EAmbientScoreManager::AllocateAndLoadResource(EFile *file, uint id1, uint id2)
{
    EAHeap *heap = MainHeap();
    void *mem = heap->Malloc(60, 0);
    ERAmbientScore *res = new(mem) ERAmbientScore;
    res->m_field_008 = id2;
    res->Load(file, 0);
    return res;
}
