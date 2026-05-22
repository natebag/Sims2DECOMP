// 0x802F2224 EGraphics::SetCoordinateSystem(ECoordinateSystem) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x98(3)"
extern "C" void f_802F2224() {}
