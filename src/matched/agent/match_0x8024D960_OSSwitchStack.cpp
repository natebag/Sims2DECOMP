// 0x8024D960 OSSwitchStack (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 5,1; mr 1,3; mr 3,5"
extern "C" int f_8024D960() {}
