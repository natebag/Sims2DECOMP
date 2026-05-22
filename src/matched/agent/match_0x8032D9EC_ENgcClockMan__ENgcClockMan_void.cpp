// 0x8032D9EC ENgcClockMan::ENgcClockMan(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; mr 11,3; addi 9,9,-15712; stw 9,0x0(11)"
extern "C" void f_8032D9EC() {}
