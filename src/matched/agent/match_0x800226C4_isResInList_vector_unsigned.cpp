// 0x800226C4 isResInList(vector<unsigned (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); li 7,0; lwz 0,0x4(3); li 10,0; subf 0,9,0; srawi 8,0,2; cmpw 7,8; bge 2f; lwz 0,0x0(9); b 1f; 0:; addi 10,10,1; cmpw 10,8; bge 2f; lwz 9,0x0(3); rlwinm 11,10,2,0,29; lwzx 0,9,11; 1:; cmpw 0,4; bne 0b; li 7,1; 2:; mr 3,7"
extern "C" int f_800226C4() {}
