// 0x802B480C AptValue::setRefCount(unsigned (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 4,4095; ble 0f; lwz 0,0x0(3); li 4,4095; ori 0,0,128; stw 0,0x0(3); 0:; lwz 0,0x0(3); rlwimi 0,4,14,6,17; stw 0,0x0(3)"
extern "C" void f_802B480C() {}
