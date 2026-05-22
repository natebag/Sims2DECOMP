// 0x8000ADA0 UTF8ToUCS2(char (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="add 0,3,4; cmplw 3,0; bgelr; mr 10,0; 0:; lbz 9,0x0(3); andi. 0,9,128; bne 1f; sth 9,0x0(5); addi 3,3,1; b 3f; 1:; rlwinm 0,9,0,24,26; cmpwi 0,192; bne 2f; lbz 0,0x1(3); rlwinm 9,9,6,21,25; addi 3,3,2; rlwinm 0,0,0,26,31; or 0,0,9; sth 0,0x0(5); b 3f; 2:; rlwinm 0,9,0,24,27; cmpwi 0,224; bne 4f; lbz 0,0x1(3); rlwinm 11,9,12,16,19; lbz 9,0x2(3); rlwinm 0,0,6,20,25; addi 3,3,3; or 11,11,0; rlwinm 9,9,0,26,31; or 9,9,11; sth 9,0x0(5); 3:; addi 5,5,2; 4:; cmplw 3,10; blt 0b"
extern "C" void f_8000ADA0() {}
