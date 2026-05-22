// 0x802549A4 CheckThreadQueue (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,0x0(3); cmplwi 4,0; beq 0f; lwz 0,0x2e4(4); cmplwi 0,0; beq 0f; li 3,0; blr; 0:; lwz 3,0x4(3); cmplwi 3,0; beq 1f; lwz 0,0x2e0(3); cmplwi 0,0; beq 1f; li 3,0; blr; 1:; mr 5,4; b 5f; 2:; lwz 3,0x2e0(5); cmplwi 3,0; beq 3f; lwz 0,0x2e4(3); cmplw 5,0; beq 3f; li 3,0; blr; 3:; lwz 4,0x2e4(5); cmplwi 4,0; beq 4f; lwz 0,0x2e0(4); cmplw 5,0; beq 4f; li 3,0; blr; 4:; mr 5,3; 5:; cmplwi 5,0; bne 2b; li 3,1"
extern "C" int f_802549A4() {}
