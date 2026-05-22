// 0x80152F74 XRoute::CountGoals(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); lwz 3,0x4(3); subf 3,0,3; srawi 3,3,4"
extern "C" int f_80152F74() {}
