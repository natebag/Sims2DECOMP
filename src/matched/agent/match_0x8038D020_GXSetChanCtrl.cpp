// 0x8038D020 GXSetChanCtrl (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,4,0,24,31; li 4,0; rlwimi 4,0,1,30,30; addi 10,4,0; rlwimi 10,6,0,31,31; cmpwi 9,0; rlwimi 10,5,6,25,25; rlwinm 11,3,0,30,31; bne 0f; li 8,0; 0:; subfic 4,9,2; addic 0,4,-1; subfe 0,0,4; neg 9,9; rlwimi 10,8,7,23,24; addic 6,9,-1; rlwimi 10,0,9,22,22; subfe 6,6,9; rlwimi 10,6,10,21,21; rlwimi 10,7,2,26,29; li 5,16; lis 4,-13311; stb 5,-32768(4); addi 0,11,4110; rlwimi 10,7,7,17,20; stw 0,-32768(4); cmpwi 3,4; stw 10,-32768(4); bne 1f; stb 5,-32768(4); li 0,4112; stw 0,-32768(4); stw 10,-32768(4); b 2f; 1:; cmpwi 3,5; bne 2f; stb 5,-32768(4); li 0,4113; stw 0,-32768(4); stw 10,-32768(4); 2:; lwz 3,-17720(13); li 0,1; sth 0,0x2(3)"
extern "C" void f_8038D020() {}
