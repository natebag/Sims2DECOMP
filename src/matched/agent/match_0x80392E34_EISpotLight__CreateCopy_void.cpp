// 0x80392E34 EISpotLight::CreateCopy(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 3,1,8; crxor 6,6,6; bl _s80392E34_0; bl _s80392E34_1; lwz 0,0x414(1); mtspr 8,0; addi 1,1,1040"
extern "C" void _s80392E34_0();
extern "C" void _s80392E34_1();
extern "C" int f_80392E34() {}
