// 0x803899A8 __GXSetVCD (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 6,8; lwz 4,-17720(13); lis 5,-13311; stb 6,-32768(5); li 3,80; li 0,96; stb 3,-32768(5); lwz 3,0x14(4); stw 3,-32768(5); stb 6,-32768(5); stb 0,-32768(5); lwz 0,0x18(4); stw 0,-32768(5); lbz 0,0x4d5(4); cmplwi 0,0; beq 0f; li 7,2; b 2f; 0:; lbz 0,0x4d4(4); cmplwi 0,0; beq 1f; li 7,1; b 2f; 1:; li 7,0; 2:; lwz 5,-17720(13); li 0,16; lwz 6,0x14(4); lis 4,-13311; lwz 3,0x18(5); rlwinm 6,6,19,28,31; cntlzw 6,6; stb 0,-32768(4); rlwinm 3,3,0,16,31; subfic 6,6,33; cntlzw 0,3; subfic 3,0,33; li 0,4104; stw 0,-32768(4); rlwinm 6,6,31,1,31; rlwinm 0,7,2,0,29; rlwinm 3,3,3,0,27; or 0,6,0; or 0,3,0; stw 0,-32768(4); li 0,1; sth 0,0x2(5)"
extern "C" void f_803899A8() {}
