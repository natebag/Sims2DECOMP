// 0x802933E0 AptCIH::getParentCount(void) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x48(3); li 3,0; cmpwi 9,0; beqlr; 0:; lwz 9,0x48(9); addi 3,3,1; cmpwi 9,0; bne 0b"
extern "C" int f_802933E0() {}
