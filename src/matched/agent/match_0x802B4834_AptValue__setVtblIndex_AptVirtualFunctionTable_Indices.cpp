// 0x802B4834 AptValue::setVtblIndex(AptVirtualFunctionTable_Indices) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); rlwimi 0,4,0,25,31; stw 0,0x0(3)"
extern "C" void f_802B4834() {}
