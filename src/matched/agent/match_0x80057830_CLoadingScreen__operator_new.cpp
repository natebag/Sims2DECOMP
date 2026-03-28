typedef unsigned int uint;

struct EAHeap {
    void* MallocAligned(uint size, uint align, uint flags, int extra);
};

EAHeap* MainHeap();

struct CLoadingScreen {
    void* operator new(uint size);
};

void* CLoadingScreen::operator new(uint size) {
    EAHeap* heap = MainHeap();
    return heap->MallocAligned(size, 16, 0, 0);
}
