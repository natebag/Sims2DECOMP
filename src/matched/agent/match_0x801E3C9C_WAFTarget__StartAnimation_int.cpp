// 0x801E3C9C WAFTarget::StartAnimation(int) (452 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 26,4; mr 31,3; mulli 28,26,60; addi 9,31,212; lwzx 0,9,28; cmpwi 0,1; bne 0f; lis 9,-32705; lis 11,-32705; lfs f0,0x645c(9); addi 10,31,184; lfs f13,0x6460(11); addi 9,31,188; stfsx f0,10,28; addi 11,31,192; stfsx f13,9,28; addi 10,31,196; stfsx f13,11,28; lis 5,-32705; addi 5,5,3316; addi 3,31,592; lwzx 4,10,28; lwz 6,0x94(31); bl _s801E3C9C_0; b 3f; 0:; cmpwi 0,2; bne 3f; lis 9,-32705; lis 11,-32705; lfs f0,0x6464(9); addi 10,31,188; lfs f13,0x6460(11); addi 8,31,184; stfsx f0,10,28; addi 30,31,592; stfsx f13,8,28; addi 9,31,192; stfsx f13,9,28; mr 3,30; bl _s801E3C9C_1; addi 27,31,200; addi 9,31,196; lwz 5,0x94(31); lwzx 4,9,28; mr 3,30; addi 29,31,204; bl _s801E3C9C_2; mr 25,29; lis 4,-32705; mr 3,30; addi 4,4,25624; bl _s801E3C9C_3; lwz 5,0x94(31); mr 3,30; lwzx 4,27,28; bl _s801E3C9C_4; mr 3,30; li 4,0; bl _s801E3C9C_5; lwz 5,0x94(31); mr 3,30; lwzx 4,29,28; bl _s801E3C9C_6; mr 3,30; li 4,0; bl _s801E3C9C_7; mr 3,30; bl _s801E3C9C_8; lwz 0,-31536(13); cmpwi 0,0; bne 1f; li 3,120; bl _s801E3C9C_9; bl _s801E3C9C_10; stw 3,-31536(13); 1:; lwz 3,-31536(13); lis 4,14989; ori 4,4,58004; bl _s801E3C9C_11; lwz 0,0x0(31); addi 9,31,176; lwzx 4,27,28; lwzx 5,9,28; cmpwi 0,0; beq 2f; lwz 3,0x1c(31); cmpwi 3,0; beq 2f; lwz 6,0x7c(31); li 7,0; bl _s801E3C9C_12; 2:; mulli 0,26,60; lwz 9,0x0(31); addi 11,31,180; cmpwi 9,0; lwzx 4,25,0; lwzx 5,11,0; beq 3f; lwz 3,0x1c(31); cmpwi 3,0; beq 3f; lwz 6,0x7c(31); li 7,0; bl _s801E3C9C_13; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s801E3C9C_0();
extern "C" void _s801E3C9C_1();
extern "C" void _s801E3C9C_2();
extern "C" void _s801E3C9C_3();
extern "C" void _s801E3C9C_4();
extern "C" void _s801E3C9C_5();
extern "C" void _s801E3C9C_6();
extern "C" void _s801E3C9C_7();
extern "C" void _s801E3C9C_8();
extern "C" void _s801E3C9C_9();
extern "C" void _s801E3C9C_10();
extern "C" void _s801E3C9C_11();
extern "C" void _s801E3C9C_12();
extern "C" void _s801E3C9C_13();
extern "C" void f_801E3C9C() {}
