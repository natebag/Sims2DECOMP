// 0x802D058C FlashesHeap(void) (116 B)
// VERIFY-SYMBOL: FlashesHeap
//
// Lazily-constructed singleton accessor for the flashes heap, parented to the
// ResourceHeap. Local static EAHeap, atexit-registered destructor, pointer
// cached in a small-data global and returned.

struct GeneralAllocator {
    char _pad[0x528];
    GeneralAllocator(void* core, unsigned coreSize, bool a, bool b,
                     void* cb, void* ctx);
};

struct EAHeap : GeneralAllocator {
    char*   m_name;       // 0x528
    EAHeap* m_subHeapA;   // 0x52C
    EAHeap* m_subHeapB;   // 0x530
    EAHeap(char* name, void* mem, unsigned int size, EAHeap* subA, EAHeap* subB);
    ~EAHeap();
};

extern EAHeap* gpFlashesHeap;
EAHeap* ResourceHeap();

EAHeap* FlashesHeap()
{
    static EAHeap s_heap((char*)"FlashesHeap", 0, 0, ResourceHeap(), 0);
    gpFlashesHeap = &s_heap;
    return &s_heap;
}
