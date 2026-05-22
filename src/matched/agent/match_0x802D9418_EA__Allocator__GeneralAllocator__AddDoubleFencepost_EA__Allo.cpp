// 0x802D9418 EA::Allocator::GeneralAllocator::AddDoubleFencepost(EA::Allocator::GeneralAllocator::Chunk (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(3); ori 4,4,8; li 7,8; li 6,9; clrlwi 9,0,28; addi 9,9,-16; rlwinm 0,0,0,29,31; or 0,0,9; add 8,3,9; stw 0,0x4(3); addi 11,9,8; stwx 9,3,9; add 10,3,11; stw 4,0x4(8); stwx 7,3,11; stw 6,0x4(10)"
extern "C" void f_802D9418() {}
