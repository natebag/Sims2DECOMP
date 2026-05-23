// 0x80060CE0 SAnimator2::getUseSpeed(float, (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f27,0x10(1); stfd f28,0x18(1); stfd f29,0x20(1); stfd f30,0x28(1); stfd f31,0x30(1); stw 31,0xc(1); stw 0,0x3c(1); fmr f28,f1; lis 9,-32707; fneg f27,f28; lfs f13,0x47c8(9); fdivs f29,f27,f2; mr 31,3; fmuls f13,f29,f13; fmuls f13,f13,f2; fmuls f0,f28,f2; fmadds f30,f13,f2,f0; fmr f31,f3; fcmpu 0,f31,f30; bge 2f; lwz 11,0xc(31); lwz 10,0x14(31); lwz 0,0x0(11); lwz 9,0x4(11); subf 9,0,9; srawi 9,9,3; addi 9,9,-2; cmpw 10,9; blt 2f; lwz 11,0x4(31); li 4,9; lwz 10,0x0(11); lwz 9,0x4(10); lha 3,0x260(9); lwz 0,0x264(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; fsubs f0,f30,f31; fadds f1,f29,f29; fmuls f1,f1,f0; fmr f31,f28; fmadds f1,f31,f31,f1; bl _s80060CE0_0; lis 9,-32707; fadds f1,f27,f1; lfs f0,0x47cc(9); fadds f31,f31,f1; fmuls f31,f31,f0; b 3f; 0:; fdivs f1,f31,f30; bl _s80060CE0_1; lis 9,-32707; lfs f0,0x47d0(9); fcmpu 0,f1,f0; bge 1f; fmr f1,f0; 1:; lbz 0,0x5f8(31); fmr f31,f28; cmpwi 0,1; beq 3f; fmuls f31,f1,f31; b 3f; 2:; lfs f31,0x114(31); fneg f0,f29; fmadds f31,f0,f4,f31; 3:; fcmpu 0,f31,f28; ble 4f; fmr f31,f28; 4:; fmr f1,f31; lwz 0,0x3c(1); mtspr 8,0; lwz 31,0xc(1); lfd f27,0x10(1); lfd f28,0x18(1); lfd f29,0x20(1); lfd f30,0x28(1); lfd f31,0x30(1); addi 1,1,56"

extern "C" void _s80060CE0_0();
extern "C" void _s80060CE0_1();

struct SAnimator2 {
    void getUseSpeed();
};

void SAnimator2::getUseSpeed() {
}
