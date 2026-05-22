// 0x8037CE5C MIXGetAuxB (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-22064(13); cmplwi 0,3; bne 0f; li 3,-960; blr; 0:; lwz 4,0x18(3); lis 3,-32688; addi 0,3,-30144; mulli 3,4,96; add 3,0,3; lwz 3,0x10(3)"
extern "C" int f_8037CE5C() {}
