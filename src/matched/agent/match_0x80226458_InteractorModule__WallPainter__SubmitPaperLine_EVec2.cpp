// 0x80226458 InteractorModule::WallPainter::SubmitPaperLine(EVec2 (984 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-248(1); mfspr 0,8; stmw 15,0xb4(1); stw 0,0xfc(1); mr 31,3; mr 26,5; mr 25,7; addi 3,1,8; mr 27,4; mr 16,6; bl _s80226458_0; lis 23,-32697; addi 30,1,16; mr 3,30; mr 18,30; bl _s80226458_1; lwz 4,0x90(31); addi 29,1,24; addi 28,1,40; addi 3,23,24012; bl _s80226458_2; mr 24,29; lis 9,-32704; lwz 0,0x88(31); lfs f12,0x4(27); mr 17,3; lfs f11,0x4(26); addi 5,1,8; lfs f13,0x0(27); mr 6,30; lfs f0,0x0(26); mr 3,29; lfs f10,-7172(9); rlwinm 21,0,30,31,31; stfs f13,0x18(1); mr 4,28; stfs f12,0x1c(1); mr 22,28; stfs f0,0x28(1); stfs f11,0x2c(1); stfs f10,0x30(1); stfs f10,0x20(1); bl _s80226458_3; addi 3,1,8; mr 4,30; bl _s80226458_4; addi 3,1,8; mr 4,30; bl _s80226458_5; mr 29,3; cmpwi 29,8; beq 0f; addi 30,1,32; mr 3,29; bl _s80226458_6; mr 20,30; stw 3,0xa8(1); addi 4,1,8; mr 3,24; bl _s80226458_7; mr 4,18; mr 3,30; bl _s80226458_8; li 0,0; mr 4,25; stw 0,0xac(1); addi 3,1,168; addi 5,1,172; mr 6,24; mr 7,30; bl _s80226458_9; lwz 0,0x88(31); andi. 9,0,4; beq 2f; lwz 9,0x94(31); cmpwi 9,-1; beq 3f; lwz 0,0x98(31); cmpw 0,9; ble 2f; addi 3,23,24012; lwz 0,0x3bc(3); cmpwi 0,0; bne 2f; bl _s80226458_10; cmpwi 3,0; bne 2f; mr 3,20; li 4,2; bl _s80226458_11; mr 3,24; li 4,2; bl _s80226458_12; 0:; mr 3,18; li 4,2; bl _s80226458_13; addi 3,1,8; li 4,2; bl _s80226458_14; li 3,0; b 11f; 1:; mr 3,25; li 4,2; bl _s80226458_15; b 10f; 2:; lwz 9,0x94(31); cmpwi 9,-1; beq 3f; cmpwi 21,1; bne 3f; lwz 0,0x98(31); subf 0,0,9; stw 0,0x94(31); 3:; addi 25,1,56; rlwinm 0,29,1,0,30; lis 9,-32696; mr 28,22; lwz 30,-21488(13); add 19,0,29; addi 15,9,24096; mr 26,25; li 22,0; addi 23,1,112; mr 27,24; 4:; lwz 9,0x0(30); mr 3,26; mr 5,24; lha 4,0xa8(9); lwz 0,0xac(9); add 4,30,4; mtspr 8,0; blrl; lwz 4,0xa8(1); mr 3,26; bl _s80226458_16; cmpwi 3,0; beq 7f; lwz 9,0x0(30); mr 4,24; lha 3,0x128(9); lwz 0,0x12c(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 7f; lwz 4,0xa8(1); mr 3,25; li 5,0; bl _s80226458_17; cmpwi 21,0; beq 5f; cmpw 3,17; beq 6f; cmpwi 3,0; beq 6f; addi 4,31,156; bl _s80226458_18; b 6f; 5:; cmpwi 3,0; beq 6f; addi 4,31,156; bl _s80226458_19; 6:; lwz 5,0xa8(1); mr 4,16; lwz 6,0xac(1); mr 3,26; bl _s80226458_20; mr 4,26; mr 3,23; bl _s80226458_21; lwz 9,0x0(30); mr 4,24; mr 5,23; lha 3,0xb0(9); lwz 0,0xb4(9); add 3,30,3; mtspr 8,0; blrl; 7:; add 5,19,15; mr 3,28; mr 4,27; li 29,0; bl _s80226458_22; mr 4,28; mr 3,27; bl _s80226458_23; mr 3,28; li 4,2; bl _s80226458_24; li 0,1; mr 4,27; stb 0,0x1a(1); lwz 9,0x0(30); lha 3,0x58(9); lwz 0,0x5c(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; bne 8f; mr 3,24; mr 4,20; bl _s80226458_25; cmpwi 3,0; beq 9f; 8:; li 29,1; 9:; lwz 9,0x0(30); addi 22,22,1; lha 3,0x40(9); lwz 0,0x44(9); add 3,30,3; mtspr 8,0; blrl; cmpw 22,3; bge 1b; mr 3,25; li 4,2; bl _s80226458_26; cmpwi 29,0; beq 4b; 10:; lwz 3,-21424(13); lwz 9,0x0(3); lha 0,0x88(9); lwz 9,0x8c(9); add 3,3,0; mtspr 8,9; blrl; mr 3,20; li 4,2; bl _s80226458_27; mr 3,24; li 4,2; bl _s80226458_28; mr 3,18; li 4,2; bl _s80226458_29; addi 3,1,8; li 4,2; bl _s80226458_30; li 3,1; 11:; lwz 0,0xfc(1); mtspr 8,0; lmw 15,0xb4(1); addi 1,1,248"
extern "C" void _s80226458_0();
extern "C" void _s80226458_1();
extern "C" void _s80226458_2();
extern "C" void _s80226458_3();
extern "C" void _s80226458_4();
extern "C" void _s80226458_5();
extern "C" void _s80226458_6();
extern "C" void _s80226458_7();
extern "C" void _s80226458_8();
extern "C" void _s80226458_9();
extern "C" void _s80226458_10();
extern "C" void _s80226458_11();
extern "C" void _s80226458_12();
extern "C" void _s80226458_13();
extern "C" void _s80226458_14();
extern "C" void _s80226458_15();
extern "C" void _s80226458_16();
extern "C" void _s80226458_17();
extern "C" void _s80226458_18();
extern "C" void _s80226458_19();
extern "C" void _s80226458_20();
extern "C" void _s80226458_21();
extern "C" void _s80226458_22();
extern "C" void _s80226458_23();
extern "C" void _s80226458_24();
extern "C" void _s80226458_25();
extern "C" void _s80226458_26();
extern "C" void _s80226458_27();
extern "C" void _s80226458_28();
extern "C" void _s80226458_29();
extern "C" void _s80226458_30();
extern "C" void f_80226458() {}
