// 0x8003DED4 EffectsPreRenderVisitor::Visit(Effects::FastParticleEmitter (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stw 0,0x44(1); lwz 0,0x140(4); li 9,1; andi. 11,0,2048; bne 0f; li 9,0; 0:; cmpwi 9,0; beq 5f; lis 11,-32707; li 0,0; lfs f0,0x202c(11); addi 9,1,8; stw 0,0x8(1); stw 0,0x4(9); stw 0,0x8(9); stw 0,0xc(9); stw 0,0x10(9); stw 0,0x14(9); stw 0,0x18(9); stw 0,0x1c(9); stw 0,0x20(9); stw 0,0x24(9); stw 0,0x34(9); stfs f0,0x30(9); stw 0,0x28(9); stfs f0,0x2c(9); stw 0,0x8(1); lwz 11,0x4c(4); stw 0,0x34(9); stw 0,0x4(9); cmpwi 11,0; stw 0,0x8(9); stw 0,0xc(9); stw 0,0x10(9); stw 0,0x14(9); stw 0,0x18(9); stw 0,0x1c(9); stw 0,0x20(9); stw 0,0x24(9); stw 4,0x20(1); bne 1f; lwz 0,0x44(4); cmpwi 0,0; bne 2f; 1:; addi 0,4,192; 2:; stw 0,0x10(1); lis 9,-32697; lha 0,0x40(4); addi 9,9,23888; lis 11,-32764; stw 9,0x2c(1); addi 11,11,-8044; stw 0,0xc(1); stw 11,0x1c(1); lwz 9,-26512(13); lwz 3,0x30(9); cmpwi 3,0; bne 3f; li 3,0; b 6f; 3:; lwz 0,0x48(4); cmpwi 0,0; beq 4f; li 0,16384; addi 4,1,8; stw 0,0x8(1); bl _s8003DED4_0; b 5f; 4:; addi 4,1,8; bl _s8003DED4_1; 5:; li 3,1; 6:; lwz 0,0x44(1); mtspr 8,0; addi 1,1,64"

extern "C" void _s8003DED4_0();
extern "C" void _s8003DED4_1();

struct Effects {
    void Visit_Effects__FastParticleEmitter();
};

void Effects::Visit_Effects__FastParticleEmitter() {
}
