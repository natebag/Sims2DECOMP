// 0x803907A4 Copy6Floats (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0xE0030000; .long 0xE0230008; .long 0xE0430010; .long 0xF0040000; .long 0xF0240008; .long 0xF0440010"
extern "C" int f_803907A4() {}
