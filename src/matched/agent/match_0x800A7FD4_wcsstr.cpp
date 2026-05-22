// 0x800A7FD4 wcsstr (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,4; mr 0,3; mr 3,30; mr 31,0; bl _s800A7FD4_0; lhz 28,0x0(30); mr. 29,3; bne 1f; li 3,0; b 3f; 0:; addi 31,31,2; 1:; mr 3,31; mr 4,28; bl _s800A7FD4_1; mr. 31,3; beq 2f; mr 3,31; mr 4,30; mr 5,29; bl _s800A7FD4_2; cmpwi 3,0; bne 0b; 2:; mr 3,31; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800A7FD4_0();
extern "C" void _s800A7FD4_1();
extern "C" void _s800A7FD4_2();
extern "C" void f_800A7FD4() {}
