// 0x801AA0A0 CSPTarget::InstallPromotionShaders(void) (360 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 31,3; lis 9,-32701; lis 11,-32705; addi 26,9,29208; addi 25,11,27320; li 29,0; addi 30,31,204; li 28,0; li 27,3; 0:; addi 9,31,180; lwzx 0,9,28; cmpwi 7,0,0; bge cr7,1f; bl _s801AA0A0_0; lwz 0,0x0(31); mr 5,3; lwzx 4,28,26; cmpwi 0,0; beq 13f; lwz 3,0x1c(31); cmpwi 3,0; beq 13f; lwz 6,0x7c(31); li 7,0; bl _s801AA0A0_1; b 13f; 1:; cmpwi 0,3; beq 6f; bgt 2f; cmpwi 0,1; beq 4f; bgt 5f; beq cr7,3f; b 12f; 2:; cmpwi 0,5; beq 8f; blt 7f; cmpwi 0,6; beq 9f; cmpwi 0,7; beq 10f; b 12f; 3:; li 29,0; b 12f; 4:; lwz 0,0xe0(31); li 29,1; b 11f; 5:; lwz 0,0xe4(31); li 29,2; b 11f; 6:; lwz 0,0xe8(31); li 29,3; b 11f; 7:; lwz 0,0xec(31); li 29,4; b 11f; 8:; lwz 0,0xf0(31); li 29,5; b 11f; 9:; lwz 0,0xf4(31); li 29,6; b 11f; 10:; lwz 0,0xf8(31); li 29,7; 11:; stw 0,0x0(30); 12:; lwz 9,0x0(31); rlwinm 0,29,2,0,29; lwzx 5,25,0; cmpwi 9,0; lwzx 4,28,26; beq 13f; lwz 3,0x1c(31); cmpwi 3,0; beq 13f; lwz 6,0x7c(31); li 7,0; bl _s801AA0A0_2; 13:; addi 30,30,4; addi 28,28,4; addic. 27,27,-1; bne 0b; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s801AA0A0_0();
extern "C" void _s801AA0A0_1();
extern "C" void _s801AA0A0_2();
extern "C" void f_801AA0A0() {}
