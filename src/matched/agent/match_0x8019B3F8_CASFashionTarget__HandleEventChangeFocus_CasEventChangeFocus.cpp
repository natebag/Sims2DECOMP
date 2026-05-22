// 0x8019B3F8 CASFashionTarget::HandleEventChangeFocus(CasEventChangeFocus (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x14(4); stw 0,0x8c(3)"
extern "C" void f_8019B3F8() {}
