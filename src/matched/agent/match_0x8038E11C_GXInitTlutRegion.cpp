// 0x8038E11C GXInitTlutRegion (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x0(3); addis 0,4,-8; lwz 4,0x0(3); rlwimi 4,0,23,22,31; li 0,101; stw 4,0x0(3); lwz 4,0x0(3); rlwimi 4,5,10,11,21; stw 4,0x0(3); lwz 4,0x0(3); rlwimi 4,0,24,0,7; stw 4,0x0(3)"
extern "C" void f_8038E11C() {}
