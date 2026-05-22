// 0x80328AB0 EffectsSequencerManager::AllocateAndLoadResource(EFile (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,6; mr 29,4; bl _s80328AB0_0; li 5,0; li 4,20; bl _s80328AB0_1; bl _s80328AB0_2; mr 30,3; mr 4,29; stw 28,0x8(30); bl _s80328AB0_3; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80328AB0_0();
extern "C" void _s80328AB0_1();
extern "C" void _s80328AB0_2();
extern "C" void _s80328AB0_3();
extern "C" void f_80328AB0() {}
