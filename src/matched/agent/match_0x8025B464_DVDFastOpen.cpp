// 0x8025B464 DVDFastOpen (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,0; blt 2f; lwz 0,-23500(13); cmplw 3,0; bge 2f; mulli 6,3,12; lwz 3,-23508(13); lwzx 0,3,6; rlwinm. 0,0,0,0,7; bne 0f; li 0,0; b 1f; 0:; li 0,1; 1:; cmpwi 0,0; beq 3f; 2:; li 3,0; blr; 3:; add 3,3,6; lwz 5,0x4(3); li 0,0; li 3,1; stw 5,0x30(4); lwz 5,-23508(13); add 5,5,6; lwz 5,0x8(5); stw 5,0x34(4); stw 0,0x38(4); stw 0,0xc(4)"
extern "C" void f_8025B464() {}
