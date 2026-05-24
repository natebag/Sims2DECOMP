// 0x80354978 Effects::FastParticleEmitter::InitParticlePool(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,278; stw 0,-25868(13); bl _s80354978_0; lis 4,3; li 5,64; ori 4,4,8000; li 6,0; li 7,0; bl _s80354978_1; stw 3,-22456(13); li 3,24; bl _s80354978_2; lis 4,-32702; lwz 5,-22456(13); lwz 7,-25868(13); addi 4,4,10616; li 6,736; bl _s80354978_3; stw 3,-25872(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s80354978_0();
extern "C" void _s80354978_1();
extern "C" void _s80354978_2();
extern "C" void _s80354978_3();

struct Effects {
    void FastParticleEmitter__InitParticlePool();
};

void Effects::FastParticleEmitter__InitParticlePool() {
}
