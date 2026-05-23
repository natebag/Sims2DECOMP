// 0x80304D10 EController::IsControlFake(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x1ac(3)"
extern "C" int f_80304D10() {}
