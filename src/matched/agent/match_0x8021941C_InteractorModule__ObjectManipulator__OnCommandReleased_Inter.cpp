// 0x8021941C InteractorModule::ObjectManipulator::OnCommandReleased(InteractorModule::InteractorInputManager::InteractorCommand) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,8; beq 2f; bgt 0f; cmpwi 4,7; beq 1f; blr; 0:; cmpwi 4,11; beq 3f; cmpwi 4,12; beq 4f; blr; 1:; lis 9,-32704; lfs f0,-9796(9); stfs f0,0x34(3); blr; 2:; lis 9,-32704; lfs f0,-9796(9); stfs f0,0x38(3); blr; 3:; lis 9,-32704; lfs f0,-9796(9); stfs f0,0x3c(3); blr; 4:; lis 9,-32704; lfs f0,-9796(9); stfs f0,0x40(3)"
extern "C" void f_8021941C() {}
