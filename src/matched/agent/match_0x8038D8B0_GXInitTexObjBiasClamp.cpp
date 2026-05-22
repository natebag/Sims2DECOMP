// 0x8038D8B0 GXInitTexObjBiasClamp (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,4,0,24,31; lwz 4,0x0(3); rlwimi 4,0,21,10,10; stw 4,0x0(3)"
extern "C" void f_8038D8B0() {}
