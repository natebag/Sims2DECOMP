// 0x803631AC EDL::operator (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); lis 30,-32690; mr 31,3; addi 30,30,-6992; li 4,-1; addi 0,30,24; lwz 9,0x18(30); stw 0,0x8(1); lha 3,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; mr 3,30; bl _s803631AC_0; lwz 11,0x8(1); mr 30,3; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 30,0; bne 0f; bl _s803631AC_1; mr 4,31; li 5,0; bl _s803631AC_2; b 1f; 0:; mr 3,30; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s803631AC_0();
extern "C" void _s803631AC_1();
extern "C" void _s803631AC_2();
extern "C" void f_803631AC() {}
