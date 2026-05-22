// 0x80221BD4 InteractorModule::WallManipulator::GetWallLineCost(EVec3 (532 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-128(1); mfspr 0,8; mfcr 12; stmw 19,0x4c(1); stw 0,0x84(1); stw 12,0x48(1); li 0,0; mr 24,6; stw 0,0x0(24); mr 26,3; addi 31,1,16; mr 29,5; mr 30,4; mr 25,8; addi 3,1,8; lwz 22,-21488(13); bl _s80221BD4_0; mr 20,31; mr 3,31; bl _s80221BD4_1; lfs f9,0x8(29); addi 3,1,24; lfs f13,0x0(29); addi 4,1,40; lfs f12,0x4(29); mr 6,31; lfs f10,0x8(30); addi 5,1,8; lfs f11,0x0(30); lfs f0,0x4(30); stfs f11,0x18(1); stfs f0,0x1c(1); stfs f10,0x20(1); stfs f13,0x28(1); stfs f12,0x2c(1); stfs f9,0x30(1); bl _s80221BD4_2; addi 3,1,8; mr 4,31; bl _s80221BD4_3; mr 29,3; cmpwi 29,8; beq 5f; addi 30,1,56; bl _s80221BD4_4; mr 28,30; mr 27,3; addi 4,1,8; mr 3,30; cmpwi 4,25,0; bl _s80221BD4_5; mr 23,28; rlwinm 0,29,1,0,30; lis 9,-32696; add 21,0,29; addi 19,9,24096; li 30,0; li 25,1; addi 31,1,64; 0:; bne cr4,1f; mr 3,26; mr 4,28; mr 5,27; bl _s80221BD4_6; cmpwi 3,0; beq 2f; stw 25,0x0(24); addi 30,30,1; b 2f; 1:; mr 3,26; mr 4,28; mr 5,27; bl _s80221BD4_7; cmpwi 3,0; beq 2f; stw 25,0x0(24); lwz 0,0xc4(26); andi. 9,0,256; addi 30,30,-1; 2:; add 5,21,19; mr 3,31; mr 4,23; li 29,0; bl _s80221BD4_8; mr 4,31; mr 3,23; bl _s80221BD4_9; mr 3,31; li 4,2; bl _s80221BD4_10; stb 25,0x3a(1); mr 4,23; lwz 9,0x0(22); lha 3,0x58(9); lwz 0,0x5c(9); add 3,22,3; mtspr 8,0; blrl; cmpwi 3,0; bne 3f; mr 3,28; mr 4,20; bl _s80221BD4_11; cmpwi 3,0; beq 4f; 3:; li 29,1; 4:; cmpwi 29,0; beq 0b; mr 3,28; li 4,2; bl _s80221BD4_12; mr 3,20; li 4,2; bl _s80221BD4_13; addi 3,1,8; li 4,2; bl _s80221BD4_14; mr 3,30; b 6f; 5:; mr 3,31; li 4,2; bl _s80221BD4_15; addi 3,1,8; li 4,2; bl _s80221BD4_16; li 3,0; 6:; lwz 0,0x84(1); lwz 12,0x48(1); mtspr 8,0; lmw 19,0x4c(1); mtcrf 8,12; addi 1,1,128"
extern "C" void _s80221BD4_0();
extern "C" void _s80221BD4_1();
extern "C" void _s80221BD4_2();
extern "C" void _s80221BD4_3();
extern "C" void _s80221BD4_4();
extern "C" void _s80221BD4_5();
extern "C" void _s80221BD4_6();
extern "C" void _s80221BD4_7();
extern "C" void _s80221BD4_8();
extern "C" void _s80221BD4_9();
extern "C" void _s80221BD4_10();
extern "C" void _s80221BD4_11();
extern "C" void _s80221BD4_12();
extern "C" void _s80221BD4_13();
extern "C" void _s80221BD4_14();
extern "C" void _s80221BD4_15();
extern "C" void _s80221BD4_16();
extern "C" void f_80221BD4() {}
