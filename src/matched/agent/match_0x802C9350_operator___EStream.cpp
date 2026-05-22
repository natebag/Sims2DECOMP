// 0x802C9350 operator<<(EStream (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 29,3; mr 26,4; li 9,0; addi 27,1,8; 0:; rlwinm 0,9,4,0,27; addi 28,9,1; add 31,0,26; li 30,4; 1:; lwz 9,0x18(29); mr 4,27; li 5,4; lfs f0,0x0(31); lha 3,0x38(9); addi 31,31,4; lwz 0,0x3c(9); add 3,29,3; stfs f0,0x8(1); mtspr 8,0; blrl; addic. 30,30,-1; bne 1b; mr 9,28; cmpwi 9,3; ble 0b; mr 3,29; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void f_802C9350() {}
