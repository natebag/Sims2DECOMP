// 0x80390B08 GXLoadNrmMtxImm3x3 (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 5,4,3; lis 4,-13311; li 0,16; addi 5,5,1024; stb 0,-32768(4); oris 0,5,8; stwu 0,-32768(4); .long 0xE0830000; .long 0xE0630008; .long 0xE0430010; .long 0xE0230018; lfs f0,0x20(3); .long 0xF0840000; .long 0xF0640000; .long 0xF0440000; .long 0xF0240000; stfs f0,0x0(4)"
extern "C" void f_80390B08() {}
