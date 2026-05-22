// 0x80393B34 __THPHuffGenerateCodeTable (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 6,-21656(13); li 8,0; lwz 5,-21652(13); li 9,0; lbz 7,0x0(6); li 3,1; b 3f; 0:; rlwinm 4,7,0,24,31; b 2f; 1:; rlwinm 0,8,1,15,30; sthx 9,5,0; addi 8,8,1; addi 9,9,1; 2:; rlwinm 0,8,0,16,31; lbzx 0,6,0; cmplw 4,0; beq 1b; rlwinm 0,9,0,16,31; slw 0,0,3; rlwinm 9,0,0,16,31; addi 7,7,1; 3:; rlwinm 0,8,0,16,31; lbzx 0,6,0; cmplwi 0,0; bne 0b"
extern "C" void f_80393B34() {}
