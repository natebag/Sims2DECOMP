// 0x802CFFA0 ResourceHeap(void) (116 B)
// VERIFY-SYMBOL: ResourceHeap
//
// Lazily-constructed singleton accessor for the resource heap, parented to the
// MainHeap. Local static EAHeap, atexit-registered destructor, pointer cached
// in a small-data global and returned.

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

extern EAHeap* gpResourceHeap;
EAHeap* MainHeap();

EAHeap* ResourceHeap()
{
    static EAHeap s_heap((char*)"ResourceHeap", 0, 0, MainHeap(), 0);
    gpResourceHeap = &s_heap;
    return &s_heap;
}
