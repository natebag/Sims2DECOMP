// 0x802C694C EFile::SetDevice(EFile::DeviceType) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x10(3)"
extern "C" void f_802C694C() {}
