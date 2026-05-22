// 0x80388B38 GXSaveGPFifo (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 5,-21996(13); lhz 4,0x3a(5); lhz 5,0x38(5); rlwimi 5,4,16,0,15; addis 0,5,-32768; stw 0,0x14(3); lwz 5,-21996(13); lhz 4,0x32(5); lhz 0,0x30(5); rlwimi 0,4,16,0,15; stw 0,0x1c(3)"
extern "C" void f_80388B38() {}
