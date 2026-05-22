// 0x800690F8 SAnimator2::GetPortalMode(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 3,0x5f8(3); extsb 3,3"
extern "C" int f_800690F8() {}
