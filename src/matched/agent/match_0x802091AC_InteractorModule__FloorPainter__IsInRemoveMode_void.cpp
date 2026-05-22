// 0x802091AC InteractorModule::FloorPainter::IsInRemoveMode(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xa4(3); subfic 0,3,0; adde 3,0,3"
extern "C" int f_802091AC() {}
