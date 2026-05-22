// 0x802096F8 InteractorModule::InteractorInputManager::InstanceData::InstanceData(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mr 9,3; li 0,0; stw 0,0x0(9); addi 11,9,8; stw 0,0x4(9); li 10,-1; stw 0,0x4(11); stw 10,0x14(9); stw 0,0x1c(9); stb 0,0x10(9); addi 1,1,32"
extern "C" void f_802096F8() {}
