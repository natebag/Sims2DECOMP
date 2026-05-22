// 0x801DE85C RCPTarget::install_ing_shaders(void) (956 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 16,0x10(1); stw 0,0x54(1); mr 30,3; bl _s801DE85C_0; mr. 18,3; bne 0f; li 3,0; b 19f; 0:; lis 8,-32705; lis 10,-32705; lis 9,-32705; lis 11,-32705; lwz 7,0x134(30); addi 16,9,32456; addi 17,11,32216; addi 23,10,32720; addi 24,8,32600; li 22,0; 1:; lwz 0,0x128(30); cmplw 7,0; bge 11f; mulli 11,7,20; lwz 9,0x124(30); rlwinm 0,22,2,0,29; addi 19,7,1; add 27,0,16; li 26,0; addi 20,1,8; add 25,9,11; addi 21,1,12; add 28,0,17; 2:; lbzx 29,25,26; lis 31,-24685; ori 31,31,65396; cmpwi 29,0; beq 3f; lis 31,7141; ori 31,31,56265; 3:; lwz 0,0x0(30); lwz 4,0x0(27); cmpwi 0,0; beq 4f; lwz 3,0x1c(30); cmpwi 3,0; beq 4f; lwz 6,0x7c(30); mr 5,31; li 7,0; bl _s801DE85C_1; 4:; lis 31,-24685; cmpwi 29,0; ori 31,31,65396; beq 6f; lwz 0,0x8(25); cmpwi 0,0; beq 5f; lis 31,12002; ori 31,31,53994; b 6f; 5:; mr 4,29; mr 3,18; bl _s801DE85C_2; mr. 3,3; beq 6f; lwz 31,0x8(3); 6:; lwz 0,0x0(30); lwz 4,0x0(28); cmpwi 0,0; beq 7f; lwz 3,0x1c(30); cmpwi 3,0; beq 7f; lwz 6,0x7c(30); mr 5,31; li 7,0; bl _s801DE85C_3; 7:; addi 26,26,1; addi 28,28,4; addi 27,27,4; addi 22,22,1; cmplwi 26,3; ble 2b; mr 4,25; mr 5,20; mr 3,30; mr 6,21; bl _s801DE85C_4; lwz 0,0x0(30); lwz 4,0x0(24); lwz 5,0x8(1); addi 24,24,4; cmpwi 0,0; beq 8f; lwz 3,0x1c(30); cmpwi 3,0; beq 8f; lwz 6,0x7c(30); li 7,0; bl _s801DE85C_5; 8:; lwz 0,0x0(30); lwz 4,0x0(24); cmpwi 0,0; lwz 5,0xc(1); addi 24,24,4; beq 9f; lwz 3,0x1c(30); cmpwi 3,0; beq 9f; lwz 6,0x7c(30); li 7,0; bl _s801DE85C_6; 9:; mr 4,25; mr 5,20; mr 6,21; mr 3,30; bl _s801DE85C_7; lwz 0,0x0(30); lwz 4,0x0(23); lwz 5,0x8(1); addi 23,23,4; cmpwi 0,0; beq 10f; lwz 3,0x1c(30); cmpwi 3,0; beq 10f; lwz 6,0x7c(30); li 7,0; bl _s801DE85C_8; 10:; lwz 0,0x0(30); lwz 4,0x0(23); cmpwi 0,0; lwz 5,0xc(1); addi 23,23,4; beq 18f; lwz 3,0x1c(30); cmpwi 3,0; beq 18f; lwz 6,0x7c(30); li 7,0; bl _s801DE85C_9; b 18f; 11:; rlwinm 0,22,2,0,29; addi 19,7,1; add 29,0,16; li 26,0; add 31,0,17; 12:; lwz 0,0x0(30); lwz 4,0x0(29); cmpwi 0,0; addi 29,29,4; beq 13f; lwz 3,0x1c(30); cmpwi 3,0; beq 13f; lis 5,-24685; lwz 6,0x7c(30); ori 5,5,65396; li 7,0; bl _s801DE85C_10; 13:; lwz 0,0x0(30); lwz 4,0x0(31); cmpwi 0,0; beq 14f; lwz 3,0x1c(30); cmpwi 3,0; beq 14f; lis 5,-24685; lwz 6,0x7c(30); ori 5,5,65396; li 7,0; bl _s801DE85C_11; 14:; addi 26,26,1; addi 31,31,4; addi 22,22,1; cmplwi 26,3; ble 12b; lwz 0,0x0(30); lwz 4,0x0(24); cmpwi 0,0; addi 24,24,4; beq 15f; lwz 3,0x1c(30); cmpwi 3,0; beq 15f; lis 5,-24685; lwz 6,0x7c(30); ori 5,5,65396; li 7,0; bl _s801DE85C_12; 15:; lwz 0,0x0(30); lwz 4,0x0(24); cmpwi 0,0; addi 24,24,4; beq 16f; lwz 3,0x1c(30); cmpwi 3,0; beq 16f; lis 5,-24685; lwz 6,0x7c(30); ori 5,5,65396; li 7,0; bl _s801DE85C_13; 16:; lwz 0,0x0(30); lwz 4,0x0(23); cmpwi 0,0; addi 23,23,4; beq 17f; lwz 3,0x1c(30); cmpwi 3,0; beq 17f; lis 5,-24685; lwz 6,0x7c(30); ori 5,5,65396; li 7,0; bl _s801DE85C_14; 17:; lwz 0,0x0(30); lwz 4,0x0(23); cmpwi 0,0; addi 23,23,4; beq 18f; lwz 3,0x1c(30); cmpwi 3,0; beq 18f; lis 5,-24685; lwz 6,0x7c(30); ori 5,5,65396; li 7,0; bl _s801DE85C_15; 18:; mr 7,19; cmplwi 22,11; ble 1b; li 3,1; 19:; lwz 0,0x54(1); mtspr 8,0; lmw 16,0x10(1); addi 1,1,80"
extern "C" void _s801DE85C_0();
extern "C" void _s801DE85C_1();
extern "C" void _s801DE85C_2();
extern "C" void _s801DE85C_3();
extern "C" void _s801DE85C_4();
extern "C" void _s801DE85C_5();
extern "C" void _s801DE85C_6();
extern "C" void _s801DE85C_7();
extern "C" void _s801DE85C_8();
extern "C" void _s801DE85C_9();
extern "C" void _s801DE85C_10();
extern "C" void _s801DE85C_11();
extern "C" void _s801DE85C_12();
extern "C" void _s801DE85C_13();
extern "C" void _s801DE85C_14();
extern "C" void _s801DE85C_15();
extern "C" void f_801DE85C() {}
