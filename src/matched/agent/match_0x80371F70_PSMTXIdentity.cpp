// 0x80371F70 PSMTXIdentity (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,-17964(13); lfs f1,-17968(13); .long 0xF0030008; .long 0x10400C60; .long 0xF0030018; .long 0x102104A0; .long 0xF0030020; .long 0xF0430010; .long 0xF0230000; .long 0xF0230028"
extern "C" float f_80371F70() {}
