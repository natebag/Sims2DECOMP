// 0x80164F64 CasNpcEditor::IsLoadInProgress(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32706; lfs f13,0x14(3); lfs f0,-2128(9); fcmpu 7,f13,f0; mfcr 3; rlwinm 3,3,30,31,31"
extern "C" float f_80164F64() {}
