// 0x801F1974 INVTarget::WallManipulatorCallback(InteractorModule::WallManipulator::CallbackData (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 4,3; lwz 3,0x4(4); bl _s801F1974_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801F1974_0();
extern "C" void f_801F1974() {}
