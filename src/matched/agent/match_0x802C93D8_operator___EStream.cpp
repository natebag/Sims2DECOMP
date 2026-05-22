// 0x802C93D8 operator>>(EStream (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 27,4; li 9,0; 0:; rlwinm 0,9,4,0,27; addi 28,9,1; add 31,0,27; li 30,4; 1:; lwz 9,0x18(29); mr 4,31; li 5,4; addi 31,31,4; lha 3,0x30(9); lwz 0,0x34(9); add 3,29,3; mtspr 8,0; blrl; addic. 30,30,-1; bne 1b; mr 9,28; cmpwi 9,3; ble 0b; mr 3,29; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void f_802C93D8() {}
