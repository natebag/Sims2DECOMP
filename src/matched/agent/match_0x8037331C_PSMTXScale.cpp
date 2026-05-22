// 0x8037331C PSMTXScale (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,-17964(13); stfs f1,0x0(3); .long 0xF0030004; .long 0xF003000C; stfs f2,0x14(3); .long 0xF0030018; .long 0xF0030020; stfs f3,0x28(3); stfs f0,0x2c(3)"
extern "C" void f_8037331C() {}
