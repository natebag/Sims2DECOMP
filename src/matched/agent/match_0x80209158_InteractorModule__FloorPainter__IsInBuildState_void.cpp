// 0x80209158 InteractorModule::FloorPainter::IsInBuildState(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 3,0x60(3); rlwinm 3,3,30,31,31"
extern "C" int f_80209158() {}
