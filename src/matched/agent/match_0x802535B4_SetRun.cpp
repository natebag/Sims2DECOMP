// 0x802535B4 SetRun (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 5,0x2d0(3); lis 4,-32694; addi 0,4,-24616; rlwinm 4,5,3,0,28; add 0,0,4; stw 0,0x2dc(3); lwz 5,0x2dc(3); lwz 4,0x4(5); cmplwi 4,0; bne 0f; stw 3,0x0(5); b 1f; 0:; stw 3,0x2e0(4); 1:; stw 4,0x2e4(3); li 0,0; li 4,1; stw 0,0x2e0(3); lwz 5,0x2dc(3); stw 3,0x4(5); lwz 0,0x2d0(3); lwz 3,-23584(13); subfic 0,0,31; slw 0,4,0; or 0,3,0; stw 0,-23584(13); stw 4,-23580(13)"
extern "C" void f_802535B4() {}
