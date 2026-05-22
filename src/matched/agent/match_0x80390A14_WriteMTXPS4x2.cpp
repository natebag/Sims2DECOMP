// 0x80390A14 WriteMTXPS4x2 (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0xE0030000; .long 0xE0230008; .long 0xE0430010; .long 0xE0630018; .long 0xF0040000; .long 0xF0240000; .long 0xF0440000; .long 0xF0640000"
extern "C" int f_80390A14() {}
