// 0x80313310 EResPrefetchFile::ValidateStreamPos(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x34(3); lwz 0,0x40(3); lwz 9,0x3c(3); lwz 3,0x30(3); subf 0,9,0; subf 3,11,3; subfc 3,3,0; li 3,0; adde 3,3,3"
extern "C" int f_80313310() {}
