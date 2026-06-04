// VERIFY-SYMBOL: f_802D070C
// 0x802D070C EAHeap::InitializeHeapStatics(void) (384 B)
//
// GCC2.95 function-local-static initializer. `static AllocPoolManager s_mgr;`
// emits the guard (SDA flag), the inlined ctor, the `guard=1` store and the
// atexit(__tcf) cleanup registration. The ctor is inlined: it zeroes the two
// header words then placement-new-constructs 8 ProtectedAllocPool elements in a
// `n=7; do { ... } while (n-- != 0)` pointer-walk loop (stride 52). After the
// guard block: stash &s_mgr to the SDA pointer, InitAllocPools(table), then the
// unconditional tail — two SetOption(6,0) calls and ten per-heap
// SetMallocFailureFunction calls. The first three heaps (Root/Main/Resource)
// share ResourceHeapFreeMemory, so its @ha is CSE'd into r30 and reused.
//
// Relocations are masked by verify, so the simplified extern callee signatures
// below are sufficient — only the call/guard STRUCTURE has to match.
// NOTE: the static's __tcf cleanup thunk precedes this function in .text, so it
// is verified by symbol (see VERIFY-SYMBOL above), not section offset 0.

inline void* operator new(unsigned int, void* p) { return p; }

struct GeneralAllocator {
    void SetOption(int opt, int val);
    void SetMallocFailureFunction(void* fn, void* ctx);
};

extern GeneralAllocator* ResourceHeap();
extern GeneralAllocator* ModelHeap();
extern GeneralAllocator* RootHeap();
extern GeneralAllocator* MainHeap();
extern GeneralAllocator* AudioHeap();
extern GeneralAllocator* VMHeap();
extern GeneralAllocator* ShaderHeap();
extern GeneralAllocator* TextureHeap();
extern GeneralAllocator* AnimationHeap();
extern GeneralAllocator* FlashesHeap();

extern "C" int ResourceHeapFreeMemory(GeneralAllocator*, unsigned, unsigned, void*);
extern "C" int AudioHeapFreeMemory(GeneralAllocator*, unsigned, unsigned, void*);
extern "C" int VMHeapFreeMemory(GeneralAllocator*, unsigned, unsigned, void*);
extern "C" int ShaderHeapFreeMemory(GeneralAllocator*, unsigned, unsigned, void*);
extern "C" int TextureHeapFreeMemory(GeneralAllocator*, unsigned, unsigned, void*);
extern "C" int AnimationHeapFreeMemory(GeneralAllocator*, unsigned, unsigned, void*);
extern "C" int ModelHeapFreeMemory(GeneralAllocator*, unsigned, unsigned, void*);
extern "C" int FlashesHeapFreeMemory(GeneralAllocator*, unsigned, unsigned, void*);

struct ProtectedAllocPool {
    char m_data[52];
    ProtectedAllocPool(char* a, void* b, int c, int d);
    ~ProtectedAllocPool();
};

struct AllocPoolManager {
    int  m_field0;
    int  m_field4;
    char m_poolBuf[8 * 52];   // raw storage for 8 ProtectedAllocPool
    AllocPoolManager();
    ~AllocPoolManager();
    void InitAllocPools(unsigned int* table);
};

inline AllocPoolManager::AllocPoolManager()
{
    m_field0 = 0;
    m_field4 = 0;
    ProtectedAllocPool* p = (ProtectedAllocPool*)m_poolBuf;
    int n = 7;
    do {
        new (p) ProtectedAllocPool(0, 0, 0, 0);
        p++;
    } while (n-- != 0);
}

extern unsigned int g_initTable[];
extern AllocPoolManager* g_pPoolManager;

extern "C" void f_802D070C()
{
    static AllocPoolManager s_mgr;
    g_pPoolManager = &s_mgr;
    s_mgr.InitAllocPools(g_initTable);

    ResourceHeap()->SetOption(6, 0);
    ModelHeap()->SetOption(6, 0);
    RootHeap()->SetMallocFailureFunction((void*)&ResourceHeapFreeMemory, 0);
    MainHeap()->SetMallocFailureFunction((void*)&ResourceHeapFreeMemory, 0);
    ResourceHeap()->SetMallocFailureFunction((void*)&ResourceHeapFreeMemory, 0);
    AudioHeap()->SetMallocFailureFunction((void*)&AudioHeapFreeMemory, 0);
    VMHeap()->SetMallocFailureFunction((void*)&VMHeapFreeMemory, 0);
    ShaderHeap()->SetMallocFailureFunction((void*)&ShaderHeapFreeMemory, 0);
    TextureHeap()->SetMallocFailureFunction((void*)&TextureHeapFreeMemory, 0);
    AnimationHeap()->SetMallocFailureFunction((void*)&AnimationHeapFreeMemory, 0);
    ModelHeap()->SetMallocFailureFunction((void*)&ModelHeapFreeMemory, 0);
    FlashesHeap()->SetMallocFailureFunction((void*)&FlashesHeapFreeMemory, 0);
}
