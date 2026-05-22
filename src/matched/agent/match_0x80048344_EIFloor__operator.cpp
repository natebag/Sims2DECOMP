// 0x80048344 EIFloor::operator (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 3,4"
extern "C" int f_80048344() {}
