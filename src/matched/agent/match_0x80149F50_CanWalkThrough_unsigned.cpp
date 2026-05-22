// 0x80149F50 CanWalkThrough(unsigned (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="xori 3,3,3; subfic 0,3,0; adde 3,0,3"
extern "C" int f_80149F50() {}
