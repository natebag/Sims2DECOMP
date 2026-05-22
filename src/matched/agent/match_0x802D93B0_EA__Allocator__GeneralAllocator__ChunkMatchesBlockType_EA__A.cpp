// 0x802D93B0 EA::Allocator::GeneralAllocator::ChunkMatchesBlockType(EA::Allocator::GeneralAllocator::Chunk (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,4,0,29,30; cmpwi 0,6; bne 0f; li 3,1; blr; 0:; lwz 9,0x4(3); andi. 0,4,2; rlwinm 9,9,0,0,28; add 9,3,9; lwz 0,0x4(9); rlwinm 3,0,0,31,31; bnelr; andi. 0,4,4; bne 1f; li 3,0; blr; 1:; xori 3,3,1"
extern "C" int f_802D93B0() {}
