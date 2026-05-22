// 0x802B9190 AptScriptFunctionByteCodeBlock::GetByteCodeBase(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x34(3)"
extern "C" int f_802B9190() {}
