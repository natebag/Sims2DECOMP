// 0x80287E48 AptArray::GetAt(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x24(3); rlwinm 4,4,2,0,29; lwzx 3,4,9"
extern "C" int f_80287E48() {}
