// 0x80209480 InteractorModule::Interactor::NotifyClient(InteractorModule::Interactor::ClientNotificationState, (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); stw 3,0x0(4); mr 3,4; lwz 0,0x8(5); stw 0,0x4(4); lwz 0,0xc(5); mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_80209480() {}
