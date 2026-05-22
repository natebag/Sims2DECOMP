// 0x801253B4 cXPersonImpl::GetMotiveRef(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,2,0,29; addi 4,4,168; add 3,3,4"
extern "C" int f_801253B4() {}
