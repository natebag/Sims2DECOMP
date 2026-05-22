// 0x803B523C basic_string<wchar_t, (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; li 0,0; stw 0,0x0(31); addi 9,31,8; stw 0,0x4(31); stw 0,0x4(9); lwz 29,0x0(4); lwz 30,0x4(4); subf 28,29,30; srawi 4,28,1; addi 4,4,1; bl _s803B523C_0; lwz 3,0x0(31); cmpw 30,29; beq 0f; mr 4,29; mr 5,28; bl _s803B523C_1; add 3,3,28; 0:; stw 3,0x4(31); li 0,0; sth 0,0x0(3); mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s803B523C_0();
extern "C" void _s803B523C_1();
extern "C" void f_803B523C() {}
