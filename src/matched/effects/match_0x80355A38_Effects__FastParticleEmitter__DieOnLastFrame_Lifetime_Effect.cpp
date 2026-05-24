// 0x80355A38 Effects::FastParticleEmitter::DieOnLastFrame_Lifetime(Effects::FastParticlePacket (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lwz 9,0x18c(3); mr 7,11; lis 6,17200; lfs f10,0x0(9); lis 10,-32702; lfs f9,0xb4(9); lis 8,-32702; lfd f8,0x29d8(10); rlwinm 5,5,5,0,26; fmuls f0,f10,f9; lfs f12,0x29e0(8); lfs f7,0xb0(9); fctiwz f13,f0; lwz 0,0x48(9); stfd f13,0x8(1); addi 5,5,192; andis. 9,0,8192; lwz 11,0xc(1); xoris 11,11,32768; stw 11,0xc(1); stw 6,0x8(1); lfd f0,0x8(1); fsub f0,f0,f8; frsp f0,f0; fadds f0,f0,f12; fmuls f10,f7,f0; beq 0f; lwzx 0,4,5; lis 9,-32702; lis 10,-32702; rlwinm 0,0,0,20,31; lfd f0,0x29e8(9); stw 0,0xc(1); mr 9,11; lfs f11,0x29f0(10); stw 6,0x8(1); mr 10,11; lfd f13,0x8(1); fsub f13,f13,f0; frsp f13,f13; fmuls f13,f13,f11; fmuls f0,f13,f9; fctiwz f12,f0; stfd f12,0x8(1); lwz 9,0xc(1); xoris 9,9,32768; stw 9,0xc(1); stw 6,0x8(1); lfd f0,0x8(1); fsub f0,f0,f8; frsp f0,f0; fmuls f0,f7,f0; fsubs f13,f13,f0; fsubs f10,f10,f13; 0:; lis 9,-32702; fmr f1,f10; lfs f0,0x29f4(9); fcmpu 0,f10,f0; bgt 1f; fmr f1,f0; 1:; addi 1,1,16"

struct Effects {
    void FastParticleEmitter__DieOnLastFrame_Lifetime_Effect();
};

void Effects::FastParticleEmitter__DieOnLastFrame_Lifetime_Effect() {
}
