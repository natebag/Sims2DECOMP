// 0x800295AC ERoomWall::IsWallsOpaque(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,2,0,29; addi 3,3,44; lwzx 3,3,4"
extern "C" int f_800295AC() {}
