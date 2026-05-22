// 0x8020812C InteractorModule::FloorPainter::PaintFloor(int (632 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 22,0x38(1); stw 0,0x64(1); lwz 11,-21488(13); mr 26,3; addi 29,1,8; addi 27,1,32; lwz 9,0x0(11); mr 24,4; mr 22,29; li 25,0; lwz 0,0x34(9); mr 23,27; lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21488(13); mr 28,3; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; mr 30,3; lis 4,-32704; addi 3,1,32; addi 4,4,-13076; bl _s8020812C_0; addi 7,1,32; mr 5,28; mr 6,30; li 4,1; mr 3,29; bl _s8020812C_1; addi 3,1,32; li 4,2; bl _s8020812C_2; lwz 11,-21488(13); lwz 9,0x0(11); lwz 0,0x84(9); lha 3,0x80(9); mtspr 8,0; add 3,11,3; blrl; mr 4,3; mr 3,29; bl _s8020812C_3; mr 3,26; addi 4,1,40; addi 5,1,44; addi 6,1,48; addi 7,1,52; bl _s8020812C_4; mr 3,27; bl _s8020812C_5; lwz 28,0x28(1); lwz 0,0x30(1); lwz 31,0x98(26); cmpw 28,0; bgt 4f; 0:; lwz 30,0x2c(1); addi 27,28,1; lwz 0,0x34(1); cmpw 30,0; bgt 3f; mr 29,23; 1:; mr 3,29; mr 4,28; mr 5,30; li 6,1; bl _s8020812C_6; mr 3,26; mr 4,29; mr 5,31; mr 6,24; bl _s8020812C_7; cmpwi 3,0; beq 2f; addi 25,25,1; 2:; lwz 0,0x34(1); addi 30,30,1; cmpw 30,0; ble 1b; 3:; lwz 0,0x30(1); mr 28,27; cmpw 28,0; ble 0b; 4:; bl _s8020812C_8; cmpwi 3,0; beq 7f; cmpwi 31,0; beq 6f; lwz 0,-31536(13); cmpwi 0,0; bne 5f; li 3,120; bl _s8020812C_9; bl _s8020812C_10; stw 3,-31536(13); 5:; lis 4,-32543; lwz 3,-31536(13); ori 4,4,43469; bl _s8020812C_11; 6:; lwz 11,-21488(13); li 4,0; lwz 9,0x0(11); lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,11,3; blrl; lis 3,-32697; addi 3,3,24012; bl _s8020812C_12; lwz 11,-21424(13); lwz 9,0x0(11); lha 3,0x88(9); lwz 0,0x8c(9); add 3,11,3; mtspr 8,0; blrl; b 9f; 7:; lwz 11,-21488(13); lwz 9,0x0(11); lwz 0,0x84(9); lha 3,0x80(9); mtspr 8,0; add 3,11,3; blrl; addi 4,1,8; bl _s8020812C_13; lwz 0,-31536(13); cmpwi 0,0; bne 8f; li 3,120; bl _s8020812C_14; bl _s8020812C_15; stw 3,-31536(13); 8:; lis 4,28199; lwz 3,-31536(13); ori 4,4,30903; li 25,0; bl _s8020812C_16; 9:; mr 3,23; li 4,2; bl _s8020812C_17; mr 3,22; li 4,2; bl _s8020812C_18; mr 3,25; lwz 0,0x64(1); mtspr 8,0; lmw 22,0x38(1); addi 1,1,96"
extern "C" void _s8020812C_0();
extern "C" void _s8020812C_1();
extern "C" void _s8020812C_2();
extern "C" void _s8020812C_3();
extern "C" void _s8020812C_4();
extern "C" void _s8020812C_5();
extern "C" void _s8020812C_6();
extern "C" void _s8020812C_7();
extern "C" void _s8020812C_8();
extern "C" void _s8020812C_9();
extern "C" void _s8020812C_10();
extern "C" void _s8020812C_11();
extern "C" void _s8020812C_12();
extern "C" void _s8020812C_13();
extern "C" void _s8020812C_14();
extern "C" void _s8020812C_15();
extern "C" void _s8020812C_16();
extern "C" void _s8020812C_17();
extern "C" void _s8020812C_18();
extern "C" void f_8020812C() {}
