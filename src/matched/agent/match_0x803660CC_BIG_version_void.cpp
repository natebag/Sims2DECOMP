// 0x803660CC BIG_version(void (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); li 0,0; addi 4,1,8; stw 0,0x8(1); li 5,0; bl _s803660CC_0; lwz 3,0x8(1); lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s803660CC_0();
extern "C" void f_803660CC() {}
