// 0x802562F0 __OSCheckDeadLock (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,0x2f0(3); b 2f; 0:; cmplw 4,3; bne 1f; li 3,1; blr; 1:; lwz 4,0x2f0(4); 2:; cmplwi 4,0; beq 3f; lwz 4,0x8(4); cmplwi 4,0; bne 0b; 3:; li 3,0"
extern "C" int f_802562F0() {}
