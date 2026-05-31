// 0x802CFF00 MainHeap(void) (116 B)
// FLAGS:
//
// Lazily-constructed singleton accessor for the main game heap. A function-local
// static EAHeap is built on first call (guarded), parented to the RootHeap with
// no fixed backing memory, and its destructor registered via atexit. The
// resulting heap pointer is cached in a small-data global and returned.

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

extern EAHeap* gpMainHeap;
EAHeap* RootHeap();

EAHeap* MainHeap()
{
    static EAHeap s_heap((char*)"MainHeap", 0, 0, RootHeap(), 0);
    gpMainHeap = &s_heap;
    return &s_heap;
}
