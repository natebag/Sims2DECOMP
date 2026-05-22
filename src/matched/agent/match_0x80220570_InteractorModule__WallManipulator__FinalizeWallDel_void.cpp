// 0x80220570 InteractorModule::WallManipulator::FinalizeWallDel(void) (976 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-160(1); mfspr 0,8; stmw 21,0x74(1); stw 0,0xa4(1); mr 31,3; addi 27,1,8; lfs f0,0x60(31); addi 9,31,96; lfs f12,0x20(31); addi 11,31,32; stfs f0,0x8(1); addi 23,1,40; lwz 10,-21488(13); addi 22,1,24; lfs f13,0x4(9); lis 21,-32704; stfs f13,0x4(27); lfs f0,0x8(9); stfs f0,0x8(27); stfs f12,0x18(1); lfs f0,0x4(11); stfs f0,0x1c(1); lfs f13,0x8(11); stfs f13,0x20(1); lwz 9,0x0(10); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,10,3; blrl; lwz 11,-21488(13); mr 29,3; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; mr 30,3; addi 4,21,-7976; addi 3,1,64; bl _s80220570_0; addi 7,1,64; mr 5,29; mr 6,30; addi 3,1,40; li 4,8; bl _s80220570_1; addi 3,1,64; li 4,2; bl _s80220570_2; lwz 11,-21488(13); lwz 9,0x0(11); lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,11,3; blrl; mr 4,3; mr 3,23; bl _s80220570_3; li 0,0; mr 3,31; stw 0,0x68(1); mr 4,27; mr 5,22; addi 6,1,104; li 7,1; li 8,1; bl _s80220570_4; cmpwi 3,0; beq 0f; mr 3,31; bl _s80220570_5; cmpwi 3,0; beq 2f; lis 9,-32697; lwz 4,0xc4(31); addi 25,9,24012; lwz 9,0xc8(25); rlwinm 4,4,24,31,31; lwz 3,0x8(9); bl _s80220570_6; cmpwi 3,0; bne 2f; lwz 11,-21488(13); addi 26,1,64; addi 28,1,96; addi 24,1,72; lwz 9,0x0(11); lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,11,3; blrl; mr 4,23; bl _s80220570_7; lwz 11,-21488(13); li 4,0; lwz 9,0x0(11); lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21488(13); lwz 9,0x0(11); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21488(13); mr 29,3; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; mr 30,3; addi 4,21,-7976; addi 3,1,64; bl _s80220570_8; addi 7,1,64; addi 3,1,72; mr 5,29; mr 6,30; li 4,8; bl _s80220570_9; addi 3,1,64; li 4,2; bl _s80220570_10; lwz 11,-21488(13); lwz 9,0x0(11); lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,11,3; blrl; mr 4,3; mr 3,24; bl _s80220570_11; mr 3,26; bl _s80220570_12; mr 3,28; bl _s80220570_13; mr 5,26; mr 6,28; mr 3,27; mr 4,22; bl _s80220570_14; mr 4,28; mr 3,26; bl _s80220570_15; bl _s80220570_16; lwz 9,0xc8(25); mr 4,3; mr 5,26; mr 6,28; lwz 3,0x8(9); bl _s80220570_17; lwz 9,0xc8(25); lwz 4,0xc4(31); lwz 3,0x8(9); rlwinm 4,4,24,31,31; bl _s80220570_18; cmpwi 3,0; bne 1f; lwz 11,-21488(13); lwz 9,0x0(11); lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,11,3; blrl; mr 4,24; bl _s80220570_19; lwz 11,-21488(13); li 4,0; lwz 9,0x0(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; mr 3,28; li 4,2; bl _s80220570_20; mr 3,26; li 4,2; bl _s80220570_21; mr 3,24; li 4,2; bl _s80220570_22; 0:; mr 3,23; li 4,2; bl _s80220570_23; li 3,0; b 4f; 1:; mr 3,28; li 4,2; bl _s80220570_24; mr 3,26; li 4,2; bl _s80220570_25; mr 3,24; li 4,2; bl _s80220570_26; 2:; lwz 9,0xc8(31); cmpwi 9,-1; beq 3f; lwz 0,0x68(1); cmpwi 0,-1; beq 3f; add 0,9,0; stw 0,0xc8(31); 3:; lwz 11,-21488(13); li 4,0; lwz 9,0x0(11); lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,11,3; blrl; lis 3,-32697; addi 3,3,24012; bl _s80220570_27; lwz 11,-21424(13); lwz 9,0x0(11); lha 3,0x88(9); lwz 0,0x8c(9); add 3,11,3; mtspr 8,0; blrl; addi 3,1,40; li 4,2; bl _s80220570_28; li 3,1; 4:; lwz 0,0xa4(1); mtspr 8,0; lmw 21,0x74(1); addi 1,1,160"
extern "C" void _s80220570_0();
extern "C" void _s80220570_1();
extern "C" void _s80220570_2();
extern "C" void _s80220570_3();
extern "C" void _s80220570_4();
extern "C" void _s80220570_5();
extern "C" void _s80220570_6();
extern "C" void _s80220570_7();
extern "C" void _s80220570_8();
extern "C" void _s80220570_9();
extern "C" void _s80220570_10();
extern "C" void _s80220570_11();
extern "C" void _s80220570_12();
extern "C" void _s80220570_13();
extern "C" void _s80220570_14();
extern "C" void _s80220570_15();
extern "C" void _s80220570_16();
extern "C" void _s80220570_17();
extern "C" void _s80220570_18();
extern "C" void _s80220570_19();
extern "C" void _s80220570_20();
extern "C" void _s80220570_21();
extern "C" void _s80220570_22();
extern "C" void _s80220570_23();
extern "C" void _s80220570_24();
extern "C" void _s80220570_25();
extern "C" void _s80220570_26();
extern "C" void _s80220570_27();
extern "C" void _s80220570_28();
extern "C" void f_80220570() {}
