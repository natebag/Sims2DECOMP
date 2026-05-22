// 0x800A2BEC BString2::replace(unsigned (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 31,6; mr 28,3; mr 30,7; mr 27,4; mr 29,5; mr 26,8; mr 3,31; bl _s800A2BEC_0; cmplw 30,3; ble 0f; bl _s800A2BEC_1; 0:; mr 3,28; bl _s800A2BEC_2; subf 3,27,3; cmplw 29,3; ble 1f; mr 3,28; bl _s800A2BEC_3; subf 25,27,3; b 2f; 1:; mr 25,29; 2:; mr 3,31; bl _s800A2BEC_4; subf 3,30,3; cmplw 26,3; ble 3f; mr 3,31; bl _s800A2BEC_5; subf 29,30,3; b 4f; 3:; mr 29,26; 4:; mr 3,31; bl _s800A2BEC_6; cmpwi 3,0; beq 5f; lwz 9,0x0(31); lwz 3,0x0(9); b 6f; 5:; li 3,0; 6:; add 6,30,30; mr 4,25; add 6,3,6; mr 5,27; mr 3,28; mr 7,29; bl _s800A2BEC_7; mr 3,28; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s800A2BEC_0();
extern "C" void _s800A2BEC_1();
extern "C" void _s800A2BEC_2();
extern "C" void _s800A2BEC_3();
extern "C" void _s800A2BEC_4();
extern "C" void _s800A2BEC_5();
extern "C" void _s800A2BEC_6();
extern "C" void _s800A2BEC_7();
extern "C" void f_800A2BEC() {}
