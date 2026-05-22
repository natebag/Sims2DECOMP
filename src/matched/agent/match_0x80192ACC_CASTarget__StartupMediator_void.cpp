// 0x80192ACC CASTarget::StartupMediator(void) (388 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x1348(31); andi. 9,0,16; bne 5f; lwz 0,0x1350(31); addi 30,31,216; cmpwi 0,0; beq 0f; stw 0,0x18(30); 0:; stw 31,0x1c(30); lwz 4,0x1350(31); cmpwi 4,0; beq 1f; mr 3,30; bl _s80192ACC_0; 1:; addi 4,31,132; mr 3,30; bl _s80192ACC_1; lwz 4,0x1354(31); cmpwi 4,0; beq 4f; mr 3,30; bl _s80192ACC_2; lis 9,-32697; addi 9,9,24012; lwz 0,0x41c(9); cmpwi 0,0; beq 2f; lwz 3,0x1354(31); li 4,1; bl _s80192ACC_3; b 4f; 2:; lwz 0,0x420(9); cmpwi 0,0; beq 3f; lwz 3,0x1354(31); li 4,2; bl _s80192ACC_4; b 4f; 3:; lwz 0,0x424(9); cmpwi 0,0; beq 4f; lwz 3,0x1354(31); li 4,3; bl _s80192ACC_5; 4:; lwz 4,0x1370(31); mr 3,30; addi 4,4,132; bl _s80192ACC_6; lwz 4,0x1374(31); mr 3,30; addi 4,4,132; bl _s80192ACC_7; lwz 4,0x1378(31); mr 3,30; addi 4,4,132; bl _s80192ACC_8; lwz 4,0x137c(31); mr 3,30; addi 4,4,132; bl _s80192ACC_9; lwz 4,0x1380(31); mr 3,30; addi 4,4,132; bl _s80192ACC_10; lwz 4,0x1384(31); mr 3,30; addi 4,4,132; bl _s80192ACC_11; lwz 4,0x1388(31); mr 3,30; addi 4,4,132; bl _s80192ACC_12; lwz 4,0x138c(31); mr 3,30; addi 4,4,132; bl _s80192ACC_13; lwz 4,0x1390(31); mr 3,30; addi 4,4,132; bl _s80192ACC_14; lwz 4,0x1398(31); mr 3,30; addi 4,4,132; bl _s80192ACC_15; lwz 0,0x1348(31); ori 0,0,16; stw 0,0x1348(31); 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80192ACC_0();
extern "C" void _s80192ACC_1();
extern "C" void _s80192ACC_2();
extern "C" void _s80192ACC_3();
extern "C" void _s80192ACC_4();
extern "C" void _s80192ACC_5();
extern "C" void _s80192ACC_6();
extern "C" void _s80192ACC_7();
extern "C" void _s80192ACC_8();
extern "C" void _s80192ACC_9();
extern "C" void _s80192ACC_10();
extern "C" void _s80192ACC_11();
extern "C" void _s80192ACC_12();
extern "C" void _s80192ACC_13();
extern "C" void _s80192ACC_14();
extern "C" void _s80192ACC_15();
extern "C" void f_80192ACC() {}
