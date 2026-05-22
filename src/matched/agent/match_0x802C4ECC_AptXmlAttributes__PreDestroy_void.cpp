// 0x802C4ECC AptXmlAttributes::PreDestroy(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x24(3)"
extern "C" void f_802C4ECC() {}
