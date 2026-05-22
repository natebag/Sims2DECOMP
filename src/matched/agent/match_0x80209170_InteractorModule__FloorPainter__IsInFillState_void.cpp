// 0x80209170 InteractorModule::FloorPainter::IsInFillState(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 3,0x60(3); rlwinm 3,3,31,31,31"
extern "C" int f_80209170() {}
