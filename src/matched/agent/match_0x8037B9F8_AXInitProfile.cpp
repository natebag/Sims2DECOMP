// 0x8037B9F8 AXInitProfile (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 5,0; stw 3,-22088(13); li 0,1; stw 4,-22084(13); stw 5,-22080(13); stw 0,-22076(13)"
extern "C" void f_8037B9F8() {}
