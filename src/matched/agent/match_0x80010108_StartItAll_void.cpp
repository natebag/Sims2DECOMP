// 0x80010108 StartItAll(void) (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 28,0x48(1); stw 0,0x5c(1); lwz 9,-26392(13); li 5,0; lwz 4,0x1c(9); lwz 3,0x18(9); bl _s80010108_0; li 8,512; addi 9,1,8; stw 8,0x8(1); li 0,64; li 10,256; li 7,32; li 6,1024; li 30,384; li 29,0; stw 8,0x4(9); stw 7,0x24(9); lis 5,-32697; stw 10,0x28(9); li 28,128; stw 6,0x2c(9); li 11,0; stw 0,0x34(9); ori 11,11,32768; stw 30,0x20(9); li 8,10; stw 29,0x3c(9); mr 3,9; lwz 4,0x6144(5); stw 0,0x8(9); stw 10,0xc(9); stw 0,0x10(9); stw 10,0x14(9); stw 0,0x1c(9); stw 30,0x18(9); stw 28,0x30(9); stw 29,0x38(9); stw 11,0x30(1); stw 28,0x2c(1); stw 8,0x3c(1); bl _s80010108_1; lwz 3,-23020(13); li 4,4; bl _s80010108_2; lis 9,-32697; mr 11,3; addi 9,9,-24776; stw 9,0x0(11); bl _s80010108_3; bl _s80010108_4; lwz 0,0x5c(1); mtspr 8,0; lmw 28,0x48(1); addi 1,1,88"
extern "C" void _s80010108_0();
extern "C" void _s80010108_1();
extern "C" void _s80010108_2();
extern "C" void _s80010108_3();
extern "C" void _s80010108_4();
extern "C" void f_80010108() {}
