// 0x80057C18 MorphUtilities::MorphUtilities(EIStaticModel (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x0(3)"
extern "C" void f_80057C18() {}
