// 0x8007F074 DlgWrapper::SetPlayer(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xcc(3); stw 4,0xcc(3); mr 3,0"
extern "C" void f_8007F074() {}
