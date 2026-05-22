// 0x8039E8E4 void (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 28,3; lwz 0,0x0(5); subf 4,28,4; srawi 29,4,2; stw 0,0x8(1); cmpwi 29,1; ble 1f; addi 0,29,-2; rlwinm 9,0,1,31,31; add 0,0,9; srawi 31,0,1; rlwinm 9,31,2,0,29; add 30,9,28; 0:; lwz 0,0x8(1); mr 3,28; lwz 6,0x0(30); mr 4,31; mr 5,29; stw 0,0x10(1); addi 7,1,16; addi 30,30,-4; bl _s8039E8E4_0; cmpwi 31,0; beq 1f; addi 31,31,-1; b 0b; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s8039E8E4_0();
extern "C" void f_8039E8E4() {}
