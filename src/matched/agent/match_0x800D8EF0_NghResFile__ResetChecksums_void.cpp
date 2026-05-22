// 0x800D8EF0 NghResFile::ResetChecksums(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,-31924(13); stw 0,-31928(13)"
extern "C" void f_800D8EF0() {}
