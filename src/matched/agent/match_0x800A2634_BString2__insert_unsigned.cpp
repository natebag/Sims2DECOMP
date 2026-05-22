// 0x800A2634 BString2::insert(unsigned (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,5; mr 28,3; mr 30,6; mr 27,4; mr 29,7; mr 3,31; bl _s800A2634_0; cmplw 30,3; ble 0f; bl _s800A2634_1; 0:; mr 3,31; bl _s800A2634_2; subf 3,30,3; cmplw 29,3; ble 1f; mr 3,31; bl _s800A2634_3; subf 29,30,3; 1:; mr 3,31; bl _s800A2634_4; cmpwi 3,0; beq 2f; lwz 9,0x0(31); lwz 3,0x0(9); b 3f; 2:; li 3,0; 3:; add 5,30,30; mr 4,27; add 5,3,5; mr 6,29; mr 3,28; bl _s800A2634_5; mr 3,28; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800A2634_0();
extern "C" void _s800A2634_1();
extern "C" void _s800A2634_2();
extern "C" void _s800A2634_3();
extern "C" void _s800A2634_4();
extern "C" void _s800A2634_5();
extern "C" void f_800A2634() {}
