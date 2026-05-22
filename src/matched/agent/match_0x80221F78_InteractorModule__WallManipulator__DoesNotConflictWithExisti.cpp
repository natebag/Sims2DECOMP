// 0x80221F78 InteractorModule::WallManipulator::DoesNotConflictWithExistingArchitecture(CTilePt (1028 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; stmw 23,0x74(1); stw 0,0x9c(1); lwz 26,-21488(13); mr 25,4; mr 28,5; addi 3,1,8; lwz 9,0x0(26); mr 5,25; li 24,0; lwz 0,0xac(9); lha 4,0xa8(9); mtspr 8,0; add 4,26,4; blrl; lwz 9,0x0(26); mr 4,25; lha 3,0x128(9); lwz 0,0x12c(9); add 3,26,3; mtspr 8,0; blrl; cmpwi 3,0; beq 13f; addi 3,1,8; mr 4,28; bl _s80221F78_0; mr. 27,3; beq 23f; addi 3,1,64; mr 4,25; li 5,0; bl _s80221F78_1; cmpwi 28,16; beq 2f; bgt 0f; cmpwi 28,2; bgt 23f; cmpwi 28,1; blt 23f; b 9f; 0:; cmpwi 28,32; bne 23f; b 2f; 1:; addi 3,1,64; bl _s80221F78_2; 2:; lwz 11,0x44(1); cmpwi 11,0; beq 10f; lwz 9,0x4(11); lha 3,0x318(9); lwz 0,0x31c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,9; beq 1b; li 27,0; cmpwi 24,0; bne 9f; li 24,11; b 9f; 3:; lwz 30,0x44(1); lwz 9,0x4(30); lha 3,0x318(9); lwz 0,0x31c(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,2; beq 8f; lwz 9,0x4(30); li 4,13; lwz 0,0x264(9); lha 3,0x260(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x4(30); mr 31,3; li 4,1; mr 29,31; lha 3,0x260(9); lwz 0,0x264(9); add 3,30,3; mtspr 8,0; blrl; subfic 4,3,8; rlwinm 4,4,31,30,31; mr 3,28; bl _s80221F78_3; cmpwi 3,1; bne 4f; andi. 0,31,2048; bne 7f; 4:; cmpwi 3,8; bne 5f; andi. 0,31,1024; bne 7f; 5:; cmpwi 3,2; bne 6f; andi. 0,31,256; bne 7f; 6:; cmpwi 3,4; bne 8f; andi. 0,29,512; beq 8f; 7:; li 27,0; cmpwi 24,0; bne 10f; li 24,11; b 10f; 8:; addi 3,1,64; bl _s80221F78_4; 9:; lwz 0,0x44(1); cmpwi 0,0; bne 3b; 10:; cmpwi 27,0; beq 23f; addi 3,1,80; mr 4,25; mr 25,3; bl _s80221F78_5; cmpwi 28,1; bne 11f; addi 30,1,88; li 5,0; li 4,2; mr 3,30; bl _s80221F78_6; mr 23,30; mr 4,30; mr 3,25; bl _s80221F78_7; mr 3,30; li 4,2; bl _s80221F78_8; b 12f; 11:; addi 30,1,88; li 5,0; li 4,0; mr 3,30; bl _s80221F78_9; mr 4,30; mr 3,25; bl _s80221F78_10; mr 23,30; mr 3,30; li 4,2; bl _s80221F78_11; 12:; lwz 9,0x0(26); mr 4,25; lha 3,0x128(9); lwz 0,0x12c(9); add 3,26,3; mtspr 8,0; blrl; cmpwi 3,0; bne 14f; mr 3,25; li 4,2; bl _s80221F78_12; 13:; addi 3,1,8; li 4,2; bl _s80221F78_13; li 3,0; b 24f; 14:; mr 4,25; mr 3,23; bl _s80221F78_14; mr 3,28; li 4,2; bl _s80221F78_15; mr 28,3; mr 4,23; addi 3,1,96; li 5,0; bl _s80221F78_16; lwz 10,0x60(1); addi 11,1,96; lwz 0,0x4(11); addi 9,1,64; lwz 8,0x8(11); mr 26,9; stw 10,0x40(1); stw 0,0x4(9); stw 8,0x8(9); b 21f; 15:; lwz 30,0x44(1); lwz 9,0x4(30); lha 3,0x318(9); lwz 0,0x31c(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,2; beq 20f; lwz 9,0x4(30); li 4,13; lwz 0,0x264(9); lha 3,0x260(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x4(30); mr 31,3; li 4,1; mr 29,31; lha 3,0x260(9); lwz 0,0x264(9); add 3,30,3; mtspr 8,0; blrl; subfic 4,3,8; rlwinm 4,4,31,30,31; mr 3,28; bl _s80221F78_17; cmpwi 3,1; bne 16f; andi. 0,31,2048; bne 19f; 16:; cmpwi 3,8; bne 17f; andi. 0,31,1024; bne 19f; 17:; cmpwi 3,2; bne 18f; andi. 0,31,256; bne 19f; 18:; cmpwi 3,4; bne 20f; andi. 0,29,512; beq 20f; 19:; cmpwi 24,0; li 27,0; b 22f; 20:; mr 3,26; bl _s80221F78_18; 21:; lwz 0,0x44(1); cmpwi 0,0; bne 15b; 22:; mr 3,23; li 4,2; bl _s80221F78_19; mr 3,25; li 4,2; bl _s80221F78_20; 23:; addi 3,1,8; li 4,2; bl _s80221F78_21; mr 3,27; 24:; lwz 0,0x9c(1); mtspr 8,0; lmw 23,0x74(1); addi 1,1,152"
extern "C" void _s80221F78_0();
extern "C" void _s80221F78_1();
extern "C" void _s80221F78_2();
extern "C" void _s80221F78_3();
extern "C" void _s80221F78_4();
extern "C" void _s80221F78_5();
extern "C" void _s80221F78_6();
extern "C" void _s80221F78_7();
extern "C" void _s80221F78_8();
extern "C" void _s80221F78_9();
extern "C" void _s80221F78_10();
extern "C" void _s80221F78_11();
extern "C" void _s80221F78_12();
extern "C" void _s80221F78_13();
extern "C" void _s80221F78_14();
extern "C" void _s80221F78_15();
extern "C" void _s80221F78_16();
extern "C" void _s80221F78_17();
extern "C" void _s80221F78_18();
extern "C" void _s80221F78_19();
extern "C" void _s80221F78_20();
extern "C" void _s80221F78_21();
extern "C" void f_80221F78() {}
