// 0x8025A8E0 __DBIsExceptionMarked (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-23520(13); rlwinm 0,3,0,24,31; li 3,1; lwz 4,0x4(4); slw 0,3,0; and 3,4,0"
extern "C" int f_8025A8E0() {}
