// 0x80254068 OSJoinThread (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,3,0; stw 30,0x18(1); stw 29,0x14(1); addi 29,4,0; bl _s80254068_0; lhz 0,0x2ca(31); addi 30,3,0; rlwinm. 0,0,0,31,31; bne 5f; lhz 0,0x2c8(31); cmplwi 0,8; beq 5f; lwz 0,0x2e8(31); cmplwi 0,0; bne 5f; addi 3,31,744; bl _s80254068_1; lhz 0,0x2c8(31); cmplwi 0,0; bne 0f; li 0,0; b 4f; 0:; lis 3,-32768; lwz 3,0xdc(3); b 3f; 1:; cmplw 31,3; bne 2f; li 0,1; b 4f; 2:; lwz 3,0x2fc(3); 3:; cmplwi 3,0; bne 1b; li 0,0; 4:; cmpwi 0,0; bne 5f; mr 3,30; bl _s80254068_2; li 3,0; b 12f; 5:; lhz 0,0x2c8(31); cmplwi 0,8; bne 11f; cmplwi 29,0; beq 6f; lwz 0,0x2d8(31); stw 0,0x0(29); 6:; lwz 4,0x2fc(31); lwz 5,0x300(31); cmplwi 4,0; bne 7f; lis 3,-32768; stw 5,0xe0(3); b 8f; 7:; stw 5,0x300(4); 8:; cmplwi 5,0; bne 9f; lis 3,-32768; stw 4,0xdc(3); b 10f; 9:; stw 4,0x2fc(5); 10:; li 0,0; sth 0,0x2c8(31); mr 3,30; bl _s80254068_3; li 3,1; b 12f; 11:; mr 3,30; bl _s80254068_4; li 3,0; 12:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80254068_0();
extern "C" void _s80254068_1();
extern "C" void _s80254068_2();
extern "C" void _s80254068_3();
extern "C" void _s80254068_4();
extern "C" void f_80254068() {}
