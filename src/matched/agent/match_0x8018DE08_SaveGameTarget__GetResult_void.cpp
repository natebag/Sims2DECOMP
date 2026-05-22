// 0x8018DE08 SaveGameTarget::GetResult(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x110(3)"
extern "C" int f_8018DE08() {}
