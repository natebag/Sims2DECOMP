// 0x80027810 _kTopRightWallsEndCapTest(CTilePt (784 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-400(1); mfspr 0,8; stmw 15,0x14c(1); stw 0,0x194(1); mr 24,3; mr 20,4; lis 5,-32696; addi 30,1,16; addi 3,1,8; lwz 31,-21488(13); mr 4,24; addi 5,5,24096; bl _s80027810_0; mr 19,30; lwz 9,0x0(31); addi 5,1,8; mr 3,30; addi 27,1,80; lwz 0,0xac(9); addi 30,1,72; lha 4,0xa8(9); addi 29,1,136; mtspr 8,0; addi 28,1,200; add 4,31,4; addi 26,1,144; addi 25,1,208; mr 22,27; mr 21,30; mr 15,29; mr 17,26; mr 16,28; blrl; mr 18,25; lis 5,-32696; mr 4,24; mr 3,30; addi 5,5,24105; bl _s80027810_1; li 23,0; lwz 9,0x0(31); mr 3,27; mr 5,30; li 27,0; lwz 0,0xac(9); lha 4,0xa8(9); mtspr 8,0; add 4,31,4; blrl; lis 5,-32696; mr 4,24; mr 3,29; addi 5,5,24108; bl _s80027810_2; lwz 9,0x0(31); mr 5,29; mr 3,26; lwz 0,0xac(9); lha 4,0xa8(9); mtspr 8,0; add 4,31,4; blrl; lis 5,-32696; mr 4,24; mr 3,28; addi 5,5,24114; bl _s80027810_3; lwz 9,0x0(31); mr 3,25; mr 5,28; lha 4,0xa8(9); lwz 0,0xac(9); add 4,31,4; mtspr 8,0; blrl; mr 3,20; li 4,4; bl _s80027810_4; cmpwi 3,0; bne 0f; mr 3,22; li 4,32; bl _s80027810_5; cmpwi 3,0; bne 0f; mr 3,18; li 4,16; bl _s80027810_6; cmpwi 3,0; bne 0f; mr 3,22; li 4,2; bl _s80027810_7; subfic 0,3,0; adde 23,0,3; 0:; cmpwi 23,0; beq 2f; mr 3,19; li 4,4; bl _s80027810_8; cmpwi 3,0; beq 1f; ori 27,27,1; b 2f; 1:; ori 27,27,4; 2:; addi 30,1,264; lis 5,-32696; addi 29,1,272; addi 5,5,24102; mr 4,24; mr 3,30; bl _s80027810_9; li 23,0; mr 4,30; mr 3,21; bl _s80027810_10; li 4,2; mr 3,30; bl _s80027810_11; lwz 9,0x0(31); mr 5,21; mr 3,29; lha 4,0xa8(9); lwz 0,0xac(9); add 4,31,4; mtspr 8,0; blrl; mr 4,29; mr 3,22; bl _s80027810_12; mr 3,29; li 4,2; bl _s80027810_13; mr 3,20; li 4,1; bl _s80027810_14; cmpwi 3,0; bne 3f; mr 3,17; li 4,32; bl _s80027810_15; cmpwi 3,0; bne 3f; mr 3,22; li 4,16; bl _s80027810_16; cmpwi 3,0; bne 3f; mr 3,22; li 4,2; bl _s80027810_17; subfic 0,3,0; adde 23,0,3; 3:; cmpwi 23,0; beq 5f; mr 3,19; li 4,1; bl _s80027810_18; cmpwi 3,0; beq 4f; ori 27,27,2; b 5f; 4:; ori 27,27,8; 5:; mr 3,27; bl _s80027810_19; mr 30,3; li 4,2; mr 3,18; bl _s80027810_20; mr 3,16; li 4,2; bl _s80027810_21; mr 3,17; li 4,2; bl _s80027810_22; mr 3,15; li 4,2; bl _s80027810_23; mr 3,22; li 4,2; bl _s80027810_24; mr 3,21; li 4,2; bl _s80027810_25; mr 3,19; li 4,2; bl _s80027810_26; addi 3,1,8; li 4,2; bl _s80027810_27; mr 3,30; lwz 0,0x194(1); mtspr 8,0; lmw 15,0x14c(1); addi 1,1,400"
extern "C" void _s80027810_0();
extern "C" void _s80027810_1();
extern "C" void _s80027810_2();
extern "C" void _s80027810_3();
extern "C" void _s80027810_4();
extern "C" void _s80027810_5();
extern "C" void _s80027810_6();
extern "C" void _s80027810_7();
extern "C" void _s80027810_8();
extern "C" void _s80027810_9();
extern "C" void _s80027810_10();
extern "C" void _s80027810_11();
extern "C" void _s80027810_12();
extern "C" void _s80027810_13();
extern "C" void _s80027810_14();
extern "C" void _s80027810_15();
extern "C" void _s80027810_16();
extern "C" void _s80027810_17();
extern "C" void _s80027810_18();
extern "C" void _s80027810_19();
extern "C" void _s80027810_20();
extern "C" void _s80027810_21();
extern "C" void _s80027810_22();
extern "C" void _s80027810_23();
extern "C" void _s80027810_24();
extern "C" void _s80027810_25();
extern "C" void _s80027810_26();
extern "C" void _s80027810_27();
extern "C" void f_80027810() {}
