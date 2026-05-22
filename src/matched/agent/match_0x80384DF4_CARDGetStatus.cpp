// 0x80384DF4 CARDGetStatus (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); addi 31,5,0; stw 30,0x20(1); stw 29,0x1c(1); mr. 29,4; blt 0f; cmpwi 29,127; blt 1f; 0:; li 3,-128; b 4f; 1:; addi 4,1,20; bl _s80384DF4_0; cmpwi 3,0; bge 2f; b 4f; 2:; lwz 3,0x14(1); bl _s80384DF4_1; rlwinm 0,29,6,0,25; add 29,3,0; lwz 3,0x14(1); mr 4,29; bl _s80384DF4_2; mr. 30,3; blt 3f; addi 4,29,0; addi 3,31,40; li 5,4; bl _s80384DF4_3; addi 3,31,44; addi 4,29,4; li 5,2; bl _s80384DF4_4; lwz 5,0x14(1); mr 3,31; lhz 6,0x38(29); addi 4,29,8; lwz 0,0xc(5); li 5,32; mullw 0,6,0; stw 0,0x20(31); bl _s80384DF4_5; lwz 0,0x28(29); addi 3,29,0; addi 4,31,0; stw 0,0x24(31); lbz 0,0x7(29); stb 0,0x2e(31); lwz 0,0x2c(29); stw 0,0x30(31); lhz 0,0x30(29); sth 0,0x34(31); lhz 0,0x32(29); sth 0,0x36(31); lwz 0,0x3c(29); stw 0,0x38(31); bl _s80384DF4_6; 3:; lwz 3,0x14(1); mr 4,30; bl _s80384DF4_7; 4:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80384DF4_0();
extern "C" void _s80384DF4_1();
extern "C" void _s80384DF4_2();
extern "C" void _s80384DF4_3();
extern "C" void _s80384DF4_4();
extern "C" void _s80384DF4_5();
extern "C" void _s80384DF4_6();
extern "C" void _s80384DF4_7();
extern "C" void f_80384DF4() {}
