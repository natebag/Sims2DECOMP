typedef unsigned int uint;

struct EAHeap {
    void* MallocAligned(uint size, uint align, uint flags, int extra);
};

EAHeap* MainHeap();
void* memset(void*, int, uint);

struct ISimsMultiTileObjectModel {
    ISimsMultiTileObjectModel();
    static ISimsMultiTileObjectModel* New();
};

inline void* operator new(uint, void* p) { return p; }

ISimsMultiTileObjectModel* ISimsMultiTileObjectModel::New() {
    EAHeap* heap = MainHeap();
    void* p = heap->MallocAligned(1216, 16, 0, 0);
    memset(p, 0, 1216);
    ISimsMultiTileObjectModel* obj = new (p) ISimsMultiTileObjectModel;
    return obj;
}
