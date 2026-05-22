// 0x80041BE0 CollectInteractionsForObject(cXObject (800 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 22,0x28(1); stw 0,0x54(1); mr 28,4; mr 26,5; mr 27,6; mr. 30,3; beq 14f; cmpwi 26,0; beq 14f; mr 3,28; bl _s80041BE0_0; lwz 9,0x4(30); mr 23,3; lha 3,0x390(9); lwz 0,0x394(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 13f; lwz 9,0x4(30); lha 3,0x310(9); lwz 0,0x314(9); add 3,30,3; mtspr 8,0; blrl; mr 29,3; lha 24,0x10(29); lwz 9,0xc0(29); rlwinm 22,24,1,31,31; cmpwi 9,0; beq 0f; lbz 0,0x9(9); li 25,1; cmpwi 0,0; bne 1f; 0:; li 25,0; 1:; cmpwi 30,0; beq 2f; lwz 3,0x0(30); li 4,3; bl _s80041BE0_1; mr 31,3; b 3f; 2:; li 31,0; 3:; lwz 9,0x4(31); lha 3,0x40(9); lwz 0,0x44(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 7f; lwz 3,0x1c(29); cmpwi 3,1079; beq 7f; cmpwi 3,1081; beq 7f; cmpwi 25,0; bne 7f; lwz 9,0x4(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; mr. 31,3; beq 14f; 4:; lwz 11,0x0(31); lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lha 0,0x10(3); cmpwi 0,0; bge 6f; cmpwi 31,0; li 5,0; beq 5f; lwz 5,0x0(31); 5:; addi 3,1,8; mr 4,26; bl _s80041BE0_2; addi 3,1,8; mr 4,28; mr 5,27; bl _s80041BE0_3; mr 3,28; bl _s80041BE0_4; subf 3,23,3; cmpw 3,27; bge 12f; addi 3,1,8; li 4,2; bl _s80041BE0_5; 6:; lwz 9,0x4(31); lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; blrl; mr. 31,3; bne 4b; b 14f; 7:; cmpwi 22,0; beq 11f; lwz 9,0x4(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; mr. 31,3; beq 14f; srawi 0,24,31; xor 30,0,24; subf 30,0,30; 8:; lwz 11,0x0(31); lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lha 0,0x10(3); srawi 11,0,31; xor 9,11,0; subf 9,11,9; cmpw 9,30; bne 10f; lwz 11,0x0(31); lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lha 0,0x10(3); cmpwi 0,0; bge 10f; cmpwi 31,0; li 5,0; beq 9f; lwz 5,0x0(31); 9:; addi 3,1,8; mr 4,26; bl _s80041BE0_6; addi 3,1,8; mr 4,28; mr 5,27; bl _s80041BE0_7; mr 3,28; bl _s80041BE0_8; subf 3,23,3; cmpw 3,27; bge 12f; addi 3,1,8; li 4,2; bl _s80041BE0_9; 10:; lwz 9,0x4(31); lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; blrl; mr. 31,3; bne 8b; b 14f; 11:; mr 4,26; mr 5,30; addi 3,1,8; bl _s80041BE0_10; mr 4,28; addi 3,1,8; mr 5,27; bl _s80041BE0_11; 12:; addi 3,1,8; li 4,2; bl _s80041BE0_12; b 14f; 13:; mr 4,26; mr 5,30; addi 3,1,8; bl _s80041BE0_13; mr 4,28; addi 3,1,8; mr 5,27; bl _s80041BE0_14; addi 3,1,8; li 4,2; bl _s80041BE0_15; 14:; lwz 0,0x54(1); mtspr 8,0; lmw 22,0x28(1); addi 1,1,80"
extern "C" void _s80041BE0_0();
extern "C" void _s80041BE0_1();
extern "C" void _s80041BE0_2();
extern "C" void _s80041BE0_3();
extern "C" void _s80041BE0_4();
extern "C" void _s80041BE0_5();
extern "C" void _s80041BE0_6();
extern "C" void _s80041BE0_7();
extern "C" void _s80041BE0_8();
extern "C" void _s80041BE0_9();
extern "C" void _s80041BE0_10();
extern "C" void _s80041BE0_11();
extern "C" void _s80041BE0_12();
extern "C" void _s80041BE0_13();
extern "C" void _s80041BE0_14();
extern "C" void _s80041BE0_15();
extern "C" void f_80041BE0() {}
