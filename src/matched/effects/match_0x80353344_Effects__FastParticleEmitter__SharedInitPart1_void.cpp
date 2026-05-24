// 0x80353344 Effects::FastParticleEmitter::SharedInitPart1(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; addi 3,30,80; bl _s80353344_0; addi 3,30,144; bl _s80353344_1; lis 9,-32702; li 0,0; lfs f0,0x28e8(9); mr 3,30; stw 0,0x148(30); stfs f0,0x14c(30); bl _s80353344_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80353344_0();
extern "C" void _s80353344_1();
extern "C" void _s80353344_2();

struct Effects {
    void FastParticleEmitter__SharedInitPart1();
};

void Effects::FastParticleEmitter__SharedInitPart1() {
}
