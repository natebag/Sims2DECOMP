// 0x802BBD94 AptFloat::GetFloat(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0xc(3)"
extern "C" int f_802BBD94() {}
