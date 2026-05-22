// 0x800284A0 _kHorizDiagWallskBottomEndCapTest(CTilePt (864 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-464(1); mfspr 0,8; stmw 14,0x188(1); stw 0,0x1d4(1); mr 24,3; lis 5,-32696; addi 3,1,8; lwz 31,-21488(13); mr 4,24; addi 5,5,24102; bl _s800284A0_0; li 23,0; lwz 9,0x0(31); addi 3,1,16; addi 5,1,8; addi 30,1,72; lwz 0,0xac(9); addi 27,1,80; lha 4,0xa8(9); addi 29,1,136; mtspr 8,0; addi 28,1,200; add 4,31,4; addi 25,1,144; mr 16,3; mr 17,27; mr 14,29; mr 20,25; mr 15,28; li 22,0; blrl; lis 5,-32696; mr 3,30; mr 4,24; addi 5,5,24096; bl _s800284A0_1; lwz 9,0x0(31); mr 5,30; mr 3,27; addi 26,1,208; lwz 0,0xac(9); addi 30,1,264; lha 4,0xa8(9); addi 27,1,272; mtspr 8,0; mr 18,26; add 4,31,4; mr 19,30; mr 21,27; blrl; lis 5,-32696; mr 4,24; mr 3,29; addi 5,5,24114; bl _s800284A0_2; lwz 9,0x0(31); mr 5,29; mr 3,25; lwz 0,0xac(9); lha 4,0xa8(9); mtspr 8,0; add 4,31,4; blrl; lis 5,-32696; mr 4,24; mr 3,28; addi 5,5,24117; bl _s800284A0_3; lwz 9,0x0(31); mr 5,28; mr 3,26; lwz 0,0xac(9); lha 4,0xa8(9); mtspr 8,0; add 4,31,4; blrl; lis 5,-32696; mr 4,24; mr 3,30; addi 5,5,24099; bl _s800284A0_4; lwz 9,0x0(31); mr 3,27; mr 5,30; lha 4,0xa8(9); lwz 0,0xac(9); add 4,31,4; mtspr 8,0; blrl; mr 3,26; li 4,16; bl _s800284A0_5; cmpwi 3,0; bne 0f; mr 3,18; li 4,4; bl _s800284A0_6; cmpwi 3,0; bne 0f; mr 3,21; li 4,32; bl _s800284A0_7; subfic 0,3,0; adde 22,0,3; 0:; cmpwi 22,0; beq 3f; mr 3,16; li 4,32; bl _s800284A0_8; cmpwi 3,0; bne 1f; mr 3,18; li 4,2; bl _s800284A0_9; cmpwi 3,0; beq 2f; 1:; ori 23,23,2; b 3f; 2:; ori 23,23,8; 3:; addi 30,1,328; lis 5,-32696; addi 29,1,336; addi 5,5,24105; mr 4,24; mr 3,30; bl _s800284A0_10; li 22,0; mr 4,30; mr 3,19; bl _s800284A0_11; li 4,2; mr 3,30; bl _s800284A0_12; lwz 9,0x0(31); mr 5,19; mr 3,29; lha 4,0xa8(9); lwz 0,0xac(9); add 4,31,4; mtspr 8,0; blrl; mr 4,29; mr 3,21; bl _s800284A0_13; mr 3,29; li 4,2; bl _s800284A0_14; mr 3,20; li 4,16; bl _s800284A0_15; cmpwi 3,0; bne 4f; mr 3,20; li 4,8; bl _s800284A0_16; cmpwi 3,0; bne 4f; mr 3,21; li 4,32; bl _s800284A0_17; subfic 0,3,0; adde 22,0,3; 4:; cmpwi 22,0; beq 7f; mr 3,17; li 4,32; bl _s800284A0_18; cmpwi 3,0; bne 5f; mr 3,20; li 4,1; bl _s800284A0_19; cmpwi 3,0; beq 6f; 5:; ori 23,23,1; b 7f; 6:; ori 23,23,4; 7:; mr 3,23; bl _s800284A0_20; mr 30,3; li 4,2; mr 3,21; bl _s800284A0_21; mr 3,19; li 4,2; bl _s800284A0_22; mr 3,18; li 4,2; bl _s800284A0_23; mr 3,15; li 4,2; bl _s800284A0_24; mr 3,20; li 4,2; bl _s800284A0_25; mr 3,14; li 4,2; bl _s800284A0_26; mr 3,17; li 4,2; bl _s800284A0_27; addi 3,1,72; li 4,2; bl _s800284A0_28; mr 3,16; li 4,2; bl _s800284A0_29; addi 3,1,8; li 4,2; bl _s800284A0_30; mr 3,30; lwz 0,0x1d4(1); mtspr 8,0; lmw 14,0x188(1); addi 1,1,464"
extern "C" void _s800284A0_0();
extern "C" void _s800284A0_1();
extern "C" void _s800284A0_2();
extern "C" void _s800284A0_3();
extern "C" void _s800284A0_4();
extern "C" void _s800284A0_5();
extern "C" void _s800284A0_6();
extern "C" void _s800284A0_7();
extern "C" void _s800284A0_8();
extern "C" void _s800284A0_9();
extern "C" void _s800284A0_10();
extern "C" void _s800284A0_11();
extern "C" void _s800284A0_12();
extern "C" void _s800284A0_13();
extern "C" void _s800284A0_14();
extern "C" void _s800284A0_15();
extern "C" void _s800284A0_16();
extern "C" void _s800284A0_17();
extern "C" void _s800284A0_18();
extern "C" void _s800284A0_19();
extern "C" void _s800284A0_20();
extern "C" void _s800284A0_21();
extern "C" void _s800284A0_22();
extern "C" void _s800284A0_23();
extern "C" void _s800284A0_24();
extern "C" void _s800284A0_25();
extern "C" void _s800284A0_26();
extern "C" void _s800284A0_27();
extern "C" void _s800284A0_28();
extern "C" void _s800284A0_29();
extern "C" void _s800284A0_30();
extern "C" void f_800284A0() {}
