// 0x802D0040 VMHeap(void) (116 B)
// VERIFY-SYMBOL: VMHeap
//
// Lazily-constructed singleton accessor for the virtual-memory heap, parented
// to the MainHeap. Local static EAHeap, atexit-registered destructor, pointer
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

extern EAHeap* gpVMHeap;
EAHeap* MainHeap();

EAHeap* VMHeap()
{
    static EAHeap s_heap((char*)"VMHeap", 0, 0, MainHeap(), 0);
    gpVMHeap = &s_heap;
    return &s_heap;
}
