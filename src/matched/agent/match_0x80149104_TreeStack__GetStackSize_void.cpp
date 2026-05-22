// 0x80149104 TreeStack::GetStackSize(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x8(3); lwz 3,0xc(3); subf 3,0,3; srawi 3,3,2"
extern "C" int f_80149104() {}
