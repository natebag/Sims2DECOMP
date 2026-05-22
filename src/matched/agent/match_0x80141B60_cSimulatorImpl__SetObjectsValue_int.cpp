// 0x80141B60 cSimulatorImpl::SetObjectsValue(int) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 0,26843; srawi 11,4,31; ori 0,0,35757; stw 4,0x88(3); mulhw 0,4,0; srawi 0,0,12; subf 0,11,0; mulli 9,0,10000; sth 0,0x58(3); subf 4,9,4; sth 4,0x56(3)"
extern "C" void f_80141B60() {}
