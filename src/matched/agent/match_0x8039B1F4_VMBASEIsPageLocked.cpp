// 0x8039B1F4 VMBASEIsPageLocked (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-21528(13); lbzx 3,4,3"
extern "C" int f_8039B1F4() {}
