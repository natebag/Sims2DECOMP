// 0x803C2F10 EString2::operator (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3)"
extern "C" int f_803C2F10() {}
