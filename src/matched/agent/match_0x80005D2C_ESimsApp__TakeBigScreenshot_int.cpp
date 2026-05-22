// 0x80005D2C ESimsApp::TakeBigScreenshot(int, (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 5,0x4a4(3); stw 0,0x49c(3); stw 4,0x4a0(3)"
extern "C" void f_80005D2C() {}
