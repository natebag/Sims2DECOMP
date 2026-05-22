// 0x80208654 InteractorModule::FloorPainter::PaintRoom(int (768 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 21,0x44(1); stw 0,0x74(1); mr 25,3; lfs f0,0x24(25); mr 5,9; lfs f13,0x20(25); mr 23,4; li 6,1; fctiwz f12,f0; addi 3,1,8; stfd f12,0x38(1); fctiwz f11,f13; lwz 9,0x3c(1); stfd f11,0x38(1); mr 4,9; lwz 5,0x3c(1); bl _s80208654_0; lwz 11,-21488(13); addi 4,1,8; lwz 9,0x0(11); lha 3,0xe8(9); lwz 0,0xec(9); add 3,11,3; mtspr 8,0; blrl; mr 30,3; lwz 3,-21472(13); cmpwi 3,0; beq 0f; mr 4,30; bl _s80208654_1; mr 31,3; b 1f; 0:; li 31,0; 1:; li 21,0; li 24,0; cmpwi 31,0; beq 12f; cmpwi 30,0; beq 12f; addi 26,31,4; lwz 9,0x4(31); lwz 0,0x4(26); lwz 27,0x98(25); cmpw 9,0; beq 12f; lwz 11,-21488(13); addi 28,1,16; mr 22,28; lwz 9,0x0(11); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21488(13); mr 29,3; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; mr 30,3; lis 4,-32704; addi 3,1,40; addi 4,4,-13076; bl _s80208654_2; mr 6,30; mr 5,29; addi 7,1,40; addi 3,1,16; li 4,1; bl _s80208654_3; addi 3,1,40; li 4,2; bl _s80208654_4; lwz 11,-21488(13); lwz 9,0x0(11); lwz 0,0x84(9); lha 3,0x80(9); mtspr 8,0; add 3,11,3; blrl; mr 4,3; mr 3,28; bl _s80208654_5; lwz 30,0x4(31); lwz 0,0x4(26); cmpw 30,0; beq 4f; 2:; mr 3,25; mr 4,30; mr 5,27; mr 6,31; mr 7,23; bl _s80208654_6; cmpwi 3,0; bne 3f; addi 24,24,1; 3:; lwz 0,0x4(26); addi 30,30,3; cmpw 30,0; bne 2b; 4:; bl _s80208654_7; cmpwi 3,0; beq 9f; cmpwi 27,0; beq 6f; lwz 0,-31536(13); cmpwi 0,0; bne 5f; li 3,120; bl _s80208654_8; bl _s80208654_9; stw 3,-31536(13); 5:; lis 4,-32543; lwz 3,-31536(13); ori 4,4,43469; bl _s80208654_10; b 8f; 6:; lwz 0,-31536(13); cmpwi 0,0; bne 7f; li 3,120; bl _s80208654_11; bl _s80208654_12; stw 3,-31536(13); 7:; lis 4,26334; lwz 3,-31536(13); ori 4,4,56946; bl _s80208654_13; 8:; lwz 11,-21488(13); li 4,0; lwz 9,0x0(11); lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,11,3; blrl; lis 3,-32697; addi 3,3,24012; bl _s80208654_14; lwz 11,-21424(13); lwz 9,0x0(11); lwz 0,0x8c(9); lha 3,0x88(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x0(26); lis 9,-21846; lwz 0,0x4(26); ori 9,9,43691; subf 0,11,0; mullw 21,0,9; b 11f; 9:; lwz 11,-21488(13); lwz 9,0x0(11); lwz 0,0x84(9); lha 3,0x80(9); mtspr 8,0; add 3,11,3; blrl; mr 4,22; bl _s80208654_15; lwz 0,-31536(13); cmpwi 0,0; bne 10f; li 3,120; bl _s80208654_16; bl _s80208654_17; stw 3,-31536(13); 10:; lis 4,28199; lwz 3,-31536(13); ori 4,4,30903; bl _s80208654_18; 11:; addi 3,1,16; li 4,2; bl _s80208654_19; 12:; addi 3,1,8; li 4,2; subf 30,24,21; bl _s80208654_20; mr 3,30; lwz 0,0x74(1); mtspr 8,0; lmw 21,0x44(1); addi 1,1,112"
extern "C" void _s80208654_0();
extern "C" void _s80208654_1();
extern "C" void _s80208654_2();
extern "C" void _s80208654_3();
extern "C" void _s80208654_4();
extern "C" void _s80208654_5();
extern "C" void _s80208654_6();
extern "C" void _s80208654_7();
extern "C" void _s80208654_8();
extern "C" void _s80208654_9();
extern "C" void _s80208654_10();
extern "C" void _s80208654_11();
extern "C" void _s80208654_12();
extern "C" void _s80208654_13();
extern "C" void _s80208654_14();
extern "C" void _s80208654_15();
extern "C" void _s80208654_16();
extern "C" void _s80208654_17();
extern "C" void _s80208654_18();
extern "C" void _s80208654_19();
extern "C" void _s80208654_20();
extern "C" void f_80208654() {}
