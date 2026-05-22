// 0x80372008 PSMTXCopy (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0xE0030000; .long 0xF0040000; .long 0xE0230008; .long 0xF0240008; .long 0xE0430010; .long 0xF0440010; .long 0xE0630018; .long 0xF0640018; .long 0xE0830020; .long 0xF0840020; .long 0xE0A30028; .long 0xF0A40028"
extern "C" int f_80372008() {}
