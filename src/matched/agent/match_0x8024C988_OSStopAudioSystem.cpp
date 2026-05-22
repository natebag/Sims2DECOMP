// 0x8024C988 __OSStopAudioSystem (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-13312; stw 0,0x4(1); li 0,2052; stwu 1,-16(1); stw 31,0xc(1); addi 31,3,20480; addi 3,3,20480; stw 30,0x8(1); sth 0,0xa(31); lhz 0,0x36(3); rlwinm 0,0,0,17,15; sth 0,0x36(3); lhzu 0,0xa(31); b 1f; 0:; lhz 0,0x0(31); 1:; rlwinm. 0,0,0,21,21; bne 0b; lhz 0,0x0(31); b 3f; 2:; lhz 0,0x0(31); 3:; rlwinm. 0,0,0,22,22; bne 2b; li 0,2220; lis 3,-13312; sth 0,0x0(31); li 0,0; sth 0,0x5000(3); addi 4,3,20480; 4:; lhz 3,0x4(4); lhz 0,0x6(4); rlwimi 0,3,16,0,15; rlwinm. 0,0,0,0,0; bne 4b; bl _s8024C988_0; mr 30,3; 5:; bl _s8024C988_1; subf 0,30,3; cmpwi 0,44; blt 5b; lhz 0,0x0(31); ori 0,0,1; sth 0,0x0(31); lhz 0,0x0(31); b 7f; 6:; lhz 0,0x0(31); 7:; rlwinm. 0,0,0,31,31; bne 6b; lwz 0,0x14(1); lwz 31,0xc(1); lwz 30,0x8(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8024C988_0();
extern "C" void _s8024C988_1();
extern "C" void f_8024C988() {}
