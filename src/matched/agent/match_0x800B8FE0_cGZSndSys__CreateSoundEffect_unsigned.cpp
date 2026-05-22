// 0x800B8FE0 cGZSndSys::CreateSoundEffect(unsigned (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stmw 30,0x8(1); stw 0,0x1c(1); fmr f31,f1; mr 30,4; bl _s800B8FE0_0; li 4,64; li 5,1; li 6,0; bl _s800B8FE0_1; bl _s800B8FE0_2; mr 9,3; stw 30,0x14(9); stfs f31,0x30(9); lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x8(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s800B8FE0_0();
extern "C" void _s800B8FE0_1();
extern "C" void _s800B8FE0_2();
extern "C" void f_800B8FE0() {}
