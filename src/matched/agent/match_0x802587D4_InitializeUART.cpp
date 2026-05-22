// 0x802587D4 InitializeUART (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); lwz 3,-23548(13); addis 0,3,23041; cmplwi 0,90; bne 0f; li 3,0; b 2f; 0:; bl _s802587D4_0; rlwinm. 0,3,0,3,3; bne 1f; li 0,0; stw 0,-23552(13); li 3,2; b 2f; 1:; lis 3,-23041; addi 0,3,90; li 3,0; stw 0,-23552(13); li 0,1; stw 3,-23560(13); li 3,0; stw 0,-23556(13); 2:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s802587D4_0();
extern "C" void f_802587D4() {}
