// 0x8006EBD4 SimImageMaker::SetSkinShader(EShader (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x8c(3)"
extern "C" void f_8006EBD4() {}
