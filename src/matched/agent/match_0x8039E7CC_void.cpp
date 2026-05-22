// 0x8039E7CC void (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); mr 30,4; mr 28,5; mr 26,30; mr 29,3; add 9,26,26; mr 25,6; addi 31,9,2; mr 27,7; cmpw 31,28; bge 2f; 0:; rlwinm 0,31,2,0,29; mr 3,27; add 9,0,29; lwzx 4,29,0; lwz 5,-4(9); bl _s8039E7CC_0; cmpwi 3,0; beq 1f; addi 31,31,-1; 1:; rlwinm 10,30,2,0,29; rlwinm 9,31,2,0,29; mr 30,31; lwzx 11,9,29; addi 0,30,1; add 31,0,0; stwx 11,10,29; cmpw 31,28; blt 0b; 2:; cmpw 31,28; bne 3f; rlwinm 9,31,2,0,29; rlwinm 11,30,2,0,29; add 9,9,29; addi 30,31,-1; lwz 0,-4(9); stwx 0,11,29; 3:; addi 9,30,-1; lwz 0,0x0(27); rlwinm 11,9,1,31,31; add 9,9,11; stw 0,0x8(1); b 5f; 4:; rlwinm 10,30,2,0,29; lwzx 11,31,29; mr 30,28; addi 9,30,-1; stwx 11,10,29; rlwinm 0,9,1,31,31; add 9,9,0; 5:; srawi 28,9,1; cmpw 30,26; ble 6f; rlwinm 31,28,2,0,29; addi 3,1,8; lwzx 4,31,29; mr 5,25; bl _s8039E7CC_1; cmpwi 3,0; bne 4b; 6:; rlwinm 0,30,2,0,29; stwx 25,29,0; lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"
extern "C" void _s8039E7CC_0();
extern "C" void _s8039E7CC_1();
extern "C" void f_8039E7CC() {}
