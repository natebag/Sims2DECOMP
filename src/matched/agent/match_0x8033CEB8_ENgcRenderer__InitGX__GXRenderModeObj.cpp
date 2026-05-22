// 0x8033CEB8 ENgcRenderer::InitGX(_GXRenderModeObj (824 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); li 11,1000; lis 9,-32690; mtspr 9,11; addi 9,9,-25768; mr 31,3; mr 28,4; addi 9,9,3996; addi 27,1,8; addi 26,1,12; li 0,0; 0:; stw 0,0x0(9); addi 9,9,-4; bdnz 0b; bl _s8033CEB8_0; lis 29,-32702; li 7,0; li 6,0; li 5,32; lis 4,1; bl _s8033CEB8_1; lis 30,-32702; mr 0,3; lis 4,1; stw 0,0x358(31); bl _s8033CEB8_2; lwz 3,0x358(31); lis 4,1; bl _s8033CEB8_3; mr 0,3; mr 4,27; mr 5,26; stw 0,0x3a8(31); bl _s8033CEB8_4; lhz 0,0x4(28); lis 8,17200; lhz 7,0x6(28); stw 0,0x14(1); mr 10,9; lis 11,-32702; lfs f1,0x1cf0(29); stw 8,0x10(1); lfd f0,0x1ce8(11); fmr f2,f1; lfd f3,0x10(1); fmr f5,f2; stw 7,0x14(1); fsub f3,f3,f0; lfs f6,0x1cf4(30); stw 8,0x10(1); frsp f3,f3; lfd f4,0x10(1); fsub f4,f4,f0; frsp f4,f4; bl _s8033CEB8_5; lhz 5,0x4(28); li 3,0; lhz 6,0x6(28); li 4,0; bl _s8033CEB8_6; lfs f2,0x1cf0(29); lfs f1,0x1cf4(30); bl _s8033CEB8_7; lhz 4,0x8(28); lhz 3,0x6(28); bl _s8033CEB8_8; bl _s8033CEB8_9; lhz 5,0x4(28); li 3,0; lhz 6,0x6(28); li 4,0; bl _s8033CEB8_10; lhz 3,0x4(28); lhz 4,0x8(28); bl _s8033CEB8_11; lbz 3,0x19(28); addi 4,28,26; li 5,1; addi 6,28,50; bl _s8033CEB8_12; lbz 0,0x19(28); cmpwi 0,0; beq 1f; li 3,2; li 4,0; bl _s8033CEB8_13; b 2f; 1:; li 3,1; li 4,0; bl _s8033CEB8_14; 2:; li 3,2; addi 30,31,996; bl _s8033CEB8_15; lis 29,-32702; li 3,0; lis 28,-32702; bl _s8033CEB8_16; li 3,1; bl _s8033CEB8_17; li 6,7; li 7,0; li 5,1; li 3,7; li 4,0; bl _s8033CEB8_18; mr 3,30; li 4,15; bl _s8033CEB8_19; li 4,15; mr 3,30; bl _s8033CEB8_20; mr 3,31; bl _s8033CEB8_21; li 3,1; bl _s8033CEB8_22; li 3,1; bl _s8033CEB8_23; mr 3,30; li 4,30; li 5,1; bl _s8033CEB8_24; li 3,1; li 4,0; li 5,3; li 6,3; li 7,3; bl _s8033CEB8_25; li 7,3; li 4,2; li 5,2; li 6,2; li 3,2; bl _s8033CEB8_26; lis 3,-32716; addi 3,3,-12816; bl _s8033CEB8_27; lis 3,-32716; addi 3,3,-12768; bl _s8033CEB8_28; lfs f1,0x1cf0(29); lis 9,-32702; lfs f2,0x1cf4(9); lis 3,-32688; fmr f3,f1; lfs f6,0x1cf8(28); fmr f4,f2; addi 3,3,-12340; fmr f5,f3; bl _s8033CEB8_29; lhz 0,0x36a(31); lis 8,17200; lhz 7,0x368(31); stw 0,0x14(1); mr 11,9; lis 10,-32702; lfs f1,0x1cf0(29); stw 8,0x10(1); lis 3,-32688; lfd f0,0x1ce8(10); fmr f3,f1; lfd f2,0x10(1); fmr f5,f3; stw 7,0x14(1); addi 3,3,-12276; fsub f2,f2,f0; lfs f6,0x1cf8(28); stw 8,0x10(1); frsp f2,f2; lfd f4,0x10(1); fsub f4,f4,f0; frsp f4,f4; bl _s8033CEB8_30; lis 3,-32688; addi 3,3,-12212; bl _s8033CEB8_31; lwz 3,0x4d8(31); addi 3,3,1952; bl _s8033CEB8_32; lwz 3,0x4d8(31); addi 3,3,2144; bl _s8033CEB8_33; lwz 3,0x4d8(31); addi 3,3,2288; bl _s8033CEB8_34; lwz 3,0x4d8(31); addi 3,3,2336; bl _s8033CEB8_35; lwz 3,0x4d8(31); addi 3,3,2384; bl _s8033CEB8_36; lwz 3,0x4d8(31); addi 3,3,2432; bl _s8033CEB8_37; lwz 9,0x4d8(31); lwz 0,0x6cc(9); oris 0,0,32768; ori 0,0,30; stw 0,0x6cc(9); lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"
extern "C" void _s8033CEB8_0();
extern "C" void _s8033CEB8_1();
extern "C" void _s8033CEB8_2();
extern "C" void _s8033CEB8_3();
extern "C" void _s8033CEB8_4();
extern "C" void _s8033CEB8_5();
extern "C" void _s8033CEB8_6();
extern "C" void _s8033CEB8_7();
extern "C" void _s8033CEB8_8();
extern "C" void _s8033CEB8_9();
extern "C" void _s8033CEB8_10();
extern "C" void _s8033CEB8_11();
extern "C" void _s8033CEB8_12();
extern "C" void _s8033CEB8_13();
extern "C" void _s8033CEB8_14();
extern "C" void _s8033CEB8_15();
extern "C" void _s8033CEB8_16();
extern "C" void _s8033CEB8_17();
extern "C" void _s8033CEB8_18();
extern "C" void _s8033CEB8_19();
extern "C" void _s8033CEB8_20();
extern "C" void _s8033CEB8_21();
extern "C" void _s8033CEB8_22();
extern "C" void _s8033CEB8_23();
extern "C" void _s8033CEB8_24();
extern "C" void _s8033CEB8_25();
extern "C" void _s8033CEB8_26();
extern "C" void _s8033CEB8_27();
extern "C" void _s8033CEB8_28();
extern "C" void _s8033CEB8_29();
extern "C" void _s8033CEB8_30();
extern "C" void _s8033CEB8_31();
extern "C" void _s8033CEB8_32();
extern "C" void _s8033CEB8_33();
extern "C" void _s8033CEB8_34();
extern "C" void _s8033CEB8_35();
extern "C" void _s8033CEB8_36();
extern "C" void _s8033CEB8_37();
extern "C" void f_8033CEB8() {}
