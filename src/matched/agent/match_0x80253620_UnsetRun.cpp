// 0x80253620 UnsetRun (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,0x2e0(3); lwz 5,0x2dc(3); cmplwi 4,0; lwz 6,0x2e4(3); bne 0f; stw 6,0x4(5); b 1f; 0:; stw 6,0x2e4(4); 1:; cmplwi 6,0; bne 2f; stw 4,0x0(5); b 3f; 2:; stw 4,0x2e0(6); 3:; lwz 0,0x0(5); cmplwi 0,0; bne 4f; lwz 0,0x2d0(3); li 4,1; lwz 5,-23584(13); subfic 0,0,31; slw 0,4,0; andc 0,5,0; stw 0,-23584(13); 4:; li 0,0; stw 0,0x2dc(3)"
extern "C" void f_80253620() {}
