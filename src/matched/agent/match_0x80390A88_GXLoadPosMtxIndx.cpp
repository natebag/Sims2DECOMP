// 0x80390A88 GXLoadPosMtxIndx (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,4,2,0,29; li 4,0; rlwimi 4,0,0,20,31; addi 5,4,0; li 0,11; rlwimi 5,0,12,16,19; li 0,32; lis 4,-13311; stb 0,-32768(4); rlwimi 5,3,16,0,15; stw 5,-32768(4)"
extern "C" void f_80390A88() {}
