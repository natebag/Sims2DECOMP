// 0x80252544 __OSSyncSram (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32694; addi 3,3,-24704; lwz 3,0x4c(3)"
extern "C" int f_80252544() {}
