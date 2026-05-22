// 0x800D18B0 NeighborhoodImpl::GetNeighborhoodVar(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,1,0,30; addi 3,3,132; lhax 3,3,4"
extern "C" int f_800D18B0() {}
