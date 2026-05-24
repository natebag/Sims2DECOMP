// 0x8035312C Effects::FastParticleEmitter::FastParticleEmitter(Effects::Effect::ClientParams (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s8035312C_0; lis 9,-32697; li 0,0; addi 9,9,-10672; li 11,0; stw 9,0x144(30); mr 3,30; sth 11,0x164(30); stw 0,0x1a4(30); stw 0,0x18c(30); stw 0,0x190(30); stw 0,0x194(30); sth 0,0x198(30); sth 0,0x19a(30); stw 0,0x19c(30); stw 0,0x1a0(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8035312C_0();

struct Effects {
    void FastParticleEmitter__FastParticleEmitter_Effects__E();
};

void Effects::FastParticleEmitter__FastParticleEmitter_Effects__E() {
}
