// 0x801253C4 cXPersonImpl::GetOldMotiveRef(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,2,0,29; addi 4,4,232; add 3,3,4"
extern "C" int f_801253C4() {}
