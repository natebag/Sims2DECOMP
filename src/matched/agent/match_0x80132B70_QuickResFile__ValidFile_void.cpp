// 0x80132B70 QuickResFile::ValidFile(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x8(3); li 3,1; cmplwi 0,0; bnelr; li 3,0"
extern "C" int f_80132B70() {}
