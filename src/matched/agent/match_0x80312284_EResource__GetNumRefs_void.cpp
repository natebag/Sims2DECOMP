// 0x80312284 EResource::GetNumRefs(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 3,0xc(3)"
extern "C" int f_80312284() {}
