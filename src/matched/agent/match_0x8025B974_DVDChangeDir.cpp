// 0x8025B974 DVDChangeDir (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s8025B974_0; cmpwi 3,0; blt 2f; mulli 0,3,12; lwz 4,-23508(13); lwzx 0,4,0; rlwinm. 0,0,0,0,7; bne 0f; li 0,0; b 1f; 0:; li 0,1; 1:; cmpwi 0,0; bne 3f; 2:; li 3,0; b 4f; 3:; stw 3,-23496(13); li 3,1; 4:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8025B974_0();
extern "C" void f_8025B974() {}
