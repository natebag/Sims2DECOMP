// 0x802D8610 EThread::IsValidMemoryBlock(void (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 10,3; beq 4f; lwz 9,-22764(13); cmpwi 9,0; beq 3f; add 11,10,4; 0:; lwz 3,0x31c(9); cmplw 11,3; ble 2f; lwz 0,0x320(9); add 4,3,0; cmplw 10,4; bge 2f; cmplw 10,3; blt 1f; cmplw 11,4; li 3,1; blelr; 1:; li 3,0; blr; 2:; lwz 9,0x334(9); cmpwi 9,0; bne 0b; 3:; li 3,1; blr; 4:; li 3,1"
extern "C" int f_802D8610() {}
