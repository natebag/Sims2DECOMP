// 0x80327E38 EResourceMap::IsEmpty(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x4(3); subfic 0,3,0; adde 3,0,3"
extern "C" int f_80327E38() {}
