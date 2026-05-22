// 0x802AEC6C AptString::cpy(char (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); addi 30,3,12; addi 3,1,8; bl _s802AEC6C_0; addi 4,1,8; mr 3,30; bl _s802AEC6C_1; addi 3,1,8; li 4,2; bl _s802AEC6C_2; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s802AEC6C_0();
extern "C" void _s802AEC6C_1();
extern "C" void _s802AEC6C_2();
extern "C" void f_802AEC6C() {}
