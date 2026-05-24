// 0x8022B4E8 EISpotLight::Setup(void) (532 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-128(1); mfspr 0,8; stfd f27,0x58(1); stfd f28,0x60(1); stfd f29,0x68(1); stfd f30,0x70(1); stfd f31,0x78(1); stmw 23,0x34(1); stw 0,0x84(1); lis 9,-32704; addi 11,1,20; lfs f0,-4972(9); mr 27,3; addi 10,1,8; mr 23,11; stfs f0,0x20(1); mr 24,10; stfs f0,0x28(1); addi 28,1,32; stfs f0,0x24(1); lwz 0,0x20(1); lwz 8,0x24(1); lwz 7,0x28(1); stw 0,0x14(1); stw 8,0x4(11); stw 7,0x8(11); lwz 9,0x14(1); lwz 0,0xd4(27); stw 9,0x8(1); cmpwi 0,0; stw 8,0x4(10); stw 7,0x8(10); beq 0f; lfs f1,0xc8(27); mr 3,24; addi 4,27,172; bl _s8022B4E8_0; b 1f; 0:; lis 9,-32704; lis 11,-32704; lfs f0,-4968(9); lfs f13,-4964(11); stfs f0,0x8(28); stfs f0,0x4(28); stfs f0,0x20(1); lwz 9,0x4(28); lwz 11,0x8(28); lwz 0,0x20(1); stw 9,0x4(24); stw 0,0x8(1); stw 11,0x8(24); stfs f13,0x8(28); stfs f13,0x4(28); stfs f13,0x20(1); lwz 9,0x4(28); lwz 11,0x8(28); lwz 0,0x20(1); stw 9,0x4(23); stw 0,0x14(1); stw 11,0x8(23); 1:; lis 9,-32704; lis 11,-32704; lfs f13,-4960(9); lis 10,-32704; lis 9,-32704; lfs f0,-4956(11); lfs f31,-4972(9); lis 11,-32704; lis 9,-32704; lfs f27,-4952(11); lfs f30,-4948(10); fmuls f29,f13,f0; lfs f28,-4944(9); addi 26,27,184; mr 30,28; addi 31,27,172; li 29,0; li 25,3; 2:; stfs f31,0x8(30); mr 3,30; stfs f31,0x4(30); mr 4,26; stfs f31,0x20(1); stfsx f27,29,30; bl _s8022B4E8_1; bl _s8022B4E8_2; lfs f0,0xd0(27); fmadds f0,f0,f30,f29; fcmpu 0,f1,f0; cror 3,2,1; bns 3f; lfs f0,0x0(31); stfsx f0,29,23; b 4f; 3:; mr 3,28; mr 4,26; stfsx f28,29,28; bl _s8022B4E8_3; bl _s8022B4E8_4; lfs f0,0xd0(27); fmadds f0,f0,f30,f29; fcmpu 0,f1,f0; cror 3,2,1; bns 4f; lfs f0,0x0(31); stfsx f0,29,24; 4:; addi 31,31,4; addi 29,29,4; addic. 25,25,-1; bne 2b; mr 3,27; addi 4,1,8; bl _s8022B4E8_5; lis 9,-32704; lfs f1,0xcc(27); lfs f31,-4948(9); fmuls f1,f1,f31; bl _s8022B4E8_6; lfs f0,0xd0(27); stfs f1,0xd8(27); fmuls f1,f0,f31; bl _s8022B4E8_7; stfs f1,0xdc(27); lwz 0,0x84(1); mtspr 8,0; lmw 23,0x34(1); lfd f27,0x58(1); lfd f28,0x60(1); lfd f29,0x68(1); lfd f30,0x70(1); lfd f31,0x78(1); addi 1,1,128"

extern "C" void _s8022B4E8_0();
extern "C" void _s8022B4E8_1();
extern "C" void _s8022B4E8_2();
extern "C" void _s8022B4E8_3();
extern "C" void _s8022B4E8_4();
extern "C" void _s8022B4E8_5();
extern "C" void _s8022B4E8_6();
extern "C" void _s8022B4E8_7();

struct EISpotLight {
    void Setup();
};

void EISpotLight::Setup() {
}
