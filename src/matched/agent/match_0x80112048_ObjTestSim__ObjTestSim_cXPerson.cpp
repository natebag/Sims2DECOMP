// 0x80112048 ObjTestSim::ObjTestSim(cXPerson (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; li 0,0; stw 4,0x0(9); stw 0,0x18(9); stw 0,0x4(9)"
extern "C" void f_80112048() {}
