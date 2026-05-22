// 0x802FAB68 EShader::IsCylindricalFacer(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x4(3); rlwinm 3,3,29,31,31"
extern "C" int f_802FAB68() {}
