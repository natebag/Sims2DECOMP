// 0x803909E8 WriteMTXPS3x3 (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0xE0030000; .long 0xE0230008; .long 0xE0430010; .long 0xE0630018; lfs f4,0x20(3); .long 0xF0040000; .long 0xF0240000; .long 0xF0440000; .long 0xF0640000; stfs f4,0x0(4)"
extern "C" void f_803909E8() {}
