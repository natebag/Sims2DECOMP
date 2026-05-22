// 0x80208954 InteractorModule::FloorPainter::RemoveRoom(int (800 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 21,0x44(1); stw 0,0x74(1); mr 25,3; lfs f0,0x24(25); mr 5,9; lfs f13,0x20(25); mr 23,4; li 6,1; fctiwz f12,f0; addi 3,1,8; stfd f12,0x38(1); fctiwz f11,f13; lwz 9,0x3c(1); stfd f11,0x38(1); mr 4,9; lwz 5,0x3c(1); bl _s80208954_0; lwz 11,-21488(13); addi 4,1,8; lwz 9,0x0(11); lha 3,0xe8(9); lwz 0,0xec(9); add 3,11,3; mtspr 8,0; blrl; mr 30,3; lwz 3,-21472(13); cmpwi 3,0; beq 0f; mr 4,30; bl _s80208954_1; mr 31,3; b 1f; 0:; li 31,0; 1:; cmpwi 31,0; beq 11f; cmpwi 30,0; beq 11f; addi 26,31,4; lwz 9,0x4(31); lwz 0,0x4(26); lwz 22,0x98(25); cmpw 9,0; beq 11f; lwz 11,-21488(13); addi 28,1,16; addi 27,1,40; mr 21,28; lwz 9,0x0(11); mr 24,27; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21488(13); mr 29,3; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; mr 30,3; lis 4,-32704; addi 3,1,40; addi 4,4,-13076; bl _s80208954_2; mr 6,30; addi 7,1,40; mr 5,29; addi 3,1,16; li 4,1; bl _s80208954_3; addi 3,1,40; li 4,2; bl _s80208954_4; lwz 11,-21488(13); lwz 9,0x0(11); lwz 0,0x84(9); lha 3,0x80(9); mtspr 8,0; add 3,11,3; blrl; mr 4,3; mr 3,28; bl _s80208954_5; mr 3,27; bl _s80208954_6; lwz 30,0x4(31); lwz 0,0x4(26); cmpw 30,0; beq 3f; mr 29,24; 2:; mr 4,30; mr 3,29; bl _s80208954_7; addi 30,30,3; mr 3,25; mr 4,29; mr 5,23; bl _s80208954_8; lwz 0,0x4(26); cmpw 30,0; bne 2b; 3:; bl _s80208954_9; cmpwi 3,0; beq 8f; cmpwi 22,0; beq 5f; lwz 0,-31536(13); cmpwi 0,0; bne 4f; li 3,120; bl _s80208954_10; bl _s80208954_11; stw 3,-31536(13); 4:; lis 4,-32543; lwz 3,-31536(13); ori 4,4,43469; bl _s80208954_12; b 7f; 5:; lwz 0,-31536(13); cmpwi 0,0; bne 6f; li 3,120; bl _s80208954_13; bl _s80208954_14; stw 3,-31536(13); 6:; lis 4,26334; lwz 3,-31536(13); ori 4,4,56946; bl _s80208954_15; 7:; lwz 11,-21488(13); li 4,0; lwz 9,0x0(11); lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,11,3; blrl; lis 3,-32697; addi 3,3,24012; bl _s80208954_16; lwz 11,-21424(13); lwz 9,0x0(11); lha 3,0x88(9); lwz 0,0x8c(9); add 3,11,3; mtspr 8,0; blrl; b 10f; 8:; lwz 11,-21488(13); lwz 9,0x0(11); lwz 0,0x84(9); lha 3,0x80(9); mtspr 8,0; add 3,11,3; blrl; mr 4,21; bl _s80208954_17; lwz 0,-31536(13); cmpwi 0,0; bne 9f; li 3,120; bl _s80208954_18; bl _s80208954_19; stw 3,-31536(13); 9:; lwz 3,-31536(13); lis 4,28199; ori 4,4,30903; bl _s80208954_20; mr 3,24; li 4,2; bl _s80208954_21; mr 3,21; li 4,2; bl _s80208954_22; addi 3,1,8; li 4,2; bl _s80208954_23; li 3,0; b 12f; 10:; mr 3,24; li 4,2; bl _s80208954_24; addi 3,1,16; li 4,2; bl _s80208954_25; 11:; addi 3,1,8; li 4,2; bl _s80208954_26; li 3,1; 12:; lwz 0,0x74(1); mtspr 8,0; lmw 21,0x44(1); addi 1,1,112"
extern "C" void _s80208954_0();
extern "C" void _s80208954_1();
extern "C" void _s80208954_2();
extern "C" void _s80208954_3();
extern "C" void _s80208954_4();
extern "C" void _s80208954_5();
extern "C" void _s80208954_6();
extern "C" void _s80208954_7();
extern "C" void _s80208954_8();
extern "C" void _s80208954_9();
extern "C" void _s80208954_10();
extern "C" void _s80208954_11();
extern "C" void _s80208954_12();
extern "C" void _s80208954_13();
extern "C" void _s80208954_14();
extern "C" void _s80208954_15();
extern "C" void _s80208954_16();
extern "C" void _s80208954_17();
extern "C" void _s80208954_18();
extern "C" void _s80208954_19();
extern "C" void _s80208954_20();
extern "C" void _s80208954_21();
extern "C" void _s80208954_22();
extern "C" void _s80208954_23();
extern "C" void _s80208954_24();
extern "C" void _s80208954_25();
extern "C" void _s80208954_26();
extern "C" void f_80208954() {}
