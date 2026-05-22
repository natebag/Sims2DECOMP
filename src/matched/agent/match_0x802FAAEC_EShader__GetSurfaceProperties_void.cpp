// 0x802FAAEC EShader::GetSurfaceProperties(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x4(3)"
extern "C" int f_802FAAEC() {}
