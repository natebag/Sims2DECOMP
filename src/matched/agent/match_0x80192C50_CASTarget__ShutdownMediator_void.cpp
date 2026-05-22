// 0x80192C50 CASTarget::ShutdownMediator(void) (360 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x1348(31); andi. 9,0,16; beq 3f; andi. 9,0,32; addi 30,31,216; beq 0f; lwz 0,0x134c(31); mr 3,30; rlwinm 4,0,3,0,28; add 4,4,0; rlwinm 4,4,6,0,25; addi 4,4,2632; add 4,31,4; bl _s80192C50_0; lwz 4,0x134c(31); mr 3,30; mulli 4,4,592; addi 4,4,264; add 4,31,4; bl _s80192C50_1; 0:; lwz 4,0x1398(31); mr 3,30; addi 4,4,132; bl _s80192C50_2; lwz 4,0x1390(31); mr 3,30; addi 4,4,132; bl _s80192C50_3; lwz 4,0x138c(31); mr 3,30; addi 4,4,132; bl _s80192C50_4; lwz 4,0x1388(31); mr 3,30; addi 4,4,132; bl _s80192C50_5; lwz 4,0x1384(31); mr 3,30; addi 4,4,132; bl _s80192C50_6; lwz 4,0x1380(31); mr 3,30; addi 4,4,132; bl _s80192C50_7; lwz 4,0x1380(31); mr 3,30; addi 4,4,132; bl _s80192C50_8; lwz 4,0x137c(31); mr 3,30; addi 4,4,132; bl _s80192C50_9; lwz 4,0x1378(31); mr 3,30; addi 4,4,132; bl _s80192C50_10; lwz 4,0x1374(31); mr 3,30; addi 4,4,132; bl _s80192C50_11; lwz 4,0x1370(31); mr 3,30; addi 4,4,132; bl _s80192C50_12; lwz 4,0x1354(31); cmpwi 4,0; beq 1f; mr 3,30; bl _s80192C50_13; 1:; addi 4,31,132; mr 3,30; bl _s80192C50_14; lwz 4,0x1350(31); cmpwi 4,0; beq 2f; mr 3,30; bl _s80192C50_15; 2:; lwz 0,0x1348(31); rlwinm 0,0,0,28,25; stw 0,0x1348(31); 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80192C50_0();
extern "C" void _s80192C50_1();
extern "C" void _s80192C50_2();
extern "C" void _s80192C50_3();
extern "C" void _s80192C50_4();
extern "C" void _s80192C50_5();
extern "C" void _s80192C50_6();
extern "C" void _s80192C50_7();
extern "C" void _s80192C50_8();
extern "C" void _s80192C50_9();
extern "C" void _s80192C50_10();
extern "C" void _s80192C50_11();
extern "C" void _s80192C50_12();
extern "C" void _s80192C50_13();
extern "C" void _s80192C50_14();
extern "C" void _s80192C50_15();
extern "C" void f_80192C50() {}
