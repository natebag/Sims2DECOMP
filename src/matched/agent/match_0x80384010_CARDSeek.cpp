// 0x80384010 __CARDSeek (440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stw 31,0x2c(1); addi 31,6,0; stw 30,0x28(1); addi 30,5,0; stw 29,0x24(1); addi 29,4,0; addi 4,1,24; stw 28,0x20(1); mr 28,3; lwz 3,0x0(3); bl _s80384010_0; cmpwi 3,0; bge 0f; b 10f; 0:; lhz 0,0x10(28); cmplwi 0,5; blt 1f; lwz 3,0x18(1); lhz 5,0x10(3); cmplw 0,5; bge 1f; lwz 4,0xc(3); lwz 0,0x8(28); mullw 4,5,4; cmpw 4,0; bgt 2f; 1:; lwz 3,0x18(1); li 4,-128; bl _s80384010_1; b 10f; 2:; bl _s80384010_2; lwz 0,0x4(28); lwz 5,0x18(1); rlwinm 0,0,6,0,25; add 4,3,0; lwz 3,0xc(5); lhz 0,0x38(4); mullw 3,0,3; cmpw 3,30; ble 3f; add 0,30,29; cmpw 3,0; bge 4f; 3:; addi 3,5,0; li 4,-11; bl _s80384010_3; b 10f; 4:; stw 28,0xc0(5); stw 29,0xc(28); lwz 0,0x8(28); cmpw 30,0; bge 6f; li 0,0; stw 0,0x8(28); lhz 0,0x36(4); sth 0,0x10(28); lhz 4,0x10(28); cmplwi 4,5; blt 5f; lwz 3,0x18(1); lhz 0,0x10(3); cmplw 4,0; blt 6f; 5:; lwz 3,0x18(1); li 4,-6; bl _s80384010_4; b 10f; 6:; lwz 3,0x18(1); bl _s80384010_5; b 9f; 7:; lwz 0,0x8(28); add 0,0,4; stw 0,0x8(28); lhz 0,0x10(28); rlwinm 0,0,1,0,30; lhzx 0,3,0; sth 0,0x10(28); lhz 5,0x10(28); cmplwi 5,5; blt 8f; lwz 4,0x18(1); lhz 0,0x10(4); cmplw 5,0; blt 9f; 8:; lwz 3,0x18(1); li 4,-6; bl _s80384010_6; b 10f; 9:; lwz 4,0x18(1); lwz 5,0x8(28); lwz 4,0xc(4); addi 0,4,-1; andc 0,30,0; cmplw 5,0; blt 7b; stw 30,0x8(28); li 3,0; lwz 0,0x18(1); stw 0,0x0(31); 10:; lwz 0,0x34(1); lwz 31,0x2c(1); lwz 30,0x28(1); lwz 29,0x24(1); lwz 28,0x20(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s80384010_0();
extern "C" void _s80384010_1();
extern "C" void _s80384010_2();
extern "C" void _s80384010_3();
extern "C" void _s80384010_4();
extern "C" void _s80384010_5();
extern "C" void _s80384010_6();
extern "C" void f_80384010() {}
