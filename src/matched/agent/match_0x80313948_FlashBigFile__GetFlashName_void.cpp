// 0x80313948 FlashBigFile::GetFlashName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); addi 3,3,24"
extern "C" int f_80313948() {}
