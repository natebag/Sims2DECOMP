// 0x802D9354 EA::Allocator::GeneralAllocator::SetNewTopChunk(Chunk*, int) (60 B)
// Install pChunk as the new top chunk (self-linked free list of one), then, if
// the previous top wasn't the empty-bin sentinel (at this+52) and bAddToBin is
// set, splice the old top chunk into that bin's circular list.
// Chunk free-list links: mpPrev @ +0x08, mpNext @ +0x0C. mpTopChunk @ +0x444.
struct Chunk {
    char   pad0[8];
    Chunk* mpPrev;   // 0x08
    Chunk* mpNext;   // 0x0C
};

struct GeneralAllocator {
    char   pad0[52];
    Chunk  mBin;                                  // 0x34 (this+52)
    char   pad2[1092 - 52 - (int)sizeof(Chunk)];
    Chunk* mpTopChunk;                            // 0x444 (1092)
    void SetNewTopChunk(Chunk* pChunk, int bAddToBin);
};

void GeneralAllocator::SetNewTopChunk(Chunk* pChunk, int bAddToBin)
{
    Chunk* oldTop = mpTopChunk;
    Chunk* bin = &mBin;
    mpTopChunk = pChunk;
    pChunk->mpNext = pChunk;
    pChunk->mpPrev = pChunk;
    if (oldTop == bin)
        return;
    if (!bAddToBin)
        return;
    Chunk* binNext = bin->mpNext;
    oldTop->mpPrev = bin;
    oldTop->mpNext = binNext;
    bin->mpNext = oldTop;
    binNext->mpPrev = oldTop;
}
