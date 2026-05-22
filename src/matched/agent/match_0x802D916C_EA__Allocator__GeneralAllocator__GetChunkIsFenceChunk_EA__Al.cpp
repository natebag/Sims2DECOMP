// 0x802D916C EA::Allocator::GeneralAllocator::GetChunkIsFenceChunk(EA::Allocator::GeneralAllocator::Chunk (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; lwz 0,0x4(31); rlwinm 0,0,0,0,28; cmplwi 0,15; bgt 0f; bl _s802D916C_0; mr 9,3; lwz 0,0x4(9); li 3,1; add 9,9,0; addi 9,9,-16; cmplw 31,9; bge 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802D916C_0();
extern "C" void f_802D916C() {}
