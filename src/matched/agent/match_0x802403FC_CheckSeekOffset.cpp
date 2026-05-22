// 0x802403FC CheckSeekOffset (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 0,22277; ori 0,0,65535; cmpw 3,0; lis 3,5; ori 3,3,8448; bgtlr; li 3,0"
extern "C" int f_802403FC() {}
