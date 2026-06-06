// 0x802D886C EA::Allocator::GeneralAllocator::GeneralAllocator(...) (448 B)
// FLAGS: -fno-schedule-insns
//
// NEAR-MATCH WALL (Matcher-Opus-2f, 2026-06-06): instruction COUNT matches exactly
// (448 B / 112 insns) — this clean straight-line constructor describes the function
// faithfully. ~55 byte diffs, ALL register-coloring / constant-materialization-ordering
// (the same class as ReportNext 0x802DA950, Init 0x802D8A6C, FindChunkBin 0x802D91C8).
//
// WHAT IT DOES: zero-init the GeneralAllocator (6 memsets over the fast-bin / regular-bin /
// core-block / option regions + ~45 individual field zero-stores), set the non-zero defaults
// (m08=1, m47C=1, m484=9, m485=10, m4CC=256, m4EC=4096, m4F0=0x400000, m4F4=0x100000,
// m520..m524 = {221,222,205,171,254}, two default-callback fn-ptrs @0x4D0/0x4D8, two self
// back-pointers @0x4D4/0x4DC = this), then delegate to Init(a,b,c,d,e,f). Returns this.
//
// THE GAP (not source-fixable — register allocation + constant scheduling tiebreaks):
//   * Param coloring: the 6 ctor params (live entry->Init call) get assigned to callee-saved
//     r22-r27 in a different order than the DOL (DOL: a=r27,b=r24,c=r26,d=r25,e=r23,f=r22).
//   * Constant coloring: 9/10 land in swapped regs (DOL r9/r0); the four block constants
//     256/4096/0x400000/0x100000 the DOL materializes UP FRONT and stores at the end of the
//     zero-block (held across ~12 zero-stores), while 3.9.3 materializes-then-stores each
//     inline — a constant-scheduling difference that cascades ~40 store-offset diffs.
//   * -fno-schedule-insns is the closest baseline (55 diffs); default scheduling is worse (a
//     different, larger cascade). Neither reproduces the DOL allocator/scheduler choices.
//
// Same redundant-mr / coloring class CEO notes flag as a genuine "do not grind" wall. The 2005
// SN ProDG register allocator + constant scheduler differ from verify 3.9.3 with no source lever.
// Retry only via objdiff or a genuinely-different point-version. SN-VERSION forbidden in this lane.
// Forced ASMPROC stub LEFT UNCHANGED at
// src/matched/agent/match_0x802D886C_..._GeneralAllocator_void.cpp.

namespace EA { namespace Allocator {

extern "C" void* memset(void* p, int c, unsigned int n);

// Default callback function pointers stored into the allocator (absolute relocs
// at 0x802DA51C / 0x802DA584 in the original; masked by verify).
extern "C" void GeneralAllocator_DefaultCoreCallback();
extern "C" void GeneralAllocator_DefaultTraceCallback();

typedef unsigned int (*CoreAddFn)(void*, void*, unsigned int, void*);

struct GeneralAllocator {
    int           m00;                 // 0x000
    int           m04;                 // 0x004
    int           m08;                 // 0x008
    char          mFastBins[0x34-0x0C];// 0x00C (40)  memset
    char          mBins[1024];         // 0x034       memset
    char          m434[16];            // 0x434       memset
    int           m444;                // 0x444
    int           m448;                // 0x448
    char          mHeadCoreBlock[40];  // 0x44C       memset (0x44C..0x474)
    int           m474;                // 0x474
    int           m478;                // 0x478
    int           m47C;                // 0x47C
    int           m480;                // 0x480
    unsigned char m484;                // 0x484
    unsigned char m485;                // 0x485
    char          mPad486[2];          // 0x486
    int           m488;                // 0x488
    int           m48C;                // 0x48C
    int           m490;                // 0x490
    int           m494;                // 0x494
    int           m498;                // 0x498
    int           m49C;                // 0x49C
    int           m4A0;                // 0x4A0
    int           m4A4;                // 0x4A4
    int           m4A8;                // 0x4A8
    char          m4AC[16];            // 0x4AC       memset (0x4AC..0x4BC)
    int           m4BC;                // 0x4BC
    int           m4C0;                // 0x4C0
    int           m4C4;                // 0x4C4
    int           m4C8;                // 0x4C8
    int           m4CC;                // 0x4CC
    void*         m4D0;                // 0x4D0
    void*         m4D4;                // 0x4D4
    void*         m4D8;                // 0x4D8
    void*         m4DC;                // 0x4DC
    int           m4E0;                // 0x4E0
    int           m4E4;                // 0x4E4
    int           m4E8;                // 0x4E8
    int           m4EC;                // 0x4EC
    int           m4F0;                // 0x4F0
    int           m4F4;                // 0x4F4
    int           m4F8;                // 0x4F8
    void*         m_mutex;             // 0x4FC
    char          m500[32];            // 0x500       memset (0x500..0x520)
    unsigned char m520;                // 0x520
    unsigned char m521;                // 0x521
    unsigned char m522;                // 0x522
    unsigned char m523;                // 0x523
    unsigned char m524;                // 0x524

    void Init(void* a, unsigned int b, bool c, bool d, CoreAddFn e, void* f);
    GeneralAllocator(void* a, unsigned int b, bool c, bool d, CoreAddFn e, void* f);
};

GeneralAllocator::GeneralAllocator(void* a, unsigned int b, bool c, bool d, CoreAddFn e, void* f)
{
    m00 = 0;
    m04 = 0;
    m08 = 1;
    memset(mFastBins, 0, 40);
    memset(mBins, 0, 1024);
    memset(m434, 0, 16);
    m444 = 0;
    m448 = 0;
    memset(mHeadCoreBlock, 0, 40);
    m474 = 0;
    m478 = 0;
    m480 = 0;
    m488 = 0;
    m48C = 0;
    m490 = 0;
    m494 = 0;
    m498 = 0;
    m49C = 0;
    m4A0 = 0;
    m4A4 = 0;
    m4A8 = 0;
    m47C = 1;
    m484 = 9;
    m485 = 10;
    memset(m4AC, 0, 16);
    m_mutex = 0;
    m4BC = 0;
    m4C0 = 0;
    m4C4 = 0;
    m4C8 = 0;
    m4D0 = 0;
    m4D4 = 0;
    m4D8 = 0;
    m4DC = 0;
    m4E0 = 0;
    m4E4 = 0;
    m4E8 = 0;
    m4F8 = 0;
    m4CC = 256;
    m4EC = 4096;
    m4F0 = 0x400000;
    m4F4 = 0x100000;
    memset(m500, 0, 32);
    m521 = 222;
    m522 = 205;
    m523 = 171;
    m4D4 = (void*)this;
    m4DC = (void*)this;
    m520 = 221;
    m524 = 254;
    m4D0 = (void*)&GeneralAllocator_DefaultCoreCallback;
    m4D8 = (void*)&GeneralAllocator_DefaultTraceCallback;
    Init(a, b, c, d, e, f);
}

}}
