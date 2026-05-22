// 0x80390778 global (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="fmuls f0,f0,f1; fadds f0,f2,f0; stfs f0,0x0(8); blr; .long 0xE0030000; .long 0xE0230008; .long 0xE0430010; .long 0xF0040000; .long 0xF0240000; .long 0xF0440000"
extern "C" void f_80390778() {}
