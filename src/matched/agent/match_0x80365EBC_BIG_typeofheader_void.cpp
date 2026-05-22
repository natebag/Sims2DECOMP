// 0x80365EBC BIG_typeofheader(void (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 8,0x0(3); li 9,0; lbz 10,0x1(3); ori 9,9,49403; rlwinm 0,8,8,0,23; li 7,0; or 0,0,10; cmpw 0,9; bne 0f; li 7,1; b 2f; 0:; lbz 11,0x2(3); rlwinm 0,10,16,0,15; rlwinm 9,8,24,0,7; lbz 10,0x3(3); or 9,9,0; rlwinm 11,11,8,0,23; or 9,9,11; lis 0,16969; or 3,9,10; ori 0,0,18246; cmpw 3,0; bne 1f; li 7,2; b 2f; 1:; lis 0,16969; rlwinm 9,3,0,0,23; ori 0,0,18176; cmpw 9,0; bne 2f; li 7,3; 2:; mr 3,7"
extern "C" int f_80365EBC() {}
