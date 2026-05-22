// 0x8038B238 GXPokeDstAlpha (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,4,0,24,31; lwz 4,-21992(13); li 5,0; rlwimi 5,0,0,24,31; rlwinm 0,3,0,24,31; addi 3,5,0; rlwimi 3,0,8,23,23; sth 3,0x4(4)"
extern "C" void f_8038B238() {}
