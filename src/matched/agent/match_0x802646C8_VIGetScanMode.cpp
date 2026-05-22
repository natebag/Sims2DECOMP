// 0x802646C8 VIGetScanMode (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); bl _s802646C8_0; lis 4,-13312; addi 4,4,8192; lhz 0,0x6c(4); rlwinm 0,0,0,31,31; cmplwi 0,1; bne 0f; li 31,2; b 2f; 0:; lhz 0,0x2(4); rlwinm. 0,0,30,31,31; bne 1f; li 31,0; b 2f; 1:; li 31,1; 2:; bl _s802646C8_1; mr 3,31; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s802646C8_0();
extern "C" void _s802646C8_1();
extern "C" void f_802646C8() {}
