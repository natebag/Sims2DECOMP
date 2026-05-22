// 0x802FAB38 EShader::UndoOverrideTexture(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(3); rlwinm 0,0,0,7,5; stw 0,0x4(3)"
extern "C" void f_802FAB38() {}
