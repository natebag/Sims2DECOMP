// 0x8012CA18 cXPersonImpl::SetIgnoringObject(cXObject (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x53c(3)"
extern "C" void f_8012CA18() {}
