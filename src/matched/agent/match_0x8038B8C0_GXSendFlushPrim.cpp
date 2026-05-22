// 0x8038B8C0 __GXSendFlushPrim (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-17720(13); li 0,152; lis 5,-13311; lhz 6,0x4(3); li 4,0; lhz 3,0x6(3); mullw 7,6,3; stb 0,-32768(5); sth 6,-32768(5); addi 3,7,3; cmplwi 7,0; rlwinm 3,3,30,2,31; ble 3f; rlwinm. 0,3,29,3,31; mtspr 9,0; beq 1f; 0:; stw 4,-32768(5); stw 4,-32768(5); stw 4,-32768(5); stw 4,-32768(5); stw 4,-32768(5); stw 4,-32768(5); stw 4,-32768(5); stw 4,-32768(5); bdnz 0b; andi. 3,3,7; beq 3f; 1:; mtspr 9,3; 2:; stw 4,-32768(5); bdnz 2b; 3:; lwz 3,-17720(13); li 0,1; sth 0,0x2(3)"
extern "C" void f_8038B8C0() {}
