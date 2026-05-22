// 0x8009B8FC BitArray64::operator|=(BitArray64 (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 6,3; lwz 7,0x0(4); lwz 8,0x4(4); lwz 11,0x0(6); lwz 12,0x4(6); or 9,11,7; or 10,12,8; stw 9,0x0(6); stw 10,0x4(6)"
extern "C" void f_8009B8FC() {}
