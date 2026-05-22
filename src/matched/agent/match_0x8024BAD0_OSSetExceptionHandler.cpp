// 0x8024BAD0 __OSSetExceptionHandler (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,3,0,24,31; lwz 3,-23708(13); rlwinm 0,0,2,0,29; add 5,3,0; lwz 3,0x0(5); stw 4,0x0(5)"
extern "C" void f_8024BAD0() {}
