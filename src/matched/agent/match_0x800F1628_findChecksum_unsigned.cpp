// 0x800F1628 findChecksum(unsigned (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,0x0(4); cmpwi 4,0; beq 2f; 0:; lwz 0,0x0(4); cmpw 0,3; bne 1f; li 3,1; blr; 1:; lwz 4,0x8(4); cmpwi 4,0; bne 0b; 2:; li 3,0"
extern "C" int f_800F1628() {}
