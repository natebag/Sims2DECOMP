// 0x802B8CEC AptScriptFunction1::GetByteCodeBase(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x34(3); addi 3,3,24"
extern "C" int f_802B8CEC() {}
