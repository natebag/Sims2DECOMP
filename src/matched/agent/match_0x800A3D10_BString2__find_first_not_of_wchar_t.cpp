// 0x800A3D10 BString2::find_first_not_of(wchar_t, (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; sth 4,0x8(1); mr 31,5; b 1f; 0:; addi 31,31,1; 1:; mr 3,30; bl _s800A3D10_0; cmplw 31,3; bge 4f; mr 3,30; bl _s800A3D10_1; cmpwi 3,0; beq 2f; lwz 9,0x0(30); lwz 10,0x0(9); b 3f; 2:; li 10,0; 3:; add 9,31,31; lhz 11,0x8(1); lhzx 0,9,10; cmpw 0,11; beq 0b; 4:; mr 3,30; bl _s800A3D10_2; cmplw 31,3; li 3,-1; bge 5f; mr 3,31; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800A3D10_0();
extern "C" void _s800A3D10_1();
extern "C" void _s800A3D10_2();
extern "C" void f_800A3D10() {}
