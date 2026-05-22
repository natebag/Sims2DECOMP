// 0x8038B2B8 GXPokeARGB (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,3,0,16,31; lis 3,-14336; rlwimi 3,0,2,20,29; li 0,0; rlwimi 3,4,12,10,19; rlwimi 3,0,22,8,9; stw 5,0x0(3)"
extern "C" void f_8038B2B8() {}
