// 0x8021F0C8 InteractorModule::SimInteractor::SetPlumbBobShadowSave(unsigned (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 4,65535; beqlr; stw 4,0x190(3)"
extern "C" void f_8021F0C8() {}
