// 0x8038D750 GXInitTexObjData (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xc(3); rlwimi 0,4,27,11,31; stw 0,0xc(3)"
extern "C" void f_8038D750() {}
