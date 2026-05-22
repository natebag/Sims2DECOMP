// 0x8001AEE4 CameraDirector::~CameraDirector(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; li 30,0; addi 29,31,424; stw 30,0x170(31); mr 28,4; mr 3,29; bl _s8001AEE4_0; lwz 3,0x2d0(31); bl _s8001AEE4_1; lwz 3,0x2d0(31); bl _s8001AEE4_2; stw 30,0x2d0(31); mr 3,31; bl _s8001AEE4_3; mr 3,29; li 4,2; bl _s8001AEE4_4; andi. 0,28,1; beq 0f; bl _s8001AEE4_5; mr 4,31; bl _s8001AEE4_6; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8001AEE4_0();
extern "C" void _s8001AEE4_1();
extern "C" void _s8001AEE4_2();
extern "C" void _s8001AEE4_3();
extern "C" void _s8001AEE4_4();
extern "C" void _s8001AEE4_5();
extern "C" void _s8001AEE4_6();
extern "C" void f_8001AEE4() {}
