// 0x80384930 CARDFastDeleteAsync (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); addi 30,5,0; stw 29,0x1c(1); mr. 29,4; stw 28,0x18(1); addi 28,3,0; blt 0f; cmpwi 29,127; blt 1f; 0:; li 3,-128; b 8f; 1:; addi 3,28,0; addi 4,1,20; bl _s80384930_0; cmpwi 3,0; bge 2f; b 8f; 2:; lwz 3,0x14(1); bl _s80384930_1; rlwinm 0,29,6,0,25; add 31,3,0; lwz 3,0x14(1); mr 4,31; bl _s80384930_2; mr. 4,3; bge 3f; lwz 3,0x14(1); bl _s80384930_3; b 8f; 3:; lwz 3,0x14(1); mr 4,29; bl _s80384930_4; cmpwi 3,0; beq 4f; lwz 3,0x14(1); li 4,-1; bl _s80384930_5; b 8f; 4:; lhz 0,0x36(31); mr 3,31; lwz 6,0x14(1); li 4,255; li 5,64; sth 0,0xbe(6); bl _s80384930_6; cmplwi 30,0; beq 5f; mr 0,30; b 6f; 5:; lis 3,-32712; addi 0,3,-4304; 6:; lwz 5,0x14(1); lis 3,-32712; addi 4,3,18572; stw 0,0xd0(5); mr 3,28; bl _s80384930_7; mr. 31,3; bge 7f; lwz 3,0x14(1); mr 4,31; bl _s80384930_8; 7:; mr 3,31; 8:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); lwz 28,0x18(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80384930_0();
extern "C" void _s80384930_1();
extern "C" void _s80384930_2();
extern "C" void _s80384930_3();
extern "C" void _s80384930_4();
extern "C" void _s80384930_5();
extern "C" void _s80384930_6();
extern "C" void _s80384930_7();
extern "C" void _s80384930_8();
extern "C" void f_80384930() {}
