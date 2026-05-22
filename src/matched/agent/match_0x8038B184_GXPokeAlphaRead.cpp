// 0x8038B184 GXPokeAlphaRead (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 5,0; lwz 4,-21992(13); rlwimi 5,3,0,30,31; li 0,1; addi 3,5,0; rlwimi 3,0,2,29,29; sth 3,0x8(4)"
extern "C" void f_8038B184() {}
