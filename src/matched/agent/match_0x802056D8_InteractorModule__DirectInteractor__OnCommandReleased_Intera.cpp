// 0x802056D8 InteractorModule::DirectInteractor::OnCommandReleased(InteractorModule::InteractorInputManager::InteractorCommand) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; bne 0f; stw 4,0x30(3); blr; 0:; cmpwi 4,18; bne 1f; lis 9,-32704; lfs f0,-13504(9); stfs f0,0x34(3); blr; 1:; cmpwi 4,19; bne 2f; lis 9,-32704; lfs f0,-13504(9); stfs f0,0x38(3); blr; 2:; cmpwi 4,11; bne 3f; lis 9,-32704; lfs f0,-13504(9); stfs f0,0x3c(3); blr; 3:; cmpwi 4,12; bnelr; lis 9,-32704; lfs f0,-13504(9); stfs f0,0x40(3)"
extern "C" void f_802056D8() {}
