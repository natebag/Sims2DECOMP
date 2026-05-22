// 0x802D51C8 EString2::Replace(wchar_t, (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); lhz 0,0x0(3); cmpwi 0,0; beqlr; 0:; cmpw 0,4; bne 1f; sth 5,0x0(3); 1:; lhzu 0,0x2(3); cmpwi 0,0; bne 0b"
extern "C" void f_802D51C8() {}
