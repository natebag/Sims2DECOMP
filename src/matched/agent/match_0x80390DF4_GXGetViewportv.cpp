// 0x80390DF4 GXGetViewportv (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-17720(13); addi 4,4,1268; .long 0xE0440000; .long 0xE0240008; .long 0xE0040010; .long 0xF0430000; .long 0xF0230008; .long 0xF0030010"
extern "C" int f_80390DF4() {}
