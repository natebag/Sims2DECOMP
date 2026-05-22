// 0x802B8F30 AptScriptFunction2::GetByteCodeBase(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x34(3); addi 3,3,28"
extern "C" int f_802B8F30() {}
