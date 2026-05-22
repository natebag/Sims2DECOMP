// 0x8012CA20 cXPersonImpl::ClearIgnoringObject(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x53c(3)"
extern "C" void f_8012CA20() {}
