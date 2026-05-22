// 0x802D8FB0 EA::Allocator::GeneralAllocator::FindPriorChunk(EA::Allocator::GeneralAllocator::Chunk (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; lwz 0,0x0(31); cmpwi 0,0; beq 1f; bl _s802D8FB0_0; mr. 3,3; beq 1f; lwz 3,0x0(3); cmplw 31,3; ble 1f; lwz 0,0x4(3); rlwinm 0,0,0,0,28; add 0,3,0; cmplw 0,31; bge 2f; 0:; mr 3,0; lwz 0,0x4(3); rlwinm 0,0,0,0,28; add 0,3,0; cmplw 0,31; blt 0b; b 2f; 1:; li 3,0; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802D8FB0_0();
extern "C" void f_802D8FB0() {}
