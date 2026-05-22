// 0x802B0838 AptValue::toString(char (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); lis 11,-32700; mr 30,4; lhz 9,-6476(11); addi 0,11,-6476; addi 4,1,8; stw 0,0x8(1); addi 9,9,1; sth 9,-6476(11); bl _s802B0838_0; lwz 4,0x8(1); mr 3,30; addi 4,4,8; bl _s802B0838_1; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802B0838_2; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s802B0838_0();
extern "C" void _s802B0838_1();
extern "C" void _s802B0838_2();
extern "C" void f_802B0838() {}
