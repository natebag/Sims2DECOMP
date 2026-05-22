// 0x8021F480 InteractorModule::SocialModeInteractor::SetupInteractionMenu(cXObject (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 29,4; mr 28,5; bl _s8021F480_0; lis 9,-32697; addi 30,9,23428; lwz 3,0x44(30); cmpwi 3,0; beq 0f; lwz 4,0x0(31); bl _s8021F480_1; cmpwi 3,0; bne 1f; 0:; li 3,0; b 4f; 1:; lwz 9,0x0(31); rlwinm 9,9,4,0,27; add 9,9,30; lwz 3,0xfc(9); cmpwi 3,0; beq 3f; mr 4,29; mr 5,28; bl _s8021F480_2; cmpwi 3,0; beq 3f; lwz 3,0x44(30); lwz 4,0x0(31); bl _s8021F480_3; lwz 0,-31536(13); cmpwi 0,0; bne 2f; li 3,120; bl _s8021F480_4; bl _s8021F480_5; stw 3,-31536(13); 2:; lis 4,14155; lwz 3,-31536(13); ori 4,4,56554; bl _s8021F480_6; 3:; li 3,1; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8021F480_0();
extern "C" void _s8021F480_1();
extern "C" void _s8021F480_2();
extern "C" void _s8021F480_3();
extern "C" void _s8021F480_4();
extern "C" void _s8021F480_5();
extern "C" void _s8021F480_6();
extern "C" void f_8021F480() {}
