// 0x80374384 PSMTX44Identity (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,-17872(13); lfs f1,-17864(13); stfs f0,0x0(3); .long 0xF0230004; .long 0xF023000C; stfs f0,0x14(3); .long 0xF0230018; .long 0xF0230020; stfs f0,0x28(3); .long 0xF023002C; .long 0xF0230034; stfs f0,0x3c(3)"
extern "C" void f_80374384() {}
