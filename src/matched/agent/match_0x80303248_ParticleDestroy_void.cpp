// 0x80303248 ParticleDestroy(void (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 3,-22684(13); lwz 4,0x0(30); bl _s80303248_0; li 0,0; stw 0,0x0(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80303248_0();
extern "C" void f_80303248() {}
