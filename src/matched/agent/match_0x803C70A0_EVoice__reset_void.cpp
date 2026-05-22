// 0x803C70A0 EVoice::reset(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32702; li 0,0; lfs f0,0x1510(9); stw 0,0x1c(3); stfs f0,0xc(3); stw 0,0x0(3); stfs f0,0x14(3); stfs f0,0x10(3); stw 0,0x18(3)"
extern "C" void f_803C70A0() {}
