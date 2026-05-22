// 0x801C786C MMUTarget::UpdateTopLevelChoice(char (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 3,5; bl _s801C786C_0; lwz 0,0xa4(30); stw 3,0xa4(30); stw 0,0xa8(30); mr 3,30; bl _s801C786C_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801C786C_0();
extern "C" void _s801C786C_1();
extern "C" void f_801C786C() {}
