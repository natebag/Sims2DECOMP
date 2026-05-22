// 0x80384F08 CARDSetStatusAsync (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stw 31,0x2c(1); mr. 31,4; stw 30,0x28(1); addi 30,6,0; stw 29,0x24(1); addi 29,5,0; stw 28,0x20(1); addi 28,3,0; blt 1f; cmpwi 31,127; bge 1f; lwz 3,0x30(29); addis 0,3,1; cmplwi 0,65535; beq 0f; cmplwi 3,512; bge 1f; 0:; lwz 3,0x38(29); addis 0,3,1; cmplwi 0,65535; beq 2f; rlwinm 0,3,0,19,31; cmplwi 0,8128; ble 2f; 1:; li 3,-128; b 7f; 2:; addi 3,28,0; addi 4,1,24; bl _s80384F08_0; cmpwi 3,0; bge 3f; b 7f; 3:; lwz 3,0x18(1); bl _s80384F08_1; rlwinm 0,31,6,0,25; add 31,3,0; lwz 3,0x18(1); mr 4,31; bl _s80384F08_2; mr. 4,3; bge 4f; lwz 3,0x18(1); bl _s80384F08_3; b 7f; 4:; lbz 0,0x2e(29); addi 3,31,0; addi 4,29,0; stb 0,0x7(31); lwz 0,0x30(29); stw 0,0x2c(31); lhz 0,0x34(29); sth 0,0x30(31); lhz 0,0x36(29); sth 0,0x32(31); lwz 0,0x38(29); stw 0,0x3c(31); bl _s80384F08_4; lwz 3,0x2c(31); addis 0,3,1; cmplwi 0,65535; bne 5f; lhz 0,0x32(31); rlwinm 0,0,0,0,29; ori 0,0,1; sth 0,0x32(31); 5:; lis 3,-32768; lwz 0,0xf8(3); rlwinm 29,0,30,2,31; bl _s80384F08_5; addi 6,29,0; li 5,0; bl _s80384F08_6; stw 4,0x28(31); addi 3,28,0; addi 4,30,0; bl _s80384F08_7; mr. 28,3; bge 6f; lwz 3,0x18(1); mr 4,28; bl _s80384F08_8; 6:; mr 3,28; 7:; lwz 0,0x34(1); lwz 31,0x2c(1); lwz 30,0x28(1); lwz 29,0x24(1); lwz 28,0x20(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s80384F08_0();
extern "C" void _s80384F08_1();
extern "C" void _s80384F08_2();
extern "C" void _s80384F08_3();
extern "C" void _s80384F08_4();
extern "C" void _s80384F08_5();
extern "C" void _s80384F08_6();
extern "C" void _s80384F08_7();
extern "C" void _s80384F08_8();
extern "C" void f_80384F08() {}
