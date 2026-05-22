// 0x801B9458 INGTarget::SetRefrigeratorLevel(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-30260(13); stw 3,-30260(13); mr 3,0"
extern "C" void f_801B9458() {}
