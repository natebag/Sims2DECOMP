// 0x8015D89C TreeTableAdQuickData::TreeTableAdQuickData(TreeTableAd (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32698; mr 11,3; addi 9,9,24192; li 0,0; stw 9,0x0(11); stw 4,0x4(11); stw 0,0x8(11)"
extern "C" void f_8015D89C() {}
