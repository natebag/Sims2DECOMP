// 0x80250D70 OSGetSavedRegion (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 5,-32694; addi 5,5,-24816; lwz 0,0xc(5); stw 0,0x0(3); lwz 0,0x10(5); stw 0,0x0(4)"
extern "C" void f_80250D70() {}
