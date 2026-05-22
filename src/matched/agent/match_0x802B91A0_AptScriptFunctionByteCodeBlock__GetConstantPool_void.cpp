// 0x802B91A0 AptScriptFunctionByteCodeBlock::GetConstantPool(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x40(4); lwz 12,0x44(4); mr 9,3; stw 11,0x0(9); stw 12,0x4(9)"
extern "C" void f_802B91A0() {}
