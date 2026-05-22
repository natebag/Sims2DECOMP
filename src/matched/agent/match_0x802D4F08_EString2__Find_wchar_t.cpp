// 0x802D4F08 EString2::Find(wchar_t) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); li 9,0; lhz 0,0x0(3); cmpwi 0,0; beq 2f; 0:; cmpw 0,4; bne 1f; mr 3,9; blr; 1:; lhzu 0,0x2(3); addi 9,9,1; cmpwi 0,0; bne 0b; 2:; li 3,-1"
extern "C" int f_802D4F08() {}
