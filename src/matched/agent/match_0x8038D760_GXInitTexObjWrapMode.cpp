// 0x8038D760 GXInitTexObjWrapMode (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); rlwimi 0,4,0,30,31; stw 0,0x0(3); lwz 0,0x0(3); rlwimi 0,5,2,28,29; stw 0,0x0(3)"
extern "C" void f_8038D760() {}
