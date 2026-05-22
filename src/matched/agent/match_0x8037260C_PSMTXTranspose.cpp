// 0x8037260C PSMTXTranspose (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,-17964(13); .long 0xE0230000; stfs f0,0x2c(4); .long 0xE0430010; .long 0x10811420; .long 0xE0638008; .long 0x10A114E0; .long 0xE0438018; .long 0xF0840000; .long 0xE0230020; .long 0x10431420; .long 0xF0A40010; .long 0x10810420; .long 0xF0440020; .long 0x10A104A0; .long 0xF0840008; lfs f3,0x28(3); .long 0xF0A40018; stfs f3,0x28(4)"
extern "C" void f_8037260C() {}
