// 0x803509C4 ENgcTextureC4_32::Select(int, (588 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f31,0x30(1); stmw 26,0x18(1); stw 0,0x3c(1); mr 31,3; mr 26,5; lwz 0,0x80(31); cmpwi 0,0; bne 3f; li 0,1; addi 29,31,72; stw 0,0x80(31); addi 28,31,156; bl _s803509C4_0; stw 3,0x94(31); li 5,0; lwz 4,0xcc(31); addi 3,31,132; lhz 6,0x14(31); bl _s803509C4_1; lwz 0,0x94(31); li 10,0; lwz 7,0x70(31); mr 3,29; lwz 8,0x68(31); lwz 9,0x6c(31); lwz 4,0x74(31); lhz 5,0x10(31); lhz 6,0x12(31); stw 0,0x8(1); bl _s803509C4_2; bl _s803509C4_3; stw 3,0xc8(31); li 5,0; lwz 4,0xd0(31); addi 3,31,188; lhz 6,0x14(31); bl _s803509C4_4; lwz 0,0xc8(31); mr 3,28; lwz 9,0x6c(31); li 10,0; lwz 4,0x74(31); lhz 5,0x10(31); lhz 6,0x12(31); lwz 7,0x70(31); lwz 8,0x68(31); stw 0,0x8(1); bl _s803509C4_5; lwz 0,0x8(31); andi. 9,0,32; beq 2f; lhz 0,0x16(31); addic. 0,0,-1; bge 0f; li 0,0; 0:; xoris 0,0,32768; stw 0,0x14(1); lis 27,17200; lis 11,-32702; lis 30,-32702; stw 27,0x10(1); mr 3,29; lfd f31,0x2498(11); li 4,3; lfd f2,0x10(1); li 5,1; lfs f1,0x24a0(30); li 6,0; fsub f2,f2,f31; li 7,0; frsp f2,f2; li 8,0; fmr f3,f1; bl _s803509C4_6; lhz 0,0x16(31); addic. 0,0,-1; bge 1f; li 0,0; 1:; xoris 0,0,32768; stw 0,0x14(1); mr 3,28; lfs f1,0x24a0(30); li 4,3; stw 27,0x10(1); li 5,1; fmr f3,f1; li 6,0; lfd f2,0x10(1); li 7,0; li 8,0; fsub f2,f2,f31; frsp f2,f2; bl _s803509C4_7; b 3f; 2:; lis 30,-32702; mr 3,29; lfs f1,0x24a0(30); li 4,1; li 5,1; li 6,0; fmr f2,f1; li 7,0; fmr f3,f2; li 8,0; bl _s803509C4_8; lfs f1,0x24a0(30); mr 3,28; li 4,1; li 5,1; fmr f2,f1; li 6,0; fmr f3,f2; li 7,0; li 8,0; bl _s803509C4_9; 3:; bl _s803509C4_10; addi 30,31,72; stw 3,0x94(31); addi 29,31,156; bl _s803509C4_11; stw 3,0xc8(31); lwz 4,0x94(31); mr 3,30; bl _s803509C4_12; lwz 4,0x94(31); addi 3,31,132; bl _s803509C4_13; lwz 4,0xc8(31); mr 3,29; bl _s803509C4_14; lwz 4,0xc8(31); addi 3,31,188; bl _s803509C4_15; mr 3,30; mr 4,26; bl _s803509C4_16; mr 3,29; addi 4,26,1; bl _s803509C4_17; lwz 0,0x3c(1); mtspr 8,0; lmw 26,0x18(1); lfd f31,0x30(1); addi 1,1,56"
extern "C" void _s803509C4_0();
extern "C" void _s803509C4_1();
extern "C" void _s803509C4_2();
extern "C" void _s803509C4_3();
extern "C" void _s803509C4_4();
extern "C" void _s803509C4_5();
extern "C" void _s803509C4_6();
extern "C" void _s803509C4_7();
extern "C" void _s803509C4_8();
extern "C" void _s803509C4_9();
extern "C" void _s803509C4_10();
extern "C" void _s803509C4_11();
extern "C" void _s803509C4_12();
extern "C" void _s803509C4_13();
extern "C" void _s803509C4_14();
extern "C" void _s803509C4_15();
extern "C" void _s803509C4_16();
extern "C" void _s803509C4_17();
extern "C" void f_803509C4() {}
