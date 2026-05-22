// 0x8038CDCC GXLoadLightObjIndx (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cntlzw 0,4; lwz 4,-17720(13); subfic 0,0,31; rlwinm 5,0,4,25,27; addi 0,5,1536; li 5,0; rlwimi 5,0,0,20,31; addi 6,5,0; li 0,15; rlwimi 6,0,12,16,19; li 0,56; lis 5,-13311; stb 0,-32768(5); rlwimi 6,3,16,0,15; li 0,1; stw 6,-32768(5); sth 0,0x2(4)"
extern "C" void f_8038CDCC() {}
