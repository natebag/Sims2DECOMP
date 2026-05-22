// 0x802D99C4 EA::Allocator::GeneralAllocator::CheckUsedChunk(EA::Allocator::GeneralAllocator::Chunk (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 29,3; mr 31,4; lwz 3,0x4fc(29); stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s802D99C4_0; 0:; mr 3,29; mr 4,31; bl _s802D99C4_1; lwz 9,0x4(31); mr 30,3; andi. 0,9,2; bne 4f; rlwinm 9,9,0,0,28; li 4,1; add 9,31,9; lwz 0,0x4(9); andi. 9,0,1; bne 1f; li 4,0; 1:; mr 3,29; bl _s802D99C4_2; lwz 0,0x4(31); add 30,30,3; rlwinm 9,0,0,0,28; andi. 11,0,1; add 28,31,9; bne 2f; lwz 4,0x0(31); mr 3,29; subf 4,4,31; lwz 0,0x4(4); rlwinm 0,0,0,0,28; add 4,4,0; xor 4,4,31; subfic 0,4,0; adde 4,0,4; bl _s802D99C4_3; add 30,30,3; 2:; lwz 0,0x444(29); cmpw 28,0; bne 4f; lwz 0,0x4(28); li 4,1; andi. 9,0,1; bne 3f; li 4,0; 3:; mr 3,29; bl _s802D99C4_4; lwz 4,0x4(28); add 30,30,3; mr 3,29; rlwinm 4,4,0,0,28; subfic 4,4,15; subfe 4,4,4; neg 4,4; bl _s802D99C4_5; add 30,30,3; 4:; lwz 3,0x8(1); cmpwi 3,0; beq 5f; bl _s802D99C4_6; 5:; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s802D99C4_0();
extern "C" void _s802D99C4_1();
extern "C" void _s802D99C4_2();
extern "C" void _s802D99C4_3();
extern "C" void _s802D99C4_4();
extern "C" void _s802D99C4_5();
extern "C" void _s802D99C4_6();
extern "C" void f_802D99C4() {}
