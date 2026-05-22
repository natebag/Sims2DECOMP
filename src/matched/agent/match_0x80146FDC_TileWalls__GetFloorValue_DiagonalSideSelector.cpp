// 0x80146FDC TileWalls::GetFloorValue(DiagonalSideSelector) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 4,4,-1; cmplwi 4,1; ble 0f; lhz 3,0x14(3); blr; 0:; lhz 3,0x8(3)"
extern "C" int f_80146FDC() {}
