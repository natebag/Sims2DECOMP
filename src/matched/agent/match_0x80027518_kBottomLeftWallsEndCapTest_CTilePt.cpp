// 0x80027518 _kBottomLeftWallsEndCapTest(CTilePt (760 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-400(1); mfspr 0,8; stmw 14,0x148(1); stw 0,0x194(1); mr 25,3; mr 19,4; lis 5,-32696; addi 30,1,16; addi 3,1,8; lwz 29,-21488(13); mr 4,25; addi 5,5,24099; bl _s80027518_0; mr 18,30; lwz 9,0x0(29); addi 5,1,8; mr 3,30; addi 27,1,80; lwz 0,0xac(9); addi 30,1,72; lha 4,0xa8(9); addi 26,1,200; mtspr 8,0; addi 28,1,136; add 4,29,4; addi 24,1,144; addi 23,1,208; mr 16,27; mr 17,24; mr 14,26; mr 20,23; li 31,0; blrl; li 22,0; lis 5,-32696; mr 3,30; mr 4,25; addi 5,5,24111; bl _s80027518_1; lwz 9,0x0(29); mr 5,30; mr 3,27; addi 30,1,272; lwz 0,0xac(9); addi 27,1,264; lha 4,0xa8(9); mr 15,27; mtspr 8,0; mr 21,30; add 4,29,4; blrl; lis 5,-32696; mr 4,25; mr 3,28; addi 5,5,24117; bl _s80027518_2; lwz 9,0x0(29); mr 5,28; mr 3,24; lwz 0,0xac(9); lha 4,0xa8(9); mtspr 8,0; add 4,29,4; blrl; lis 5,-32696; mr 4,25; mr 3,26; addi 5,5,24105; bl _s80027518_3; lwz 9,0x0(29); mr 5,26; mr 3,23; lwz 0,0xac(9); lha 4,0xa8(9); mtspr 8,0; add 4,29,4; blrl; lis 5,-32696; mr 4,25; addi 5,5,24102; mr 3,27; bl _s80027518_4; lwz 9,0x0(29); mr 3,30; mr 5,27; lha 4,0xa8(9); lwz 0,0xac(9); add 4,29,4; mtspr 8,0; blrl; mr 3,19; li 4,4; bl _s80027518_5; cmpwi 3,0; bne 0f; mr 3,16; li 4,32; bl _s80027518_6; cmpwi 3,0; bne 0f; mr 3,20; li 4,16; bl _s80027518_7; cmpwi 3,0; bne 0f; mr 3,20; li 4,8; bl _s80027518_8; subfic 0,3,0; adde 22,0,3; 0:; cmpwi 22,0; beq 2f; mr 3,18; li 4,4; bl _s80027518_9; cmpwi 3,0; beq 1f; ori 31,31,2; b 2f; 1:; ori 31,31,8; 2:; mr 3,19; li 4,1; bl _s80027518_10; li 22,0; cmpwi 3,0; bne 3f; mr 3,21; li 4,32; bl _s80027518_11; cmpwi 3,0; bne 3f; mr 3,17; li 4,16; bl _s80027518_12; cmpwi 3,0; bne 3f; mr 3,21; li 4,8; bl _s80027518_13; subfic 0,3,0; adde 22,0,3; 3:; cmpwi 22,0; beq 5f; mr 3,18; li 4,1; bl _s80027518_14; cmpwi 3,0; beq 4f; ori 31,31,1; b 5f; 4:; ori 31,31,4; 5:; mr 3,31; bl _s80027518_15; mr 30,3; li 4,2; mr 3,21; bl _s80027518_16; mr 3,15; li 4,2; bl _s80027518_17; mr 3,20; li 4,2; bl _s80027518_18; mr 3,14; li 4,2; bl _s80027518_19; mr 3,17; li 4,2; bl _s80027518_20; addi 3,1,136; li 4,2; bl _s80027518_21; mr 3,16; li 4,2; bl _s80027518_22; addi 3,1,72; li 4,2; bl _s80027518_23; mr 3,18; li 4,2; bl _s80027518_24; addi 3,1,8; li 4,2; bl _s80027518_25; mr 3,30; lwz 0,0x194(1); mtspr 8,0; lmw 14,0x148(1); addi 1,1,400"
extern "C" void _s80027518_0();
extern "C" void _s80027518_1();
extern "C" void _s80027518_2();
extern "C" void _s80027518_3();
extern "C" void _s80027518_4();
extern "C" void _s80027518_5();
extern "C" void _s80027518_6();
extern "C" void _s80027518_7();
extern "C" void _s80027518_8();
extern "C" void _s80027518_9();
extern "C" void _s80027518_10();
extern "C" void _s80027518_11();
extern "C" void _s80027518_12();
extern "C" void _s80027518_13();
extern "C" void _s80027518_14();
extern "C" void _s80027518_15();
extern "C" void _s80027518_16();
extern "C" void _s80027518_17();
extern "C" void _s80027518_18();
extern "C" void _s80027518_19();
extern "C" void _s80027518_20();
extern "C" void _s80027518_21();
extern "C" void _s80027518_22();
extern "C" void _s80027518_23();
extern "C" void _s80027518_24();
extern "C" void _s80027518_25();
extern "C" void f_80027518() {}
