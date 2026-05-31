// 0x802D037C TextureHeap(void) (132 B)
// VERIFY-SYMBOL: TextureHeap
//
// Lazily-constructed singleton accessor for the texture heap, parented to
// ResourceHeap with AnimationHeap as secondary fallback. Local static EAHeap,
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

extern EAHeap* gpTextureHeap;
EAHeap* ResourceHeap();
EAHeap* AnimationHeap();

EAHeap* TextureHeap()
{
    static EAHeap s_heap((char*)"TextureHeap", 0, 0, ResourceHeap(), AnimationHeap());
    gpTextureHeap = &s_heap;
    return &s_heap;
}
