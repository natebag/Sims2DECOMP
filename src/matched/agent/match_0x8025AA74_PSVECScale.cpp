// 0x8025AA74 PSVECScale (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0xE0030000; .long 0xE0438008; .long 0x10000058; .long 0xF0040000; .long 0x10020058; .long 0xF0048008"
extern "C" int f_8025AA74() {}
