// 0x802D8A6C EA::Allocator::GeneralAllocator::Init(void*, unsigned int, bool, bool,
//            unsigned int(*)(GeneralAllocator*, void*, unsigned int, void*), void*) (424 B)
//
// NEAR-MATCH WALL (Matcher-Opus-2f, 2026-06-06): 105/120... 105/106 instructions with
// DEFAULT scheduling (NOT the forced stub's -fno-schedule-insns, which is over-applied
// here and drops to 104/106 by also losing the param-register allocation). Default
// scheduling reproduces the DOL's 12-callee-saved-reg allocation and param numbering
// (r20-r25) exactly. The function is fully decoded; this clean C++ describes it faithfully.
//
// WHAT IT DOES: one-time allocator init guarded by mField0. If mField0==0: set it, call
// SetOption(0,1), then under an RAII mutex guard (m_mutex@0x4FC, spilled to 8(1)):
//   mFlags=64; memset fast bins (this+0x0C,40); memset regular bins (this+0x34,1024);
//   init 127 circular-empty bin sentinels (each: fd@+8=self, bk@+12=self, stride 8);
//   memset(this+0x434,16); mpTopChunk=&mBins; clear/self-link mHeadCoreBlock (this+0x44C,40);
//   set a pile of fields (@0x474/0x478/0x498/0x49C counters=0, @0x4A0=0x10000, @0x4A4=0x20000,
//   mFlags=(mFlags&1)|72); memset(this+0x4AC,16) + self-link @0x4B4/0x4B8; @0x4E0=0x20000,
//   @0x4E4=0x10000, @0x4E8=mpTopChunk, @0x4EC=GetPageSize(). Unlock. Then, unconditionally,
//   if (a||b) AddCore(a,b,c,d,e,f); return true.
//
// THE GAP (the same redundant-mr coloring class as ReportNext 0x802DA950 / FindChunkBin):
//   * Loop-walker copy: DOL captures this+52 into r29 BEFORE the bins memset, then for the
//     DESTRUCTIVE bin-init walk it makes a FRESH temp copy `mr r9,r29` and walks r9, leaving
//     the memset pointer (r30) dead. SN ProDG 3.9.3 instead COALESCES the walker into the
//     already-dead memset pointer (walks r30 directly), eliding the `mr` = 1 insn shorter.
//     No source form tried (shared `char* base`, typed Chunk* walker, memset-return idiom)
//     makes 3.9.3 emit the redundant copy — coalescing a same-valued dead reg is strictly
//     better codegen the source can't un-do.
//   * Store-sort: the ~10 field stores in the 0x46C..0x4A4 block are scheduled into a
//     different (also-legal) order than the DOL under default scheduling; brute-forcing the
//     source statement order could align these, but it is moot while the loop-walker walls
//     the instruction COUNT (105 vs 106 -> SIZE_MISMATCH regardless of store order).
//
// ROOT CAUSE (not source-fixable): redundant-mr / register-coalescing-tiebreak — the 2005
// SN ProDG allocator inserts a copy the verify 3.9.3 allocator coalesces. CEO-noted genuine
// wall class ("do not grind"). SN-VERSION forbidden in this lane (3.9.3 IS the original);
// calibration shows 3.8.1/3.7/3.5 identical on the copy/coloring class. Retry only via objdiff
// or a genuinely-different-allocator point-version.
//
// Forced ASMPROC stub LEFT UNCHANGED at
// src/matched/agent/match_0x802D8A6C_EA__Allocator__GeneralAllocator__Init_void.cpp.

namespace EA { namespace Allocator {

extern "C" void  PPMMutexLock(void* m);
extern "C" void  PPMMutexUnlock(void* m);
extern "C" void* memset(void* p, int c, unsigned int n);

typedef unsigned int (*CoreAddFn)(void*, void*, unsigned int, void*);

struct CoreBlock {
    char        pad00[0x20];   // 0x00
    CoreBlock*  mpNext;        // 0x20
    CoreBlock*  mpPrev;        // 0x24
};                             // 0x28 = 40

struct PPMutexAutoLock {
    void* mpMutex;
    PPMutexAutoLock(void* m) : mpMutex(m) { if (m) PPMMutexLock(m); }
    ~PPMutexAutoLock() { if (mpMutex) PPMMutexUnlock(mpMutex); }
};

struct GeneralAllocator {
    int           mField0;             // 0x000
    unsigned int  mFlags;              // 0x004
    char          mPad08[0x0C - 0x08]; // 0x008
    void*         mFastBins[10];       // 0x00C (40)
    char          mBins[1024];         // 0x034
    char          mField434[16];       // 0x434
    void*         mpTopChunk;          // 0x444
    void*         mField448;           // 0x448
    CoreBlock     mHeadCoreBlock;      // 0x44C (40) -> mpNext@0x46C, mpPrev@0x470
    unsigned int  mField474;           // 0x474
    unsigned int  mField478;           // 0x478
    char          mPad47C[0x498 - 0x47C];
    unsigned int  mField498;           // 0x498
    unsigned int  mField49C;           // 0x49C
    unsigned int  mField4A0;           // 0x4A0
    unsigned int  mField4A4;           // 0x4A4
    unsigned int  mField4A8;           // 0x4A8
    char          mField4AC[0x4B4 - 0x4AC]; // 0x4AC (8)
    void*         mField4B4;           // 0x4B4
    void*         mField4B8;           // 0x4B8
    char          mPad4BC[0x4E0 - 0x4BC];
    unsigned int  mField4E0;           // 0x4E0
    unsigned int  mField4E4;           // 0x4E4
    void*         mField4E8;           // 0x4E8
    int           mField4EC;           // 0x4EC
    char          mPad4F0[0x4FC - 0x4F0];
    void*         m_mutex;             // 0x4FC

    void          SetOption(int option, int value);
    static int    GetPageSize();
    bool          AddCore(void* a, unsigned int b, bool c, bool d, CoreAddFn e, void* f);
    bool          Init(void* a, unsigned int b, bool c, bool d, CoreAddFn e, void* f);
};

bool GeneralAllocator::Init(void* a, unsigned int b, bool c, bool d, CoreAddFn e, void* f)
{
    if (mField0 == 0) {
        mField0 = 1;
        SetOption(0, 1);

        PPMutexAutoLock lock(m_mutex);

        mFlags = 64;
        memset(mFastBins, 0, 40);
        memset(mBins, 0, 1024);

        {
            char* p = mBins;
            int i = 127;
            do {
                *(char**)(p + 8) = p;
                *(char**)(p + 12) = p;
                p += 8;
            } while (--i);
        }

        memset(mField434, 0, 16);

        mpTopChunk = mBins;
        mField448 = 0;
        memset(&mHeadCoreBlock, 0, 40);

        mHeadCoreBlock.mpPrev = &mHeadCoreBlock;
        mField4A8 = 0;
        mHeadCoreBlock.mpNext = &mHeadCoreBlock;
        mField474 = 0;
        mField478 = 0;
        mField498 = 0;
        mField49C = 0;
        mField4A0 = 0x10000;
        mField4A4 = 0x20000;
        mFlags = (mFlags & 1) | 72;
        memset(mField4AC, 0, 16);

        mField4B8 = mField4AC;
        mField4E0 = 0x20000;
        mField4E4 = 0x10000;
        mField4B4 = mField4AC;
        mField4E8 = mpTopChunk;
        mField4EC = GetPageSize();
    }

    if (a != 0 || b != 0)
        AddCore(a, b, c, d, e, f);

    return true;
}

}}
