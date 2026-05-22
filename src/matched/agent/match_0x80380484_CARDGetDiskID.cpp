// 0x80380484 CARDGetDiskID (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 0,3,272; lis 3,-32688; addi 3,3,-24000; add 3,3,0; lwz 3,0x10c(3)"
extern "C" int f_80380484() {}
