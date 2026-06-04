// 0x802D93B0 EA::Allocator::GeneralAllocator::ChunkMatchesBlockType(Chunk*, int) const (72 B)
// Predicate: does this chunk's allocation state match the requested blockType
// mask? blockType bits 0x2/0x4 select "in-use" / "free"; (mask & 6) == 6 means
// "either", so always matches. Otherwise consult the NEXT chunk's in-use bit
// (mnSize & 1). mnSize @ +0x04 (flags in low 3 bits, size = mnSize & ~7).
struct Chunk {
    unsigned int mnPriorSize;  // 0x00
    unsigned int mnSize;       // 0x04
};

// r3 = chunk, r4 = blockType
extern "C" int f_802D93B0(Chunk* chunk, int blockType)
{
    if ((blockType & 6) == 6)
        return 1;
    Chunk* next = (Chunk*)((char*)chunk + (chunk->mnSize & ~7u));
    unsigned int nextInUse = next->mnSize & 1;
    if (blockType & 2)
        return nextInUse;
    if (blockType & 4)
        return nextInUse ^ 1;
    return 0;
}
