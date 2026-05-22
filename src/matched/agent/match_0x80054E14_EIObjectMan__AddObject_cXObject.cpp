// 0x80054E14 EIObjectMan::AddObject(cXObject (480 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 28,4; mr 29,5; bl _s80054E14_0; mr. 31,3; beq 6f; lwz 4,0x0(30); addi 3,30,4; mr 5,31; li 6,0; addi 0,4,1; stw 0,0x0(30); bl _s80054E14_1; cmpwi 3,0; bne 0f; lwz 9,0x0(31); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; li 3,0; b 7f; 0:; cmpwi 29,0; beq 6f; lwz 9,0x118(31); li 11,0; cmpwi 9,0; beq 1f; lwz 0,0x8(9); andi. 9,0,8192; beq 1f; li 11,1; 1:; cmpwi 11,0; bne 2f; mr 3,29; mr 4,31; li 5,0; bl _s80054E14_2; b 3f; 2:; mr 3,29; mr 4,31; bl _s80054E14_3; 3:; lwz 9,0x0(31); mr 4,29; lwz 0,0x18c(9); lha 3,0x188(9); mtspr 8,0; add 3,31,3; blrl; mr 3,31; bl _s80054E14_4; lwz 9,0x4(3); lha 0,0x4b0(9); lwz 9,0x4b4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 4f; lis 9,-32763; lis 11,-32763; addi 9,9,-6384; addi 11,11,-6496; stw 9,0x1c(31); stw 11,0x20(31); stw 28,0x28(31); stw 31,0x24(31); 4:; lis 9,-32763; stw 28,0x2c(31); addi 9,9,-6252; mr 3,31; stw 9,0x30(31); bl _s80054E14_5; lwz 9,0x4(3); lha 0,0x48(9); lwz 9,0x4c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 6f; lwz 0,0x14(31); cmpwi 0,0; bne 5f; li 0,1; stw 0,0x14(31); 5:; li 3,216; bl _s80054E14_6; bl _s80054E14_7; mr 0,3; li 5,0; stw 0,0x3bc(31); mr 4,31; bl _s80054E14_8; lwz 4,0x3bc(31); mr 3,29; bl _s80054E14_9; li 3,216; bl _s80054E14_10; bl _s80054E14_11; mr 0,3; mr 4,31; stw 0,0x3c0(31); li 5,1; bl _s80054E14_12; lwz 4,0x3c0(31); mr 3,29; bl _s80054E14_13; 6:; mr 3,31; 7:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80054E14_0();
extern "C" void _s80054E14_1();
extern "C" void _s80054E14_2();
extern "C" void _s80054E14_3();
extern "C" void _s80054E14_4();
extern "C" void _s80054E14_5();
extern "C" void _s80054E14_6();
extern "C" void _s80054E14_7();
extern "C" void _s80054E14_8();
extern "C" void _s80054E14_9();
extern "C" void _s80054E14_10();
extern "C" void _s80054E14_11();
extern "C" void _s80054E14_12();
extern "C" void _s80054E14_13();
extern "C" void f_80054E14() {}
