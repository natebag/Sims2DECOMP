// 0x802D91C8 EA::Allocator::GeneralAllocator::FindChunkBin(Chunk*) const (392 B)
//
// NEAR-MATCH WALL (Matcher-Opus-2e, 2026-06-05): 97/98 instructions, BLOCK ORDER
// MATCHES DOL EXACTLY. Single remaining gap = the classic "redundant-mr" register-
// coloring quirk described in CEO notes: DOL keeps `size` in r11 and emits a
// redundant `mr r3,r11` before the `bl GetLargeBinIndexFromChunkSize`; this clean
// source lets the SAME SN ProDG 3.9.3 compiler coalesce `size` directly into r3
// (the call-arg register), so the `mr` is elided and `size` is r3 throughout.
//
// ROOT CAUSE (not source-fixable): `size`'s live range (computed at top, last used
// at the GetLargeBin call) STRICTLY CONTAINS the size-specific fastbin head's live
// range (the do-while walk). Both prefer r3. They CONFLICT (can't share r3 since
// size is live across the head walk). DOL's allocator picked head->r3 (size->r11,
// + the redundant mr). This source's allocator picked size->r3 (head->r9, no mr) —
// strictly better/shorter codegen. The algorithm forces this overlap (fastbin walk
// must run before the bin-index calc, and size feeds both), so there is no clean
// C++ lever to flip the tiebreak. Confirmed unaffected by -fno-schedule-insns
// (coloring, not scheduling). Re-test only on a different SN point-version.
//
// VALIDATED RECIPES banked from this attempt (these DID land their pieces):
//  - block-order: write `if (in_range) {sentinel} else {size_based}` (in-range as
//    the THEN branch) -> GCC emits `blt size_based; bge size_based; sentinel falls
//    through; b search` matching the DOL layout. The inverted (`if out_of_range`)
//    form reorders the blocks.
//  - sentinel index reassoc: an EXPLICIT `int adj=(int)pChunk-52;` temp prevents
//    GCC from folding `pChunk-52-this` into `pChunk-(this+52)` (reusing the cached
//    &mBins[0] reg). Gives DOL's 2-insn `addi r9,r31,-52; subf r9,r30,r9`.
//  - add-operand canon: `(size>>1) + (unsigned int)this + 4` (offset FIRST, uint
//    cast) yields `add rD,half,this` (half as rA) matching DOL, vs `(char*)this +
//    (size>>1)` which puts this as rA.
//  - size-specific fastbin address = *(Chunk**)((size>>1) + (uint)this + 4)
//    => srwi rN,size,1; add; lwz rD,4(.)  (the +4 folds into the lwz displacement).
//
// DO NOT FORCE. The forced ASMPROC stub at src/matched/agent/ is left UNCHANGED.
namespace EA { namespace Allocator {

struct Chunk {
    unsigned int mPrevSize;   // 0x00
    unsigned int mnSize;      // 0x04  size | flag bits
    Chunk*       mpNext;      // 0x08  fd
    Chunk*       mpPrev;      // 0x0C  bk
};

struct GeneralAllocator {
    char         mPad0[0x04];    // 0x00
    unsigned int mField4;        // 0x04  max-fast threshold
    char         mPad1[0x04];    // 0x08
    Chunk*       mFastBins[10];  // 0x0C
    Chunk*       mBins[256];     // 0x34
    char         mPad2[0x10];    // 0x434
    Chunk*       mpTopChunk;     // 0x444

    int FindChunkBin(Chunk* pChunk) const;
    static int GetLargeBinIndexFromChunkSize(unsigned int size);
};

int GeneralAllocator::FindChunkBin(Chunk* pChunk) const
{
    if (pChunk == mpTopChunk)
        return 3;

    unsigned int size = pChunk->mnSize & ~7u;

    if (size > 15 && size <= mField4)
    {
        unsigned int half = size >> 1;
        Chunk* p = *(Chunk**)(half + (unsigned int)this + 4);
        if (p)
        {
            do {
                if (p == pChunk)
                    return 1;
                p = p->mpPrev;
            } while (p);
        }
    }

    int binIndex;
    if ((char*)pChunk >= (char*)&mBins[0] && (char*)pChunk < (char*)&mBins[256])
    {
        int adj = (int)pChunk - 52;
        binIndex = ((adj - (int)this) >> 4) + 2;
    }
    else
    {
        if (size <= 511)
            binIndex = size >> 3;
        else
            binIndex = GetLargeBinIndexFromChunkSize(size);
    }

    {
        Chunk* pBin = mBins[binIndex];
        Chunk* p = pBin->mpPrev;
        if (p != pBin)
        {
            do {
                if (p == pChunk)
                    return 2;
                p = p->mpPrev;
            } while (p != pBin);
        }
    }

    {
        Chunk* const* ppFast = &mFastBins[0];
        for (int i = 0; i < 10; i++)
        {
            Chunk* p = *ppFast++;
            if (p)
            {
                do {
                    if (p == pChunk)
                        return 1;
                    p = p->mpPrev;
                } while (p);
            }
        }
    }

    for (int i = 1; i < 128; i++)
    {
        Chunk* pHead = mBins[2 * i];
        Chunk* p = pHead->mpPrev;
        if (p != pHead)
        {
            do {
                if (p == pChunk)
                    return 2;
                p = p->mpPrev;
            } while (p != mBins[2 * i]);
        }
    }

    return 0;
}

}}
