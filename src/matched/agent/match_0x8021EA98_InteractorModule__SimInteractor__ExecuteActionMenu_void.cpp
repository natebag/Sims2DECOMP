// 0x8021EA98 InteractorModule::SimInteractor::ExecuteActionMenu(void) (536 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); lis 9,-32697; mr 30,3; lwz 3,0x5bc8(9); cmpwi 3,0; beq 0f; lwz 4,0x0(30); bl _s8021EA98_0; cmpwi 3,0; bne 2f; 0:; lwz 0,-31536(13); cmpwi 0,0; bne 1f; li 3,120; bl _s8021EA98_1; bl _s8021EA98_2; stw 3,-31536(13); 1:; lwz 3,-31536(13); lis 4,14340; ori 4,4,8607; bl _s8021EA98_3; li 0,0; stw 0,0x30(30); b 8f; 2:; addi 5,1,8; li 0,0; stw 0,0x4(5); lis 9,-32697; stw 0,0x8(1); addi 31,9,24012; li 0,1; mr 28,5; stw 0,0x8(5); lwz 9,0xc8(31); lwz 4,0x0(30); lwz 3,0x4(9); bl _s8021EA98_4; lwz 0,0x8(1); cmpwi 0,0; beq 5f; lwz 0,0x0(30); addi 9,31,188; rlwinm 0,0,2,0,29; lwzx 3,9,0; cmpwi 3,0; beq 5f; lwz 3,0x0(3); li 4,0; lwz 9,0x4(3); lha 0,0x2b8(9); lwz 9,0x2bc(9); add 3,3,0; mtspr 8,9; blrl; mr. 3,3; beq 5f; lha 4,0x4(3); cmpwi 4,0; beq 5f; lwz 11,-21484(13); mr 29,28; lwz 9,0x0(11); lwz 0,0x94(9); lha 3,0x90(9); mtspr 8,0; add 3,11,3; blrl; mr 31,3; lwz 11,0x0(31); lwz 9,0x18(11); lha 3,0x98(9); lwz 0,0x9c(9); add 3,11,3; mtspr 8,0; blrl; lwz 4,0x8(1); b 4f; 3:; lwz 4,0x8(4); 4:; cmpwi 4,0; beq 5f; lwz 0,0x0(4); cmpw 0,3; bne 3b; mr 3,29; bl _s8021EA98_5; lwz 11,0x0(31); lwz 9,0x18(11); lha 3,0x98(9); lwz 0,0x9c(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 3,29; bl _s8021EA98_6; 5:; lwz 11,0x0(30); lis 9,-32697; addi 9,9,23428; rlwinm 11,11,4,0,27; add 11,11,9; lwz 3,0xfc(11); cmpwi 3,0; beq 7f; addi 4,1,8; bl _s8021EA98_7; cmpwi 3,0; beq 7f; lwz 0,-31536(13); cmpwi 0,0; bne 6f; li 3,120; bl _s8021EA98_8; bl _s8021EA98_9; stw 3,-31536(13); 6:; lis 4,14155; lwz 3,-31536(13); ori 4,4,56554; bl _s8021EA98_10; 7:; lwz 9,0x5c(30); lha 3,0x78(9); lwz 0,0x7c(9); add 3,30,3; mtspr 8,0; blrl; mr 3,28; bl _s8021EA98_11; 8:; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s8021EA98_0();
extern "C" void _s8021EA98_1();
extern "C" void _s8021EA98_2();
extern "C" void _s8021EA98_3();
extern "C" void _s8021EA98_4();
extern "C" void _s8021EA98_5();
extern "C" void _s8021EA98_6();
extern "C" void _s8021EA98_7();
extern "C" void _s8021EA98_8();
extern "C" void _s8021EA98_9();
extern "C" void _s8021EA98_10();
extern "C" void _s8021EA98_11();
extern "C" void f_8021EA98() {}
