// 0x8012C768 cXPersonImpl::SetPersonData(int, (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,1,0,30; addi 3,3,8; sthx 5,3,4"
extern "C" void f_8012C768() {}
