// 0x8038A7BC EILight::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8038A824" lines="rlwimi 10,0,4,25,27; rlwimi 10,11,7,20,24"
extern "C" void f_8038A824();
extern "C" void f_8038A7BC() {}
