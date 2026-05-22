// 0x80337644 AudioDecoder(void (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); 0:; bl _s80337644_0; mr 30,3; bl _s80337644_1; mr 3,30; bl _s80337644_2; b 0b"
extern "C" void _s80337644_0();
extern "C" void _s80337644_1();
extern "C" void _s80337644_2();
extern "C" void f_80337644() {}
