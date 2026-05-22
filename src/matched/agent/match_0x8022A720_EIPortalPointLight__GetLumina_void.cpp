// 0x8022A720 EIPortalPointLight::GetLumina(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32704; lfs f0,0xc8(3); lfs f13,-5108(9); lfs f1,0x8c(3); fmuls f0,f0,f13; fmuls f1,f1,f0; fmuls f1,f1,f0"
extern "C" float f_8022A720() {}
