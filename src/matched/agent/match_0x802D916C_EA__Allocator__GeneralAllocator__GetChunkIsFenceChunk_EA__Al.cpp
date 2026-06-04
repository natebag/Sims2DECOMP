// 0x802D916C EA::Allocator::GeneralAllocator::GetChunkIsFenceChunk(GeneralAllocator::Chunk*) (92 B)
// A fence chunk is a tiny (<=15-byte) chunk parked in the last 16 bytes of its
// owning core block. Reject anything larger up front, then locate the core block
// and test whether the chunk sits at or past (coreEnd - 16).
namespace EA { namespace Allocator {

struct Chunk {
    char         pad0[4];
    unsigned int mnSize;     // 0x04 (low 3 bits = flags)
};

struct CoreBlock {
    char         pad0[4];
    unsigned int mnSize;     // 0x04
};

struct GeneralAllocator {
    bool       GetChunkIsFenceChunk(Chunk* chunk);
    CoreBlock* FindCoreBlockForAddress(void* addr);
};

bool GeneralAllocator::GetChunkIsFenceChunk(Chunk* chunk)
{
    unsigned int size = chunk->mnSize & ~7u;
    if (size <= 15) {
        CoreBlock* core = FindCoreBlockForAddress(chunk);
        if ((char*)chunk >= (char*)core + core->mnSize - 16)
            return true;
    }
    return false;
}

}}
