// 0x802D87B0 PPMMutexUnlock(void (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 30,0xc(3); addi 30,30,-1; bl _s802D87B0_0; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D87B0_0();
extern "C" void f_802D87B0() {}
