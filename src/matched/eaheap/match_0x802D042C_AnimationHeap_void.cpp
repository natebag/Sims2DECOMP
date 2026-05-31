// 0x802D042C AnimationHeap(void) (132 B)
// VERIFY-SYMBOL: AnimationHeap
//
// Lazily-constructed singleton accessor for the animation heap, parented to
// ResourceHeap with ModelHeap as secondary fallback. Local static EAHeap,
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

extern EAHeap* gpAnimationHeap;
EAHeap* ResourceHeap();
EAHeap* ModelHeap();

EAHeap* AnimationHeap()
{
    static EAHeap s_heap((char*)"AnimationHeap", 0, 0, ResourceHeap(), ModelHeap());
    gpAnimationHeap = &s_heap;
    return &s_heap;
}
