// FLAGS: -fno-schedule-insns
// 0x802DC554 EA::Allocator::GeneralAllocator::GetBlockSize(void*) (12B)
// lwz r3,-4(r4); rlwinm r3,r3,0,0,28; blr — load header word, clear low 3 flag bits
namespace EA { namespace Allocator {
struct GeneralAllocator {
    int GetBlockSize(void* blockPtr) const;
};
int GeneralAllocator::GetBlockSize(void* blockPtr) const {
    return *(int*)((char*)blockPtr - 4) & ~7;
}
}}
