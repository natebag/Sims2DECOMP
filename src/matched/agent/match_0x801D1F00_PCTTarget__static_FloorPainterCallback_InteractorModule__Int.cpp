// 0x801D1F00 PCTTarget::static_FloorPainterCallback(InteractorModule::Interactor::CallbackData (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 4,3; lwz 3,0x4(4); cmpwi 3,0; beq 0f; bl _s801D1F00_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801D1F00_0();
extern "C" void f_801D1F00() {}
