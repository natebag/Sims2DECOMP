// 0x801D1F30 PCTTarget::cCellInfo::cCellInfo(void) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; li 0,0; stw 0,0x14(9); stw 0,0x0(9); stw 0,0x4(9); stw 0,0x8(9); stw 0,0xc(9); stw 0,0x10(9)"
extern "C" void f_801D1F30() {}
