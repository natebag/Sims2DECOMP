// 0x8038AFB8 GXReadDrawSync (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-21992(13); lhz 3,0xe(3)"
extern "C" int f_8038AFB8() {}
