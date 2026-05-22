// 0x80095874 TheSimsStartScreenStateMachine::Reset(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 3,-24644(13); bl _s80095874_0; lis 9,-32697; lwz 3,-26524(13); li 0,1; li 4,0; stw 0,0x6244(9); li 5,0; bl _s80095874_1; lis 9,-32706; mr 3,30; lfs f1,-30744(9); li 4,0; bl _s80095874_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80095874_0();
extern "C" void _s80095874_1();
extern "C" void _s80095874_2();
extern "C" void f_80095874() {}
