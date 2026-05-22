// 0x803548D4 Effects::FastParticleEmitter::RotateEmitter(float) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 10,3; lwz 9,0x18c(10); addi 3,10,80; lwz 0,0x4c(9); cmpwi 0,0; bge 0f; lfs f3,0x3c(9); lfs f0,0x174(10); lfs f13,0x178(10); fmadds f3,f3,f1,f0; stfs f3,0x174(10); lfs f2,0x40(9); fmadds f2,f2,f1,f13; stfs f2,0x178(10); lfs f1,0x38(9); fneg f1,f1; bl _s803548D4_0; b 1f; 0:; lis 9,-32702; lis 11,-32702; lfs f0,0x2970(9); stfs f0,0x20(3); stfs f0,0xc(3); stfs f0,0x8(3); stfs f0,0x4(3); stfs f0,0x1c(3); stfs f0,0x18(3); stfs f0,0x10(3); stfs f0,0x2c(3); stfs f0,0x24(3); lfs f13,0x2974(11); stfs f13,0x14(3); stfs f13,0x28(3); stfs f13,0x50(10); 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s803548D4_0();
extern "C" void f_803548D4() {}
