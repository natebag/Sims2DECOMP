// 0x80371BAC OSUTF32to8 (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 3,55296; blt 0f; cmplwi 3,57343; bgt 0f; li 3,0; blr; 0:; cmplwi 3,128; bge 1f; extsb 0,3; stb 0,0x0(4); addi 6,4,1; b 5f; 1:; cmplwi 3,2048; bge 2f; rlwinm 0,3,26,6,31; ori 0,0,192; stb 0,0x0(4); addi 6,4,1; li 5,1; b 5f; 2:; lis 0,1; cmplw 3,0; bge 3f; rlwinm 0,3,20,12,31; ori 0,0,224; stb 0,0x0(4); addi 6,4,1; li 5,2; b 5f; 3:; lis 0,17; cmplw 3,0; bge 4f; rlwinm 0,3,14,18,31; ori 0,0,240; stb 0,0x0(4); addi 6,4,1; li 5,3; b 5f; 4:; li 3,0; blr; 5:; mulli 4,5,6; b 7f; 6:; srw 0,3,4; rlwinm 0,0,0,26,31; ori 0,0,128; stb 0,0x0(6); addi 6,6,1; 7:; cmpwi 5,0; addi 4,4,-6; addi 5,5,-1; bgt 6b; mr 3,6"
extern "C" void f_80371BAC() {}
