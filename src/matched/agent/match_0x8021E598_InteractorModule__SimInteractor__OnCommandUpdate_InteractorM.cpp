// 0x8021E598 InteractorModule::SimInteractor::OnCommandUpdate(InteractorModule::InteractorInputManager::InteractorCommand, (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,7; bne 0f; stfs f1,0x34(3); blr; 0:; cmpwi 4,8; bne 1f; stfs f1,0x38(3); blr; 1:; cmpwi 4,11; bne 2f; stfs f1,0x3c(3); blr; 2:; cmpwi 4,12; bnelr; stfs f1,0x40(3)"
extern "C" void f_8021E598() {}
