// 0x802D2C48 EString::MakeUpper(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x0(3); lbz 9,0x0(11); cmpwi 9,0; beqlr; 0:; addi 0,9,-97; cmplwi 0,25; bgt 1f; addi 0,9,-32; stb 0,0x0(11); 1:; lbzu 9,0x1(11); cmpwi 9,0; bne 0b"
extern "C" void f_802D2C48() {}
