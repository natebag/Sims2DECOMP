// 0x800A1DC8 BString2::operator=(BString2 (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 31,4; cmpw 29,31; beq 1f; bl _s800A1DC8_0; mr 3,31; bl _s800A1DC8_1; cmpwi 3,-1; beq 0f; lwz 11,0x0(31); stw 11,0x0(29); lwz 9,0xc(11); addi 9,9,1; stw 9,0xc(11); b 1f; 0:; bl _s800A1DC8_2; li 4,16; li 5,0; bl _s800A1DC8_3; mr 30,3; mr 3,31; bl _s800A1DC8_4; mr 6,3; mr 4,31; mr 3,30; li 5,0; bl _s800A1DC8_5; stw 3,0x0(29); 1:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800A1DC8_0();
extern "C" void _s800A1DC8_1();
extern "C" void _s800A1DC8_2();
extern "C" void _s800A1DC8_3();
extern "C" void _s800A1DC8_4();
extern "C" void _s800A1DC8_5();
extern "C" void f_800A1DC8() {}
