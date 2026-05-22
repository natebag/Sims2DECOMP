// 0x80035120 ESim::GetTypeInfoStatic(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-19416"
extern "C" int f_80035120() {}
