// 0x8026B7F8 AptSetXMLImplementor(IAptXmlImpl (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 3,3; beqlr; stw 3,-27576(13)"
extern "C" void f_8026B7F8() {}
