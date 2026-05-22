// 0x802D16C0 operator>>(EStream (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 29,4; mr 30,3; lwz 9,0x0(29); addi 28,1,8; lha 3,0x10(9); lwz 0,0x14(9); add 3,29,3; mtspr 8,0; blrl; mr 31,3; 0:; lwz 9,0x18(30); mr 4,28; li 5,2; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; lhz 0,0x8(1); sth 0,0x16(31); lwz 31,0x18(31); cmpwi 31,0; bne 0b; lwz 9,0x0(29); mr 4,30; lha 3,0x38(9); lwz 0,0x3c(9); add 3,29,3; mtspr 8,0; blrl; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void f_802D16C0() {}
