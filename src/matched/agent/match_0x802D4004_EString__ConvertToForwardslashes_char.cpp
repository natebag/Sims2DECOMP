// 0x802D4004 EString::ConvertToForwardslashes(char (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,0x0(3); cmpwi 0,0; beqlr; li 9,47; 0:; cmpwi 0,92; bne 1f; stb 9,0x0(3); 1:; lbzu 0,0x1(3); cmpwi 0,0; bne 0b"
extern "C" void f_802D4004() {}
