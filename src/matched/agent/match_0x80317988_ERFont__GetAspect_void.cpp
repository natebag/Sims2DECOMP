// 0x80317988 ERFont::GetAspect(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0x50(3)"
extern "C" int f_80317988() {}
