// 0x801E3900 WAFTarget::NewWantsAndFearsIcon(int, (924 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 20,0x18(1); stw 0,0x4c(1); mr 31,3; mr 28,4; lwz 0,0x24c(31); mr 24,5; mr 23,6; mr 25,7; mr 26,8; cmpwi 0,0; beq 13f; rlwinm 0,28,2,0,29; addi 9,26,408; lwzx 27,9,0; mr 3,27; bl _s801E3900_0; cmpwi 3,128; bne 0f; li 8,1; b 2f; 0:; cmpwi 3,4; bne 1f; li 8,2; b 2f; 1:; cmpwi 3,1; li 8,0; bne 2f; li 8,3; 2:; cmplwi 28,6; bgt 13f; mulli 0,28,60; addi 9,31,208; addi 11,31,176; addi 10,31,180; mr 22,9; mr 21,11; mr 20,10; lwzx 30,9,0; add 4,0,31; stwx 24,11,0; mr 29,0; stwx 23,10,0; addi 4,4,216; stwx 8,9,0; mr 5,26; li 6,1; mr 3,27; bl _s801E3900_1; lis 4,-32705; addi 3,1,8; addi 4,4,25672; mr 5,28; crxor 6,6,6; bl _s801E3900_2; addi 0,25,-1; cmplwi 0,1; bgt 10f; cmpwi 25,1; bne 8f; cmpwi 30,3; bne 4f; lwz 0,-31536(13); cmpwi 0,0; bne 3f; li 3,120; bl _s801E3900_3; bl _s801E3900_4; stw 3,-31536(13); 3:; lis 4,19749; lwz 3,-31536(13); ori 4,4,1399; bl _s801E3900_5; b 6f; 4:; cmpwi 30,2; bne 6f; lwz 0,-31536(13); cmpwi 0,0; bne 5f; li 3,120; bl _s801E3900_6; bl _s801E3900_7; stw 3,-31536(13); 5:; lis 4,-28090; lwz 3,-31536(13); ori 4,4,38178; bl _s801E3900_8; 6:; cmpwi 30,1; bne 7f; lis 9,-32697; lwz 3,0x5bcc(9); cmpwi 3,0; beq 8f; lwz 4,0x94(31); li 5,1; li 6,0; bl _s801E3900_9; b 8f; 7:; lis 9,-32697; lwz 3,0x5bcc(9); cmpwi 3,0; beq 8f; lwz 4,0x94(31); li 5,1; li 6,1; bl _s801E3900_10; 8:; addi 9,31,220; addi 30,31,592; stwx 26,9,29; mr 3,30; bl _s801E3900_11; lwz 5,0x94(31); addi 4,1,8; mr 3,30; bl _s801E3900_12; mr 3,30; li 4,0; bl _s801E3900_13; mr 3,30; li 4,14; bl _s801E3900_14; mr 3,30; bl _s801E3900_15; addi 9,31,212; stwx 25,9,29; lwz 0,0x90(31); cmpwi 0,0; bne 9f; lis 9,-32705; lis 11,-32705; lfs f13,0x6454(9); addi 10,31,192; lfs f0,0x6458(11); addi 8,31,188; stfsx f13,10,29; addi 9,31,184; stfsx f0,8,29; stfsx f0,9,29; b 13f; 9:; mr 3,31; mr 4,28; bl _s801E3900_16; b 13f; 10:; lwz 0,0x0(31); addi 9,31,200; mr 27,9; lwzx 4,9,29; cmpwi 0,0; lwzx 5,21,29; beq 11f; lwz 3,0x1c(31); cmpwi 3,0; beq 11f; lwz 6,0x7c(31); li 7,0; bl _s801E3900_17; 11:; lwz 0,0x0(31); addi 9,31,204; mr 28,9; lwzx 4,9,29; cmpwi 0,0; lwzx 5,20,29; beq 12f; lwz 3,0x1c(31); cmpwi 3,0; beq 12f; lwz 6,0x7c(31); li 7,0; bl _s801E3900_18; 12:; addi 30,31,592; mr 3,30; bl _s801E3900_19; addi 9,31,196; lwz 5,0x94(31); lwzx 4,9,29; mr 3,30; bl _s801E3900_20; lwzx 0,22,29; lis 9,-32700; addi 9,9,-25216; mr 3,30; rlwinm 0,0,2,0,29; lwzx 4,9,0; bl _s801E3900_21; lwz 5,0x94(31); addi 4,1,8; mr 3,30; bl _s801E3900_22; mr 3,30; li 4,1; bl _s801E3900_23; mr 3,30; li 4,14; bl _s801E3900_24; lwz 5,0x94(31); mr 3,30; lwzx 4,27,29; bl _s801E3900_25; mr 3,30; li 4,1; bl _s801E3900_26; lwz 5,0x94(31); mr 3,30; lwzx 4,28,29; bl _s801E3900_27; mr 3,30; li 4,1; bl _s801E3900_28; mr 3,30; bl _s801E3900_29; addi 9,31,220; li 0,0; stwx 0,9,29; addi 7,31,168; lis 9,-32705; addi 6,31,172; lwzx 11,21,29; addi 8,31,184; lfs f0,0x6458(9); addi 10,31,188; stwx 11,7,29; lwzx 0,20,29; stwx 0,6,29; stfsx f0,8,29; stfsx f0,10,29; 13:; lwz 0,0x4c(1); mtspr 8,0; lmw 20,0x18(1); addi 1,1,72"
extern "C" void _s801E3900_0();
extern "C" void _s801E3900_1();
extern "C" void _s801E3900_2();
extern "C" void _s801E3900_3();
extern "C" void _s801E3900_4();
extern "C" void _s801E3900_5();
extern "C" void _s801E3900_6();
extern "C" void _s801E3900_7();
extern "C" void _s801E3900_8();
extern "C" void _s801E3900_9();
extern "C" void _s801E3900_10();
extern "C" void _s801E3900_11();
extern "C" void _s801E3900_12();
extern "C" void _s801E3900_13();
extern "C" void _s801E3900_14();
extern "C" void _s801E3900_15();
extern "C" void _s801E3900_16();
extern "C" void _s801E3900_17();
extern "C" void _s801E3900_18();
extern "C" void _s801E3900_19();
extern "C" void _s801E3900_20();
extern "C" void _s801E3900_21();
extern "C" void _s801E3900_22();
extern "C" void _s801E3900_23();
extern "C" void _s801E3900_24();
extern "C" void _s801E3900_25();
extern "C" void _s801E3900_26();
extern "C" void _s801E3900_27();
extern "C" void _s801E3900_28();
extern "C" void _s801E3900_29();
extern "C" void f_801E3900() {}
