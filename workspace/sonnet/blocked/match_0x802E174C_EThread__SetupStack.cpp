// 0x802E174C EThread::SetupStack (164b)
// STATUS: BLOCKED — scheduling wall on common tail (offsets 0x68-0x7c)
//
// Attempted flag combos (all MISMATCH):
//   default  (-O2 -fno-elide-constructors -fno-schedule-insns2) → 7 diffs
//   -fno-elide-constructors (schedule2 on)                      → 7 diffs
//   -fno-schedule-insns (best)                                  → 6 diffs (common tail only)
//   -fno-schedule-insns -fno-schedule-insns2                    → 10 diffs
//   -fno-schedule-insns -fno-elide-constructors                 → same as default
//   -fno-schedule-insns -fno-elide-constructors -fno-schedule-insns2 → 10 diffs
//   tu_match.py --combine e_thread (default tu flags)           → 7 diffs
//
// Root cause: compiler pushes `stw r0,804(r31)` (m_ownsStack) DOWN past `lwz r3,796` + `mr r5,r29`
// (memset arg setup) for latency hiding. DOL wants m_ownsStack store FIRST. No flag combo preserves.
//
// C++ structure VERIFIED correct by partial match (6 of ~40 instructions differ). The rest of the
// function including prologue, first branch, malloc branch, epilogue all match perfectly.
//
// Future: try splitting into inline helper, or hand-tuning variable lifetimes to block scheduler.
// FLAGS: -fno-schedule-insns

typedef unsigned int size_t;
extern "C" void* memset(void*, int, size_t);

class EAHeap {
public:
    void* MallocAligned(unsigned int, unsigned int, unsigned int, int);
};

EAHeap* MainHeap(void);

class EThread {
public:
    char pad_000[0x31C];
    void *m_stackPtr;       // 0x31C
    int m_stackSize;        // 0x320
    int m_ownsStack;        // 0x324
    int m_initialized;      // 0x328

    int SetupStack(int, void *);
    void DeallocateStack(void);
};

int EThread::SetupStack(int size, void *existingStack) {
    DeallocateStack();
    int owned;
    if (existingStack != 0) {
        owned = 0;
        m_stackPtr = existingStack;
    } else {
        void *alloc = MainHeap()->MallocAligned(size, 64, 0, 0);
        m_initialized = (int)existingStack;
        m_stackPtr = alloc;
        if (alloc == 0) return 0;
        owned = 1;
    }
    m_ownsStack = owned;
    m_stackSize = size;
    memset(m_stackPtr, (int)0xDBDBDBDB, size);
    m_initialized = 1;
    return 1;
}
