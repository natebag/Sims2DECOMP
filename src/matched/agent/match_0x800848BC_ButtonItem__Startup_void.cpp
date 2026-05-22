// 0x800848BC ButtonItem::Startup(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s800848BC_0; lwz 4,-21404(13); mr 3,30; bl _s800848BC_1; lfs f0,-21376(13); addi 9,30,32; mr 3,9; stfs f0,0x34(9); bl _s800848BC_2; lwz 0,0x4(30); ori 0,0,2; stw 0,0x4(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800848BC_0();
extern "C" void _s800848BC_1();
extern "C" void _s800848BC_2();
extern "C" void f_800848BC() {}
