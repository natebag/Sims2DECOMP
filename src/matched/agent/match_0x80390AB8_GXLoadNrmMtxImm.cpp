// 0x80390AB8 GXLoadNrmMtxImm (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 5,4,3; lis 4,-13311; li 0,16; addi 5,5,1024; stb 0,-32768(4); oris 0,5,8; stwu 0,-32768(4); .long 0xE0A30000; lfs f4,0x8(3); .long 0xE0630010; lfs f2,0x18(3); .long 0xE0230020; lfs f0,0x28(3); .long 0xF0A40000; stfs f4,0x0(4); .long 0xF0640000; stfs f2,0x0(4); .long 0xF0240000; stfs f0,0x0(4)"
extern "C" void f_80390AB8() {}
