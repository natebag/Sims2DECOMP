// 0x802D85CC EThread::GetThreadFromStackPtr(void (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 11,3; beq 2f; lwz 3,-22764(13); cmpwi 3,0; beq 2f; 0:; lwz 9,0x31c(3); cmplw 11,9; blt 1f; lwz 0,0x320(3); add 0,9,0; cmplw 11,0; bltlr; 1:; lwz 3,0x334(3); cmpwi 3,0; bne 0b; 2:; li 3,0"
extern "C" int f_802D85CC() {}
