// 0x80027E30 _kTopLeftWallsEndCapTest(CTilePt (784 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-400(1); mfspr 0,8; stmw 15,0x14c(1); stw 0,0x194(1); mr 24,3; mr 20,4; lis 5,-32696; addi 30,1,16; addi 3,1,8; lwz 31,-21488(13); mr 4,24; addi 5,5,24102; bl _s80027E30_0; mr 19,30; lwz 9,0x0(31); addi 5,1,8; mr 3,30; addi 27,1,80; lwz 0,0xac(9); addi 30,1,72; lha 4,0xa8(9); addi 29,1,136; mtspr 8,0; addi 28,1,200; add 4,31,4; addi 26,1,144; addi 25,1,208; mr 17,27; mr 15,30; mr 16,29; mr 18,26; mr 21,28; blrl; mr 22,25; lis 5,-32696; mr 4,24; mr 3,30; addi 5,5,24108; bl _s80027E30_1; li 23,0; lwz 9,0x0(31); mr 3,27; mr 5,30; li 27,0; lwz 0,0xac(9); lha 4,0xa8(9); mtspr 8,0; add 4,31,4; blrl; lis 5,-32696; mr 4,24; mr 3,29; addi 5,5,24117; bl _s80027E30_2; lwz 9,0x0(31); mr 5,29; mr 3,26; lwz 0,0xac(9); lha 4,0xa8(9); mtspr 8,0; add 4,31,4; blrl; lis 5,-32696; mr 4,24; mr 3,28; addi 5,5,24096; bl _s80027E30_3; lwz 9,0x0(31); mr 3,25; mr 5,28; lha 4,0xa8(9); lwz 0,0xac(9); add 4,31,4; mtspr 8,0; blrl; mr 3,20; li 4,2; bl _s80027E30_4; cmpwi 3,0; bne 0f; mr 3,22; li 4,1; bl _s80027E30_5; cmpwi 3,0; bne 0f; mr 3,17; li 4,32; bl _s80027E30_6; cmpwi 3,0; bne 0f; mr 3,22; li 4,16; bl _s80027E30_7; subfic 0,3,0; adde 23,0,3; 0:; cmpwi 23,0; beq 2f; mr 3,19; li 4,2; bl _s80027E30_8; cmpwi 3,0; beq 1f; ori 27,27,1; b 2f; 1:; ori 27,27,4; 2:; addi 30,1,264; lis 5,-32696; addi 29,1,272; addi 5,5,24099; mr 4,24; mr 3,30; bl _s80027E30_9; li 23,0; mr 4,30; mr 3,21; bl _s80027E30_10; li 4,2; mr 3,30; bl _s80027E30_11; lwz 9,0x0(31); mr 5,21; mr 3,29; lha 4,0xa8(9); lwz 0,0xac(9); add 4,31,4; mtspr 8,0; blrl; mr 4,29; mr 3,22; bl _s80027E30_12; mr 3,29; li 4,2; bl _s80027E30_13; mr 3,20; li 4,8; bl _s80027E30_14; cmpwi 3,0; bne 3f; mr 3,22; li 4,1; bl _s80027E30_15; cmpwi 3,0; bne 3f; mr 3,22; li 4,32; bl _s80027E30_16; cmpwi 3,0; bne 3f; mr 3,18; li 4,16; bl _s80027E30_17; subfic 0,3,0; adde 23,0,3; 3:; cmpwi 23,0; beq 5f; mr 3,19; li 4,8; bl _s80027E30_18; cmpwi 3,0; beq 4f; ori 27,27,2; b 5f; 4:; ori 27,27,8; 5:; mr 3,27; bl _s80027E30_19; mr 30,3; li 4,2; mr 3,22; bl _s80027E30_20; mr 3,21; li 4,2; bl _s80027E30_21; mr 3,18; li 4,2; bl _s80027E30_22; mr 3,16; li 4,2; bl _s80027E30_23; mr 3,17; li 4,2; bl _s80027E30_24; mr 3,15; li 4,2; bl _s80027E30_25; mr 3,19; li 4,2; bl _s80027E30_26; addi 3,1,8; li 4,2; bl _s80027E30_27; mr 3,30; lwz 0,0x194(1); mtspr 8,0; lmw 15,0x14c(1); addi 1,1,400"
extern "C" void _s80027E30_0();
extern "C" void _s80027E30_1();
extern "C" void _s80027E30_2();
extern "C" void _s80027E30_3();
extern "C" void _s80027E30_4();
extern "C" void _s80027E30_5();
extern "C" void _s80027E30_6();
extern "C" void _s80027E30_7();
extern "C" void _s80027E30_8();
extern "C" void _s80027E30_9();
extern "C" void _s80027E30_10();
extern "C" void _s80027E30_11();
extern "C" void _s80027E30_12();
extern "C" void _s80027E30_13();
extern "C" void _s80027E30_14();
extern "C" void _s80027E30_15();
extern "C" void _s80027E30_16();
extern "C" void _s80027E30_17();
extern "C" void _s80027E30_18();
extern "C" void _s80027E30_19();
extern "C" void _s80027E30_20();
extern "C" void _s80027E30_21();
extern "C" void _s80027E30_22();
extern "C" void _s80027E30_23();
extern "C" void _s80027E30_24();
extern "C" void _s80027E30_25();
extern "C" void _s80027E30_26();
extern "C" void _s80027E30_27();
extern "C" void f_80027E30() {}
