// 0x80069194 SAnimator2::SetBoneIndex(int, (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,2,0,29; addi 3,3,1548; stwx 5,3,4"
extern "C" void f_80069194() {}
