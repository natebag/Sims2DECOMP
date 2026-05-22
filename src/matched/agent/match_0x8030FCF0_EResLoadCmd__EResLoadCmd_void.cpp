// 0x8030FCF0 EResLoadCmd::EResLoadCmd(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; li 0,0; li 11,1; stw 0,0x18(9); stw 11,0x24(9); stw 0,0x0(9); stw 0,0x4(9); stw 0,0x8(9); stw 0,0xc(9); stw 0,0x10(9); stw 0,0x14(9); stw 11,0x20(9)"
extern "C" void f_8030FCF0() {}
