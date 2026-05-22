// 0x802DC80C EA::Allocator::GeneralAllocator::AddCoreInternal(unsigned (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; addi 4,4,-1; lwz 9,0x4ec(29); lwz 11,0x4f0(29); neg 10,9; add 4,4,9; and 28,4,10; mr 30,28; mr 27,30; cmplw 30,11; bge 0f; addi 0,11,-1; add 0,0,9; and 30,0,10; 0:; mr 3,30; bl _s802DC80C_0; mr. 31,3; bne 3f; cmplw 30,28; blt 2f; 1:; rlwinm 0,30,1,0,30; add 0,0,30; rlwinm 30,0,30,2,31; mr 3,30; bl _s802DC80C_1; mr. 31,3; bne 3f; cmplw 30,27; bge 1b; 2:; cmpwi 31,0; beq 5f; 3:; addi 0,31,47; li 9,0; rlwinm 0,0,0,0,28; stw 9,0xc(31); stw 0,0x0(31); addi 5,29,1100; stw 30,0x4(31); stw 30,0x8(31); li 9,1; lwz 0,0x470(29); cmpw 0,5; bne 4f; li 9,0; 4:; li 0,0; mr 4,31; mr 3,29; stw 9,0x14(31); stw 0,0x1c(31); stw 9,0x10(31); stw 0,0x18(31); bl _s802DC80C_2; lwz 3,0x0(31); li 5,1; subf 4,31,3; subf 4,4,30; bl _s802DC80C_3; b 6f; 5:; li 3,0; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s802DC80C_0();
extern "C" void _s802DC80C_1();
extern "C" void _s802DC80C_2();
extern "C" void _s802DC80C_3();
extern "C" void f_802DC80C() {}
