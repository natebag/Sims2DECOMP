// 0x800567E4 IBaseSimInstance::IBaseSimInstance(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32698; mr 11,3; addi 9,9,-14112; stw 9,0x0(11)"
extern "C" void f_800567E4() {}
