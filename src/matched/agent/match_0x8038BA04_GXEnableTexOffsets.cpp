// 0x8038BA04 GXEnableTexOffsets (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 7,-17720(13); rlwinm 3,3,2,0,29; rlwinm 0,5,0,24,31; add 6,7,3; lwz 3,0xb8(6); rlwimi 3,4,18,13,13; lis 4,-13311; stw 3,0xb8(6); li 3,97; lwz 5,0xb8(6); rlwimi 5,0,19,12,12; li 0,0; stw 5,0xb8(6); stb 3,-32768(4); lwz 3,0xb8(6); stw 3,-32768(4); sth 0,0x2(7)"
extern "C" void f_8038BA04() {}
