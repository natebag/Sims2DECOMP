// 0x80356680 Effects::FastParticleEmitter::PreRollParticles(void) (496 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f31,0x38(1); stmw 29,0x2c(1); stw 0,0x44(1); mr 31,3; li 0,0; sth 0,0x198(31); lis 9,-32702; stw 0,0x8(1); lfs f31,0x2a38(9); li 29,1; sth 0,0x19a(31); bl _s80356680_0; lfs f0,0x17c(31); fcmpu 0,f0,f31; cror 3,2,0; bns 0f; li 30,1; b 3f; 0:; lwz 9,0x18c(31); lfs f0,0x0(9); fcmpu 0,f0,f31; cror 3,2,0; bns 2f; lha 4,0x44(9); cmpwi 4,0; bgt 1f; li 30,0; b 3f; 1:; lha 0,0x64(9); lis 5,17200; lwz 11,-18432(13); xoris 0,0,32768; lha 8,0x66(9); stw 0,0x24(1); addi 11,11,-1; lwz 6,-25888(13); mr 7,10; stw 5,0x20(1); xoris 8,8,32768; and 6,6,11; lis 9,-32690; lfd f12,0x20(1); addi 9,9,-13824; rlwinm 0,6,2,0,29; stw 8,0x24(1); lwzx 11,9,0; lis 10,-32702; stw 5,0x20(1); lis 9,-32702; rlwinm 11,11,0,9,31; lfd f11,0x2a40(10); oris 11,11,16256; lfs f0,0x180(31); lfd f13,0x20(1); fsub f12,f12,f11; stw 11,0x10(1); frsp f12,f12; fsub f13,f13,f11; lfs f10,0x2a3c(9); lfs f11,0x10(1); frsp f13,f13; addi 6,6,1; fsubs f10,f11,f10; stw 6,-25888(13); fmadds f10,f10,f13,f12; fmuls f0,f0,f10; fctiwz f11,f0; stfd f11,0x20(1); lwz 11,0x24(1); add 9,4,11; addi 9,9,-1; divw 30,9,11; b 3f; 2:; fmr f31,f0; li 30,1000; li 29,0; 3:; cmpwi 30,0; ble 7f; lwz 11,0x18c(31); lis 9,-32702; lfs f13,0x2a38(9); lfs f0,0x0(11); b 6f; 4:; lhz 4,0x198(31); mr 3,31; fmr f1,f31; addi 5,1,8; bl _s80356680_1; lis 9,-32702; lfs f13,0x2a38(9); stfs f13,0x154(31); fcmpu 0,f1,f13; cror 3,2,0; bso 7f; cmpwi 29,0; bne 5f; fsubs f31,f31,f1; 5:; addic. 30,30,-1; ble 7f; lwz 9,0x18c(31); lfs f0,0x0(9); 6:; fcmpu 0,f0,f13; cror 3,2,0; bso 4b; lis 9,-32702; lfs f0,0x2a48(9); fcmpu 0,f31,f0; bgt 4b; 7:; lis 9,-32702; cmpwi 30,0; lfs f0,0x2a38(9); li 3,0; stfs f0,0x154(31); stfs f0,0x150(31); beq 8f; li 3,1; 8:; lwz 0,0x44(1); mtspr 8,0; lmw 29,0x2c(1); lfd f31,0x38(1); addi 1,1,64"

extern "C" void _s80356680_0();
extern "C" void _s80356680_1();

struct Effects {
    void FastParticleEmitter__PreRollParticles();
};

void Effects::FastParticleEmitter__PreRollParticles() {
}
