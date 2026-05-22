// 0x80205A60 InteractorModule::DirectInteractor::ExecuteObjectActionMenu(cXObject (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); mr 29,3; mr 28,4; lwz 31,0x80(29); cmpwi 31,0; bne 2f; lis 9,-32697; addi 27,9,23428; lwz 3,0x44(27); cmpwi 3,0; beq 2f; lwz 4,0x0(29); bl _s80205A60_0; cmpwi 3,0; beq 2f; addi 30,1,8; li 0,1; stw 31,0x4(30); mr 26,30; stw 31,0x8(1); stw 0,0x8(30); lwz 11,0x0(28); lwz 9,0x18(11); lha 3,0x98(9); lwz 0,0x9c(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 3,30; bl _s80205A60_1; lwz 9,0x0(29); rlwinm 9,9,4,0,27; add 9,9,27; lwz 3,0xfc(9); cmpwi 3,0; beq 1f; mr 4,26; bl _s80205A60_2; cmpwi 3,0; beq 1f; lwz 0,-31536(13); cmpwi 0,0; bne 0f; li 3,120; bl _s80205A60_3; bl _s80205A60_4; stw 3,-31536(13); 0:; lis 4,14155; lwz 3,-31536(13); ori 4,4,56554; bl _s80205A60_5; 1:; addi 3,1,8; bl _s80205A60_6; lwz 9,0x5c(29); lha 3,0x78(9); lwz 0,0x7c(9); add 3,29,3; mtspr 8,0; blrl; mr 3,26; bl _s80205A60_7; 2:; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"
extern "C" void _s80205A60_0();
extern "C" void _s80205A60_1();
extern "C" void _s80205A60_2();
extern "C" void _s80205A60_3();
extern "C" void _s80205A60_4();
extern "C" void _s80205A60_5();
extern "C" void _s80205A60_6();
extern "C" void _s80205A60_7();
extern "C" void f_80205A60() {}
