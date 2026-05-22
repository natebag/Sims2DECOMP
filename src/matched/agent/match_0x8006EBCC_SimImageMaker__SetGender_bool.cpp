// 0x8006EBCC SimImageMaker::SetGender(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x88(3)"
extern "C" void f_8006EBCC() {}
