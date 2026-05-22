// 0x80276DB0 AptActionInterpreter::_FunctionAptActionDefineLocal2(AptActionInterpreter (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 31,4; lwz 9,0x0(30); lwz 0,0x8(30); rlwinm 9,9,2,0,29; add 9,9,0; lwz 11,-4(9); lwz 0,0x0(11); rlwinm 0,0,0,25,31; cmpwi 0,1; beq 0f; lwz 11,0x24(11); 0:; lwz 28,0x30(30); addi 29,11,12; cmpwi 28,0; beq 5f; lwz 3,-26960(13); cmpwi 3,0; bne 1f; lwz 3,0x2c(28); cmpwi 3,0; beq 2f; 1:; addi 3,3,12; mr 4,29; bl _s80276DB0_0; cmpwi 3,0; li 0,1; bne 3f; 2:; li 0,0; 3:; cmpwi 0,0; bne 6f; lwz 0,-26960(13); lwz 31,-22936(13); cmpwi 0,0; bne 4f; mr 3,28; bl _s80276DB0_1; 4:; lwz 3,-26960(13); mr 4,29; mr 5,31; addi 3,3,12; bl _s80276DB0_2; b 6f; 5:; lwz 4,0x4(31); li 9,0; lwz 5,0x8(31); mr 3,30; mr 6,29; li 7,0; li 8,1; bl _s80276DB0_3; lwz 0,0x0(3); andis. 9,0,2048; bne 6f; lwz 5,0x8(31); mr 6,29; lwz 4,0x4(31); mr 3,30; lwz 7,-22936(13); li 8,0; li 9,1; li 10,0; bl _s80276DB0_4; 6:; lwz 9,0x0(30); cmpwi 9,0; ble 7f; lwz 0,0x8(30); rlwinm 9,9,2,0,29; lis 4,-32704; lis 5,-32704; add 9,9,0; addi 4,4,5964; lwz 11,-4(9); addi 5,5,5812; li 6,160; lwz 9,0x8(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x0(30); addi 9,9,-1; stw 9,0x0(30); 7:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80276DB0_0();
extern "C" void _s80276DB0_1();
extern "C" void _s80276DB0_2();
extern "C" void _s80276DB0_3();
extern "C" void _s80276DB0_4();
extern "C" void f_80276DB0() {}
