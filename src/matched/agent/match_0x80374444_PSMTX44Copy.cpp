// 0x80374444 PSMTX44Copy (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0xE0230000; .long 0xF0240000; .long 0xE0230008; .long 0xF0240008; .long 0xE0230010; .long 0xF0240010; .long 0xE0230018; .long 0xF0240018; .long 0xE0230020; .long 0xF0240020; .long 0xE0230028; .long 0xF0240028; .long 0xE0230030; .long 0xF0240030; .long 0xE0230038; .long 0xF0240038"
extern "C" int f_80374444() {}
