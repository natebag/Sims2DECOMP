// 0x801A0800 CASTarget::GetPrevUIFocus(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xa0(3)"
extern "C" int f_801A0800() {}
