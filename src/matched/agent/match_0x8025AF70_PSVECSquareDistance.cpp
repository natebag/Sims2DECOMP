// 0x8025AF70 PSVECSquareDistance (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0xE0030004; .long 0xE0240004; .long 0x10400828; .long 0xE0030000; .long 0xE0240000; .long 0x104200B2; .long 0x10000828; .long 0x1020103A; .long 0x10211094"
extern "C" int f_8025AF70() {}
