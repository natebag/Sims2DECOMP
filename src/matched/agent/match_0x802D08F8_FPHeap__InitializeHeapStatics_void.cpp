// VERIFY-SYMBOL: f_802D08F8
// 0x802D08F8 FPHeap::InitializeHeapStatics(void) (180 B)
//
// Sibling of EAHeap::InitializeHeapStatics (0x802D070C) — same GCC2.95
// function-local-static recipe, smaller: the pooled type is FastAllocPool
// (24-byte element, 8 of them) and the tail is a single
// AptHeap()->SetMallocFailureFunction(&cb, 0). `static AllocPoolManager s_mgr;`
// emits the SDA guard + inlined ctor (zero 2 header words + a
// `n=7; do{...}while(n--!=0)` placement-new pointer-walk @ stride 24) + guard=1
// + atexit(__tcf). Relocations are masked, so simplified extern callees suffice.
// The __tcf cleanup thunk precedes the fn in .text -> verified by symbol.

inline void* operator new(unsigned int, void* p) { return p; }

struct GeneralAllocator {
    void SetMallocFailureFunction(void* fn, void* ctx);
};

extern GeneralAllocator* AptHeap();
extern "C" int AptHeapFreeMemory(GeneralAllocator*, unsigned, unsigned, void*);

struct FastAllocPool {
    char m_data[24];
    FastAllocPool(char* a, void* b, int c, int d);
    ~FastAllocPool();
};

struct AllocPoolManager {
    int  m_field0;
    int  m_field4;
    char m_poolBuf[8 * 24];   // raw storage for 8 FastAllocPool
    AllocPoolManager();
    ~AllocPoolManager();
    void InitAllocPools(unsigned int* table);
};

inline AllocPoolManager::AllocPoolManager()
{
    m_field0 = 0;
    m_field4 = 0;
    FastAllocPool* p = (FastAllocPool*)m_poolBuf;
    int n = 7;
    do {
        new (p) FastAllocPool(0, 0, 0, 0);
        p++;
    } while (n-- != 0);
}

extern unsigned int g_fpInitTable[];
extern AllocPoolManager* g_pFPPoolManager;

extern "C" void f_802D08F8()
{
    static AllocPoolManager s_mgr;
    g_pFPPoolManager = &s_mgr;
    s_mgr.InitAllocPools(g_fpInitTable);

    AptHeap()->SetMallocFailureFunction((void*)&AptHeapFreeMemory, 0);
}
