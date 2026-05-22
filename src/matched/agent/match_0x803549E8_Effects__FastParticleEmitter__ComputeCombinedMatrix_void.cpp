// 0x803549E8 Effects::FastParticleEmitter::ComputeCombinedMatrix(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 30,0x48(1); stw 0,0x54(1); mr 31,3; addi 30,1,8; mr 3,30; addi 4,31,80; bl _s803549E8_0; lis 9,-32702; lwz 0,0x140(31); lfs f0,0x2990(9); andi. 9,0,256; stfs f0,0x44(1); bne 0f; lis 9,-32702; lfs f0,0x2994(9); stfs f0,0x40(1); stfs f0,0x38(1); stfs f0,0x3c(1); 0:; mr 4,30; addi 5,31,256; addi 3,31,144; bl _s803549E8_1; lwz 0,0x54(1); mtspr 8,0; lmw 30,0x48(1); addi 1,1,80"
extern "C" void _s803549E8_0();
extern "C" void _s803549E8_1();
extern "C" void f_803549E8() {}
