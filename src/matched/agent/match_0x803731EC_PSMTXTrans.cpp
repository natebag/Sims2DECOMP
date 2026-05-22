// 0x803731EC PSMTXTrans (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,-17964(13); lfs f4,-17968(13); stfs f1,0xc(3); stfs f2,0x1c(3); .long 0xF0030004; .long 0xF0030020; stfs f0,0x10(3); stfs f4,0x14(3); stfs f0,0x18(3); stfs f4,0x28(3); stfs f3,0x2c(3); stfs f4,0x0(3)"
extern "C" void f_803731EC() {}
