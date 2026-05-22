// 0x800A0C78 BString2::assign_str(unsigned (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,5; mr 31,3; mr 30,4; cmpwi 29,-1; bne 0f; bl _s800A0C78_0; 0:; mr 3,31; bl _s800A0C78_1; cmplwi 3,1; bgt 1f; cmpwi 29,0; beq 3f; mr 3,31; bl _s800A0C78_2; addi 0,29,1; cmplw 3,0; bge 2f; 1:; bl _s800A0C78_3; li 4,16; li 5,0; bl _s800A0C78_4; mr 4,30; mr 5,29; bl _s800A0C78_5; mr 30,3; mr 3,31; bl _s800A0C78_6; stw 30,0x0(31); b 4f; 2:; mr 3,31; bl _s800A0C78_7; mr 4,30; rlwinm 5,29,1,0,30; bl _s800A0C78_8; 3:; mr 3,31; bl _s800A0C78_9; cmpwi 3,0; beq 4f; mr 3,31; bl _s800A0C78_10; mr 30,3; bl _s800A0C78_11; add 9,29,29; sthx 3,9,30; 4:; lwz 9,0x0(31); stw 29,0x4(9); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800A0C78_0();
extern "C" void _s800A0C78_1();
extern "C" void _s800A0C78_2();
extern "C" void _s800A0C78_3();
extern "C" void _s800A0C78_4();
extern "C" void _s800A0C78_5();
extern "C" void _s800A0C78_6();
extern "C" void _s800A0C78_7();
extern "C" void _s800A0C78_8();
extern "C" void _s800A0C78_9();
extern "C" void _s800A0C78_10();
extern "C" void _s800A0C78_11();
extern "C" void f_800A0C78() {}
