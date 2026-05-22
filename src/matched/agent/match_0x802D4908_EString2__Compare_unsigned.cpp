// 0x802D4908 EString2::Compare(unsigned (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); 0:; lhz 9,0x0(3); lhz 0,0x0(4); cmplw 9,0; bge 1f; li 3,-1; blr; 1:; bgt 2f; lhzu 0,0x2(3); addi 4,4,2; cmpwi 0,0; bne 0b; lhz 0,0x0(4); cmpwi 0,0; bne 0b; li 3,0; blr; 2:; li 3,1"
extern "C" int f_802D4908() {}
