// 0x803B518C basic_string<wchar_t, (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); li 0,0; mr 29,3; stw 0,0x0(29); addi 9,29,8; stw 0,0x4(29); mr 28,4; stw 0,0x4(9); li 30,0; lhz 0,0x0(28); cmpwi 0,0; beq 1f; li 11,0; mr 9,28; 0:; lhzu 0,0x2(9); addi 30,30,1; cmpw 0,11; bne 0b; 1:; add 30,30,30; mr 3,29; add 30,30,28; subf 31,28,30; srawi 4,31,1; addi 4,4,1; bl _s803B518C_0; lwz 3,0x0(29); cmpw 30,28; beq 2f; mr 4,28; mr 5,31; bl _s803B518C_1; add 3,3,31; 2:; stw 3,0x4(29); li 0,0; sth 0,0x0(3); mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s803B518C_0();
extern "C" void _s803B518C_1();
extern "C" void f_803B518C() {}
