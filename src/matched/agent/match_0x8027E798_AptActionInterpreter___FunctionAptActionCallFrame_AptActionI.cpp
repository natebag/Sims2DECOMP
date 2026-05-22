// 0x8027E798 AptActionInterpreter::_FunctionAptActionCallFrame(AptActionInterpreter (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,3; mr 30,4; lwz 9,0x0(31); li 29,-1; lwz 0,0x8(31); li 11,0; rlwinm 9,9,2,0,29; add 9,9,0; lwz 3,-4(9); lwz 9,0x0(3); rlwinm 0,9,0,25,31; cmpwi 0,1; beq 0f; cmpwi 0,42; bne 1f; 0:; andis. 0,9,2048; beq 1f; li 11,1; 1:; cmpwi 11,0; beq 3f; lis 11,-32700; mr 5,3; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); addi 9,9,1; sth 9,-6476(11); lwz 0,0x0(3); lwz 9,0x4(30); rlwinm 0,0,0,25,31; lwz 4,0x8(30); cmpwi 0,1; beq 2f; lwz 5,0x24(3); 2:; addi 5,5,12; mr 3,9; addi 6,1,16; addi 7,1,8; bl _s8027E798_0; lwz 11,0x10(1); addi 4,1,8; lwz 9,0x4c(11); lwz 3,0x8(9); addi 3,3,8; bl _s8027E798_1; lwz 4,0x8(1); mr 29,3; lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 5f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027E798_2; b 5f; 3:; lwz 9,0x0(3); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,7; bne 4f; rlwinm 11,9,5,31,31; 4:; cmpwi 11,0; beq 5f; bl _s8027E798_3; mr 29,3; 5:; lwz 9,0x0(31); cmpwi 9,0; ble 6f; lwz 0,0x8(31); rlwinm 9,9,2,0,29; lis 4,-32704; lis 5,-32704; add 9,9,0; addi 4,4,5964; lwz 11,-4(9); addi 5,5,5812; li 6,160; lwz 9,0x8(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x0(31); addi 9,9,-1; stw 9,0x0(31); 6:; cmpwi 29,-1; beq 7f; lwz 4,0x4(30); mr 5,29; lwz 9,0x4c(4); lwz 3,0x8(9); addi 3,3,8; bl _s8027E798_4; 7:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s8027E798_0();
extern "C" void _s8027E798_1();
extern "C" void _s8027E798_2();
extern "C" void _s8027E798_3();
extern "C" void _s8027E798_4();
extern "C" void f_8027E798() {}
