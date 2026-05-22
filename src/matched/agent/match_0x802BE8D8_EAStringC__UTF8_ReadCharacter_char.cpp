// 0x802BE8D8 EAStringC::UTF8_ReadCharacter(char (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 9,0x0(3); mr 11,9; andi. 0,9,128; bne 0f; mr 10,9; addi 7,3,1; b 4f; 0:; rlwinm 0,9,0,24,26; cmpwi 0,192; bne 1f; lbz 0,0x1(3); rlwinm 10,9,6,21,25; addi 7,3,2; rlwinm 0,0,0,26,31; or 10,10,0; b 4f; 1:; rlwinm 0,9,0,24,27; cmpwi 0,224; bne 2f; lbz 0,0x1(3); rlwinm 10,9,12,16,19; lbz 8,0x2(3); addi 7,3,3; rlwinm 0,0,6,20,25; or 10,10,0; rlwinm 9,8,0,26,31; b 3f; 2:; lbz 0,0x1(3); rlwinm 10,11,18,11,13; lbz 8,0x2(3); addi 7,3,4; rlwinm 11,0,12,14,19; lbz 9,0x3(3); or 10,10,11; rlwinm 0,8,6,20,25; or 10,10,0; rlwinm 9,9,0,26,31; 3:; or 10,10,9; 4:; stw 10,0x0(4); mr 3,7"
extern "C" void f_802BE8D8() {}
