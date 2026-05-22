// 0x802D47A4 EString2::MakeUpper(void) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x0(3); lhz 9,0x0(11); cmpwi 9,0; beqlr; 0:; addi 0,9,-97; cmplwi 0,25; bgt 1f; addis 9,9,1; addi 9,9,-32; sth 9,0x0(11); 1:; lhzu 9,0x2(11); cmpwi 9,0; bne 0b"
extern "C" void f_802D47A4() {}
