// 0x8020913C InteractorModule::FloorPainter::IsInAnchorState(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 3,0x60(3); rlwinm 3,3,0,31,31"
extern "C" int f_8020913C() {}
