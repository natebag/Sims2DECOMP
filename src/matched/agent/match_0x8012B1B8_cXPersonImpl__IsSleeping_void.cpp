// 0x8012B1B8 cXPersonImpl::IsSleeping(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32706; lfs f13,0xd4(3); lfs f0,-12760(9); fcmpu 7,f13,f0; mfcr 3; rlwinm 3,3,29,31,31"
extern "C" float f_8012B1B8() {}
