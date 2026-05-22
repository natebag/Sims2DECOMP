// 0x802FAAC4 EShader::ClearSurfaceProperty(unsigned (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(3); andc 4,0,4; stw 4,0x4(3)"
extern "C" void f_802FAAC4() {}
