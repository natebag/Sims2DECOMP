typedef unsigned int uint;

struct EAHeap {
    void Free(void* ptr);
};

EAHeap* MainHeap();

struct CLoadingScreen {
    void operator delete(void* ptr);
};

void CLoadingScreen::operator delete(void* ptr) {
    EAHeap* heap = MainHeap();
    heap->Free(ptr);
}
