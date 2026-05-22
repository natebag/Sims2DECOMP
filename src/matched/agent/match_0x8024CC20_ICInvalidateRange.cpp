// 0x8024CC20 ICInvalidateRange (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 4,0; blelr; rlwinm 5,3,0,27,31; add 4,4,5; addi 4,4,31; rlwinm 4,4,27,5,31; mtspr 9,4; 0:; icbi 0,3; addi 3,3,32; bdnz 0b; sync; isync"
extern "C" int f_8024CC20() {}
