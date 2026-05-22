// 0x80161B50 CasListener::CasListener(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32698; mr 11,3; addi 9,9,24424; li 0,0; stw 9,0x4(11); stw 0,0x0(11)"
extern "C" void f_80161B50() {}
