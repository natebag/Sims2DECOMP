// 0x802BE868 EAStringC::CalculateHashValue(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); lis 10,-32484; ori 10,10,40389; lbz 0,0x8(9); addi 9,9,9; extsb 11,0; cmpwi 11,0; beq 2f; lis 8,256; ori 8,8,403; 0:; addi 0,11,-65; cmplwi 0,25; bgt 1f; addi 11,11,32; 1:; lbz 0,0x0(9); xor 10,10,11; mullw 10,10,8; addi 9,9,1; extsb 11,0; cmpwi 11,0; bne 0b; 2:; rlwinm 0,10,0,16,31; cmpwi 0,0; bne 3f; li 0,17767; 3:; lwz 9,0x0(3); sth 0,0x6(9)"
extern "C" void f_802BE868() {}
