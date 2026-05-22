// 0x8021CFB0 FadeSquare::ShouldDraw(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32704; lfs f13,0x10(3); lfs f0,-9128(9); fcmpu 7,f13,f0; mfcr 3; rlwinm 3,3,30,31,31"
extern "C" float f_8021CFB0() {}
