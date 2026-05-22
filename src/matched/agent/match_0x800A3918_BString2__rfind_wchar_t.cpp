// 0x800A3918 BString2::rfind(wchar_t, (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; mr 31,5; sth 4,0x8(1); bl _s800A3918_0; cmplw 31,3; bge 0f; addi 31,31,1; b 1f; 0:; mr 3,30; bl _s800A3918_1; mr 31,3; 1:; mr 3,30; bl _s800A3918_2; cmpwi 3,0; bne 3f; li 3,-1; b 12f; 2:; cmplwi 31,1; ble 7f; addi 31,31,-1; 3:; mr 3,30; bl _s800A3918_3; cmpwi 3,0; beq 4f; lwz 9,0x0(30); lwz 0,0x0(9); b 5f; 4:; li 0,0; 5:; add 9,31,31; lhz 11,0x8(1); add 9,9,0; li 10,1; lhz 0,-2(9); cmpw 0,11; bne 6f; li 10,0; 6:; cmpwi 10,0; bne 2b; 7:; cmpwi 31,1; bne 11f; mr 3,30; bl _s800A3918_4; cmpwi 3,0; beq 8f; lwz 9,0x0(30); lwz 3,0x0(9); b 9f; 8:; li 3,0; 9:; lhz 9,0x0(3); li 11,1; lhz 0,0x8(1); cmpw 9,0; bne 10f; li 11,0; 10:; cmpwi 11,0; li 3,-1; bne 12f; 11:; addi 3,31,-1; 12:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800A3918_0();
extern "C" void _s800A3918_1();
extern "C" void _s800A3918_2();
extern "C" void _s800A3918_3();
extern "C" void _s800A3918_4();
extern "C" void f_800A3918() {}
