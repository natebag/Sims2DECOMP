// 0x80148D28 TreeStack::GetMemReserved(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); lwz 3,0x4(3); subf 3,0,3"
extern "C" int f_80148D28() {}
