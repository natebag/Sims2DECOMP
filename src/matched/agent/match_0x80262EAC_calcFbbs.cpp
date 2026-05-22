// 0x80262EAC calcFbbs (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 6,6,5,19,26; rlwinm 0,5,0,16,31; mullw 0,6,0; rlwinm 4,4,1,15,26; add 0,4,0; add 0,3,0; cmpwi 7,0; stw 0,0x0(9); bne 0f; lwz 0,0x0(9); b 1f; 0:; lwz 0,0x0(9); add 0,0,6; 1:; rlwinm 3,8,0,16,31; stw 0,0x0(10); srawi 0,3,1; addze 0,0; rlwinm 0,0,1,0,30; subfc 0,0,3; cmpwi 0,1; bne 2f; lwz 3,0x0(9); lwz 0,0x0(10); stw 0,0x0(9); stw 3,0x0(10); 2:; lwz 0,0x0(9); rlwinm 0,0,0,2,31; stw 0,0x0(9); lwz 0,0x0(10); rlwinm 0,0,0,2,31; stw 0,0x0(10)"
extern "C" void f_80262EAC() {}
