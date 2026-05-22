// 0x80258B04 SIIsChanBusy (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 4,-32694; rlwinm 5,3,5,0,26; addi 0,4,-21872; add 4,0,5; lwz 0,0x0(4); li 5,1; cmpwi 0,-1; bne 0f; lis 4,-32700; lwz 0,-15972(4); cmpw 0,3; beq 0f; li 5,0; 0:; mr 3,5"
extern "C" int f_80258B04() {}
