// 0x800A254C BString2::assign(wchar_t, (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,5; mr 29,3; sth 4,0x8(1); cmpwi 31,-1; bne 0f; bl _s800A254C_0; 0:; mr 3,29; bl _s800A254C_1; cmplwi 3,1; bgt 1f; cmpwi 31,0; beq 2f; mr 3,29; bl _s800A254C_2; addi 0,31,1; cmplw 3,0; bge 2f; 1:; bl _s800A254C_3; li 4,16; li 5,0; bl _s800A254C_4; lhz 4,0x8(1); mr 5,31; bl _s800A254C_5; mr 30,3; mr 3,29; bl _s800A254C_6; stw 30,0x0(29); b 5f; 2:; li 30,0; add 28,31,31; cmplw 30,31; bge 4f; 3:; mr 3,29; bl _s800A254C_7; add 9,30,30; lhz 0,0x8(1); addi 30,30,1; sthx 0,9,3; cmplw 30,31; blt 3b; 4:; mr 3,29; bl _s800A254C_8; mr 30,3; bl _s800A254C_9; sthx 3,28,30; lwz 9,0x0(29); stw 31,0x4(9); 5:; mr 3,29; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s800A254C_0();
extern "C" void _s800A254C_1();
extern "C" void _s800A254C_2();
extern "C" void _s800A254C_3();
extern "C" void _s800A254C_4();
extern "C" void _s800A254C_5();
extern "C" void _s800A254C_6();
extern "C" void _s800A254C_7();
extern "C" void _s800A254C_8();
extern "C" void _s800A254C_9();
extern "C" void f_800A254C() {}
