// 0x802E0914 EBitArray::GetBuffer(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3)"
extern "C" int f_802E0914() {}
