// 0x8038D0D0 __GXGetTexTileShift (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 3,60; bgt 0f; lis 6,-32698; addi 6,6,-23792; rlwinm 0,3,2,0,29; lwzx 0,6,0; mtspr 9,0; bctr; li 0,3; stw 0,0x0(4); stw 0,0x0(5); blr; li 0,3; stw 0,0x0(4); li 0,2; stw 0,0x0(5); blr; li 0,2; stw 0,0x0(4); stw 0,0x0(5); blr; 0:; li 0,0; stw 0,0x0(5); stw 0,0x0(4)"
extern "C" void f_8038D0D0() {}
