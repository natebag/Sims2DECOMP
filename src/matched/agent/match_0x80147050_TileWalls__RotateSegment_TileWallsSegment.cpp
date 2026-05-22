// 0x80147050 TileWalls::RotateSegment(TileWallsSegment, (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 3,3,2,0,29; rlwinm 4,4,8,0,23; lis 9,-32688; add 3,3,4; addi 9,9,-17360; lwzx 3,9,3"
extern "C" int f_80147050() {}
