// 0x8015E7E4 TreeTableEntryQuickData::GetActivationSubtile(unsigned (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); lwz 0,0x20(9); rlwinm 0,0,0,28,31; stb 0,0x0(4); lwz 11,0x20(9); rlwinm 11,11,28,28,31; stb 11,0x0(5)"
extern "C" void f_8015E7E4() {}
