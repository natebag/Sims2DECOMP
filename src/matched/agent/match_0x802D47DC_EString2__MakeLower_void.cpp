// 0x802D47DC EString2::MakeLower(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x0(3); lhz 9,0x0(11); cmpwi 9,0; beqlr; 0:; addi 0,9,-65; cmplwi 0,25; bgt 1f; addi 0,9,32; sth 0,0x0(11); 1:; lhzu 9,0x2(11); cmpwi 9,0; bne 0b"
extern "C" void f_802D47DC() {}
