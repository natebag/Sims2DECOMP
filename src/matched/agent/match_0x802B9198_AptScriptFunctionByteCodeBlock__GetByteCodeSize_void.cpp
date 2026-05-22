// 0x802B9198 AptScriptFunctionByteCodeBlock::GetByteCodeSize(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x38(3)"
extern "C" int f_802B9198() {}
