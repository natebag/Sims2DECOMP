// 0x8025ACE0 PSVECDotProduct (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0xE0430004; .long 0xE0640004; .long 0x104200F2; .long 0xE0A30000; .long 0xE0840000; .long 0x1065113A; .long 0x10231094"
extern "C" int f_8025ACE0() {}
