// 0x802934D0 AptCIH::isParent(AptCIH (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x48(3); cmpwi 9,0; beq 2f; 0:; cmpw 4,9; bne 1f; li 3,1; blr; 1:; lwz 9,0x48(9); cmpwi 9,0; bne 0b; 2:; li 3,0"
extern "C" int f_802934D0() {}
