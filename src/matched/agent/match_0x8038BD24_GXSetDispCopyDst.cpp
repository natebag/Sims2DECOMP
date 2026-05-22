// 0x8038BD24 GXSetDispCopyDst (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-17720(13); li 0,0; stw 0,0x1e8(4); rlwinm 0,3,1,16,30; srawi 0,0,5; lwz 3,0x1e8(4); rlwimi 3,0,0,22,31; li 0,77; stw 3,0x1e8(4); lwz 3,0x1e8(4); rlwimi 3,0,24,0,7; stw 3,0x1e8(4)"
extern "C" void f_8038BD24() {}
