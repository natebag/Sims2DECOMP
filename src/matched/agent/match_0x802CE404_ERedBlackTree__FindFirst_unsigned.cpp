// 0x802CE404 ERedBlackTree::FindFirst(unsigned (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,5; li 5,0; bl _s802CE404_0; mr. 3,3; beq 2f; 0:; lwz 9,0xc(3); cmpwi 9,0; beq 1f; lwz 0,0x18(9); cmpw 0,31; bne 1f; mr 3,9; b 0b; 1:; cmpwi 30,0; beq 2f; lwz 0,0x1c(3); stw 0,0x0(30); 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802CE404_0();
extern "C" void f_802CE404() {}
