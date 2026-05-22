// 0x80208C74 InteractorModule::FloorPainter::CheckDiagForRoomContainment(Room (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); li 0,0; mr 28,7; mr 27,6; mr 26,8; stw 0,0x0(28); mr 25,4; mr 31,5; stw 0,0x0(26); mr 3,27; bl _s80208C74_0; cmpwi 3,0; beq 3f; mr 3,31; bl _s80208C74_1; addi 30,3,-1; mr 3,31; bl _s80208C74_2; mr 5,3; li 6,1; addi 3,1,8; mr 4,30; bl _s80208C74_3; addi 4,1,8; mr 3,25; bl _s80208C74_4; mr 29,3; li 4,2; addi 3,1,8; bl _s80208C74_5; mr 3,31; bl _s80208C74_6; addi 30,3,1; mr 3,31; bl _s80208C74_7; mr 5,3; li 6,1; addi 3,1,8; mr 4,30; bl _s80208C74_8; addi 4,1,8; mr 3,25; bl _s80208C74_9; mr 31,3; li 4,2; addi 3,1,8; bl _s80208C74_10; cmpwi 29,0; beq 1f; mr 3,27; li 4,16; bl _s80208C74_11; cmpwi 3,0; li 0,1; beq 0f; li 0,2; 0:; stw 0,0x0(28); 1:; cmpwi 31,0; beq 3f; mr 3,27; li 4,16; bl _s80208C74_12; cmpwi 3,0; li 0,3; beq 2f; li 0,4; 2:; stw 0,0x0(26); 3:; lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"
extern "C" void _s80208C74_0();
extern "C" void _s80208C74_1();
extern "C" void _s80208C74_2();
extern "C" void _s80208C74_3();
extern "C" void _s80208C74_4();
extern "C" void _s80208C74_5();
extern "C" void _s80208C74_6();
extern "C" void _s80208C74_7();
extern "C" void _s80208C74_8();
extern "C" void _s80208C74_9();
extern "C" void _s80208C74_10();
extern "C" void _s80208C74_11();
extern "C" void _s80208C74_12();
extern "C" void f_80208C74() {}
