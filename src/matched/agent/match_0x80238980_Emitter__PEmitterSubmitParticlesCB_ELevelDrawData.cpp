// 0x80238980 Emitter::PEmitterSubmitParticlesCB(ELevelDrawData (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,0x24(4); mr 31,3; lwz 3,0x7c(9); cmpwi 3,0; beq 0f; lfs f1,-26796(13); bl _s80238980_0; li 0,0; stw 0,0xb8(31); stw 0,0xac(31); stw 0,0xb4(31); stw 0,0xa8(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80238980_0();
extern "C" void f_80238980() {}
