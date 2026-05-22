// 0x80372D54 PSMTXRotRad (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stfd f31,0x20(1); stw 31,0x1c(1); stw 30,0x18(1); fmr f31,f1; mr 30,3; mr 31,4; fmr f1,f31; bl _s80372D54_0; fmr f0,f1; fmr f1,f31; fmr f31,f0; bl _s80372D54_1; fmr f0,f1; mr 3,30; fmr f1,f31; mr 4,31; fmr f2,f0; bl _s80372D54_2; lwz 0,0x2c(1); lfd f31,0x20(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80372D54_0();
extern "C" void _s80372D54_1();
extern "C" void _s80372D54_2();
extern "C" void f_80372D54() {}
