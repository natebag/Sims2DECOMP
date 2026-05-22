// 0x80016990 ESimsCam::GetFarPlane(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); lfs f1,0x68(9)"
extern "C" float f_80016990() {}
