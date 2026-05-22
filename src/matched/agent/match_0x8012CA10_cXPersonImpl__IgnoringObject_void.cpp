// 0x8012CA10 cXPersonImpl::IgnoringObject(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x53c(3)"
extern "C" int f_8012CA10() {}
