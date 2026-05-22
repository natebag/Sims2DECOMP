// 0x800A3790 BString2::find(wchar_t, (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; sth 4,0x8(1); mr 31,5; b 4f; 0:; mr 3,30; bl _s800A3790_0; cmpwi 3,0; beq 1f; lwz 9,0x0(30); lwz 10,0x0(9); b 2f; 1:; li 10,0; 2:; add 9,31,31; lhz 11,0x8(1); lhzx 0,9,10; li 9,1; cmpw 0,11; bne 3f; li 9,0; 3:; cmpwi 9,0; beq 5f; addi 31,31,1; 4:; mr 3,30; bl _s800A3790_1; cmplw 31,3; blt 0b; 5:; mr 3,30; bl _s800A3790_2; cmplw 31,3; li 3,-1; bge 6f; mr 3,31; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800A3790_0();
extern "C" void _s800A3790_1();
extern "C" void _s800A3790_2();
extern "C" void f_800A3790() {}
