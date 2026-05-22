// 0x8025BF9C DVDGetFSTLocation (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-23512(13); lwz 3,0x38(3)"
extern "C" int f_8025BF9C() {}
