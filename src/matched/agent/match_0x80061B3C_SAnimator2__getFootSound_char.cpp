// 0x80061B3C SAnimator2::getFootSound(char (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); lis 9,-32707; lfs f0,0x1c(3); lfs f13,0x4928(9); mr 31,4; fcmpu 0,f0,f13; cror 3,2,1; bns 0f; lfs f10,0x20(3); fcmpu 0,f10,f13; cror 3,2,1; bns 0f; lis 9,-32707; lfs f13,0x492c(9); addi 30,1,16; mr 9,11; lwz 10,0x4(3); fadds f0,f0,f13; fctiwz f12,f0; stfd f12,0x18(1); fadds f13,f10,f13; fctiwz f11,f13; lwz 11,0x1c(1); stfd f11,0x18(1); stw 11,0x4(30); lwz 9,0x1c(1); stw 9,0x10(1); lwz 11,0x0(10); lwz 9,0x4(11); lha 3,0x350(9); lwz 0,0x354(9); add 3,11,3; mtspr 8,0; blrl; mr 5,3; mr 4,30; addi 3,1,8; bl _s80061B3C_0; mr 4,31; addi 3,1,8; bl _s80061B3C_1; mr 30,3; li 4,2; addi 3,1,8; bl _s80061B3C_2; mr 3,30; b 1f; 0:; li 3,-1; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s80061B3C_0();
extern "C" void _s80061B3C_1();
extern "C" void _s80061B3C_2();
extern "C" void f_80061B3C() {}
