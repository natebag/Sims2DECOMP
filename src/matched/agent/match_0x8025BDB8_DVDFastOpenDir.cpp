// 0x8025BDB8 DVDFastOpenDir (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,0; blt 2f; lwz 0,-23500(13); cmplw 3,0; bge 2f; mulli 6,3,12; lwz 5,-23508(13); lwzx 0,5,6; rlwinm. 0,0,0,0,7; bne 0f; li 0,0; b 1f; 0:; li 0,1; 1:; cmpwi 0,0; bne 3f; 2:; li 3,0; blr; 3:; stw 3,0x0(4); addi 0,3,1; li 3,1; stw 0,0x4(4); lwz 0,-23508(13); add 5,0,6; lwz 0,0x8(5); stw 0,0x8(4)"
extern "C" void f_8025BDB8() {}
