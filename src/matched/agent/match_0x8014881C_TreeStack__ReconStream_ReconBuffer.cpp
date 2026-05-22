// 0x8014881C TreeStack::ReconStream(ReconBuffer (864 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-128(1); mfspr 0,8; stmw 21,0x54(1); stw 0,0x84(1); mr 21,5; mr 26,3; mr 27,4; mr 22,6; cmpwi 21,10; ble 19f; cmpwi 21,24; bgt 2f; mr 3,27; addi 4,1,8; li 5,1; li 30,0; bl _s8014881C_0; lha 0,0x8(1); cmpw 30,0; bge 19f; addi 31,1,16; addi 29,1,48; li 25,0; li 28,4; 0:; addi 4,1,40; li 5,1; mr 3,27; bl _s8014881C_1; lha 4,0x28(1); mr 3,31; bl _s8014881C_2; addi 4,1,18; mr 3,27; li 5,1; bl _s8014881C_3; addi 4,1,20; mr 3,27; li 5,1; bl _s8014881C_4; addi 4,1,24; mr 3,27; li 5,1; bl _s8014881C_5; addi 4,1,42; mr 3,27; li 5,1; bl _s8014881C_6; mr 3,27; mr 4,29; li 5,4; bl _s8014881C_7; lwz 9,0x0(22); addi 4,31,16; mr 5,27; mr 6,21; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,22,3; blrl; lwz 0,0xc(27); stb 25,0x16(1); cmpwi 0,0; stb 28,0x17(1); bne 1f; mr 3,26; mr 4,31; mr 5,29; bl _s8014881C_8; 1:; lha 0,0x8(1); addi 30,30,1; cmpw 30,0; blt 0b; b 19f; 2:; mr 3,26; bl _s8014881C_9; stw 3,0x38(1); addi 4,1,56; mr 3,27; li 5,1; bl _s8014881C_10; lwz 0,0xc(27); cmpwi 0,0; beq 3f; mr 3,26; bl _s8014881C_11; stw 3,0x3c(1); 3:; mr 3,27; addi 4,1,60; li 5,1; bl _s8014881C_12; lwz 0,0xc(27); cmpwi 0,0; bne 4f; bl _s8014881C_13; lwz 4,0x3c(1); li 5,0; bl _s8014881C_14; lwz 0,0x3c(1); lwz 9,0x8(26); add 0,3,0; stw 3,0x0(26); stw 0,0x4(26); stw 9,0xc(26); 4:; lwz 0,0x38(1); li 23,0; cmpw 23,0; bge 18f; 5:; lwz 0,0xc(27); addi 25,23,1; cmpwi 0,0; bne 17f; mr 3,26; addi 31,26,8; bl _s8014881C_15; lwz 30,0x4(31); addi 24,1,64; lwz 0,0xc(31); stw 3,0x40(1); cmpw 30,0; beq 6f; stw 3,0x0(30); lwz 9,0x4(31); addi 9,9,4; stw 9,0x4(31); b 17f; 6:; lwz 0,0x8(26); li 9,1; stw 9,0x48(1); addi 10,1,72; subf 0,0,30; addi 11,1,68; srawi 9,0,2; stw 9,0x44(1); cmplwi 9,1; bge 7f; mr 11,10; 7:; lwz 0,0x0(11); add. 0,9,0; beq 9f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 8f; mr 3,28; bl _s8014881C_16; mr 29,3; b 10f; 8:; mr 3,28; bl _s8014881C_17; mr 29,3; b 10f; 9:; li 29,0; li 28,0; 10:; lwz 4,0x0(31); cmpw 30,4; beq 11f; subf 30,4,30; mr 3,29; mr 5,30; bl _s8014881C_18; add 0,3,30; b 12f; 11:; mr 0,29; 12:; lwz 9,0x48(1); mr 30,0; addi 25,23,1; mtspr 9,9; cmpwi 9,0; beq 14f; 13:; lwz 0,0x0(24); stw 0,0x0(30); addi 30,30,4; bdnz 13b; 14:; lwz 3,0x0(31); lwz 0,0xc(31); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 16f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 15f; bl _s8014881C_19; b 16f; 15:; bl _s8014881C_20; 16:; add 0,28,29; stw 29,0x0(31); stw 0,0xc(31); stw 30,0x4(31); 17:; mr 4,23; mr 3,26; bl _s8014881C_21; mr 23,25; mr 4,27; mr 5,21; mr 6,22; bl _s8014881C_22; lwz 0,0x38(1); cmpw 23,0; blt 5b; 18:; mr 3,26; bl _s8014881C_23; cmpwi 3,0; beq 19f; mr 3,26; bl _s8014881C_24; addi 4,3,-1; mr 3,26; bl _s8014881C_25; bl _s8014881C_26; 19:; lwz 0,0x84(1); mtspr 8,0; lmw 21,0x54(1); addi 1,1,128"
extern "C" void _s8014881C_0();
extern "C" void _s8014881C_1();
extern "C" void _s8014881C_2();
extern "C" void _s8014881C_3();
extern "C" void _s8014881C_4();
extern "C" void _s8014881C_5();
extern "C" void _s8014881C_6();
extern "C" void _s8014881C_7();
extern "C" void _s8014881C_8();
extern "C" void _s8014881C_9();
extern "C" void _s8014881C_10();
extern "C" void _s8014881C_11();
extern "C" void _s8014881C_12();
extern "C" void _s8014881C_13();
extern "C" void _s8014881C_14();
extern "C" void _s8014881C_15();
extern "C" void _s8014881C_16();
extern "C" void _s8014881C_17();
extern "C" void _s8014881C_18();
extern "C" void _s8014881C_19();
extern "C" void _s8014881C_20();
extern "C" void _s8014881C_21();
extern "C" void _s8014881C_22();
extern "C" void _s8014881C_23();
extern "C" void _s8014881C_24();
extern "C" void _s8014881C_25();
extern "C" void _s8014881C_26();
extern "C" void f_8014881C() {}
