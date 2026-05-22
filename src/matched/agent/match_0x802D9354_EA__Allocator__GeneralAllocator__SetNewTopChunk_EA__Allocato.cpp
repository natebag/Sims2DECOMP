// 0x802D9354 EA::Allocator::GeneralAllocator::SetNewTopChunk(EA::Allocator::GeneralAllocator::Chunk (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x444(3); addi 10,3,52; stw 4,0x444(3); stw 4,0x8(4); cmpw 11,10; stw 4,0xc(4); beqlr; cmplwi 5,0; beqlr; lwz 9,0xc(10); stw 10,0x8(11); stw 9,0xc(11); stw 11,0xc(10); stw 11,0x8(9)"
extern "C" void f_802D9354() {}
