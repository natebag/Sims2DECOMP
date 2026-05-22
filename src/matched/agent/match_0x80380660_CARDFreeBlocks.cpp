// 0x80380660 CARDFreeBlocks (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stw 31,0x2c(1); addi 31,5,0; stw 30,0x28(1); stw 29,0x24(1); addi 29,4,0; addi 4,1,24; bl _s80380660_0; cmpwi 3,0; bge 0f; b 12f; 0:; lwz 3,0x18(1); bl _s80380660_1; mr 30,3; lwz 3,0x18(1); bl _s80380660_2; cmplwi 30,0; beq 1f; cmplwi 3,0; bne 4f; 1:; lwz 30,0x18(1); bl _s80380660_3; lwz 0,0x0(30); cmpwi 0,0; beq 2f; li 0,-6; stw 0,0x4(30); b 3f; 2:; lwz 0,0x4(30); cmpwi 0,-1; bne 3f; li 0,-6; stw 0,0x4(30); 3:; bl _s80380660_4; li 3,-6; b 12f; 4:; cmplwi 29,0; beq 5f; lwz 4,0x18(1); lhz 0,0x6(30); lwz 4,0xc(4); mullw 0,4,0; stw 0,0x0(29); 5:; cmplwi 31,0; beq 9f; li 0,0; stw 0,0x0(31); li 5,0; b 8f; 6:; lbz 0,0x8(3); cmplwi 0,255; bne 7f; lwz 4,0x0(31); addi 0,4,1; stw 0,0x0(31); 7:; addi 3,3,64; addi 5,5,1; 8:; rlwinm 0,5,0,16,31; cmplwi 0,127; blt 6b; 9:; lwz 30,0x18(1); bl _s80380660_5; lwz 0,0x0(30); cmpwi 0,0; beq 10f; li 0,0; stw 0,0x4(30); b 11f; 10:; lwz 0,0x4(30); cmpwi 0,-1; bne 11f; li 0,0; stw 0,0x4(30); 11:; bl _s80380660_6; li 3,0; 12:; lwz 0,0x34(1); lwz 31,0x2c(1); lwz 30,0x28(1); lwz 29,0x24(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s80380660_0();
extern "C" void _s80380660_1();
extern "C" void _s80380660_2();
extern "C" void _s80380660_3();
extern "C" void _s80380660_4();
extern "C" void _s80380660_5();
extern "C" void _s80380660_6();
extern "C" void f_80380660() {}
