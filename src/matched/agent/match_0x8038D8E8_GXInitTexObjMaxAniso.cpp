// 0x8038D8E8 GXInitTexObjMaxAniso (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); rlwimi 0,4,19,11,12; stw 0,0x0(3)"
extern "C" void f_8038D8E8() {}
