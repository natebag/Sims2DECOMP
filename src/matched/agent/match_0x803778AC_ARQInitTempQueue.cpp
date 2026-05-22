// 0x803778AC __ARQInitTempQueue (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,-22320(13); stw 0,-22316(13)"
extern "C" void f_803778AC() {}
