// 0x8015BBF0 ObjectDataID::SetResourceID(unsigned (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="sth 4,0x4(3)"
extern "C" void f_8015BBF0() {}
