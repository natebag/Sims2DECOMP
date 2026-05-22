// 0x800660BC SAnimator2::cleanupParticles(TRedBlackTree<unsigned (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,4; li 27,1; lwz 30,0x0(28); cmpwi 30,0; beq 9f; 0:; lwz 29,0x1c(30); li 10,1; lwz 11,0x0(29); cmpwi 11,0; beq 3f; 1:; lwz 9,0x1c(11); lwz 0,0x7c(9); cmpwi 0,0; beq 2f; li 10,0; li 27,0; 2:; lwz 11,0x10(11); cmpwi 11,0; bne 1b; 3:; cmpwi 10,0; beq 8f; lwz 9,0x0(29); b 6f; 4:; lwz 3,0x1c(9); lwz 31,0x10(9); cmpwi 3,0; beq 5f; li 4,3; bl _s800660BC_0; 5:; mr 9,31; 6:; li 0,1; cmpwi 9,0; bne 7f; li 0,0; 7:; cmpwi 0,0; bne 4b; mr 3,29; bl _s800660BC_1; 8:; lwz 30,0x10(30); cmpwi 30,0; bne 0b; 9:; cmpwi 27,0; beq 14f; lwz 9,0x0(28); b 12f; 10:; lwz 31,0x1c(9); lwz 30,0x10(9); cmpwi 31,0; beq 11f; mr 3,31; bl _s800660BC_2; mr 3,31; bl _s800660BC_3; 11:; mr 9,30; 12:; li 0,1; cmpwi 9,0; bne 13f; li 0,0; 13:; cmpwi 0,0; bne 10b; mr 3,28; bl _s800660BC_4; 14:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800660BC_0();
extern "C" void _s800660BC_1();
extern "C" void _s800660BC_2();
extern "C" void _s800660BC_3();
extern "C" void _s800660BC_4();
extern "C" void f_800660BC() {}
