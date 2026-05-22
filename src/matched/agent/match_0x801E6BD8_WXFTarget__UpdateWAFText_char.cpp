// 0x801E6BD8 WXFTarget::UpdateWAFText(char (536 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 28,0x28(1); stw 0,0x3c(1); mr 29,3; mr 30,4; addi 3,1,8; bl _s801E6BD8_0; lwz 0,0x8c(29); cmpwi 0,0; bne 0f; lis 4,-32705; addi 3,1,8; addi 4,4,26240; li 5,1; li 6,0; bl _s801E6BD8_1; b 1f; 0:; lis 4,-32705; addi 3,1,8; addi 4,4,26240; li 5,0; li 6,0; bl _s801E6BD8_2; 1:; lis 4,-32705; mr 3,30; addi 4,4,26192; li 31,0; bl _s801E6BD8_3; cmpwi 3,0; beq 7f; lis 4,-32705; mr 3,30; addi 4,4,26208; bl _s801E6BD8_4; cmpwi 3,0; bne 2f; li 31,1; b 7f; 2:; lis 4,-32705; mr 3,30; addi 4,4,26224; bl _s801E6BD8_5; cmpwi 3,0; bne 3f; li 31,2; b 7f; 3:; lis 4,-32705; mr 3,30; addi 4,4,26240; bl _s801E6BD8_6; cmpwi 3,0; bne 4f; li 31,3; b 7f; 4:; lis 4,-32705; mr 3,30; addi 4,4,26256; bl _s801E6BD8_7; cmpwi 3,0; bne 5f; li 31,4; b 7f; 5:; lis 4,-32705; mr 3,30; addi 4,4,26280; bl _s801E6BD8_8; cmpwi 3,0; bne 6f; li 31,5; b 7f; 6:; lis 4,-32705; mr 3,30; addi 4,4,26304; bl _s801E6BD8_9; cmpwi 3,0; bne 7f; li 31,6; 7:; lwz 0,0x94(29); lis 9,-32697; addi 9,9,24012; lwz 29,-21476(13); rlwinm 0,0,2,0,29; addi 9,9,188; lwzx 11,9,0; addi 28,1,32; lwz 30,0x0(29); lwz 9,0x4(11); lha 0,0xb8(30); lha 3,0x1b0(9); addi 30,30,184; lwz 9,0x1b4(9); add 29,29,0; add 3,11,3; mtspr 8,9; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr 29,3; rlwinm 0,31,2,0,29; addi 9,29,408; mr 3,28; lwzx 30,9,0; bl _s801E6BD8_10; mr 5,29; li 6,0; mr 4,28; mr 3,30; bl _s801E6BD8_11; mr 3,28; bl _s801E6BD8_12; mr 30,3; bl _s801E6BD8_13; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801E6BD8_14; mr 29,3; mr 4,30; bl _s801E6BD8_15; mr 3,28; li 4,2; bl _s801E6BD8_16; addi 3,1,8; li 4,2; bl _s801E6BD8_17; mr 3,29; lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x28(1); addi 1,1,56"
extern "C" void _s801E6BD8_0();
extern "C" void _s801E6BD8_1();
extern "C" void _s801E6BD8_2();
extern "C" void _s801E6BD8_3();
extern "C" void _s801E6BD8_4();
extern "C" void _s801E6BD8_5();
extern "C" void _s801E6BD8_6();
extern "C" void _s801E6BD8_7();
extern "C" void _s801E6BD8_8();
extern "C" void _s801E6BD8_9();
extern "C" void _s801E6BD8_10();
extern "C" void _s801E6BD8_11();
extern "C" void _s801E6BD8_12();
extern "C" void _s801E6BD8_13();
extern "C" void _s801E6BD8_14();
extern "C" void _s801E6BD8_15();
extern "C" void _s801E6BD8_16();
extern "C" void _s801E6BD8_17();
extern "C" void f_801E6BD8() {}
