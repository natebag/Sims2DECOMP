// 0x802D9BD0 EA::Allocator::GeneralAllocator::CheckMallocedChunk(EA::Allocator::GeneralAllocator::Chunk (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 29,3; mr 30,4; lwz 3,0x4fc(29); mr 28,5; mr 27,6; mr 26,7; stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s802D9BD0_0; 0:; lwz 9,0x4(30); li 4,1; rlwinm 9,9,0,0,28; add 9,30,9; lwz 0,0x4(9); andi. 9,0,1; bne 1f; li 4,0; 1:; mr 3,29; bl _s802D9BD0_1; mr 31,3; mr 5,28; mr 3,29; mr 4,30; bl _s802D9BD0_2; add 31,31,3; cmpwi 27,0; beq 3f; cmpwi 26,0; bne 3f; lwz 0,0x4(30); li 4,1; andi. 9,0,1; bne 2f; li 4,0; 2:; mr 3,29; bl _s802D9BD0_3; add 31,31,3; 3:; lwz 3,0x8(1); cmpwi 3,0; beq 4f; bl _s802D9BD0_4; 4:; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s802D9BD0_0();
extern "C" void _s802D9BD0_1();
extern "C" void _s802D9BD0_2();
extern "C" void _s802D9BD0_3();
extern "C" void _s802D9BD0_4();
extern "C" void f_802D9BD0() {}
