// 0x800A3F74 BString2::substr(unsigned (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,4; mr 29,3; mr 30,5; mr 27,6; mr 3,31; bl _s800A3F74_0; cmplw 30,3; ble 0f; bl _s800A3F74_1; 0:; mr 3,31; bl _s800A3F74_2; cmpwi 3,0; beq 5f; mr 3,31; bl _s800A3F74_3; cmpwi 3,0; beq 1f; lwz 9,0x0(31); lwz 4,0x0(9); b 2f; 1:; li 4,0; 2:; add 0,30,30; mr 3,31; add 28,4,0; bl _s800A3F74_4; subf 3,30,3; cmplw 27,3; ble 3f; mr 3,31; bl _s800A3F74_5; subf 5,30,3; b 4f; 3:; mr 5,27; 4:; mr 4,28; mr 3,29; bl _s800A3F74_6; b 6f; 5:; mr 3,29; bl _s800A3F74_7; 6:; mr 3,29; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800A3F74_0();
extern "C" void _s800A3F74_1();
extern "C" void _s800A3F74_2();
extern "C" void _s800A3F74_3();
extern "C" void _s800A3F74_4();
extern "C" void _s800A3F74_5();
extern "C" void _s800A3F74_6();
extern "C" void _s800A3F74_7();
extern "C" void f_800A3F74() {}
