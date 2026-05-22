// 0x802B4884 AptValue::setGCRoot(unsigned (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); rlwimi 0,4,8,18,23; stw 0,0x0(3)"
extern "C" void f_802B4884() {}
