// 0x802601A0 __DVDIsBlockInWaitingQueue (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 4,-32694; lwzu 0,-17096(4); cmplw 0,4; beq 3f; mr 5,0; b 2f; 0:; cmplw 5,3; bne 1f; li 3,1; blr; 1:; lwz 5,0x0(5); 2:; cmplw 5,4; bne 0b; 3:; lwzu 0,0x8(4); cmplw 0,4; beq 7f; mr 5,0; b 6f; 4:; cmplw 5,3; bne 5f; li 3,1; blr; 5:; lwz 5,0x0(5); 6:; cmplw 5,4; bne 4b; 7:; lwzu 0,0x8(4); cmplw 0,4; beq 11f; mr 5,0; b 10f; 8:; cmplw 5,3; bne 9f; li 3,1; blr; 9:; lwz 5,0x0(5); 10:; cmplw 5,4; bne 8b; 11:; lwzu 0,0x8(4); cmplw 0,4; beq 15f; mr 5,0; b 14f; 12:; cmplw 5,3; bne 13f; li 3,1; blr; 13:; lwz 5,0x0(5); 14:; cmplw 5,4; bne 12b; 15:; li 3,0"
extern "C" int f_802601A0() {}
