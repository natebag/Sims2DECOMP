// 0x80141614 cSimulatorImpl::Simulate(void) (548 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stw 31,0x1c(1); stw 0,0x2c(1); mr 31,3; li 0,1; stw 0,0x17c(31); bl _s80141614_0; lis 11,-32706; lfs f13,-26800(13); lfs f0,-10640(11); lis 9,-32706; lfs f12,-10636(9); fmuls f31,f13,f0; fmr f0,f31; fcmpu 0,f31,f12; blt 0f; fmr f0,f12; 0:; lwz 9,0x0(31); fmr f31,f0; lha 3,0x70(9); lwz 0,0x74(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 1f; lwz 9,0x0(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; lfs f0,0xa0(31); lis 9,-32706; lis 11,-32706; lfs f11,-10632(9); fmadds f0,f31,f1,f0; lfs f13,-10628(11); fsubs f12,f0,f11; stfs f0,0xa0(31); fcmpu 0,f12,f13; ble 1f; fdivs f0,f12,f1; stfs f11,0xa0(31); fsubs f31,f31,f0; 1:; lfs f13,-26800(13); lis 11,-32706; lwz 9,0x0(31); stfs f13,0xa4(31); lfs f0,-10624(11); lha 3,0x70(9); lwz 0,0x74(9); fmuls f0,f31,f0; add 3,31,3; stfs f0,-26800(13); mtspr 8,0; blrl; cmpwi 3,0; bne 7f; lha 0,0x5e(31); cmpwi 0,0; ble 4f; lis 9,-32706; lfs f13,0xac(31); lfs f0,-10628(9); fcmpu 0,f13,f0; bne 2f; xoris 0,0,32768; stw 0,0x14(1); lis 11,17200; lis 10,-32706; stw 11,0x10(1); lfd f13,-10616(10); lfd f0,0x10(1); fsub f0,f0,f13; frsp f0,f0; stfs f0,0xb0(31); 2:; lfs f13,0xac(31); lfs f12,-26800(13); lfs f0,0xb0(31); fadds f13,f13,f12; fsubs f0,f0,f13; stfs f13,0xac(31); fctiwz f11,f0; stfd f11,0x10(1); lwz 9,0x14(1); extsh 0,9; cmpwi 0,0; bge 3f; li 0,0; 3:; sth 0,0x5e(31); b 6f; 4:; lis 9,-32706; lfs f0,-10628(9); stfs f0,0xb0(31); stfs f0,0xac(31); b 6f; 5:; lwz 9,0x0(31); lha 3,0x70(9); lwz 0,0x74(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 6f; lis 9,-32706; lfs f0,-10628(9); stfs f0,0xa0(31); 6:; lis 9,-32706; lfs f0,0xa0(31); lfs f13,-10608(9); fcmpu 0,f0,f13; cror 3,2,1; bns 7f; fsubs f0,f0,f13; mr 3,31; stfs f0,0xa0(31); bl _s80141614_1; lha 0,0x2a(31); xori 3,3,1; stw 3,0x9c(31); cmpwi 0,0; beq 5b; li 0,0; sth 0,0x2a(31); 7:; li 0,0; mr 3,31; stw 0,0x17c(31); bl _s80141614_2; lwz 0,0x2c(1); mtspr 8,0; lwz 31,0x1c(1); lfd f31,0x20(1); addi 1,1,40"

extern "C" void _s80141614_0();
extern "C" void _s80141614_1();
extern "C" void _s80141614_2();

struct cSimulatorImpl {
    void Simulate();
};

void cSimulatorImpl::Simulate() {
}
