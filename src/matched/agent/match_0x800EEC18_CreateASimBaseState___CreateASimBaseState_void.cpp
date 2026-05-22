// 0x800EEC18 CreateASimBaseState::~CreateASimBaseState(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_800EECE0" lines="lwz 9,0x3c(1); mr 10,7; lwz 0,0x40(1); stw 9,0x2c(1); stw 0,0x30(1); lwz 9,0x38(1); lwz 11,0x8(6); lwz 0,0x4(6); stw 9,0x8(1); stw 0,0x4(7); stw 11,0x8(7); stw 9,0x28(1)"
extern "C" void f_800EECE0();
extern "C" void f_800EEC18() {}
