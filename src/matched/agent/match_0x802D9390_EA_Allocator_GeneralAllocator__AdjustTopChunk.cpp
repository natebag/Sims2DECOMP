// 0x802D9390 EA::Allocator::GeneralAllocator::AdjustTopChunk(Chunk*, unsigned int) (24B)
//
// Resolved by source-only misclassification fix: function was parked as
// `static` but DOL uses r3 = this with r4 = chunk, r5 = size. Declaring
// as instance method (non-static) shifts args correctly and byte-matches
// on first compile. Same wall pattern as 0x802DC560 LinkCoreBlock.

namespace EA { namespace Allocator {

struct GeneralAllocator {
    struct Chunk {};
    void AdjustTopChunk(Chunk* chunk, unsigned int size);
};

void GeneralAllocator::AdjustTopChunk(Chunk* chunk, unsigned int size) {
    *(Chunk**)((char*)chunk + 12) = chunk;
    *(unsigned int*)((char*)chunk + 4) = size | 1;
    *(Chunk**)((char*)chunk + 8) = chunk;
    *(unsigned int*)((char*)chunk + size) = size;
}

}}
