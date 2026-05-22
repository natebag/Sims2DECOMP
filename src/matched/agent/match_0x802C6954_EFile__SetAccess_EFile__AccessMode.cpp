// 0x802C6954 EFile::SetAccess(EFile::AccessMode) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0xc(3)"
extern "C" void f_802C6954() {}
