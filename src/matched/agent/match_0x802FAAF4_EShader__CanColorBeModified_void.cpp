// 0x802FAAF4 EShader::CanColorBeModified(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xb4(3); lwz 3,0x74(3); or 3,3,0; rlwinm 3,3,27,31,31"
extern "C" int f_802FAAF4() {}
