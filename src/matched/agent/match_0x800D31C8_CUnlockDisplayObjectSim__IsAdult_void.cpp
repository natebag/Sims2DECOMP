// 0x800D31C8 CUnlockDisplayObjectSim::IsAdult(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_800D3200" lines="stw 20,0x20(24)"
extern "C" void f_800D3200();
extern "C" void f_800D31C8() {}
