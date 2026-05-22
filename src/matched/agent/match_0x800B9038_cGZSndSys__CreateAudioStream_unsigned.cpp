// 0x800B9038 cGZSndSys::CreateAudioStream(unsigned (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 29,0xc(1); stw 0,0x24(1); fmr f31,f1; mr 30,4; mr 29,5; bl _s800B9038_0; li 4,40; li 5,1; li 6,0; bl _s800B9038_1; bl _s800B9038_2; mr 9,3; stw 30,0x10(9); stw 29,0xc(9); stfs f31,0x1c(9); lwz 0,0x24(1); mtspr 8,0; lmw 29,0xc(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s800B9038_0();
extern "C" void _s800B9038_1();
extern "C" void _s800B9038_2();
extern "C" void f_800B9038() {}
