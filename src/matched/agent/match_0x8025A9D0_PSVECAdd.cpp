// 0x8025A9D0 PSVECAdd (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0xE0430000; .long 0xE0840000; .long 0x10C2202A; .long 0xF0C50000; .long 0xE0638008; .long 0xE0A48008; .long 0x10E3282A; .long 0xF0E58008"
extern "C" int f_8025A9D0() {}
