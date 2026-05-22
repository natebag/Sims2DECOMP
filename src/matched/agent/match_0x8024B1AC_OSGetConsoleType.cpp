// 0x8024B1AC OSGetConsoleType (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-23744(13); cmplwi 3,0; beq 0f; lwz 3,0x2c(3); cmplwi 3,0; bne 1f; 0:; lis 3,4096; addi 3,3,2; b 1f; 1:"
extern "C" int f_8024B1AC() {}
