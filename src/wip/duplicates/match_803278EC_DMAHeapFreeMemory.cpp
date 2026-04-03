// 0x803278EC (8 bytes) - DMAHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)
// li r3, 0; blr

namespace EA { namespace Allocator { class GeneralAllocator; } }

typedef unsigned int u32;

void* DMAHeapFreeMemory(EA::Allocator::GeneralAllocator*, u32, u32, void*) {
    return 0;
}
