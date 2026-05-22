// 0x800F95D8 ObjectModuleImpl::GetIdleStatus(int) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x1c(3); addi 4,4,-1; rlwinm 4,4,2,0,29; add 9,9,4; lha 3,0x2(9)"
extern "C" int f_800F95D8() {}
