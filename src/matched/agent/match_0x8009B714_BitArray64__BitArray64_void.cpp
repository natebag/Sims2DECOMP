// 0x8009B714 BitArray64::BitArray64(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 9,0; li 10,0; stw 9,0x0(3); stw 10,0x4(3)"
extern "C" void f_8009B714() {}
