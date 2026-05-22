// 0x80357218 InteractorModule::FloorPainter::IsInRemoveMode(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8035726C" lines="lfs f4,0x0(31); bl _s80357218_0; lwz 0,0x1c(31)"
extern "C" void _s80357218_0();
extern "C" void f_8035726C();
extern "C" void f_80357218() {}
