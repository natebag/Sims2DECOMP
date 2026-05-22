// 0x802D4154 EString2::StrLenC16(unsigned (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 3,3; bne 0f; li 3,0; blr; 0:; lhz 0,0x0(3); li 9,0; cmpwi 0,0; beq 2f; 1:; lhzu 0,0x2(3); addi 9,9,1; cmpwi 0,0; bne 1b; 2:; mr 3,9"
extern "C" int f_802D4154() {}
