// 0x80112C70 ObjTestSim::MakeNewMenuItem(unsigned (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 27,0x54(1); stw 0,0x6c(1); mr 27,3; mr 31,4; mr 30,5; mr 29,6; bl _s80112C70_0; cmpwi 3,0; beq 1f; addi 3,1,8; lwz 4,-21344(13); mr 28,3; bl _s80112C70_1; addi 3,1,8; mr 4,29; bl _s80112C70_2; mr 4,27; addi 3,1,60; bl _s80112C70_3; lwz 0,0x3c(28); lhz 7,0x6(31); lhz 10,0x0(31); ori 0,0,4; lhz 11,0x2(31); lhz 8,0x4(31); lbz 9,0x6(30); sth 10,0x20(1); sth 11,0x22(1); cmpwi 9,0; sth 8,0x24(1); sth 7,0x26(1); stw 0,0x3c(28); beq 0f; mr 3,30; bl _s80112C70_4; mr 4,3; lbz 5,0x6(30); mr 3,28; bl _s80112C70_5; 0:; lwz 3,-21348(13); mr 4,28; bl _s80112C70_6; mr 3,28; li 4,2; bl _s80112C70_7; 1:; lwz 0,0x6c(1); mtspr 8,0; lmw 27,0x54(1); addi 1,1,104"
extern "C" void _s80112C70_0();
extern "C" void _s80112C70_1();
extern "C" void _s80112C70_2();
extern "C" void _s80112C70_3();
extern "C" void _s80112C70_4();
extern "C" void _s80112C70_5();
extern "C" void _s80112C70_6();
extern "C" void _s80112C70_7();
extern "C" void f_80112C70() {}
