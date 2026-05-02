// FLAGS: -msdata=eabi -G 8
// 0x8029AF8C AptDisplayList::AptDisplayList(void) (64b)
struct DOGMA_PoolManager {
    void* Allocate(unsigned int size);
};

extern DOGMA_PoolManager* g_DOGMA_PoolManager;

struct AptDisplayListState {
    AptDisplayListState();
};

inline void* operator new(unsigned int, void* p) {
    return p;
}

struct AptDisplayList {
    AptDisplayListState* state;
    AptDisplayList();
};

AptDisplayList::AptDisplayList() {
    state = new (g_DOGMA_PoolManager->Allocate(4)) AptDisplayListState();
}
