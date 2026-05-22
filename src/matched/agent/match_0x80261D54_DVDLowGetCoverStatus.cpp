// 0x80261D54 DVDLowGetCoverStatus (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s80261D54_0; lis 5,-32768; lwz 7,-23344(13); lwz 6,0xf8(5); lis 5,4194; addi 5,5,19923; lwz 8,-23340(13); rlwinm 6,6,30,2,31; mulhwu 5,5,6; rlwinm 5,5,26,6,31; mulli 5,5,100; subfc 6,8,4; subfe 3,7,3; li 0,0; xoris 4,3,32768; xoris 3,0,32768; subfc 0,5,6; subfe 3,3,4; subfe 3,4,4; neg. 3,3; beq 0f; li 3,0; b 2f; 0:; lis 3,-13312; lwz 0,0x6004(3); rlwinm. 0,0,0,31,31; beq 1f; li 3,1; b 2f; 1:; li 3,2; 2:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80261D54_0();
extern "C" void f_80261D54() {}
