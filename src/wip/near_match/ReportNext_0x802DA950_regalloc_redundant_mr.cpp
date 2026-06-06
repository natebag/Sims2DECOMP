// 0x802DA950 EA::Allocator::GeneralAllocator::ReportNext(void*, int) (480 B)
//
// NEAR-MATCH WALL (Matcher-Opus-2f, 2026-06-06): the FULL function is decoded and
// this clean C++ reproduces the DOL's basic-block structure exactly (goto-based CF
// to force the f18/f1c reloads, per Opus-2e's head-start). 112/120 instructions;
// EVERY remaining gap is the "redundant-mr register-coloring class" CEO notes name
// as a genuine wall ("our correct 3.9.3 beats the 2005 build's codegen") — there is
// no source lever to make a compiler emit *less* optimal code.
//
// WHAT THIS FUNCTION DOES: dual-mode heap iterator over a "Snapshot" report context.
//   guard: pContext!=0 && magic=='SNAP' (0x534E4150), else return 0.
//   mMode (@0x14)==0  -> SNAPSHOT-ARRAY path: walk info[] entries (stride 24) from
//        mIndex (@0x28) up to mCount (@0x24); return &info[i] for the first whose
//        signed m_type (@info+0x10) & (flags) != 0; advance mIndex past it.
//   mMode !=0         -> LIVE-HEAP path: flags &= mBlockTypeFlags (@0x08); walk core
//        blocks from mpCurrentCore (@0x18) until the &mHeadCoreBlock sentinel
//        (this+1100); within each non-empty core, advance mpCurrentChunk (@0x1c) and
//        scan chunks up to pLimit=core+coreSize-16; on a chunk matching via
//        ChunkMatchesBlockType (0x802D93B0, static-like r3=chunk,r4=flags) emit via
//        GetBlockInfoForChunk (0x802D94C4, member const this,chunk,&info) and return
//        &info (= ctx+0x2c). Empty cores skipped; mpCurrentChunk reset to 0 per core.
//
// THE GAP (all the same class — DOL inserts copies / hoists a const that 3.9.3 elides):
//   1. sentinel: DOL `addi r9,r27,1100; mr r28,r9`  (temp then copy to callee-saved).
//      Also `mr r11,r28` at core-advance start. Clean: `addi r28/r29` direct, no copy.
//   2. pCore:    DOL `lwz r0,24(r30); mr r10,r0` at BOTH loop entry and the loop-back
//      while-condition. Clean: `lwz r10/r11,24(r30)` directly into the working reg.
//   3. cur:      DOL `lwz r0,28(r30); mr r3,r0; cmpw r0,r31` in ICHECK and MATCHED
//      (loads f1c to a temp, copies to r3 for the call arg). Clean: `lwz r3,28` direct.
//   4. const 0:  DOL hoists `li r26,0` into a callee-saved reg (6 saved regs, stmw r26)
//      for the one `stw r26,0x1c(r30)` (mpCurrentChunk=0). Clean rematerializes
//      `li r0,0` at the store (5 saved regs, stmw r27) — same total count but no hoist,
//      which shifts the whole callee-saved coloring (flags r29<->r28, sentinel r28<->r29).
//   5. snapshot loop-rotation: DOL keeps the skip-in `b SBODY` with a redundant entry
//      bound check (`cmplw;bge` duplicated in the increment block) + `mr r11,r9`; 3.9.3
//      rotates the loop to one shared bound check. (Even an exact snapshot path would
//      not match overall while the live path walls.)
//
// ROOT CAUSE (not source-fixable): items 1-4 are all the 2005 SN ProDG register
// allocator inserting redundant `mr` copies / hoisting a constant where the verify
// SN ProDG 3.9.3 coalesces directly = strictly fewer instructions. A more-optimal
// compiler cannot be coaxed by source into emitting LESS optimal code. Confirmed the
// gap is allocation, not scheduling (structure already matches; -fno-schedule-insns
// would only perturb, not add the copies). Per CEO calibration the installed SN
// 3.8.1/3.7/3.5 match 3.9.3 on the copy/coloring class, and this lane forbids
// SN-VERSION overrides (3.9.3 IS the original). Re-test only if a genuinely older
// point-version with a different register allocator becomes available, or via objdiff.
//
// Forced ASMPROC stub LEFT UNCHANGED at
// src/matched/agent/match_0x802DA950_..._ReportNext_void.cpp (do not force).

namespace EA { namespace Allocator {

struct Chunk {
    unsigned int mnPriorSize;  // 0x00
    unsigned int mnSize;       // 0x04  size | low-3 flag bits
};

struct CoreBlock {
    Chunk*        mpFirstChunk;       // 0x00
    unsigned int  mnSize;            // 0x04
    char          mPad08[0x24-0x08]; // 0x08
    CoreBlock*    mpNext;            // 0x24  (iteration link)
};

struct BlockInfo {
    void*         f00;   // 0x00
    unsigned int  f04;   // 0x04
    void*         f08;   // 0x08
    unsigned int  f0c;   // 0x0c
    signed char   m_type;// 0x10
    char          pad11[3];
    int           f14;   // 0x14
};                       // size 0x18 = 24

struct Snapshot {
    unsigned int  magic;           // 0x00
    unsigned int  f04;             // 0x04
    int           mBlockTypeFlags; // 0x08
    char          pad0c[0x14-0x0c];
    int           mMode;           // 0x14
    CoreBlock*    mpCurrentCore;   // 0x18
    Chunk*        mpCurrentChunk;  // 0x1c
    char          pad20[0x24-0x20];
    unsigned int  mCount;          // 0x24
    unsigned int  mIndex;          // 0x28
    BlockInfo     info[1];         // 0x2c
};

struct GeneralAllocator {
    char       mPad0[0x44C];        // 0x000
    CoreBlock  mHeadCoreBlock;      // 0x44C = 1100

    static int ChunkMatchesBlockType(Chunk* chunk, int blockType);
    void       GetBlockInfoForChunk(Chunk* chunk, BlockInfo* info) const;
    BlockInfo* ReportNext(void* pContext, int nBlockTypeFlags);
};

BlockInfo* GeneralAllocator::ReportNext(void* pContext, int nBlockTypeFlags)
{
    Snapshot*  pSnapshot = (Snapshot*)pContext;
    CoreBlock* sentinel;
    CoreBlock* pCore;
    Chunk*     pLimit;
    Chunk*     cur;
    unsigned int coreSize;

    if (pSnapshot == 0)
        return 0;
    if (pSnapshot->magic != 0x534E4150u)        // 'SNAP'
        return 0;
    if (pSnapshot->mMode == 0)
        goto L_snapshot;

    // ---- live-heap path ----
    sentinel = &mHeadCoreBlock;
    pCore = pSnapshot->mpCurrentCore;
    nBlockTypeFlags &= pSnapshot->mBlockTypeFlags;
    if (pCore == sentinel)
        return 0;

L_outer:
    coreSize = pCore->mnSize;
    if (coreSize == 0)
        goto L_coreadv;
    {
        Chunk* cc = pSnapshot->mpCurrentChunk;
        pLimit = (Chunk*)((char*)pCore + coreSize - 16);
        if (cc == 0)
            goto L_initchunk;
        pSnapshot->mpCurrentChunk = (Chunk*)((char*)cc + (cc->mnSize & ~7u));
        goto L_icheck;
    }
L_initchunk:
    pSnapshot->mpCurrentChunk = pCore->mpFirstChunk;
    goto L_icheck;

L_advchunk:
    {
        Chunk* a = pSnapshot->mpCurrentChunk;
        pSnapshot->mpCurrentChunk = (Chunk*)((char*)a + (a->mnSize & ~7u));
    }
L_icheck:
    cur = pSnapshot->mpCurrentChunk;
    if (cur == pLimit)
        goto L_brk;
    if (ChunkMatchesBlockType(cur, nBlockTypeFlags) == 0)
        goto L_advchunk;
    cur = pSnapshot->mpCurrentChunk;
    pCore = pSnapshot->mpCurrentCore;
    if (cur != pLimit)
        goto L_emitdone;
L_brk:
    coreSize = pSnapshot->mpCurrentCore->mnSize;
    if (coreSize == 0)
        goto L_coreadv;
    if (cur != pLimit)
        goto L_loopchk;
L_coreadv:
    for (;;) {
        pCore = pSnapshot->mpCurrentCore->mpNext;
        pSnapshot->mpCurrentCore = pCore;
        if (pCore == sentinel)
            break;
        if (pCore->mnSize != 0)
            break;
    }
    pSnapshot->mpCurrentChunk = 0;
L_loopchk:
    pCore = pSnapshot->mpCurrentCore;
    if (pCore != sentinel)
        goto L_outer;
L_emitdone:
    if (pCore == sentinel)
        return 0;
    GetBlockInfoForChunk(pSnapshot->mpCurrentChunk, &pSnapshot->info[0]);
    return &pSnapshot->info[0];

    // ---- snapshot-array path ----
L_snapshot:
    {
        unsigned int idx = pSnapshot->mIndex;
        unsigned int cnt = pSnapshot->mCount;
        if (idx >= cnt)
            return 0;
        goto L_sbody;
    L_sadv:
        idx = idx + 1;
        pSnapshot->mIndex = idx;
        if (idx >= cnt)
            return 0;
    L_sbody:
        if ((pSnapshot->info[idx].m_type & nBlockTypeFlags) == 0)
            goto L_sadv;
        {
            unsigned int i2 = pSnapshot->mIndex;
            if (i2 >= pSnapshot->mCount)
                return 0;
            pSnapshot->mIndex = i2 + 1;
            return &pSnapshot->info[i2];
        }
    }
}

}}
