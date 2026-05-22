// 0x802FAB74 EShader::GetShaderUpdate(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xe8(3)"
extern "C" int f_802FAB74() {}
