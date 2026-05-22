// 0x802E0EF8 EMemoryWriteStream::GetPos(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x1c(3)"
extern "C" int f_802E0EF8() {}
