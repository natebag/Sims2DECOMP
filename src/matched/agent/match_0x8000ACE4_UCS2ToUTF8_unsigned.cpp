// 0x8000ACE4 UCS2ToUTF8(unsigned (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,-1; bne 2f; lhz 0,0x0(3); mr 9,3; li 4,0; cmpwi 0,0; beq 1f; 0:; lhzu 0,0x2(9); addi 4,4,1; cmpwi 0,0; bne 0b; 1:; addi 4,4,1; 2:; cmpwi 4,0; blelr; mtspr 9,4; 3:; lhz 0,0x0(3); rlwinm 9,0,0,16,31; cmplwi 9,127; bgt 4f; lbz 0,0x1(3); stb 0,0x0(5); b 6f; 4:; cmplwi 9,2047; bgt 5f; rlwinm 0,0,26,27,31; ori 0,0,192; stb 0,0x0(5); lbz 9,0x1(3); rlwinm 9,9,0,26,31; ori 9,9,128; stbu 9,0x1(5); b 6f; 5:; rlwinm 0,0,20,28,31; ori 0,0,224; stb 0,0x0(5); lhz 9,0x0(3); rlwinm 9,9,26,26,31; ori 9,9,128; stbu 9,0x1(5); lbz 0,0x1(3); rlwinm 0,0,0,26,31; ori 0,0,128; stbu 0,0x1(5); 6:; addi 5,5,1; addi 3,3,2; bdnz 3b"
extern "C" void f_8000ACE4() {}
