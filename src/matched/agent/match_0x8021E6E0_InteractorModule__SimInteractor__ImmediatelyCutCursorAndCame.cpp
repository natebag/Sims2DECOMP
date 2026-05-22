// 0x8021E6E0 InteractorModule::SimInteractor::ImmediatelyCutCursorAndCameraToPos(EVec3 (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,1; mr 9,4; stw 0,0x18c(3); addi 8,3,8; lwz 11,0x0(9); lwz 10,0x4(9); lwz 0,0x8(9); stw 11,0x8(3); stw 0,0x8(8); stw 10,0x4(8); lwz 3,0x4(3); bl _s8021E6E0_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8021E6E0_0();
extern "C" void f_8021E6E0() {}
