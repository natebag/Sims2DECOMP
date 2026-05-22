// 0x8038BE88 GXSetDispCopyFrame2Field (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 5,-17720(13); li 0,0; lwz 4,0x1ec(5); rlwimi 4,3,12,18,19; stw 4,0x1ec(5); lwz 3,0x1fc(5); rlwimi 3,0,12,18,19; stw 3,0x1fc(5)"
extern "C" void f_8038BE88() {}
