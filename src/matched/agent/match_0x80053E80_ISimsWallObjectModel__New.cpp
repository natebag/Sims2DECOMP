typedef unsigned int uint;

struct EAHeap {
    void* MallocAligned(uint size, uint align, uint flags, int extra);
};

EAHeap* MainHeap();
void* memset(void*, int, uint);

struct ISimsWallObjectModel {
    ISimsWallObjectModel();
    static ISimsWallObjectModel* New();
};

inline void* operator new(uint, void* p) { return p; }

ISimsWallObjectModel* ISimsWallObjectModel::New() {
    EAHeap* heap = MainHeap();
    void* p = heap->MallocAligned(1216, 16, 0, 0);
    memset(p, 0, 1216);
    ISimsWallObjectModel* obj = new (p) ISimsWallObjectModel;
    return obj;
}
