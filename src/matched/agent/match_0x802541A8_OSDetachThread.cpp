// 0x802541A8 OSDetachThread (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s802541A8_0; lhz 0,0x2ca(30); addi 31,3,0; ori 0,0,1; sth 0,0x2ca(30); lhz 0,0x2c8(30); cmplwi 0,8; bne 4f; lwz 4,0x2fc(30); lwz 5,0x300(30); cmplwi 4,0; bne 0f; lis 3,-32768; stw 5,0xe0(3); b 1f; 0:; stw 5,0x300(4); 1:; cmplwi 5,0; bne 2f; lis 3,-32768; stw 4,0xdc(3); b 3f; 2:; stw 4,0x2fc(5); 3:; li 0,0; sth 0,0x2c8(30); 4:; addi 3,30,744; bl _s802541A8_1; mr 3,31; bl _s802541A8_2; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s802541A8_0();
extern "C" void _s802541A8_1();
extern "C" void _s802541A8_2();
extern "C" void f_802541A8() {}
