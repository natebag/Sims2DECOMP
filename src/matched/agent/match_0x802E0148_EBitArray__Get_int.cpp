// 0x802E0148 EBitArray::Get(int, (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 5,5; beq 2f; add 0,4,5; srawi 10,4,5; mr 9,0; rlwinm 4,4,0,27,31; addi 0,9,-1; rlwinm 0,0,27,5,31; cmpw 10,0; bne 1f; li 0,1; slw 0,0,5; mtspr 9,0; bdz 0f; lwz 11,0x0(3); rlwinm 9,10,2,0,29; lwzx 0,9,11; mfspr 9,9; srw 0,0,4; and 3,0,9; blr; 0:; lwz 11,0x0(3); rlwinm 9,10,2,0,29; lwzx 3,9,11; blr; 1:; rlwinm 8,0,2,0,29; lwz 7,0x0(3); rlwinm 0,9,0,27,31; rlwinm 10,10,2,0,29; li 9,1; lwzx 11,8,7; slw 9,9,0; lwzx 3,10,7; addi 9,9,-1; subfic 0,4,32; and 11,11,9; srw 3,3,4; slw 11,11,0; or 3,11,3; blr; 2:; li 3,0"
extern "C" int f_802E0148() {}
