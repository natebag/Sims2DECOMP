// 0x8026BAB4 AptUpdateZombieVector(bool) (488 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 22,0x10(1); stw 0,0x3c(1); lwz 0,-27596(13); mr 23,3; mr 30,0; cmpwi 0,0; beq 8f; lwz 0,0x4(30); addic. 27,0,-1; blt 8f; cmpw 0,27; ble 8f; rlwinm 9,27,2,0,29; li 24,0; mr 26,9; li 22,4; addi 25,9,4; 0:; lwz 3,0x8(30); lwzx 31,26,3; lwz 0,0x5c(31); rlwinm 0,0,20,30,31; cmpwi 0,1; bne 7f; cmpwi 23,0; bne 1f; lhz 0,0x5c(31); cmpwi 0,0; bne 7f; 1:; lwz 9,0x4(30); lwz 29,0x4c(31); addi 5,9,-1; stw 5,0x4(30); cmpwi 5,0; beq 2f; cmpw 27,5; beq 2f; subf 5,27,5; add 4,3,25; rlwinm 5,5,2,0,29; add 3,3,26; bl _s8026BAB4_0; 2:; lwz 9,0x4(30); addi 28,29,52; lwz 11,0x8(30); rlwinm 9,9,2,0,29; addi 30,1,8; stwx 24,9,11; cmpw 30,28; lwz 0,0x5c(31); rlwimi 0,24,12,18,19; stw 0,0x5c(31); lwz 9,0x34(29); stw 22,0x8(9); stw 24,0x8(1); beq 4f; lwz 3,0x34(29); cmpwi 3,0; beq 3f; bl _s8026BAB4_1; cmpwi 3,0; bne 3f; lwz 3,0x34(29); bl _s8026BAB4_2; 3:; lwz 3,0x0(30); stw 3,0x0(28); cmpwi 3,0; beq 4f; bl _s8026BAB4_3; 4:; lwz 3,0x8(1); cmpwi 3,0; beq 5f; bl _s8026BAB4_4; cmpwi 3,0; bne 5f; lwz 3,0x8(1); bl _s8026BAB4_5; 5:; lwz 0,0x0(31); li 30,0; lwz 11,0x4c(31); rlwimi 0,30,8,18,23; stw 0,0x0(31); lwz 9,0x14(11); lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x4c(31); lwz 9,0x14(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; lwz 11,0x4c(31); cmpwi 11,0; beq 6f; lwz 9,0x14(11); li 4,3; lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 6:; stw 30,0x4c(31); bl _s8026BAB4_6; 7:; addi 25,25,-4; addi 26,26,-4; addic. 27,27,-1; blt 8f; lwz 9,-27596(13); lwz 0,0x4(9); mr 30,9; cmpw 0,27; bgt 0b; 8:; lwz 0,0x3c(1); mtspr 8,0; lmw 22,0x10(1); addi 1,1,56"
extern "C" void _s8026BAB4_0();
extern "C" void _s8026BAB4_1();
extern "C" void _s8026BAB4_2();
extern "C" void _s8026BAB4_3();
extern "C" void _s8026BAB4_4();
extern "C" void _s8026BAB4_5();
extern "C" void _s8026BAB4_6();
extern "C" void f_8026BAB4() {}
