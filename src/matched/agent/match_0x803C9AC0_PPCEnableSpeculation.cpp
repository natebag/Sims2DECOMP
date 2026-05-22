// 0x803C9AC0 PPCEnableSpeculation (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s803C9AC0_0; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803C9AC0_0();
extern "C" void f_803C9AC0() {}
