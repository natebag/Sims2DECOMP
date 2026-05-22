// 0x80209188 InteractorModule::FloorPainter::IsInInvalidState(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 3,0x60(3); rlwinm 3,3,27,31,31"
extern "C" int f_80209188() {}
