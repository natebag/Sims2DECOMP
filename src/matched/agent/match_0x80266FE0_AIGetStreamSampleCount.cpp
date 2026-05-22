// 0x80266FE0 AIGetStreamSampleCount (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; addi 3,3,27648; lwz 3,0x8(3)"
extern "C" int f_80266FE0() {}
