// 0x80353C84 Effects::FastParticleEmitter::Init(REffectsEmitter (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,3; stw 30,0x1a0(31); mr 3,30; bl _s80353C84_0; mr 3,31; bl _s80353C84_1; lwz 9,0x14(30); stw 9,0x18c(31); cmpwi 9,0; beq 0f; lbz 0,0xa8(9); li 3,0; stb 0,0x166(31); lwz 9,0x1c(30); stw 9,0x194(31); lwz 0,0x18(30); cmpwi 0,0; stw 0,0x190(31); beq 1f; mr 3,31; bl _s80353C84_2; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80353C84_0();
extern "C" void _s80353C84_1();
extern "C" void _s80353C84_2();

struct Effects {
    void FastParticleEmitter__Init_REffectsEmitter();
};

void Effects::FastParticleEmitter__Init_REffectsEmitter() {
}
