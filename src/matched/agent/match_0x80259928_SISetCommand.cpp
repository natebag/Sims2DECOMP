// 0x80259928 SISetCommand (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 0,3,12; lis 3,-13312; addi 3,3,25600; stwx 4,3,0"
extern "C" void f_80259928() {}
