// 0x801253A4 cXPersonImpl::GetMotive(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,2,0,29; addi 3,3,168; lfsx f1,3,4"
extern "C" int f_801253A4() {}
