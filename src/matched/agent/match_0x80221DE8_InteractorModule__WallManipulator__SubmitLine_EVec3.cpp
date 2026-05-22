// 0x80221DE8 InteractorModule::WallManipulator::SubmitLine(EVec3 (400 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stmw 23,0x54(1); stw 0,0x7c(1); mr 31,3; mr 30,4; mr 28,5; mr 27,8; mr 26,6; addi 3,1,8; bl _s80221DE8_0; addi 29,1,16; mr 3,29; mr 23,29; bl _s80221DE8_1; addi 9,31,184; lfs f9,0xb8(31); lfs f10,0x4(9); addi 24,1,24; lfs f11,0x8(9); addi 25,1,40; lfs f12,0x8(30); mr 3,24; lfs f13,0x0(30); mr 4,25; lfs f0,0x4(30); fadds f12,f12,f11; fadds f13,f13,f9; stfs f12,0x20(1); fadds f0,f0,f10; stfs f13,0x18(1); stfs f0,0x1c(1); addi 5,1,8; lfs f0,0x4(28); mr 6,29; lfs f11,0x8(9); lfs f10,0x4(9); lfs f12,0x8(28); lfs f13,0x0(28); fadds f0,f0,f10; fadds f12,f12,f11; stfs f0,0x2c(1); fadds f13,f13,f9; stfs f12,0x30(1); stfs f13,0x28(1); bl _s80221DE8_2; addi 3,1,8; mr 4,29; bl _s80221DE8_3; li 0,-1; stw 3,0x48(1); stw 0,0x0(26); cmpwi 27,1; bne 0f; bl _s80221DE8_4; lwz 4,0x0(31); bl _s80221DE8_5; mr 4,24; mr 5,25; li 6,0; bl _s80221DE8_6; neg 7,3; addi 4,1,8; mr 3,31; mr 5,23; addi 6,1,72; bl _s80221DE8_7; b 1f; 0:; addi 29,1,56; addi 30,1,64; addi 4,1,8; mr 3,29; bl _s80221DE8_8; mr 4,23; mr 3,30; bl _s80221DE8_9; mr 3,31; mr 4,29; mr 5,30; addi 6,1,72; li 7,0; bl _s80221DE8_10; 1:; stw 3,0x0(26); lwz 0,0x0(26); li 31,1; cmpwi 0,-1; bne 2f; li 31,0; 2:; mr 3,23; li 4,2; bl _s80221DE8_11; addi 3,1,8; li 4,2; bl _s80221DE8_12; mr 3,31; lwz 0,0x7c(1); mtspr 8,0; lmw 23,0x54(1); addi 1,1,120"
extern "C" void _s80221DE8_0();
extern "C" void _s80221DE8_1();
extern "C" void _s80221DE8_2();
extern "C" void _s80221DE8_3();
extern "C" void _s80221DE8_4();
extern "C" void _s80221DE8_5();
extern "C" void _s80221DE8_6();
extern "C" void _s80221DE8_7();
extern "C" void _s80221DE8_8();
extern "C" void _s80221DE8_9();
extern "C" void _s80221DE8_10();
extern "C" void _s80221DE8_11();
extern "C" void _s80221DE8_12();
extern "C" void f_80221DE8() {}
