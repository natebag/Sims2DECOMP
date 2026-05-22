// 0x80042DAC DeleteSelectorOnEvict(int) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 0,9417; ori 0,0,24473; cmpw 3,0; bne 1f; 0:; li 3,1; blr; 1:; lis 0,-14860; ori 0,0,23203; cmpw 3,0; beq 0b; lis 0,14819; ori 0,0,30671; cmpw 3,0; beq 0b; lis 0,-20; ori 0,0,63157; cmpw 3,0; beq 0b; lis 0,-28537; ori 0,0,57506; cmpw 3,0; beq 0b; lis 0,18240; ori 0,0,63331; cmpw 3,0; beq 0b; lis 0,-23320; ori 0,0,45108; cmpw 3,0; beq 2f; lis 0,-29871; ori 0,0,40870; xor 3,3,0; subfic 0,3,0; adde 3,0,3; blr; 2:; li 3,1"
extern "C" int f_80042DAC() {}
