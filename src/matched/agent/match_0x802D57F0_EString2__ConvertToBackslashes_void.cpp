// 0x802D57F0 EString2::ConvertToBackslashes(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); lhz 0,0x0(3); cmpwi 0,0; beqlr; li 9,92; 0:; cmpwi 0,47; bne 1f; sth 9,0x0(3); 1:; lhzu 0,0x2(3); cmpwi 0,0; bne 0b"
extern "C" void f_802D57F0() {}
