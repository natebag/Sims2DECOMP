// 0x8039EAB0 void (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lwz 0,0x0(6); addi 7,1,8; li 6,0; stw 0,0x8(1); bl _s8039EAB0_0; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8039EAB0_0();
extern "C" void f_8039EAB0() {}
