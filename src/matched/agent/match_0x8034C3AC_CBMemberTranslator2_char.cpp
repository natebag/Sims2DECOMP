// 0x8034C3AC CBMemberTranslator2<char (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="add 3,11,3; blrl; mr 0,3; li 4,1; stw 0,0x28(29); bl _s8034C3AC_0; mr 3,29; mr 4,30; bl _s8034C3AC_1; lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x2c(1); addi 1,1,56; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s8034C3AC_2; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; lwz 10,0x0(4); addi 11,3,12; lwz 0,0x8(4); lwz 9,0x4(4); stw 10,0xc(3); stw 0,0x8(11); stw 9,0x4(11)"
extern "C" void _s8034C3AC_0();
extern "C" void _s8034C3AC_1();
extern "C" void _s8034C3AC_2();
extern "C" void f_8034C3AC() {}
