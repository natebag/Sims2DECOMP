// 0x80209354 InteractorModule::Interactor::OnCommandUpdate(InteractorModule::InteractorInputManager::InteractorCommand, (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); cmpwi 4,7; bne 0f; addi 9,1,8; stfs f1,0x4(9); stfs f1,0x8(1); lwz 0,0x4(9); lwz 11,0x8(1); stw 0,0x38(3); stw 11,0x34(3); b 1f; 0:; cmpwi 4,8; bne 1f; addi 9,1,8; stfs f1,0x4(9); stfs f1,0x8(1); lwz 0,0x4(9); lwz 11,0x8(1); stw 0,0x40(3); stw 11,0x3c(3); 1:; addi 1,1,16"
extern "C" void f_80209354() {}
