// 0x80367C9C ERAnim::OldLoad(EFile (672 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 27,0x3c(1); stw 0,0x54(1); mr 31,3; mr 27,4; addi 3,1,8; bl _s80367C9C_0; lis 5,16718; addi 3,1,8; mr 4,27; ori 5,5,18765; li 6,17; li 7,17; bl _s80367C9C_1; cmpwi 3,0; beq 0f; addi 3,1,8; addi 29,31,80; bl _s80367C9C_2; lwz 9,0x18(1); lwz 0,0x10(31); rlwimi 0,9,8,0,23; stw 0,0x10(31); bl _s80367C9C_3; lwz 4,0x18(1); li 5,0; bl _s80367C9C_4; lwz 9,0x28(27); mr 28,3; lwz 5,0x18(1); mr 4,28; lwz 0,0x1c(9); addi 30,28,28; lha 3,0x18(9); mtspr 8,0; add 3,27,3; blrl; mr 4,28; li 5,4; addi 3,31,24; bl _s80367C9C_5; addi 4,28,4; li 5,12; addi 3,31,28; bl _s80367C9C_6; li 5,12; addi 4,28,16; addi 3,31,40; bl _s80367C9C_7; mr 4,30; addi 3,31,52; bl _s80367C9C_8; add 30,30,3; li 5,4; mr 4,30; addi 3,31,64; bl _s80367C9C_9; addi 30,30,4; mr 4,30; addi 3,31,68; bl _s80367C9C_10; add 30,30,3; li 5,4; addi 3,1,32; mr 4,30; bl _s80367C9C_11; addi 30,30,4; mr 3,29; li 4,0; li 5,0; bl _s80367C9C_12; lwz 4,0x20(1); li 5,0; mr 3,29; bl _s80367C9C_13; mr 3,29; bl _s80367C9C_14; rlwinm 0,3,2,0,29; mr 4,30; lwz 3,0x50(31); add 30,30,0; mr 5,0; bl _s80367C9C_15; mr 4,30; li 5,4; addi 3,31,100; addi 30,30,4; bl _s80367C9C_16; mr 4,30; li 5,4; addi 3,31,104; addi 30,30,4; bl _s80367C9C_17; mr 4,30; li 5,4; addi 3,31,108; addi 30,30,4; bl _s80367C9C_18; mr 4,30; li 5,1; addi 3,31,114; addi 30,30,1; bl _s80367C9C_19; mr 4,30; li 5,4; addi 3,31,116; addi 30,30,4; bl _s80367C9C_20; mr 4,30; li 5,4; addi 3,31,120; addi 30,30,4; bl _s80367C9C_21; mr 4,30; li 5,4; addi 3,31,124; addi 30,30,4; bl _s80367C9C_22; mr 4,30; li 5,4; addi 3,31,128; addi 30,30,4; bl _s80367C9C_23; mr 4,30; li 5,1; addi 3,31,112; addi 30,30,1; bl _s80367C9C_24; li 5,1; mr 4,30; addi 3,31,113; bl _s80367C9C_25; addi 4,30,1; addi 3,31,148; bl _s80367C9C_26; lwz 0,0x18(31); lis 8,17200; lis 9,-32702; xoris 0,0,32768; lfd f13,0x3290(9); stw 0,0x34(1); lis 10,-32702; lfs f10,0x64(31); mr 9,11; stw 8,0x30(1); lfs f11,0x3298(10); lfd f0,0x30(1); fsub f0,f0,f13; frsp f0,f0; fdivs f0,f0,f10; fmuls f0,f0,f11; fmr f13,f0; fctiwz f12,f13; stfd f12,0x30(1); lwz 9,0x34(1); stw 9,0x14(31); bl _s80367C9C_27; mr 4,28; bl _s80367C9C_28; 0:; addi 3,1,8; li 4,2; bl _s80367C9C_29; lwz 0,0x54(1); mtspr 8,0; lmw 27,0x3c(1); addi 1,1,80"
extern "C" void _s80367C9C_0();
extern "C" void _s80367C9C_1();
extern "C" void _s80367C9C_2();
extern "C" void _s80367C9C_3();
extern "C" void _s80367C9C_4();
extern "C" void _s80367C9C_5();
extern "C" void _s80367C9C_6();
extern "C" void _s80367C9C_7();
extern "C" void _s80367C9C_8();
extern "C" void _s80367C9C_9();
extern "C" void _s80367C9C_10();
extern "C" void _s80367C9C_11();
extern "C" void _s80367C9C_12();
extern "C" void _s80367C9C_13();
extern "C" void _s80367C9C_14();
extern "C" void _s80367C9C_15();
extern "C" void _s80367C9C_16();
extern "C" void _s80367C9C_17();
extern "C" void _s80367C9C_18();
extern "C" void _s80367C9C_19();
extern "C" void _s80367C9C_20();
extern "C" void _s80367C9C_21();
extern "C" void _s80367C9C_22();
extern "C" void _s80367C9C_23();
extern "C" void _s80367C9C_24();
extern "C" void _s80367C9C_25();
extern "C" void _s80367C9C_26();
extern "C" void _s80367C9C_27();
extern "C" void _s80367C9C_28();
extern "C" void _s80367C9C_29();
extern "C" void f_80367C9C() {}
