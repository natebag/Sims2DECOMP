// 0x80222DF0 InteractorModule::WallManipulator::HandleAddLine(CTilePt, (664 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-168(1); mfspr 0,8; stmw 22,0x80(1); stw 0,0xac(1); mr 26,6; mr 24,3; lwz 0,0x0(26); mr 23,4; mr 22,5; cmpwi 0,8; bne 0f; li 31,-1; b 11f; 0:; addi 30,1,16; mr 4,23; addi 3,1,8; lwz 31,-21488(13); bl _s80222DF0_0; li 27,0; lwz 3,0x0(26); li 25,0; bl _s80222DF0_1; mr 29,3; mr 3,30; bl _s80222DF0_2; mr 28,30; b 5f; 1:; lwz 9,0x0(31); addi 30,1,72; addi 5,1,8; mr 3,30; lha 4,0xa8(9); lwz 0,0xac(9); add 4,31,4; mtspr 8,0; blrl; mr 4,30; mr 3,28; bl _s80222DF0_3; mr 3,30; li 4,2; bl _s80222DF0_4; mr 3,28; mr 4,29; bl _s80222DF0_5; cmpwi 3,0; beq 3f; lwz 9,0x0(31); andi. 0,29,48; li 5,1; lha 0,0x70(9); addi 11,9,112; add 3,31,0; bne 2f; li 5,0; 2:; lwz 0,0x4(11); addi 4,1,8; mtspr 8,0; blrl; cmpwi 3,0; bne 3f; mr 3,24; addi 4,1,8; mr 5,28; mr 6,29; bl _s80222DF0_6; b 4f; 3:; li 25,1; 4:; lwz 0,0x0(26); lis 9,-32696; addi 9,9,24096; addi 3,1,8; rlwinm 4,0,1,0,30; addi 27,27,1; add 4,4,0; add 4,4,9; bl _s80222DF0_7; li 0,1; stb 0,0xa(1); 5:; addi 3,1,8; mr 4,22; bl _s80222DF0_8; cmpwi 3,0; bne 6f; lwz 9,0x0(31); addi 4,1,8; lha 3,0x58(9); lwz 0,0x5c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1b; 6:; cmpwi 25,0; beq 9f; lis 9,-32696; li 25,1; addi 27,9,24096; addi 30,1,72; b 8f; 7:; lwz 0,0x0(26); addi 3,1,8; rlwinm 4,0,1,0,30; add 4,4,0; add 4,4,27; bl _s80222DF0_9; stb 25,0xa(1); addi 5,1,8; mr 3,30; lwz 9,0x0(31); lha 4,0xa8(9); lwz 0,0xac(9); add 4,31,4; mtspr 8,0; blrl; mr 4,30; mr 3,28; bl _s80222DF0_10; mr 3,30; li 4,2; bl _s80222DF0_11; mr 3,24; addi 4,1,8; mr 5,29; bl _s80222DF0_12; cmpwi 3,0; beq 8f; addi 3,1,8; mr 4,28; mr 5,29; bl _s80222DF0_13; 8:; addi 3,1,8; mr 4,23; bl _s80222DF0_14; cmpwi 3,0; bne 7b; li 27,0; 9:; cmpwi 27,0; bne 10f; mr 3,28; li 4,2; bl _s80222DF0_15; li 31,-1; addi 3,1,8; li 4,2; bl _s80222DF0_16; b 11f; 10:; mr 3,28; li 4,2; bl _s80222DF0_17; mr 31,27; addi 3,1,8; li 4,2; bl _s80222DF0_18; 11:; mr 3,23; li 4,2; bl _s80222DF0_19; mr 3,22; li 4,2; bl _s80222DF0_20; mr 3,31; lwz 0,0xac(1); mtspr 8,0; lmw 22,0x80(1); addi 1,1,168"
extern "C" void _s80222DF0_0();
extern "C" void _s80222DF0_1();
extern "C" void _s80222DF0_2();
extern "C" void _s80222DF0_3();
extern "C" void _s80222DF0_4();
extern "C" void _s80222DF0_5();
extern "C" void _s80222DF0_6();
extern "C" void _s80222DF0_7();
extern "C" void _s80222DF0_8();
extern "C" void _s80222DF0_9();
extern "C" void _s80222DF0_10();
extern "C" void _s80222DF0_11();
extern "C" void _s80222DF0_12();
extern "C" void _s80222DF0_13();
extern "C" void _s80222DF0_14();
extern "C" void _s80222DF0_15();
extern "C" void _s80222DF0_16();
extern "C" void _s80222DF0_17();
extern "C" void _s80222DF0_18();
extern "C" void _s80222DF0_19();
extern "C" void _s80222DF0_20();
extern "C" void f_80222DF0() {}
