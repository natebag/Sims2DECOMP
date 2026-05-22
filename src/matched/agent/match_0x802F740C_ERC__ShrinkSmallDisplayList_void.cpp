// 0x802F740C ERC::ShrinkSmallDisplayList(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 0,0x20(31); cmpwi 0,1; bne 0f; lwz 0,0x4(31); cmpwi 0,0; beq 0f; lwz 9,0x0(31); lwz 11,0x8(31); lwz 0,0x48(9); subf 29,0,11; bl _s802F740C_0; mr 4,29; li 5,0; bl _s802F740C_1; mr. 30,3; beq 0f; lwz 9,0x0(31); mr 5,29; mr 3,30; lwz 4,0x48(9); bl _s802F740C_2; lwz 3,0x0(31); lwz 4,0x48(3); addi 3,3,24; bl _s802F740C_3; bl _s802F740C_4; lwz 9,0x0(31); lwz 4,0x48(9); bl _s802F740C_5; lwz 9,0x0(31); mr 3,31; mr 4,30; mr 5,29; stw 30,0x48(9); bl _s802F740C_6; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802F740C_0();
extern "C" void _s802F740C_1();
extern "C" void _s802F740C_2();
extern "C" void _s802F740C_3();
extern "C" void _s802F740C_4();
extern "C" void _s802F740C_5();
extern "C" void _s802F740C_6();
extern "C" void f_802F740C() {}
