// 0x803778BC __ARQPushTempQueue (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-22320(13); cmplwi 0,0; bne 0f; stw 3,-22320(13); stw 3,-22316(13); blr; 0:; lwz 4,-22316(13); stw 3,0x0(4); stw 3,-22316(13)"
extern "C" void f_803778BC() {}
