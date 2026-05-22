// 0x802605F4 __DVDStoreErrorCode (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); addis 0,3,-291; cmplwi 0,17767; stwu 1,-24(1); stw 31,0x14(1); bne 0f; li 31,255; b 3f; 0:; cmplwi 0,17768; bne 1f; li 31,254; b 3f; 1:; rlwinm 31,3,8,24,31; rlwinm 3,3,0,8,31; bl _s802605F4_0; cmplwi 31,6; blt 2f; li 31,6; 2:; mulli 0,31,30; rlwinm 3,3,0,24,31; add 31,3,0; 3:; bl _s802605F4_1; stb 31,0x24(3); li 3,1; bl _s802605F4_2; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s802605F4_0();
extern "C" void _s802605F4_1();
extern "C" void _s802605F4_2();
extern "C" void f_802605F4() {}
