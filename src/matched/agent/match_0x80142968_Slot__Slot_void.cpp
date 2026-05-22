// 0x80142968 Slot::Slot(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32698; mr 11,3; addi 9,9,18992; stw 9,0x0(11)"
extern "C" void f_80142968() {}
