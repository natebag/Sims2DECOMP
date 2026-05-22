// 0x8004ED24 ISimsObjectModel::StartBurp(int) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32707; rlwinm 4,4,2,0,29; lfs f0,0x3220(9); addi 3,3,1016; stfsx f0,3,4"
extern "C" void f_8004ED24() {}
