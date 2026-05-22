// 0x802B8F48 AptScriptFunction2::GetConstantPool(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 8,0x34(4); mr 11,3; lwz 9,0x14(8); lwz 10,0x18(8); stw 9,0x0(11); stw 10,0x4(11)"
extern "C" void f_802B8F48() {}
