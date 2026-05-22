// 0x8034C49C CBMemberTranslator0<EYETarget, (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8034C6E0" lines="mtspr 8,0; add 3,31,3; blrl; lwz 9,0x24(31); addi 5,1,8; addi 6,1,12; li 4,0; lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,0x28(27); mr 29,3; addi 5,1,16; li 4,1; lwz 9,0x28(11); addi 6,1,20; lwz 30,0x74(9); mr 3,9; bl _s8034C49C_0; mr 5,3; mr 4,30; mr 3,29; crxor 6,6,6; bl _s8034C49C_1; lwz 9,0x24(31); lha 3,0x70(9); lwz 0,0x74(9)"
extern "C" void _s8034C49C_0();
extern "C" void _s8034C49C_1();
extern "C" void f_8034C6E0();
extern "C" void f_8034C49C() {}
