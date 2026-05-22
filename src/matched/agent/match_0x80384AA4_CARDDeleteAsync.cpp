// 0x80384AA4 CARDDeleteAsync (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stw 31,0x2c(1); addi 31,3,0; stw 30,0x28(1); addi 30,5,0; stw 29,0x24(1); addi 29,4,0; addi 4,1,24; bl _s80384AA4_0; cmpwi 3,0; bge 0f; b 6f; 0:; lwz 3,0x18(1); addi 4,29,0; addi 5,1,20; bl _s80384AA4_1; mr. 4,3; bge 1f; lwz 3,0x18(1); bl _s80384AA4_2; b 6f; 1:; lwz 3,0x18(1); lwz 4,0x14(1); bl _s80384AA4_3; cmpwi 3,0; beq 2f; lwz 3,0x18(1); li 4,-1; bl _s80384AA4_4; b 6f; 2:; lwz 3,0x18(1); bl _s80384AA4_5; lwz 0,0x14(1); li 4,255; lwz 6,0x18(1); li 5,64; rlwinm 0,0,6,0,25; add 3,3,0; lhz 0,0x36(3); sth 0,0xbe(6); bl _s80384AA4_6; cmplwi 30,0; beq 3f; mr 0,30; b 4f; 3:; lis 3,-32712; addi 0,3,-4304; 4:; lwz 5,0x18(1); lis 3,-32712; addi 4,3,18572; stw 0,0xd0(5); mr 3,31; bl _s80384AA4_7; mr. 31,3; bge 5f; lwz 3,0x18(1); mr 4,31; bl _s80384AA4_8; 5:; mr 3,31; 6:; lwz 0,0x34(1); lwz 31,0x2c(1); lwz 30,0x28(1); lwz 29,0x24(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s80384AA4_0();
extern "C" void _s80384AA4_1();
extern "C" void _s80384AA4_2();
extern "C" void _s80384AA4_3();
extern "C" void _s80384AA4_4();
extern "C" void _s80384AA4_5();
extern "C" void _s80384AA4_6();
extern "C" void _s80384AA4_7();
extern "C" void _s80384AA4_8();
extern "C" void f_80384AA4() {}
