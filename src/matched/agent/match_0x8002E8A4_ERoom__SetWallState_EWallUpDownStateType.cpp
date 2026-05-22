// 0x8002E8A4 ERoom::SetWallState(EWallUpDownStateType) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; subfic 30,4,1; li 30,0; adde 30,30,30; mr 3,30; addi 4,29,4; bl _s8002E8A4_0; mr 3,30; addi 4,29,16; bl _s8002E8A4_1; mr 3,30; addi 4,29,28; bl _s8002E8A4_2; mr 3,30; addi 4,29,40; bl _s8002E8A4_3; mr 3,30; addi 4,29,52; bl _s8002E8A4_4; mr 3,30; addi 4,29,64; bl _s8002E8A4_5; mr 3,30; addi 4,29,76; bl _s8002E8A4_6; mr 3,30; addi 4,29,88; bl _s8002E8A4_7; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8002E8A4_0();
extern "C" void _s8002E8A4_1();
extern "C" void _s8002E8A4_2();
extern "C" void _s8002E8A4_3();
extern "C" void _s8002E8A4_4();
extern "C" void _s8002E8A4_5();
extern "C" void _s8002E8A4_6();
extern "C" void _s8002E8A4_7();
extern "C" void f_8002E8A4() {}
