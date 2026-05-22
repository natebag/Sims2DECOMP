// 0x801E70B8 PAZTarget::GetTLA(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32705; addi 3,3,16212"
extern "C" int f_801E70B8() {}
