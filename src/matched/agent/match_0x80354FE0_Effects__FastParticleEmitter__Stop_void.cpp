// 0x80354FE0 Effects::FastParticleEmitter::Stop(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x140(3); lwz 9,0x148(3); rlwinm 0,0,0,31,29; lwz 11,0x18c(3); ori 0,0,512; ori 9,9,2052; stw 9,0x148(3); stw 0,0x140(3); lha 0,0x44(11); cmpwi 0,0; blt 0f; stw 0,0x15c(3); 0:; lwz 9,0x18c(3); lis 11,-32702; lfs f0,0x29ac(11); lfs f13,0x0(9); fcmpu 0,f13,f0; cror 3,2,0; bso 1f; lis 9,-32702; lfs f0,0x29b0(9); fcmpu 0,f13,f0; blelr; 1:; lwz 0,0x140(3); ori 0,0,1; stw 0,0x140(3)"
extern "C" void f_80354FE0() {}
