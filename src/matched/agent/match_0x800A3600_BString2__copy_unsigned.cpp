// 0x800A3600 BString2::copy(unsigned (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 30,6; mr 28,4; mr 29,5; bl _s800A3600_0; cmplw 30,3; ble 0f; bl _s800A3600_1; 0:; mr 3,31; bl _s800A3600_2; subf 3,30,3; cmplw 29,3; ble 1f; mr 3,31; bl _s800A3600_3; subf 29,30,3; 1:; mr 3,31; bl _s800A3600_4; cmpwi 3,0; beq 4f; mr 3,31; bl _s800A3600_5; cmpwi 3,0; beq 2f; lwz 9,0x0(31); lwz 9,0x0(9); b 3f; 2:; li 9,0; 3:; add 4,30,30; mr 3,28; add 4,4,9; rlwinm 5,29,1,0,30; bl _s800A3600_6; 4:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800A3600_0();
extern "C" void _s800A3600_1();
extern "C" void _s800A3600_2();
extern "C" void _s800A3600_3();
extern "C" void _s800A3600_4();
extern "C" void _s800A3600_5();
extern "C" void _s800A3600_6();
extern "C" void f_800A3600() {}
