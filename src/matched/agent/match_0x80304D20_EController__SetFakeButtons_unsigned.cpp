// 0x80304D20 EController::SetFakeButtons(unsigned (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x1b0(3)"
extern "C" void f_80304D20() {}
