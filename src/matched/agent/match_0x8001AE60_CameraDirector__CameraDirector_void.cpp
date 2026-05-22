// 0x8001AE60 CameraDirector::CameraDirector(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; addi 3,30,424; bl _s8001AE60_0; addi 3,30,288; bl _s8001AE60_1; lis 9,-32707; li 0,0; lfs f0,-6952(9); lis 4,-340; ori 4,4,59851; stw 0,0x244(30); stfs f0,0x324(30); mr 3,30; stfs f0,0x328(30); stw 0,0x170(30); bl _s8001AE60_2; li 3,12; bl _s8001AE60_3; mr 0,3; stw 0,0x2d0(30); bl _s8001AE60_4; mr 3,30; bl _s8001AE60_5; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8001AE60_0();
extern "C" void _s8001AE60_1();
extern "C" void _s8001AE60_2();
extern "C" void _s8001AE60_3();
extern "C" void _s8001AE60_4();
extern "C" void _s8001AE60_5();
extern "C" void f_8001AE60() {}
