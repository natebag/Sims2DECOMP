// 0x8024037C DvdCallback (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32694; addi 3,3,31; lwz 0,-26360(9); rlwinm 8,3,0,0,26; cmpw 8,0; bne 0f; lis 10,-32694; lis 11,-32694; lwz 0,-26364(10); li 9,0; lis 3,-32694; stw 9,-26368(11); add 0,0,8; addi 3,3,-26400; stw 0,-26364(10); bl _s8024037C_0; b 1f; 0:; lis 0,3; lis 10,-32694; li 9,-1; lis 11,-32694; ori 0,0,4352; stw 9,-26364(10); stw 0,-26368(11); bl _s8024037C_1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8024037C_0();
extern "C" void _s8024037C_1();
extern "C" void f_8024037C() {}
