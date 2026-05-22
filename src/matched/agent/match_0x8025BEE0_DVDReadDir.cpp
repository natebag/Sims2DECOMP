// 0x8025BEE0 DVDReadDir (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 7,0x4(3); lwz 0,0x0(3); cmplw 7,0; ble 0f; lwz 0,0x8(3); cmplw 0,7; bgt 1f; 0:; li 3,0; blr; 1:; stw 7,0x0(4); mulli 8,7,12; lwz 5,-23508(13); lwzx 0,5,8; rlwinm. 0,0,0,0,7; bne 2f; li 0,0; b 3f; 2:; li 0,1; 3:; stw 0,0x4(4); lwz 5,-23508(13); lwz 6,-23504(13); lwzx 0,5,8; rlwinm 0,0,0,8,31; add 0,6,0; stw 0,0x8(4); lwz 4,-23508(13); lwzx 0,4,8; rlwinm. 0,0,0,0,7; bne 4f; li 0,0; b 5f; 4:; li 0,1; 5:; cmpwi 0,0; beq 6f; add 4,4,8; lwz 0,0x8(4); b 7f; 6:; addi 0,7,1; 7:; stw 0,0x4(3); li 3,1"
extern "C" void f_8025BEE0() {}
