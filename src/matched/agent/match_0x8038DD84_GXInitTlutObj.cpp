// 0x8038DD84 GXInitTlutObj (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x0(3); li 0,100; lwz 7,0x0(3); rlwimi 7,5,10,20,21; stw 7,0x0(3); lwz 5,0x4(3); rlwimi 5,4,27,11,31; stw 5,0x4(3); lwz 4,0x4(3); rlwimi 4,0,24,0,7; stw 4,0x4(3); sth 6,0x8(3)"
extern "C" void f_8038DD84() {}
