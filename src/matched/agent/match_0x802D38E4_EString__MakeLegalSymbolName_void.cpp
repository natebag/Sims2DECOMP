// 0x802D38E4 EString::MakeLegalSymbolName(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x0(3); lbz 9,0x0(11); cmpwi 9,0; beqlr; li 10,95; 0:; addi 0,9,-97; cmplwi 0,25; bgt 1f; addi 0,9,-32; stb 0,0x0(11); b 2f; 1:; addi 0,9,-65; cmplwi 0,25; ble 2f; addi 0,9,-48; cmplwi 0,9; ble 2f; stb 10,0x0(11); 2:; lbzu 9,0x1(11); cmpwi 9,0; bne 0b"
extern "C" void f_802D38E4() {}
