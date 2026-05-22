// 0x800D18C0 NeighborhoodImpl::GetNeighborhoodVarRef(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,1,0,30; addi 4,4,132; add 3,3,4"
extern "C" int f_800D18C0() {}
