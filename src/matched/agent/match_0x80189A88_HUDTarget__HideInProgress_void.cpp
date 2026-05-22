// 0x80189A88 HUDTarget::HideInProgress(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 3,0xe8(3); xori 3,3,1; subfic 0,3,0; adde 3,0,3"
extern "C" int f_80189A88() {}
