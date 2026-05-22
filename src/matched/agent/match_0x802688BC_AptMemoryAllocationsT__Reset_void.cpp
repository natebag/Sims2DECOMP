// 0x802688BC AptMemoryAllocationsT::Reset(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x1c(3); stw 0,0x0(3); stw 0,0x4(3); stw 0,0x10(3); stw 0,0x14(3); stw 0,0x8(3); stw 0,0xc(3); stw 0,0x18(3)"
extern "C" void f_802688BC() {}
