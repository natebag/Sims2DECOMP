// 0x80304E58 EController::StickMoved(int, (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f30,0x18(1); stfd f31,0x20(1); stmw 29,0xc(1); stw 0,0x2c(1); mr 29,5; mr 31,3; mr 30,4; fmr f30,f1; li 5,0; mr 6,29; bl _s80304E58_0; fmr f31,f1; mr 3,31; mr 4,30; li 5,0; mr 6,29; bl _s80304E58_1; fsubs f0,f31,f1; li 3,1; fabs f0,f0; fcmpu 0,f0,f30; cror 3,2,1; bso 0f; mr 3,31; mr 4,30; li 5,1; mr 6,29; bl _s80304E58_2; fmr f31,f1; mr 3,31; mr 4,30; mr 6,29; li 5,1; bl _s80304E58_3; fsubs f0,f31,f1; fabs f0,f0; fcmpu 7,f0,f30; cror 31,30,29; mfcr 3; rlwinm 3,3,0,31,31; 0:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0xc(1); lfd f30,0x18(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s80304E58_0();
extern "C" void _s80304E58_1();
extern "C" void _s80304E58_2();
extern "C" void _s80304E58_3();
extern "C" void f_80304E58() {}
