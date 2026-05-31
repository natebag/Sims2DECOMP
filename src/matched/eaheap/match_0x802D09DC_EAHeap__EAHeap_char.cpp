// 0x802D09DC EAHeap::EAHeap(char*, void*, unsigned int, EAHeap*, EAHeap*) (128 B)
// FLAGS: -fno-schedule-insns2
//
// EAHeap constructor: builds the GeneralAllocator base (lockless, with the
// "supports core extension" flag set and no custom core callback), records the
// debug name and the two fallback sub-heaps, clears per-instance state, then
// initializes the managed region via Init(mem, size).

struct GeneralAllocator {
    char _pad[0x528];
    GeneralAllocator(void* core, unsigned coreSize, bool a, bool b,
                     void* coreCallback, void* coreCallbackContext);
};

struct EAHeap : GeneralAllocator {
    char*   m_name;       // 0x528
    EAHeap* m_subHeapA;   // 0x52C
    EAHeap* m_subHeapB;   // 0x530
    EAHeap(char* name, void* mem, unsigned int size, EAHeap* subA, EAHeap* subB);
    void Clear();
    void Init(void* mem, unsigned int size);
};

EAHeap::EAHeap(char* name, void* mem, unsigned int size, EAHeap* subA, EAHeap* subB)
    : GeneralAllocator(0, 0, true, false, 0, 0)
{
    m_name     = name;
    m_subHeapA = subA;
    m_subHeapB = subB;
    Clear();
    Init(mem, size);
}
