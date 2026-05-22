// 0x80097BF8 TheSimsSimsIntroMovieState::Startup(void) (332 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s80097BF8_0; bl _s80097BF8_1; bl _s80097BF8_2; bl _s80097BF8_3; bl _s80097BF8_4; bl _s80097BF8_5; bl _s80097BF8_6; bl _s80097BF8_7; bl _s80097BF8_8; bl _s80097BF8_9; bl _s80097BF8_10; bl _s80097BF8_11; bl _s80097BF8_12; bl _s80097BF8_13; bl _s80097BF8_14; bl _s80097BF8_15; bl _s80097BF8_16; bl _s80097BF8_17; bl _s80097BF8_18; bl _s80097BF8_19; bl _s80097BF8_20; bl _s80097BF8_21; bl _s80097BF8_22; bl _s80097BF8_23; bl _s80097BF8_24; bl _s80097BF8_25; bl _s80097BF8_26; lwz 10,-26564(13); lis 9,-32706; lwz 11,0x0(10); lfs f1,-29732(9); lwz 0,0x64(11); lha 3,0x60(11); mtspr 8,0; add 3,10,3; blrl; lis 9,-32697; addi 9,9,24012; lwz 0,0x43c(9); cmpwi 0,0; bne 0f; lwz 9,0x3a8(9); cmpwi 9,0; beq 1f; 0:; lis 9,-32706; mr 3,31; lfs f1,-29728(9); li 4,5; bl _s80097BF8_27; b 2f; 1:; stw 9,-28408(13); li 0,1; stw 9,-28404(13); lis 3,-32697; stw 0,0x24(31); addi 3,3,23428; bl _s80097BF8_28; mr 4,3; li 5,-1; lis 3,-32697; li 6,-1; addi 3,3,-7672; bl _s80097BF8_29; lis 9,-32706; mr 3,31; lfs f1,-29724(9); li 4,5; bl _s80097BF8_30; 2:; li 0,0; lis 3,-32697; stw 0,0x20(31); addi 3,3,23428; bl _s80097BF8_31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80097BF8_0();
extern "C" void _s80097BF8_1();
extern "C" void _s80097BF8_2();
extern "C" void _s80097BF8_3();
extern "C" void _s80097BF8_4();
extern "C" void _s80097BF8_5();
extern "C" void _s80097BF8_6();
extern "C" void _s80097BF8_7();
extern "C" void _s80097BF8_8();
extern "C" void _s80097BF8_9();
extern "C" void _s80097BF8_10();
extern "C" void _s80097BF8_11();
extern "C" void _s80097BF8_12();
extern "C" void _s80097BF8_13();
extern "C" void _s80097BF8_14();
extern "C" void _s80097BF8_15();
extern "C" void _s80097BF8_16();
extern "C" void _s80097BF8_17();
extern "C" void _s80097BF8_18();
extern "C" void _s80097BF8_19();
extern "C" void _s80097BF8_20();
extern "C" void _s80097BF8_21();
extern "C" void _s80097BF8_22();
extern "C" void _s80097BF8_23();
extern "C" void _s80097BF8_24();
extern "C" void _s80097BF8_25();
extern "C" void _s80097BF8_26();
extern "C" void _s80097BF8_27();
extern "C" void _s80097BF8_28();
extern "C" void _s80097BF8_29();
extern "C" void _s80097BF8_30();
extern "C" void _s80097BF8_31();
extern "C" void f_80097BF8() {}
