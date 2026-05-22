// 0x80146F04 TileWalls::RemoveAllWalls(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x0(3)"
extern "C" void f_80146F04() {}
