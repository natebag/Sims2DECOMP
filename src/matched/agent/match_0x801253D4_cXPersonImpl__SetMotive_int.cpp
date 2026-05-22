// 0x801253D4 cXPersonImpl::SetMotive(int, (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,2,0,29; addi 3,3,168; stfsx f1,3,4"
extern "C" void f_801253D4() {}
