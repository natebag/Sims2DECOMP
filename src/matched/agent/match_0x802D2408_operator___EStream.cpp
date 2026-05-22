// 0x802D2408 operator<<(EStream (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 30,3; mr 29,4; lwz 9,0x18(30); addi 4,1,8; li 5,4; lfs f0,0x0(29); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; stfs f0,0x8(1); add 3,30,3; blrl; lwz 9,0x18(30); addi 4,1,12; li 5,4; lfs f0,0x4(29); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; stfs f0,0xc(1); add 3,30,3; blrl; lwz 9,0x18(30); addi 4,1,16; li 5,4; lfs f0,0x8(29); lha 3,0x38(9); lwz 0,0x3c(9); add 3,30,3; stfs f0,0x10(1); mtspr 8,0; blrl; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void f_802D2408() {}
