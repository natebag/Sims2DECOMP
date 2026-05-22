// 0x80390C6C GXLoadTexMtxIndx (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 4,64; blt 0f; addi 0,4,-64; rlwinm 4,0,2,0,29; addi 0,4,1280; b 1f; 0:; rlwinm 0,4,2,0,29; 1:; cmpwi 5,1; bne 2f; li 4,8; b 3f; 2:; li 4,12; 3:; li 5,0; rlwimi 5,0,0,20,31; addi 0,4,-1; rlwimi 5,0,12,16,19; li 0,48; lis 4,-13311; stb 0,-32768(4); rlwimi 5,3,16,0,15; stw 5,-32768(4)"
extern "C" void f_80390C6C() {}
