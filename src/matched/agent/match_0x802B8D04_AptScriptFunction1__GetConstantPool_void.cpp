// 0x802B8D04 AptScriptFunction1::GetConstantPool(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 8,0x34(4); mr 11,3; lwz 9,0x10(8); lwz 10,0x14(8); stw 9,0x0(11); stw 10,0x4(11)"
extern "C" void f_802B8D04() {}
