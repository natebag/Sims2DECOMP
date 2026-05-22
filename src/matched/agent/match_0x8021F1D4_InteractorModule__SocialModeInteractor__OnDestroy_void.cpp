// 0x8021F1D4 InteractorModule::SocialModeInteractor::OnDestroy(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s8021F1D4_0; mr 4,30; bl _s8021F1D4_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8021F1D4_0();
extern "C" void _s8021F1D4_1();
extern "C" void f_8021F1D4() {}
