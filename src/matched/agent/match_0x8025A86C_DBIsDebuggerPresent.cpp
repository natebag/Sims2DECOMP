// 0x8025A86C DBIsDebuggerPresent (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-23520(13); cmplwi 3,0; bne 0f; li 3,0; blr; 0:; lwz 3,0x0(3)"
extern "C" int f_8025A86C() {}
