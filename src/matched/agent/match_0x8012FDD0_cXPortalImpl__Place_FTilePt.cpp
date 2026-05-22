// 0x8012FDD0 cXPortalImpl::Place(FTilePt (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 3,0x0(30); bl _s8012FDD0_0; mr 3,30; li 4,1; bl _s8012FDD0_1; lwz 9,0x0(30); lwz 11,0x0(9); lwz 3,0x58(11); bl _s8012FDD0_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8012FDD0_0();
extern "C" void _s8012FDD0_1();
extern "C" void _s8012FDD0_2();
extern "C" void f_8012FDD0() {}
