// 0x80382D08 FormatCallback (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); addi 30,3,0; lis 3,-32688; stw 29,0x14(1); mulli 5,30,272; stw 28,0x10(1); addi 0,3,-24000; mr. 28,4; add 31,0,5; blt 2f; lwz 3,0x28(31); addi 0,3,1; stw 0,0x28(31); lwz 4,0x28(31); cmpwi 4,5; bge 0f; lwz 0,0xc(31); lis 3,-32712; addi 5,3,11528; mullw 4,0,4; addi 3,30,0; bl _s80382D08_0; mr. 28,3; blt 2f; b 3f; 0:; cmpwi 4,10; bge 1f; lwz 0,0xc(31); addi 6,4,-5; lis 3,-32712; lwz 5,0x80(31); mullw 4,0,6; rlwinm 0,6,13,0,18; addi 7,3,11528; add 6,5,0; addi 3,30,0; li 5,8192; bl _s80382D08_1; mr. 28,3; blt 2f; b 3f; 1:; lwz 3,0x80(31); li 5,8192; addi 0,3,8192; stw 0,0x84(31); lwz 4,0x80(31); lwz 3,0x84(31); addi 4,4,16384; bl _s80382D08_2; lwz 3,0x80(31); li 5,8192; addi 0,3,24576; stw 0,0x88(31); lwz 4,0x80(31); lwz 3,0x88(31); addis 4,4,1; addi 4,4,-32768; bl _s80382D08_3; 2:; lwz 29,0xd0(31); li 0,0; addi 3,31,0; stw 0,0xd0(31); mr 4,28; bl _s80382D08_4; addi 12,29,0; mtspr 8,12; addi 3,30,0; addi 4,28,0; blrl; 3:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80382D08_0();
extern "C" void _s80382D08_1();
extern "C" void _s80382D08_2();
extern "C" void _s80382D08_3();
extern "C" void _s80382D08_4();
extern "C" void f_80382D08() {}
