// 0x80365D90 BIG_getm(void (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,1; bne 0f; lbz 3,0x0(3); blr; 0:; cmpwi 4,2; bne 1f; lbz 0,0x0(3); lbz 9,0x1(3); rlwinm 0,0,8,0,23; or 3,0,9; blr; 1:; cmpwi 4,3; bne 2f; lbz 0,0x0(3); lbz 9,0x1(3); rlwinm 0,0,16,0,15; lbz 11,0x2(3); rlwinm 9,9,8,0,23; or 0,0,9; or 3,0,11; blr; 2:; cmpwi 4,4; bne 3f; lbz 0,0x0(3); lbz 9,0x1(3); lbz 11,0x2(3); rlwinm 0,0,24,0,7; rlwinm 9,9,16,0,15; lbz 10,0x3(3); or 0,0,9; rlwinm 11,11,8,0,23; or 0,0,11; or 3,0,10; blr; 3:; li 3,0"
extern "C" int f_80365D90() {}
