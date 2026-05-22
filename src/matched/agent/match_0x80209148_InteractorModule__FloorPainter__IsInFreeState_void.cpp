// 0x80209148 InteractorModule::FloorPainter::IsInFreeState(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 3,0x60(3); subfic 0,3,0; adde 3,0,3"
extern "C" int f_80209148() {}
