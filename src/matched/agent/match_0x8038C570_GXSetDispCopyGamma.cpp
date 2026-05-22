// 0x8038C570 GXSetDispCopyGamma (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-17720(13); lwz 0,0x1ec(4); rlwimi 0,3,7,23,24; stw 0,0x1ec(4)"
extern "C" void f_8038C570() {}
