// 0x8025AA28 PSVECSubtract (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0xE0430000; .long 0xE0840000; .long 0x10C22028; .long 0xF0C50000; .long 0xE0638008; .long 0xE0A48008; .long 0x10E32828; .long 0xF0E58008"
extern "C" int f_8025AA28() {}
