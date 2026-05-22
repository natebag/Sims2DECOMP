// 0x800EB0EC cXObjectImpl::GetTemp(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,1,0,30; addi 3,3,22; lhax 3,3,4"
extern "C" int f_800EB0EC() {}
