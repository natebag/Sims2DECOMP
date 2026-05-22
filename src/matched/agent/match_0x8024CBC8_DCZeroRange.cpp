// 0x8024CBC8 DCZeroRange (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 4,0; blelr; rlwinm 5,3,0,27,31; add 4,4,5; addi 4,4,31; rlwinm 4,4,27,5,31; mtspr 9,4; 0:; dcbz 0,3; addi 3,3,32; bdnz 0b"
extern "C" int f_8024CBC8() {}
