// 0x80374F40 PSMTX44Trans (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,-17864(13); lfs f4,-17872(13); stfs f1,0xc(3); stfs f2,0x1c(3); .long 0x10202420; stfs f3,0x2c(3); .long 0xF0838000; .long 0xF0030004; .long 0xF0230010; .long 0xF0038018; .long 0xF0030020; .long 0xF0838028; .long 0xF0030030; .long 0xF0230038"
extern "C" void f_80374F40() {}
