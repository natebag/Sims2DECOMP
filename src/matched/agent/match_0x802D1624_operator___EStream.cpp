// 0x802D1624 operator<<(EStream (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 29,4; mr 30,3; lwz 9,0x0(29); lha 3,0x10(9); lwz 0,0x14(9); add 3,29,3; mtspr 8,0; blrl; mr 31,3; 0:; lwz 9,0x18(30); addi 4,1,8; li 5,2; lhz 0,0x14(31); lha 3,0x38(9); lwz 9,0x3c(9); add 3,30,3; sth 0,0x8(1); mtspr 8,9; blrl; lwz 31,0x18(31); cmpwi 31,0; bne 0b; lwz 9,0x0(29); mr 4,30; lha 3,0x40(9); lwz 0,0x44(9); add 3,29,3; mtspr 8,0; blrl; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void f_802D1624() {}
