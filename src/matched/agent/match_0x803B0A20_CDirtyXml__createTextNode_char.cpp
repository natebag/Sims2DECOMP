// 0x803B0A20 CDirtyXml::createTextNode(char (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_803B0A3C" lines="bl _s803B0A20_0"
extern "C" void _s803B0A20_0();
extern "C" void f_803B0A3C();
extern "C" void f_803B0A20() {}
