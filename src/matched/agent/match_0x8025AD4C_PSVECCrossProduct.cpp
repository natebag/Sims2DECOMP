// 0x8025AD4C PSVECCrossProduct (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0xE0240000; lfs f2,0x8(3); .long 0xE0030000; .long 0x10C10CA0; lfs f3,0x8(4); .long 0x108100B2; .long 0x10E10018; .long 0x10A020F8; .long 0x110039B8; .long 0x11252CE0; .long 0x11454460; .long 0xF1258000; .long 0x11405050; .long 0xF1450004"
extern "C" float f_8025AD4C() {}
