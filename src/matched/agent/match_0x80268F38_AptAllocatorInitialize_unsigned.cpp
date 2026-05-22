// 0x80268F38 AptAllocatorInitialize(unsigned (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); bl _s80268F38_0; li 30,0; li 3,32; li 28,1; bl _s80268F38_1; li 9,0; stw 30,0x8(1); li 4,0; stw 30,0xc(1); li 5,0; stw 28,0x10(1); li 6,0; li 7,0; li 8,0; li 10,0; bl _s80268F38_2; lis 9,-32694; stw 3,-23020(13); lwz 0,-16288(9); li 3,32; mtspr 8,0; blrl; lbz 0,-21336(13); mr 29,3; lbz 6,-21335(13); lwz 7,-21332(13); li 4,0; lbz 8,-21328(13); li 5,0; lbz 10,-21327(13); li 9,1; stw 30,0x8(1); stw 0,0xc(1); stw 28,0x10(1); bl _s80268F38_3; stw 29,-23016(13); lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s80268F38_0();
extern "C" void _s80268F38_1();
extern "C" void _s80268F38_2();
extern "C" void _s80268F38_3();
extern "C" void f_80268F38() {}
