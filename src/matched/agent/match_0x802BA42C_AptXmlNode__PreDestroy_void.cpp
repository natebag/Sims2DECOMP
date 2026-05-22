// 0x802BA42C AptXmlNode::PreDestroy(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x24(3)"
extern "C" void f_802BA42C() {}
