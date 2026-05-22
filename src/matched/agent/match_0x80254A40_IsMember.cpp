// 0x80254A40 IsMember (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); b 2f; 0:; cmplw 4,3; bne 1f; li 3,1; blr; 1:; lwz 3,0x2e0(3); 2:; cmplwi 3,0; bne 0b; li 3,0"
extern "C" int f_80254A40() {}
