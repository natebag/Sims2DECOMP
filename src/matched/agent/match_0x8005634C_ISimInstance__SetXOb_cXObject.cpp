// 0x8005634C ISimInstance::SetXOb(cXObject (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x328(3)"
extern "C" void f_8005634C() {}
