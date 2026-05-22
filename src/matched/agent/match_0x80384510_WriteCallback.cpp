// 0x80384510 WriteCallback (368 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); addi 30,3,0; lis 3,-32688; stw 29,0x14(1); mulli 5,30,272; stw 28,0x10(1); addi 0,3,-24000; mr. 28,4; add 31,0,5; blt 5f; lwz 29,0xc0(31); lwz 3,0xc(29); cmpwi 3,0; bge 0f; li 28,-14; b 5f; 0:; lwz 0,0xc(31); subf 0,0,3; stw 0,0xc(29); lwz 0,0xc(29); cmpwi 0,0; bgt 1f; mr 3,31; bl _s80384510_0; lwz 5,0x4(29); lis 4,-32768; lwz 0,0xf8(4); rlwinm 4,5,6,0,25; add 28,3,4; rlwinm 29,0,30,2,31; bl _s80384510_1; addi 6,29,0; li 5,0; bl _s80384510_2; stw 4,0x28(28); li 0,0; addi 3,30,0; lwz 4,0xd0(31); stw 0,0xd0(31); bl _s80384510_3; mr 28,3; b 4f; 1:; mr 3,31; bl _s80384510_4; lwz 4,0x8(29); lwz 0,0xc(31); add 0,4,0; stw 0,0x8(29); lhz 0,0x10(29); rlwinm 0,0,1,0,30; lhzx 0,3,0; sth 0,0x10(29); lhz 4,0x10(29); cmplwi 4,5; blt 2f; lhz 0,0x10(31); cmplw 4,0; blt 3f; 2:; li 28,-6; b 5f; 3:; lwz 0,0xc(31); lis 3,-32712; addi 5,3,18048; mullw 4,0,4; addi 3,30,0; bl _s80384510_5; mr 28,3; 4:; cmpwi 28,0; bge 6f; 5:; lwz 29,0xd0(31); li 0,0; addi 3,31,0; stw 0,0xd0(31); mr 4,28; bl _s80384510_6; addi 12,29,0; mtspr 8,12; addi 3,30,0; addi 4,28,0; blrl; 6:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80384510_0();
extern "C" void _s80384510_1();
extern "C" void _s80384510_2();
extern "C" void _s80384510_3();
extern "C" void _s80384510_4();
extern "C" void _s80384510_5();
extern "C" void _s80384510_6();
extern "C" void f_80384510() {}
