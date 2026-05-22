// 0x80380A5C CARDGetFastMode (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 0,-22006(13); cmplwi 0,0; beq 0f; li 3,1; blr; 0:; li 3,0"
extern "C" int f_80380A5C() {}
