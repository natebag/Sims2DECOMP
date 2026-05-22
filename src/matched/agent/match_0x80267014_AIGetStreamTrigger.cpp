// 0x80267014 AIGetStreamTrigger (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; addi 3,3,27648; lwz 3,0xc(3)"
extern "C" int f_80267014() {}
