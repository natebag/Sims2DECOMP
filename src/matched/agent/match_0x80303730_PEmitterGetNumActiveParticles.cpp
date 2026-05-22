// 0x80303730 PEmitterGetNumActiveParticles (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x54(3); lwz 3,0x84(9)"
extern "C" int f_80303730() {}
