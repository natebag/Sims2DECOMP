// 0x8025FCF0 DVDGetCurrentDiskID (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32768"
extern "C" int f_8025FCF0() {}
