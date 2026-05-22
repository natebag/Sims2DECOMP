// 0x80043230 HoodManager::EvictFamilyAndLiquidateAssets(int) (344 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-336(1); mfspr 0,8; stmw 28,0x140(1); stw 0,0x154(1); lis 9,-32697; mr 28,3; lwz 31,0x5c74(9); cmpwi 31,0; beq 0f; li 4,1; bl _s80043230_0; b 1f; 0:; addi 29,28,1; lwz 3,-32056(13); addi 30,1,8; li 6,0; li 5,0; mr 4,29; bl _s80043230_1; lwz 3,-32056(13); mr 4,28; bl _s80043230_2; stw 31,0x8(1); li 0,-1; addi 4,1,36; addi 3,1,28; stw 0,0x10(30); li 5,128; stw 31,0xc(30); stw 31,0x4(30); stw 31,0x8(30); bl _s80043230_3; lwz 11,-21476(13); lwz 9,0x0(11); lwz 0,0x194(9); lha 3,0x190(9); mtspr 8,0; add 3,11,3; blrl; mr 9,3; lwz 4,-32056(13); mr 6,30; stw 29,0x70(9); mr 5,29; bl _s80043230_4; lwz 30,0x14(1); mr 3,28; bl _s80043230_5; lwz 3,-32056(13); li 5,0; mr 4,29; bl _s80043230_6; lwz 3,-32056(13); mr 4,29; bl _s80043230_7; lwz 3,-32056(13); mr 4,29; bl _s80043230_8; lwz 5,-32032(13); addi 7,1,312; lha 6,-32036(13); lwz 4,-32056(13); lwz 3,-21496(13); bl _s80043230_9; lwz 11,-21496(13); li 4,0; lwz 9,0x0(11); lha 3,0x138(9); lwz 0,0x13c(9); add 3,11,3; mtspr 8,0; blrl; lwz 4,-32056(13); lwz 3,-21496(13); lwz 5,-32032(13); lha 6,-32036(13); lwz 7,0x138(1); bl _s80043230_10; mr 3,28; mr 4,30; bl _s80043230_11; 1:; lwz 0,0x154(1); mtspr 8,0; lmw 28,0x140(1); addi 1,1,336"
extern "C" void _s80043230_0();
extern "C" void _s80043230_1();
extern "C" void _s80043230_2();
extern "C" void _s80043230_3();
extern "C" void _s80043230_4();
extern "C" void _s80043230_5();
extern "C" void _s80043230_6();
extern "C" void _s80043230_7();
extern "C" void _s80043230_8();
extern "C" void _s80043230_9();
extern "C" void _s80043230_10();
extern "C" void _s80043230_11();
extern "C" void f_80043230() {}
