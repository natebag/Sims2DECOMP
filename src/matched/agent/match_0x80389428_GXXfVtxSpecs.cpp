// 0x80389428 __GXXfVtxSpecs (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-17720(13); lbz 0,0x4d5(3); cmplwi 0,0; beq 0f; li 7,2; b 2f; 0:; lbz 0,0x4d4(3); cmplwi 0,0; beq 1f; li 7,1; b 2f; 1:; li 7,0; 2:; lwz 5,-17720(13); li 0,16; lwz 6,0x14(3); lis 4,-13311; lwz 3,0x18(5); rlwinm 6,6,19,28,31; cntlzw 6,6; stb 0,-32768(4); rlwinm 3,3,0,16,31; subfic 6,6,33; cntlzw 0,3; subfic 3,0,33; li 0,4104; stw 0,-32768(4); rlwinm 6,6,31,1,31; rlwinm 0,7,2,0,29; rlwinm 3,3,3,0,27; or 0,6,0; or 0,3,0; stw 0,-32768(4); li 0,1; sth 0,0x2(5)"
extern "C" void f_80389428() {}
