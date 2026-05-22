// 0x803070A8 IsOnRightOf(EVec2, (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f8,0x0(4); lis 9,-32702; lfs f11,0x0(3); lfs f9,0x4(4); lfs f13,0x4(5); fsubs f11,f11,f8; lfs f0,0x4(3); lfs f12,0x0(5); fsubs f13,f13,f9; fmuls f11,f11,f13; lfs f10,-1292(9); fsubs f0,f0,f9; fsubs f12,f12,f8; fmsubs f0,f0,f12,f11; fcmpu 7,f0,f10; mfcr 3; rlwinm 3,3,29,31,31"
extern "C" float f_803070A8() {}
