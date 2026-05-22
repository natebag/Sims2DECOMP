// 0x8021A1C0 InteractorModule::PlaceManipulator::OnStart(InteractorModule::Interactor::InteractorParams (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s8021A1C0_0; mr 3,30; mr 4,29; bl _s8021A1C0_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8021A1C0_0();
extern "C" void _s8021A1C0_1();
extern "C" void f_8021A1C0() {}
