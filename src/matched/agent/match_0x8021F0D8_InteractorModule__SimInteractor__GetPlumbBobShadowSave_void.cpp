// 0x8021F0D8 InteractorModule::SimInteractor::GetPlumbBobShadowSave(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x190(3); li 0,-1; stw 0,0x190(3); mr 3,9"
extern "C" void f_8021F0D8() {}
