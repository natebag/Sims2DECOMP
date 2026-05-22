// 0x8020EEC0 TreeSim::SetBreakOnCallTreeStringFailure(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8020EECC" lines="addi 10,9,-1"
extern "C" void f_8020EECC();
extern "C" void f_8020EEC0() {}
