// 0x802057C8 InteractorModule::DirectInteractor::ExecuteActionMenu(void) (664 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); lis 9,-32697; mr 31,3; lwz 3,0x5bc8(9); cmpwi 3,0; beq 0f; lwz 4,0x0(31); bl _s802057C8_0; cmpwi 3,0; beq 0f; lwz 11,0x70(31); cmpwi 11,0; beq 3f; lwz 9,0x4(11); lha 3,0x168(9); lwz 0,0x16c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,3; bne 3f; 0:; lis 9,-32697; lwz 0,0x0(31); addi 9,9,24012; rlwinm 0,0,2,0,29; addi 9,9,280; lwzx 9,9,0; cmpwi 9,0; beq 2f; lwz 0,0x234(9); cmpwi 0,0; bne 2f; lwz 0,-31536(13); cmpwi 0,0; bne 1f; li 3,120; bl _s802057C8_1; bl _s802057C8_2; stw 3,-31536(13); 1:; lis 4,14340; lwz 3,-31536(13); ori 4,4,8607; bl _s802057C8_3; 2:; li 0,0; stw 0,0x30(31); b 12f; 3:; addi 9,1,8; li 0,0; stw 0,0x4(9); lis 30,-32697; stw 0,0x8(1); addi 30,30,24012; li 0,1; mr 5,9; lwz 11,0xc8(30); mr 29,9; stw 0,0x8(9); lwz 3,0x4(11); lwz 4,0x0(31); bl _s802057C8_4; lwz 0,0x0(31); addi 30,30,188; li 4,0; rlwinm 0,0,2,0,29; lwzx 9,30,0; lwz 10,0x0(9); lwz 11,0x4(10); lha 3,0x2b8(11); lwz 0,0x2bc(11); add 3,10,3; mtspr 8,0; blrl; mr. 3,3; beq 7f; lha 4,0x4(3); cmpwi 4,0; beq 7f; lwz 11,-21484(13); lwz 9,0x0(11); lwz 0,0x94(9); lha 3,0x90(9); mtspr 8,0; add 3,11,3; blrl; mr 30,3; lwz 11,0x0(30); lwz 9,0x18(11); lha 3,0x98(9); lwz 0,0x9c(9); add 3,11,3; mtspr 8,0; blrl; lwz 4,0x8(1); b 5f; 4:; lwz 4,0x8(4); 5:; cmpwi 4,0; beq 6f; lwz 0,0x0(4); cmpw 0,3; bne 4b; mr 3,29; bl _s802057C8_5; 6:; lwz 11,0x0(30); lwz 9,0x18(11); lha 3,0x98(9); lwz 0,0x9c(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 3,29; bl _s802057C8_6; 7:; lwz 0,0x8(1); cmpwi 0,0; bne 9f; lwz 0,-31536(13); cmpwi 0,0; bne 8f; li 3,120; bl _s802057C8_7; bl _s802057C8_8; stw 3,-31536(13); 8:; lis 4,14340; lwz 3,-31536(13); ori 4,4,8607; bl _s802057C8_9; b 11f; 9:; lwz 11,0x0(31); lis 9,-32697; addi 9,9,23428; rlwinm 11,11,4,0,27; add 11,11,9; lwz 3,0xfc(11); cmpwi 3,0; beq 11f; mr 4,29; bl _s802057C8_10; cmpwi 3,0; beq 11f; lwz 0,-31536(13); cmpwi 0,0; bne 10f; li 3,120; bl _s802057C8_11; bl _s802057C8_12; stw 3,-31536(13); 10:; lis 4,14155; lwz 3,-31536(13); ori 4,4,56554; bl _s802057C8_13; 11:; lwz 9,0x5c(31); lha 3,0x78(9); lwz 0,0x7c(9); add 3,31,3; mtspr 8,0; blrl; mr 3,29; bl _s802057C8_14; 12:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s802057C8_0();
extern "C" void _s802057C8_1();
extern "C" void _s802057C8_2();
extern "C" void _s802057C8_3();
extern "C" void _s802057C8_4();
extern "C" void _s802057C8_5();
extern "C" void _s802057C8_6();
extern "C" void _s802057C8_7();
extern "C" void _s802057C8_8();
extern "C" void _s802057C8_9();
extern "C" void _s802057C8_10();
extern "C" void _s802057C8_11();
extern "C" void _s802057C8_12();
extern "C" void _s802057C8_13();
extern "C" void _s802057C8_14();
extern "C" void f_802057C8() {}
