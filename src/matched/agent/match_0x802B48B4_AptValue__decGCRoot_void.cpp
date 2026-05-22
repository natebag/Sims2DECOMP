// 0x802B48B4 AptValue::decGCRoot(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); andi. 9,0,16128; beqlr; rlwinm 9,0,24,26,31; addi 9,9,-1; rlwimi 0,9,8,18,23; stw 0,0x0(3)"
extern "C" void f_802B48B4() {}
