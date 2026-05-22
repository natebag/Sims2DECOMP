// 0x80187744 HUDTarget::GetPlayerLocalizable(int, (768 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 27,0x2c(1); stw 0,0x44(1); mr 31,3; mr 30,5; mr 28,4; li 3,8192; bl _s80187744_0; li 27,1; mr 29,3; li 0,0; lis 3,-32705; sth 0,0x0(29); addi 3,3,-19724; mr 4,30; bl _s80187744_1; cmpwi 3,0; bne 0f; add 0,28,28; addi 9,31,2220; lhax 5,9,0; lis 4,-32705; addi 4,4,-19956; addi 3,1,8; crxor 6,6,6; bl _s80187744_2; li 27,0; b 1f; 0:; lis 3,-32705; mr 4,30; addi 3,3,-19712; bl _s80187744_3; cmpwi 3,0; bne 2f; mr 4,28; mr 3,31; bl _s80187744_4; li 27,0; mr 5,3; lis 4,-32705; addi 4,4,-19956; addi 3,1,8; crxor 6,6,6; bl _s80187744_5; 1:; addi 3,1,8; bl _s80187744_6; addi 4,3,1; mr 5,29; addi 3,1,8; bl _s80187744_7; b 15f; 2:; lis 3,-32705; mr 4,30; addi 3,3,-20668; bl _s80187744_8; cmpwi 3,0; bne 4f; lwz 3,0xd0(31); cmpwi 3,0; beq 15f; addi 3,3,8; bl _s80187744_9; cmpwi 3,0; beq 15f; lwz 3,0xd0(31); addi 3,3,8; 3:; bl _s80187744_10; mr 4,3; b 9f; 4:; lis 3,-32705; mr 4,30; addi 3,3,-20640; bl _s80187744_11; cmpwi 3,0; bne 5f; lwz 3,0xd0(31); cmpwi 3,0; beq 15f; addi 3,3,4; bl _s80187744_12; cmpwi 3,0; beq 15f; lwz 3,0xd0(31); addi 3,3,4; b 3b; 5:; lis 3,-32705; mr 4,30; addi 3,3,-20612; bl _s80187744_13; cmpwi 3,0; bne 6f; lwz 3,0xd0(31); cmpwi 3,0; beq 15f; addi 3,3,12; bl _s80187744_14; cmpwi 3,0; beq 15f; lwz 3,0xd0(31); addi 3,3,12; b 3b; 6:; lis 3,-32705; mr 4,30; addi 3,3,-19688; bl _s80187744_15; cmpwi 3,0; bne 7f; mr 4,28; addi 3,1,24; crxor 6,6,6; bl _s80187744_16; lwz 9,0x18(1); b 8f; 7:; lis 3,-32705; mr 4,30; addi 3,3,-19668; bl _s80187744_17; cmpwi 3,0; bne 10f; mr 4,28; addi 3,1,28; crxor 6,6,6; bl _s80187744_18; lwz 9,0x1c(1); 8:; li 4,0; cmpwi 9,0; beq 9f; lwz 4,0x0(9); 9:; mr 3,29; bl _s80187744_19; b 15f; 10:; lis 3,-32705; mr 4,30; addi 3,3,-20584; bl _s80187744_20; cmpwi 3,0; bne 15f; lis 9,-32697; li 5,0; addi 3,9,24012; lwz 0,0x158(3); cmpwi 0,0; beq 11f; lwz 3,0x464(3); bl _s80187744_21; b 12f; 11:; lwz 3,0xc8(3); cmpwi 3,0; beq 13f; bl _s80187744_22; 12:; mr 5,3; 13:; cmpwi 5,0; beq 15f; lis 4,-32697; addi 3,1,32; addi 4,4,24012; crxor 6,6,6; bl _s80187744_23; lwz 9,0x20(1); li 4,0; cmpwi 9,0; beq 14f; lwz 4,0x0(9); 14:; cmpwi 4,0; beq 15f; mr 3,29; bl _s80187744_24; 15:; mr 3,29; bl _s80187744_25; cmpwi 27,0; beq 16f; mr 3,29; bl _s80187744_26; mr 3,29; bl _s80187744_27; 16:; mr 3,29; bl _s80187744_28; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s80187744_29; mr 30,3; mr 4,29; bl _s80187744_30; mr 3,29; bl _s80187744_31; mr 3,30; lwz 0,0x44(1); mtspr 8,0; lmw 27,0x2c(1); addi 1,1,64"
extern "C" void _s80187744_0();
extern "C" void _s80187744_1();
extern "C" void _s80187744_2();
extern "C" void _s80187744_3();
extern "C" void _s80187744_4();
extern "C" void _s80187744_5();
extern "C" void _s80187744_6();
extern "C" void _s80187744_7();
extern "C" void _s80187744_8();
extern "C" void _s80187744_9();
extern "C" void _s80187744_10();
extern "C" void _s80187744_11();
extern "C" void _s80187744_12();
extern "C" void _s80187744_13();
extern "C" void _s80187744_14();
extern "C" void _s80187744_15();
extern "C" void _s80187744_16();
extern "C" void _s80187744_17();
extern "C" void _s80187744_18();
extern "C" void _s80187744_19();
extern "C" void _s80187744_20();
extern "C" void _s80187744_21();
extern "C" void _s80187744_22();
extern "C" void _s80187744_23();
extern "C" void _s80187744_24();
extern "C" void _s80187744_25();
extern "C" void _s80187744_26();
extern "C" void _s80187744_27();
extern "C" void _s80187744_28();
extern "C" void _s80187744_29();
extern "C" void _s80187744_30();
extern "C" void _s80187744_31();
extern "C" void f_80187744() {}
