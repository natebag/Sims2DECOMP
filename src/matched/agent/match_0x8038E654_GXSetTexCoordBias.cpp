// 0x8038E654 GXSetTexCoordBias (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 8,-17720(13); rlwinm 6,3,2,0,29; li 0,1; add 7,8,6; lwz 6,0xb8(7); rlwimi 6,4,16,15,15; slw 0,0,3; stw 6,0xb8(7); lwz 3,0xd8(7); rlwimi 3,5,16,15,15; stw 3,0xd8(7); lwz 3,0x594(8); and 0,3,0; beqlr; li 5,97; lis 4,-13311; stb 5,-32768(4); li 0,0; lwz 3,0xb8(7); stw 3,-32768(4); stb 5,-32768(4); lwz 3,0xd8(7); stw 3,-32768(4); sth 0,0x2(8)"
extern "C" void f_8038E654() {}
