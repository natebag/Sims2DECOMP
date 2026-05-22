// 0x8012C758 cXPersonImpl::GetPersonData(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,1,0,30; addi 3,3,8; lhax 3,3,4"
extern "C" int f_8012C758() {}
