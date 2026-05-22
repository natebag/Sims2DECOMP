// 0x8025993C SIGetCommand (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 0,3,12; lis 3,-13312; addi 3,3,25600; lwzx 3,3,0"
extern "C" int f_8025993C() {}
