// 0x802C695C EFile::SetMode(EFile::IOMode) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x8(3)"
extern "C" void f_802C695C() {}
