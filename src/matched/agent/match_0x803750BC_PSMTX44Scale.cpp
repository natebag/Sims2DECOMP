// 0x803750BC PSMTX44Scale (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,-17864(13); lfs f4,-17872(13); stfs f1,0x0(3); .long 0xF0030004; .long 0xF003000C; stfs f2,0x14(3); .long 0xF0030018; .long 0xF0030020; stfs f3,0x28(3); .long 0xF003002C; .long 0xF0030034; stfs f4,0x3c(3)"
extern "C" void f_803750BC() {}
