// 0x802C6048 EFile::EFile(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 11,-32697; mr 9,3; li 0,0; lis 10,-32768; addi 11,11,-24472; stw 10,0x10(9); stw 11,0x28(9); stb 0,0x24(9); stw 0,0x0(9); stw 0,0x4(9); stw 10,0x8(9); stw 10,0xc(9); stw 0,0x14(9); stw 0,0x1c(9); stw 0,0x20(9); stb 0,0x18(9)"
extern "C" void f_802C6048() {}
