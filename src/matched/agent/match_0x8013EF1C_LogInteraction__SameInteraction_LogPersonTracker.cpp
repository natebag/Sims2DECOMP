// 0x8013EF1C LogInteraction::SameInteraction(LogPersonTracker (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x8(4); li 10,0; lwz 0,0x0(3); lwz 11,0x10(4); cmpw 9,0; bne 0f; lwz 0,0x4(3); xor 10,11,0; subfic 9,10,0; adde 10,9,10; 0:; mr 3,10"
extern "C" int f_8013EF1C() {}
