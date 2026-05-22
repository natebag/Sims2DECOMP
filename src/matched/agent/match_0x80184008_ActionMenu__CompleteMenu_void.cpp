// 0x80184008 ActionMenu::CompleteMenu(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 9,0xa0(3); addi 9,9,-1; stb 9,0xa0(3)"
extern "C" void f_80184008() {}
