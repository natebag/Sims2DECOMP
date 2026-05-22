// 0x80209164 InteractorModule::FloorPainter::IsInRemoveState(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 3,0x60(3); rlwinm 3,3,29,31,31"
extern "C" int f_80209164() {}
