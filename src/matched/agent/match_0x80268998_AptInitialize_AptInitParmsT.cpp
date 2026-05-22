// 0x80268998 AptInitialize(AptInitParmsT (688 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 27,0x4c(1); stw 0,0x64(1); li 10,512; addi 4,1,8; stw 10,0x8(1); li 0,64; li 9,256; li 6,384; li 5,0; li 11,32; li 8,1024; li 7,128; stw 10,0x4(4); mr. 28,3; stw 6,0x20(4); stw 11,0x24(4); stw 9,0x28(4); stw 8,0x2c(4); stw 7,0x30(4); stw 0,0x34(4); stw 5,0x3c(4); stw 0,0x8(4); stw 9,0xc(4); stw 0,0x10(4); stw 9,0x14(4); stw 6,0x18(4); stw 0,0x1c(4); stw 5,0x38(4); bne 0f; mr 28,4; 0:; lis 9,-32694; mr 10,28; addi 9,9,-16116; li 8,48; 1:; lwz 11,0x0(10); addic. 8,8,-24; stw 11,0x0(9); lwz 11,0x4(10); stw 11,0x4(9); lwz 11,0x8(10); stw 11,0x8(9); lwz 11,0xc(10); stw 11,0xc(9); lwz 11,0x10(10); stw 11,0x10(9); lwz 11,0x14(10); addi 10,10,24; stw 11,0x14(9); addi 9,9,24; bne 1b; lwz 11,0x0(10); li 7,1; lwz 0,-23024(13); stw 11,0x0(9); lwz 11,0x4(10); cmpwi 0,0; stw 11,0x4(9); lwz 11,0x8(10); stw 11,0x8(9); lwz 11,0xc(10); stw 11,0xc(9); bne 2f; li 7,0; 2:; cmpwi 7,0; bne 3f; lis 9,-32700; lhz 11,-6476(9); addi 0,9,-6476; stw 0,-23024(13); addi 11,11,1; sth 11,-6476(9); 3:; lis 9,-32694; lwz 11,0x3c(28); addi 31,9,-16288; stw 8,-27584(13); lwz 0,0x8(31); stw 11,-27580(13); cmpwi 0,0; bne 4f; lis 9,-32729; addi 9,9,-31004; stw 9,0x8(31); 4:; bl _s80268998_0; lwz 3,0x2c(28); stw 31,-26904(13); bl _s80268998_1; lwz 3,-23020(13); li 4,12; bl _s80268998_2; lwz 4,0x28(28); bl _s80268998_3; lwz 0,0x34(28); stw 3,-27600(13); cmpwi 0,0; bne 5f; stw 0,-27596(13); b 6f; 5:; lwz 3,-23020(13); li 4,12; bl _s80268998_4; lwz 4,0x34(28); bl _s80268998_5; stw 3,-27596(13); 6:; bl _s80268998_6; li 30,0; lis 3,-32694; mr 4,28; addi 3,3,-16032; bl _s80268998_7; lwz 3,-23020(13); li 4,4; bl _s80268998_8; mr 9,3; li 4,24; stw 30,0x0(9); lwz 3,-23020(13); stw 9,-23000(13); bl _s80268998_9; mr 10,3; li 8,0; addi 9,10,4; stw 30,0x0(10); stw 30,0x4(10); addi 0,10,16; stw 30,0x4(9); mr 11,0; stw 0,0x8(9); li 9,1; 7:; stw 8,0x0(11); cmpwi 9,0; addi 11,11,4; addi 9,9,-1; bne 7b; lwz 3,-23020(13); li 4,28; stw 10,-22996(13); li 29,1; bl _s80268998_10; li 27,0; mr 31,3; li 0,0; addi 9,31,12; stw 0,0x4(31); stw 0,0x0(31); mr 30,9; stw 9,0x8(31); 8:; mr 3,30; bl _s80268998_11; stw 27,0x4(30); cmpwi 29,0; addi 30,30,8; addi 29,29,-1; bne 8b; lwz 3,-23020(13); li 4,172; stw 31,-22992(13); bl _s80268998_12; mr 4,28; bl _s80268998_13; stw 3,-23008(13); bl _s80268998_14; li 3,128; bl _s80268998_15; li 0,1; stw 0,-22988(13); lwz 0,0x64(1); mtspr 8,0; lmw 27,0x4c(1); addi 1,1,96"
extern "C" void _s80268998_0();
extern "C" void _s80268998_1();
extern "C" void _s80268998_2();
extern "C" void _s80268998_3();
extern "C" void _s80268998_4();
extern "C" void _s80268998_5();
extern "C" void _s80268998_6();
extern "C" void _s80268998_7();
extern "C" void _s80268998_8();
extern "C" void _s80268998_9();
extern "C" void _s80268998_10();
extern "C" void _s80268998_11();
extern "C" void _s80268998_12();
extern "C" void _s80268998_13();
extern "C" void _s80268998_14();
extern "C" void _s80268998_15();
extern "C" void f_80268998() {}
