// 0x801FAE34 MSGTarget::SetVariable(char (744 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 30,4; mr 31,3; lbz 9,0x0(30); mr 29,5; addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 30,30,1; 0:; lis 3,-32704; mr 4,30; addi 3,3,-21348; bl _s801FAE34_0; cmpwi 3,0; bne 9f; mr 3,29; li 23,0; bl _s801FAE34_1; li 25,0; lwz 0,0x98(31); rlwinm 3,3,1,0,30; lis 9,-32700; mulli 0,0,40; addi 9,9,-25200; add 3,3,0; lhzx 4,9,3; ori 4,4,32768; sthx 4,9,3; lwz 0,0x98(31); cmpwi 0,0; bne 1f; lis 9,-32704; addi 24,9,-21516; b 2f; 1:; lis 9,-32704; addi 24,9,-21504; 2:; cmpwi 4,0; beq 7f; rlwinm 4,4,0,24,31; cmpwi 4,0; beq 7f; lis 3,-32697; li 26,0; addi 3,3,24012; bl _s801FAE34_2; mr. 27,3; beq 7f; lwz 9,0x4(27); addi 3,31,148; li 4,0; cmpwi 9,0; beq 3f; lwz 4,0x0(9); 3:; bl _s801FAE34_3; lwz 0,0xc(27); cmpwi 0,0; beq 4f; lwz 11,-21508(13); mr 26,0; lwz 28,0x0(26); cmpwi 11,0; beq 4f; lwz 9,0x0(11); mr 4,28; lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 4f; lwz 11,-21508(13); mr 4,28; addi 30,31,140; addi 29,31,144; lwz 9,0x0(11); li 23,1; lwz 0,0x7c(9); lha 3,0x78(9); mtspr 8,0; add 3,11,3; blrl; bl _s801FAE34_4; mr 4,3; mr 3,30; bl _s801FAE34_5; lwz 11,-21508(13); mr 4,28; lwz 9,0x0(11); lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; bl _s801FAE34_6; mr 4,3; mr 3,29; bl _s801FAE34_7; 4:; lwz 5,0x8(27); cmpwi 5,0; bne 5f; cmpwi 26,0; beq 7f; lwz 5,0x8(26); cmpwi 5,0; bne 5f; lwz 5,0x4(26); cmpwi 5,0; beq 7f; 5:; lwz 0,0x0(31); cmpwi 0,0; beq 6f; lwz 3,0x1c(31); cmpwi 3,0; beq 6f; lwz 6,0x7c(31); mr 4,24; li 7,0; bl _s801FAE34_8; 6:; li 25,1; 7:; cmpwi 23,0; bne 8f; lis 30,-32704; addi 3,31,140; addi 4,30,-30460; bl _s801FAE34_9; addi 4,30,-30460; addi 3,31,144; bl _s801FAE34_10; addi 4,30,-30460; addi 3,31,148; bl _s801FAE34_11; 8:; cmpwi 25,0; bne 12f; lwz 0,0x0(31); cmpwi 0,0; beq 12f; lwz 3,0x1c(31); cmpwi 3,0; beq 12f; lis 5,14705; lwz 6,0x7c(31); mr 4,24; ori 5,5,38864; li 7,0; bl _s801FAE34_12; b 12f; 9:; lis 3,-32704; mr 4,30; addi 3,3,-21328; bl _s801FAE34_13; cmpwi 3,0; bne 12f; lis 3,-32704; mr 4,29; addi 3,3,-30824; bl _s801FAE34_14; cmpwi 3,0; bne 10f; lwz 9,0x88(31); lis 0,26214; ori 0,0,26215; addi 9,9,1; b 11f; 10:; lwz 9,0x88(31); lis 0,26214; ori 0,0,26215; addi 9,9,-1; 11:; mulhw 0,9,0; srawi 11,9,31; srawi 0,0,3; subf 0,11,0; mulli 0,0,20; subf 9,0,9; stw 9,0x88(31); mr 3,31; lwz 4,0x88(3); bl _s801FAE34_15; 12:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s801FAE34_0();
extern "C" void _s801FAE34_1();
extern "C" void _s801FAE34_2();
extern "C" void _s801FAE34_3();
extern "C" void _s801FAE34_4();
extern "C" void _s801FAE34_5();
extern "C" void _s801FAE34_6();
extern "C" void _s801FAE34_7();
extern "C" void _s801FAE34_8();
extern "C" void _s801FAE34_9();
extern "C" void _s801FAE34_10();
extern "C" void _s801FAE34_11();
extern "C" void _s801FAE34_12();
extern "C" void _s801FAE34_13();
extern "C" void _s801FAE34_14();
extern "C" void _s801FAE34_15();
extern "C" void f_801FAE34() {}
