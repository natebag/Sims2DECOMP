// 0x8015BBE8 ObjectDataID::SetNamespaceID(unsigned (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x0(3)"
extern "C" void f_8015BBE8() {}
