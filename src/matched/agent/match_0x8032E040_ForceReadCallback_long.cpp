// 0x8032E040 ForceReadCallback(long, (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 0,-26412(13)"
extern "C" void f_8032E040() {}
