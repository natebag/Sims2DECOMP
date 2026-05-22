// 0x80300AF0 EWindow::GetCurrent3DWindow(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-26704(13)"
extern "C" int f_80300AF0() {}
