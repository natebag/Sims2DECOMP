// 0x8015E804 TreeTableEntryQuickData::GetActivationExtents(unsigned (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x4(3); lwz 0,0x20(11); rlwinm 0,0,24,26,31; stb 0,0x0(4); lwz 9,0x20(11); rlwinm 9,9,18,26,31; stb 9,0x0(5); lwz 0,0x20(11); rlwinm 0,0,12,26,31; stb 0,0x0(6); lwz 9,0x20(11); rlwinm 9,9,6,26,31; stb 9,0x0(7)"
extern "C" void f_8015E804() {}
