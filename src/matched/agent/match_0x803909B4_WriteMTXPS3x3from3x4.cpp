// 0x803909B4 WriteMTXPS3x3from3x4 (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0xE0030000; lfs f1,0x8(3); .long 0xE0430010; lfs f3,0x18(3); .long 0xE0830020; lfs f5,0x28(3); .long 0xF0040000; stfs f1,0x0(4); .long 0xF0440000; stfs f3,0x0(4); .long 0xF0840000; stfs f5,0x0(4)"
extern "C" void f_803909B4() {}
