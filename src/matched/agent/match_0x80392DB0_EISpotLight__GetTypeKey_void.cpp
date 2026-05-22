// 0x80392DB0 EISpotLight::GetTypeKey(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 8,0; addi 1,1,16"
extern "C" int f_80392DB0() {}
