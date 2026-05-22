// 0x800A4038 BString2::compare(BString2 (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; mr 29,5; mr 30,6; mr 31,4; bl _s800A4038_0; subf 3,29,3; cmplw 30,3; ble 0f; mr 3,28; bl _s800A4038_1; subf 27,29,3; b 1f; 0:; mr 27,30; 1:; mr 3,31; bl _s800A4038_2; cmpwi 3,0; beq 2f; lwz 9,0x0(31); lwz 30,0x0(9); b 3f; 2:; li 30,0; 3:; mr 3,31; bl _s800A4038_3; mr 7,3; mr 4,29; mr 3,28; mr 5,30; mr 6,27; bl _s800A4038_4; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800A4038_0();
extern "C" void _s800A4038_1();
extern "C" void _s800A4038_2();
extern "C" void _s800A4038_3();
extern "C" void _s800A4038_4();
extern "C" void f_800A4038() {}
