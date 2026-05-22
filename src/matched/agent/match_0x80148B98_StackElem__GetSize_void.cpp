// 0x80148B98 StackElem::GetSize(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,0x7(3); lbz 3,0x6(3); add 3,3,0; addi 3,3,3; rlwinm 3,3,1,21,28; addi 3,3,20"
extern "C" int f_80148B98() {}
