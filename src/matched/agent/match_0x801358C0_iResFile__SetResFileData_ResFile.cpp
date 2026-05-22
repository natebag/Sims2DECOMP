// 0x801358C0 iResFile::SetResFileData(ResFile (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x8(3)"
extern "C" void f_801358C0() {}
