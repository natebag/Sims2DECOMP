// 0x802D021C AudioHeap(void) (132 B)
// VERIFY-SYMBOL: AudioHeap
//
// Lazily-constructed singleton accessor for the audio heap. The local static
// EAHeap is parented to ResourceHeap with ShaderHeap as its secondary fallback;
// the first parent pointer is held in a callee-saved register across the second
// parent call (hence the larger frame). Destructor registered via atexit, the
// pointer cached in a small-data global and returned.

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

extern EAHeap* gpAudioHeap;
EAHeap* ResourceHeap();
EAHeap* ShaderHeap();

EAHeap* AudioHeap()
{
    static EAHeap s_heap((char*)"AudioHeap", 0, 0, ResourceHeap(), ShaderHeap());
    gpAudioHeap = &s_heap;
    return &s_heap;
}
