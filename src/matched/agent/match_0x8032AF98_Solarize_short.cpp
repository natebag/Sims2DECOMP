// 0x8032AF98 Solarize(short (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mullw. 0,5,6; mtspr 9,0; blelr; li 6,0; 0:; lhax 0,6,3; lha 8,0x4(7); rlwinm 11,0,0,27,31; rlwinm 10,0,22,27,31; rlwinm 9,0,27,27,31; cmpw 11,8; blt 1f; not 11,11; 1:; cmpw 9,8; blt 2f; not 9,9; 2:; cmpw 10,8; blt 3f; not 10,10; 3:; rlwinm 0,10,10,17,21; rlwinm 9,9,5,22,26; or 0,0,9; rlwinm 11,11,0,27,31; or 0,0,11; sthx 0,6,4; addi 6,6,2; bdnz 0b"
extern "C" void f_8032AF98() {}
