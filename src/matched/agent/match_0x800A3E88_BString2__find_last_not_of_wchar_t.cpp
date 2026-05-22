// 0x800A3E88 BString2::find_last_not_of(wchar_t, (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; mr 31,5; sth 4,0x8(1); bl _s800A3E88_0; cmplw 31,3; bge 0f; addi 31,31,1; b 1f; 0:; mr 3,30; bl _s800A3E88_1; mr 31,3; 1:; mr 3,30; bl _s800A3E88_2; cmpwi 3,0; bne 3f; li 3,-1; b 10f; 2:; addi 31,31,-1; 3:; mr 3,30; bl _s800A3E88_3; cmpwi 3,0; beq 4f; lwz 9,0x0(30); lwz 0,0x0(9); b 5f; 4:; li 0,0; 5:; add 9,31,31; lhz 11,0x8(1); add 9,9,0; lhz 0,-2(9); cmpw 0,11; bne 6f; cmplwi 31,1; bgt 2b; 6:; cmpwi 31,1; bne 9f; mr 3,30; bl _s800A3E88_4; cmpwi 3,0; beq 7f; lwz 9,0x0(30); lwz 3,0x0(9); b 8f; 7:; li 3,0; 8:; lhz 9,0x0(3); lhz 0,0x8(1); cmpw 9,0; li 3,-1; beq 10f; 9:; addi 3,31,-1; 10:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800A3E88_0();
extern "C" void _s800A3E88_1();
extern "C" void _s800A3E88_2();
extern "C" void _s800A3E88_3();
extern "C" void _s800A3E88_4();
extern "C" void f_800A3E88() {}
