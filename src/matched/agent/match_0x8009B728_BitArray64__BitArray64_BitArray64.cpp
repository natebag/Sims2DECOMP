// 0x8009B728 BitArray64::BitArray64(BitArray64 (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x0(4); lwz 12,0x4(4); mr 9,3; stw 11,0x0(9); stw 12,0x4(9)"
extern "C" void f_8009B728() {}
