// 0x8038B1BC GXPokeBlendMode (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 7,-21992(13); cmpwi 3,1; li 9,1; lhz 10,0x2(7); beq 0f; cmpwi 3,3; beq 0f; li 9,0; 0:; subfic 0,3,3; lwz 7,-21992(13); cntlzw 8,0; subfic 0,3,2; rlwimi 10,9,0,31,31; rlwinm 3,8,27,5,31; addi 8,10,0; cntlzw 0,0; rlwimi 8,3,11,20,20; rlwimi 8,0,28,30,30; rlwimi 8,6,12,16,19; rlwimi 8,4,8,21,23; li 0,65; rlwimi 8,5,5,24,26; rlwimi 8,0,24,0,7; sth 8,0x2(7)"
extern "C" void f_8038B1BC() {}
