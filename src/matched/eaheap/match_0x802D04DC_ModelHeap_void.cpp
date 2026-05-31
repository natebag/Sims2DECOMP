// 0x802D04DC ModelHeap(void) (132 B)
// VERIFY-SYMBOL: ModelHeap
//
// Lazily-constructed singleton accessor for the model heap, parented to
// ResourceHeap with FlashesHeap as secondary fallback. Local static EAHeap,
// atexit-registered destructor, pointer cached in a small-data global.

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

extern EAHeap* gpModelHeap;
EAHeap* ResourceHeap();
EAHeap* FlashesHeap();

EAHeap* ModelHeap()
{
    static EAHeap s_heap((char*)"ModelHeap", 0, 0, ResourceHeap(), FlashesHeap());
    gpModelHeap = &s_heap;
    return &s_heap;
}
