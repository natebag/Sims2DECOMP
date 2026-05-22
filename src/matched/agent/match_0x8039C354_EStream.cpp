// 0x8039C354 EStream (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,3; mr 28,4; lwz 9,0x18(30); addi 4,1,8; lwz 31,0x4(28); li 5,4; lha 3,0x38(9); lwz 0,0x3c(9); add 3,30,3; stw 31,0x8(1); mtspr 8,0; blrl; cmpwi 31,0; ble 1f; li 29,0; 0:; lwz 9,0x18(30); addi 4,1,12; lwz 11,0x0(28); li 5,4; lha 3,0x38(9); lwz 9,0x3c(9); add 3,30,3; lwzx 0,11,29; mtspr 8,9; addi 29,29,4; stw 0,0xc(1); blrl; addic. 31,31,-1; bne 0b; 1:; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void f_8039C354() {}
