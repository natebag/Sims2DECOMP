// 0x8027465C AptActionInterpreter::_FunctionAptActionSubString(AptActionInterpreter (864 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 29,3; lwz 9,0x0(29); lwz 0,0x8(29); addi 11,9,-2; rlwinm 10,9,2,0,29; addi 9,9,-1; add 10,10,0; rlwinm 9,9,2,0,29; rlwinm 11,11,2,0,29; add 11,11,0; add 9,9,0; lwz 3,-4(10); lwz 30,-4(9); lwz 31,-4(11); bl _s8027465C_0; mr 27,3; mr 3,30; bl _s8027465C_1; addic. 28,3,-1; bge 0f; li 28,0; 0:; lis 11,-32700; mr 3,31; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); addi 4,1,8; addi 9,9,1; sth 9,-6476(11); bl _s8027465C_2; lwz 30,-26892(13); cmpwi 30,0; beq 4f; lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 1f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 2f; 1:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 2:; addi 31,30,12; mr 3,31; bl _s8027465C_3; cmpwi 3,0; bne 3f; mr 3,31; li 4,0; bl _s8027465C_4; 3:; mr 31,30; b 5f; 4:; lwz 3,-23020(13); li 4,20; bl _s8027465C_5; bl _s8027465C_6; mr 31,3; 5:; cmpwi 27,0; bne 7f; lwz 4,0xc(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 6f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027465C_7; 6:; lis 11,-32700; addi 0,11,-6476; stw 0,0xc(31); lhz 9,-6476(11); addi 9,9,1; sth 9,-6476(11); b 11f; 7:; bge 9f; addi 4,1,8; mr 5,28; addi 3,1,16; bl _s8027465C_8; lwz 11,0x10(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0xc(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 8f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027465C_9; 8:; lwz 0,0x10(1); stw 0,0xc(31); lwz 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 11f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027465C_10; b 11f; 9:; addi 4,1,8; mr 5,28; mr 6,27; addi 3,1,16; bl _s8027465C_11; lwz 11,0x10(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0xc(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 10f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027465C_12; 10:; lwz 0,0x10(1); stw 0,0xc(31); lwz 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 11f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027465C_13; 11:; lwz 0,0x0(29); lis 28,-32704; cmpwi 0,3; blt 13f; li 30,1; lis 27,-32704; 12:; lwz 11,0x0(29); addi 4,27,6004; lwz 8,0x8(29); addi 5,28,5812; subf 11,30,11; li 6,180; rlwinm 11,11,2,0,29; addi 30,30,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 30,3; ble 12b; lwz 9,0x0(29); addi 9,9,-3; stw 9,0x0(29); 13:; lwz 9,0x0(29); lis 4,-32704; lwz 10,0x8(29); lis 5,-32704; rlwinm 11,9,2,0,29; addi 4,4,5760; stwx 31,11,10; addi 9,9,1; stw 9,0x0(29); addi 5,5,5812; li 6,138; lwz 9,0x8(31); lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,31,3; blrl; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 14f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027465C_14; 14:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s8027465C_0();
extern "C" void _s8027465C_1();
extern "C" void _s8027465C_2();
extern "C" void _s8027465C_3();
extern "C" void _s8027465C_4();
extern "C" void _s8027465C_5();
extern "C" void _s8027465C_6();
extern "C" void _s8027465C_7();
extern "C" void _s8027465C_8();
extern "C" void _s8027465C_9();
extern "C" void _s8027465C_10();
extern "C" void _s8027465C_11();
extern "C" void _s8027465C_12();
extern "C" void _s8027465C_13();
extern "C" void _s8027465C_14();
extern "C" void f_8027465C() {}
