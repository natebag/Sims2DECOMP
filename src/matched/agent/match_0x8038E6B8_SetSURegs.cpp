// 0x8038E6B8 __SetSURegs (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 8,-17720(13); rlwinm 3,3,2,0,29; rlwinm 0,4,2,0,29; add 3,8,3; lwz 4,0x514(3); add 7,8,0; lwz 0,0xb8(7); li 5,97; rlwinm 6,4,0,22,31; rlwimi 0,6,0,16,31; stw 0,0xb8(7); rlwinm 4,4,22,22,31; lwz 0,0xd8(7); rlwimi 0,4,0,16,31; lis 4,-13311; stw 0,0xd8(7); li 0,0; lwz 9,0x534(3); lwz 3,0xb8(7); rlwinm 6,9,0,30,31; subfic 6,6,1; cntlzw 6,6; rlwinm 10,6,27,24,31; rlwinm 6,9,30,30,31; rlwimi 3,10,16,15,15; subfic 6,6,1; stw 3,0xb8(7); cntlzw 3,6; rlwinm 6,3,27,24,31; lwz 3,0xd8(7); rlwimi 3,6,16,15,15; stw 3,0xd8(7); stb 5,-32768(4); lwz 3,0xb8(7); stw 3,-32768(4); stb 5,-32768(4); lwz 3,0xd8(7); stw 3,-32768(4); sth 0,0x2(8)"
extern "C" void f_8038E6B8() {}
