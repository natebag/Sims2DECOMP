// 0x800A4198 BString2::compare(wchar_t, (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 30,3; mr 29,5; sth 4,0x8(1); mr 28,6; bl _s800A4198_0; cmplw 29,3; ble 0f; bl _s800A4198_1; 0:; cmpwi 28,-1; bne 1f; bl _s800A4198_2; 1:; cmpwi 28,0; beq 11f; li 31,0; add 27,29,29; b 5f; 2:; mr 3,30; bl _s800A4198_3; cmpwi 3,0; beq 3f; lwz 9,0x0(30); lwz 9,0x0(9); b 4f; 3:; li 9,0; 4:; add 11,27,9; lhz 0,0x8(1); add 9,31,31; lhzx 10,9,11; cmpw 10,0; bne 6f; addi 31,31,1; 5:; cmplw 31,28; bge 6f; mr 3,30; bl _s800A4198_4; subf 3,29,3; cmplw 31,3; blt 2b; 6:; cmpw 31,28; beq 7f; mr 3,30; bl _s800A4198_5; subf 3,29,3; cmpw 31,3; bne 8f; 7:; mr 3,30; bl _s800A4198_6; subf 3,29,3; subf 3,31,3; b 12f; 8:; mr 3,30; bl _s800A4198_7; cmpwi 3,0; beq 9f; lwz 9,0x0(30); lwz 3,0x0(9); b 10f; 9:; li 3,0; 10:; add 9,29,29; add 11,31,31; add 9,9,3; lhz 0,0x8(1); lhzx 3,11,9; subf 3,0,3; b 12f; 11:; mr 3,30; bl _s800A4198_8; subf 3,29,3; 12:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s800A4198_0();
extern "C" void _s800A4198_1();
extern "C" void _s800A4198_2();
extern "C" void _s800A4198_3();
extern "C" void _s800A4198_4();
extern "C" void _s800A4198_5();
extern "C" void _s800A4198_6();
extern "C" void _s800A4198_7();
extern "C" void _s800A4198_8();
extern "C" void f_800A4198() {}
