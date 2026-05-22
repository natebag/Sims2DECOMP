// 0x803125C0 EResPrefetch::AcquireBuffer(void (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 4,0x408(3); stw 0,0x404(3); stw 4,0x40c(3)"
extern "C" void f_803125C0() {}
