// 0x802FAAB4 EShader::SetSurfaceProperty(unsigned (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(3); or 0,0,4; stw 0,0x4(3)"
extern "C" void f_802FAAB4() {}
