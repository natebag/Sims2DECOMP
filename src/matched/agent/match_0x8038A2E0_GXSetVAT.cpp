// 0x8038A2E0 __GXSetVAT (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,-17720(13); li 11,0; li 10,0; lbz 12,0x5ab(9); lis 7,-13311; 0:; rlwinm. 0,12,0,31,31; beq 1f; li 8,8; stb 8,-32768(7); ori 3,11,112; addi 0,10,28; stb 3,-32768(7); ori 5,11,128; addi 4,10,60; lwzx 6,9,0; ori 3,11,144; addi 0,10,92; stw 6,-32768(7); stb 8,-32768(7); stb 5,-32768(7); lwzx 4,9,4; stw 4,-32768(7); stb 8,-32768(7); stb 3,-32768(7); lwzx 0,9,0; stw 0,-32768(7); 1:; rlwinm. 12,12,31,1,31; addi 10,10,4; addi 11,11,1; bne 0b; lwz 3,-17720(13); li 0,0; stb 0,0x5ab(3)"
extern "C" void f_8038A2E0() {}
