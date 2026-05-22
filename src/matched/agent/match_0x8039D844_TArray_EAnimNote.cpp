// 0x8039D844 TArray<EAnimNote, (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s8039D844_0; andi. 0,30,1; beq 0f; mr 3,31; bl _s8039D844_1; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8039D844_0();
extern "C" void _s8039D844_1();
extern "C" void f_8039D844() {}
