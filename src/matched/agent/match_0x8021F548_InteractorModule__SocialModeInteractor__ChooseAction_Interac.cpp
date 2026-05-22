// 0x8021F548 InteractorModule::SocialModeInteractor::ChooseAction(Interaction (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; mr. 4,4; beq 0f; lwz 0,0x14(4); li 3,1; sth 0,0x60(9); blr; 0:; li 0,-2; li 3,1; sth 0,0x60(9)"
extern "C" void f_8021F548() {}
