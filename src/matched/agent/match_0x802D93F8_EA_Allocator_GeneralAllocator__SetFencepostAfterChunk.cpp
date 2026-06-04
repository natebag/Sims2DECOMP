// FLAGS: -fno-schedule-insns
// 0x802D93F8 EA::Allocator::GeneralAllocator::SetFencepostAfterChunk(Chunk*, unsigned int) (32B)
// Write the trailing fencepost chunks at chunk+size: store the prior size at
// +0 (indexed), then mark the two fencepost chunk headers {+12=9, +8=8, +4=8}.
// r3 = chunk, r4 = size.
extern "C" void f_802D93F8(char* chunk, unsigned int size)
{
    *(unsigned int*)(chunk + size) = size;
    chunk = chunk + size;
    *(unsigned int*)(chunk + 12) = 9;
    *(unsigned int*)(chunk + 8)  = 8;
    *(unsigned int*)(chunk + 4)  = 8;
}
