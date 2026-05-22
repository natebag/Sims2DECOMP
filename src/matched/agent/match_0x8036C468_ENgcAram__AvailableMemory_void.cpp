// 0x8036C468 ENgcAram::AvailableMemory(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-25824(13); lwz 0,-25828(13); addis 3,3,-256; subf 3,3,0"
extern "C" int f_8036C468() {}
