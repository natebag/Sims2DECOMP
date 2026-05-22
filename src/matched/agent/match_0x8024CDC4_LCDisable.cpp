// 0x8024CDC4 LCDisable (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-8192; li 4,512; mtspr 9,4; 0:; dcbi 0,3; addi 3,3,32; bdnz 0b; mfspr 4,920; rlwinm 4,4,0,4,2; mtspr 920,4"
extern "C" int f_8024CDC4() {}
