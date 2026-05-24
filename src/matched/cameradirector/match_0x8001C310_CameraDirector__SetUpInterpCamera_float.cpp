// 0x8001C310 CameraDirector::SetUpInterpCamera(float, (560 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-248(1); mfspr 0,8; stfd f29,0xe0(1); stfd f30,0xe8(1); stfd f31,0xf0(1); stmw 27,0xcc(1); stw 0,0xfc(1); mr 31,3; addi 30,1,24; addi 29,1,40; mr 28,4; lwz 3,0x170(31); addi 4,1,8; fmr f31,f1; mr 5,30; mr 6,29; addi 27,31,64; bl _s8001C310_0; mr 5,30; mr 6,29; addi 4,1,8; mr 3,27; bl _s8001C310_1; mr 3,27; bl _s8001C310_2; lwz 3,0x170(31); bl _s8001C310_3; lis 9,-32707; lfs f29,0x1a0(31); lfs f0,-6820(9); cmpwi 28,0; fmuls f1,f1,f0; stfs f1,0x19c(31); bne 3f; addi 3,1,56; addi 4,31,128; bl _s8001C310_4; addi 3,1,120; mr 4,27; bl _s8001C310_5; addi 3,1,136; addi 4,1,56; bl _s8001C310_6; lfs f0,0x8c(1); lfs f10,0x88(1); lfs f11,0x7c(1); lfs f13,0x78(1); fsubs f11,f11,f0; lfs f12,0x80(1); fsubs f13,f13,f10; lfs f9,0x90(1); lfs f10,0x94(1); fmuls f1,f11,f11; lfs f0,0x84(1); fsubs f12,f12,f9; fmadds f1,f13,f13,f1; stfs f13,0x98(1); fsubs f0,f0,f10; stfs f11,0x9c(1); fmadds f1,f12,f12,f1; stfs f12,0xa0(1); stfs f0,0xa4(1); fmadds f1,f0,f0,f1; bl _s8001C310_7; lwz 0,0x70(31); addi 9,31,112; lwz 11,0x4(9); addi 10,1,152; lwz 8,0x8(9); addi 7,1,104; stw 0,0x98(1); addi 6,1,168; stw 8,0x8(10); fmr f30,f1; stw 11,0x4(10); addi 3,1,184; lwz 0,0x68(1); lwz 9,0x8(7); lwz 11,0x4(7); stw 0,0xa8(1); stw 9,0x8(6); stw 11,0x4(6); lfs f11,0xa8(1); lfs f13,0x98(1); lfs f12,0x9c(1); fsubs f13,f13,f11; lfs f10,0xac(1); lfs f0,0xa0(1); lfs f11,0xb0(1); fsubs f12,f12,f10; stfs f13,0xb8(1); fsubs f0,f0,f11; stfs f12,0xbc(1); stfs f0,0xc0(1); bl _s8001C310_8; lis 9,-32707; fcmpu 0,f30,f1; lfs f0,-6816(9); fdivs f0,f0,f31; cror 3,2,1; bns 0f; fmuls f1,f30,f0; b 1f; 0:; fmuls f1,f1,f0; 1:; lis 9,-32707; lfs f0,0x19c(31); lfs f13,-6816(9); fsubs f0,f0,f29; stfs f1,0x194(31); fdivs f13,f13,f31; fabs f0,f0; fmuls f0,f0,f13; fmr f13,f0; fcmpu 0,f0,f1; cror 3,2,1; bso 2f; fmr f13,f1; 2:; stfs f13,0x194(31); b 4f; 3:; stfs f31,0x194(31); 4:; lwz 11,-26532(13); lis 4,-32693; addi 4,4,-11760; lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; li 0,1; stfs f1,0x190(31); stw 0,0x198(31); lwz 0,0xfc(1); mtspr 8,0; lmw 27,0xcc(1); lfd f29,0xe0(1); lfd f30,0xe8(1); lfd f31,0xf0(1); addi 1,1,248"

extern "C" void _s8001C310_0();
extern "C" void _s8001C310_1();
extern "C" void _s8001C310_2();
extern "C" void _s8001C310_3();
extern "C" void _s8001C310_4();
extern "C" void _s8001C310_5();
extern "C" void _s8001C310_6();
extern "C" void _s8001C310_7();
extern "C" void _s8001C310_8();

struct CameraDirector {
    void SetUpInterpCamera();
};

void CameraDirector::SetUpInterpCamera() {
}
