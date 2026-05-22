// 0x80184E8C ActionQueueHUD::RunIngame(void) (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; bl _s80184E8C_0; lwz 4,0x314(31); lwz 3,-26524(13); bl _s80184E8C_1; lwz 30,0x30c(31); mr 28,3; mr 4,30; bl _s80184E8C_2; mr 29,3; mr 4,30; mr 3,28; bl _s80184E8C_3; mr 6,3; mr 5,29; mr 3,28; li 4,25; li 7,0; bl _s80184E8C_4; cmpwi 3,0; beq 0f; mr 3,31; bl _s80184E8C_5; b 3f; 0:; lwz 30,0x30c(31); mr 3,28; mr 4,30; bl _s80184E8C_6; mr 29,3; mr 4,30; mr 3,28; bl _s80184E8C_7; mr 6,3; mr 5,29; mr 3,28; li 4,6; li 7,0; bl _s80184E8C_8; cmpwi 3,0; beq 3f; mr 3,31; li 29,0; bl _s80184E8C_9; lwz 9,0x150(31); mr 30,3; cmpwi 9,0; beq 3f; cmpwi 30,0; beq 1f; addi 0,9,-1; mulli 0,0,20; addi 9,31,168; lwzx 29,9,0; 1:; cmpwi 29,0; beq 3f; mr 3,31; mr 4,29; bl _s80184E8C_10; lwz 9,0x4(30); mr 4,29; lwz 0,0xbc(9); lha 3,0xb8(9); mtspr 8,0; add 3,30,3; blrl; lwz 0,-31536(13); cmpwi 0,0; bne 2f; li 3,120; bl _s80184E8C_11; bl _s80184E8C_12; stw 3,-31536(13); 2:; lis 4,10927; lwz 3,-31536(13); ori 4,4,62296; bl _s80184E8C_13; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80184E8C_0();
extern "C" void _s80184E8C_1();
extern "C" void _s80184E8C_2();
extern "C" void _s80184E8C_3();
extern "C" void _s80184E8C_4();
extern "C" void _s80184E8C_5();
extern "C" void _s80184E8C_6();
extern "C" void _s80184E8C_7();
extern "C" void _s80184E8C_8();
extern "C" void _s80184E8C_9();
extern "C" void _s80184E8C_10();
extern "C" void _s80184E8C_11();
extern "C" void _s80184E8C_12();
extern "C" void _s80184E8C_13();
extern "C" void f_80184E8C() {}
