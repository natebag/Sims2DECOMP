// 0x80253DC8 OSExitThread (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); stw 28,0x10(1); mr 28,3; bl _s80253DC8_0; lis 31,-32768; lwz 30,0xe4(31); addi 29,3,0; addi 3,30,0; bl _s80253DC8_1; lhz 0,0x2ca(30); rlwinm. 0,0,0,31,31; beq 4f; lwz 4,0x2fc(30); lwz 5,0x300(30); cmplwi 4,0; bne 0f; stw 5,0xe0(31); b 1f; 0:; stw 5,0x300(4); 1:; cmplwi 5,0; bne 2f; lis 3,-32768; stw 4,0xdc(3); b 3f; 2:; stw 4,0x2fc(5); 3:; li 0,0; sth 0,0x2c8(30); b 5f; 4:; li 0,8; sth 0,0x2c8(30); stw 28,0x2d8(30); 5:; mr 3,30; bl _s80253DC8_2; addi 3,30,744; bl _s80253DC8_3; li 0,1; stw 0,-23580(13); lwz 0,-23580(13); cmpwi 0,0; beq 6f; li 3,0; bl _s80253DC8_4; 6:; mr 3,29; bl _s80253DC8_5; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80253DC8_0();
extern "C" void _s80253DC8_1();
extern "C" void _s80253DC8_2();
extern "C" void _s80253DC8_3();
extern "C" void _s80253DC8_4();
extern "C" void _s80253DC8_5();
extern "C" void f_80253DC8() {}
