// 0x8038C224 GXSetDispCopyYScale (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); lfs f0,-17680(13); fdivs f1,f0,f1; bl _s8038C224_0; rlwinm 7,3,0,23,31; lwz 3,-17720(13); li 0,97; lis 4,-13311; subfic 5,7,256; stb 0,-32768(4); addic 0,5,-1; subfe 5,0,5; li 6,0; li 0,78; rlwimi 6,7,0,23,31; rlwimi 6,0,24,0,7; stw 6,-32768(4); li 0,0; cmplwi 7,128; sth 0,0x2(3); addi 4,7,0; lwz 0,0x1ec(3); rlwimi 0,5,10,21,21; stw 0,0x1ec(3); lwz 0,0x1e4(3); rlwinm 5,0,22,22,31; rlwinm 0,0,30,14,23; divwu 3,0,7; addi 5,5,1; addi 3,3,1; ble 2f; cmplwi 7,256; bge 2f; b 1f; 0:; rlwinm 4,4,31,1,31; 1:; rlwinm. 0,4,0,31,31; beq 0b; divwu 0,5,4; mullw 0,0,4; subf. 0,0,5; bne 2f; addi 3,3,1; 2:; cmplwi 3,1024; ble 3f; li 3,1024; 3:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8038C224_0();
extern "C" void f_8038C224() {}
