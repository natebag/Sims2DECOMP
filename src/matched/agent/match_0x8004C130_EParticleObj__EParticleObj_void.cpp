// 0x8004C130 EParticleObj::EParticleObj(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; li 0,0; li 11,1; stw 0,0xc(9); stw 11,0x8(9); stw 0,0x4(9); stw 0,0x0(9)"
extern "C" void f_8004C130() {}
