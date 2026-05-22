// 0x8001B3EC CameraDirector::EnableControls(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x244(31); cmpwi 0,0; beq 0f; lwz 0,0x170(31); cmpwi 0,0; beq 0f; lwz 3,-26524(13); lwz 4,0x248(31); bl _s8001B3EC_0; cmpwi 3,0; beq 0f; lwz 30,-26524(13); lwz 4,0x248(31); mr 3,30; bl _s8001B3EC_1; mr 4,3; mr 3,30; bl _s8001B3EC_2; mr. 3,3; beq 0f; lwz 4,0x244(31); bl _s8001B3EC_3; li 0,0; stw 0,0x248(31); stw 0,0x244(31); 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8001B3EC_0();
extern "C" void _s8001B3EC_1();
extern "C" void _s8001B3EC_2();
extern "C" void _s8001B3EC_3();
extern "C" void f_8001B3EC() {}
