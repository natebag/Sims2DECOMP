// 0x802D8FB0 EA::Allocator::GeneralAllocator::FindPriorChunk(GeneralAllocator::Chunk*) (128 B)
// Locate the chunk physically preceding `addr` within its core block. Bail out
// if addr has no prior-size, isn't owned by any core, or sits at/before the
// core's first chunk. Otherwise walk chunk-by-chunk (size = mnSize & ~7) until
// the next boundary reaches addr, and return that chunk.
namespace EA { namespace Allocator {

struct Chunk {
    unsigned int mnPriorSize;   // 0x00
    unsigned int mnSize;        // 0x04 (low 3 bits = flags)
};

struct CoreBlock {
    Chunk* mpFirstChunk;        // 0x00
};

struct GeneralAllocator {
    Chunk*     FindPriorChunk(Chunk* addr);
    CoreBlock* FindCoreBlockForAddress(void* addr);
};

EA::Allocator::Chunk* GeneralAllocator::FindPriorChunk(Chunk* addr)
{
    if (addr->mnPriorSize != 0) {
        CoreBlock* core = FindCoreBlockForAddress(addr);
        if (core != 0) {
            Chunk* chunk = core->mpFirstChunk;
            if ((char*)addr > (char*)chunk) {
                char* next = (char*)chunk + (chunk->mnSize & ~7u);
                while (next < (char*)addr) {
                    chunk = (Chunk*)next;
                    next = (char*)chunk + (chunk->mnSize & ~7u);
                }
                return chunk;
            }
        }
    }
    return 0;
}

}}
