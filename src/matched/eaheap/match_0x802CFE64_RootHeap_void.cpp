// 0x802CFE64 RootHeap(void) (112 B)
// VERIFY-SYMBOL: RootHeap
//
// Lazily-constructed singleton accessor for the root heap — the parentless top
// of the heap hierarchy. A function-local static EAHeap is built on first call
// (no parent sub-heaps), its destructor registered via atexit, and the pointer
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

extern EAHeap* gpRootHeap;

EAHeap* RootHeap()
{
    static EAHeap s_heap((char*)"RootHeap", 0, 0, 0, 0);
    gpRootHeap = &s_heap;
    return &s_heap;
}
