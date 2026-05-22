// 0x802B4894 AptValue::incGCRoot(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); rlwinm 9,0,24,26,31; cmpwi 9,62; bgtlr; addi 9,9,1; rlwimi 0,9,8,18,23; stw 0,0x0(3)"
extern "C" void f_802B4894() {}
