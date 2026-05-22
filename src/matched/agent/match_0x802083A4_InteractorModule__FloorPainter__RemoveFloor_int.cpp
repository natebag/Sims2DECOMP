// 0x802083A4 InteractorModule::FloorPainter::RemoveFloor(int (688 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 24,0x38(1); stw 0,0x5c(1); lwz 11,-21488(13); mr 31,3; addi 29,1,8; addi 27,1,32; lwz 9,0x0(11); mr 26,4; mr 24,29; mr 25,27; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21488(13); mr 28,3; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; mr 30,3; lis 4,-32704; addi 3,1,32; addi 4,4,-13076; bl _s802083A4_0; addi 7,1,32; mr 5,28; mr 6,30; li 4,1; mr 3,29; bl _s802083A4_1; addi 3,1,32; li 4,2; bl _s802083A4_2; lwz 11,-21488(13); lwz 9,0x0(11); lwz 0,0x84(9); lha 3,0x80(9); mtspr 8,0; add 3,11,3; blrl; mr 4,3; mr 3,29; bl _s802083A4_3; mr 3,31; addi 4,1,40; addi 5,1,44; addi 6,1,48; addi 7,1,52; bl _s802083A4_4; mr 3,27; bl _s802083A4_5; lwz 28,0x28(1); lwz 0,0x30(1); cmpw 28,0; bgt 3f; 0:; lwz 30,0x2c(1); addi 27,28,1; lwz 0,0x34(1); cmpw 30,0; bgt 2f; mr 29,25; 1:; mr 5,30; mr 3,29; mr 4,28; li 6,1; bl _s802083A4_6; addi 30,30,1; mr 3,31; mr 4,29; mr 5,26; bl _s802083A4_7; lwz 0,0x34(1); cmpw 30,0; ble 1b; 2:; lwz 0,0x30(1); mr 28,27; cmpw 28,0; ble 0b; 3:; bl _s802083A4_8; cmpwi 3,0; beq 8f; lwz 0,0x98(31); cmpwi 0,0; beq 5f; lwz 0,-31536(13); cmpwi 0,0; bne 4f; li 3,120; bl _s802083A4_9; bl _s802083A4_10; stw 3,-31536(13); 4:; lis 4,-32543; lwz 3,-31536(13); ori 4,4,43469; bl _s802083A4_11; b 7f; 5:; lwz 0,-31536(13); cmpwi 0,0; bne 6f; li 3,120; bl _s802083A4_12; bl _s802083A4_13; stw 3,-31536(13); 6:; lis 4,26334; lwz 3,-31536(13); ori 4,4,56946; bl _s802083A4_14; 7:; lwz 11,-21488(13); li 4,0; lwz 9,0x0(11); lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,11,3; blrl; lis 3,-32697; addi 3,3,24012; bl _s802083A4_15; lwz 11,-21424(13); lwz 9,0x0(11); lha 3,0x88(9); lwz 0,0x8c(9); add 3,11,3; mtspr 8,0; blrl; b 10f; 8:; lwz 11,-21488(13); lwz 9,0x0(11); lwz 0,0x84(9); lha 3,0x80(9); mtspr 8,0; add 3,11,3; blrl; addi 4,1,8; bl _s802083A4_16; lwz 0,-31536(13); cmpwi 0,0; bne 9f; li 3,120; bl _s802083A4_17; bl _s802083A4_18; stw 3,-31536(13); 9:; lwz 3,-31536(13); lis 4,28199; ori 4,4,30903; bl _s802083A4_19; mr 3,25; li 4,2; bl _s802083A4_20; mr 3,24; li 4,2; bl _s802083A4_21; li 3,0; b 11f; 10:; mr 3,25; li 4,2; bl _s802083A4_22; mr 3,24; li 4,2; bl _s802083A4_23; li 3,1; 11:; lwz 0,0x5c(1); mtspr 8,0; lmw 24,0x38(1); addi 1,1,88"
extern "C" void _s802083A4_0();
extern "C" void _s802083A4_1();
extern "C" void _s802083A4_2();
extern "C" void _s802083A4_3();
extern "C" void _s802083A4_4();
extern "C" void _s802083A4_5();
extern "C" void _s802083A4_6();
extern "C" void _s802083A4_7();
extern "C" void _s802083A4_8();
extern "C" void _s802083A4_9();
extern "C" void _s802083A4_10();
extern "C" void _s802083A4_11();
extern "C" void _s802083A4_12();
extern "C" void _s802083A4_13();
extern "C" void _s802083A4_14();
extern "C" void _s802083A4_15();
extern "C" void _s802083A4_16();
extern "C" void _s802083A4_17();
extern "C" void _s802083A4_18();
extern "C" void _s802083A4_19();
extern "C" void _s802083A4_20();
extern "C" void _s802083A4_21();
extern "C" void _s802083A4_22();
extern "C" void _s802083A4_23();
extern "C" void f_802083A4() {}
