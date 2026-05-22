// 0x8025F6B8 DVDSetAutoInvalidation (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-27788(13); stw 3,-27788(13); mr 3,0"
extern "C" void f_8025F6B8() {}
