// 0x80030560 EIWallPart::GetTypeInfo(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-19536"
extern "C" int f_80030560() {}
