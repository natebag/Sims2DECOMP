// 0x80383660 InteractorModule::WallManipulator::GetAnchorDrawPos(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8038366C" lines="li 3,0"
extern "C" void f_8038366C();
extern "C" void f_80383660() {}
