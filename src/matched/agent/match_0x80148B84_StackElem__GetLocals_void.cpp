// 0x80148B84 StackElem::GetLocals(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 9,0x7(3); add 9,9,9; addi 9,9,20; add 3,3,9"
extern "C" int f_80148B84() {}
