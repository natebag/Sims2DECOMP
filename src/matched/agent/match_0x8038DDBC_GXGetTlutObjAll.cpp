// 0x8038DDBC GXGetTlutObjAll (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(3); rlwinm 0,0,5,6,26; stw 0,0x0(4); lwz 0,0x0(3); rlwinm 0,0,22,30,31; stw 0,0x0(5); lhz 0,0x8(3); sth 0,0x0(6)"
extern "C" void f_8038DDBC() {}
