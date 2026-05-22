// 0x800EC84C ObjectFolderImpl::~ObjectFolderImpl(void) (592 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lis 9,-32698; lis 11,-32698; lis 10,-32698; mr 29,3; addi 9,9,5640; addi 11,11,5664; addi 10,10,5696; mr 26,4; stw 9,0x4(29); stw 11,0x14(29); addi 31,29,1728; stw 10,0x0(29); bl _s800EC84C_0; lwz 0,0x8(31); cmpwi 0,0; beq 0f; lwz 9,0x4(31); mr 3,31; lwz 4,0x4(9); bl _s800EC84C_1; lwz 9,0x4(31); li 0,0; stw 9,0x8(9); lwz 11,0x4(31); stw 0,0x4(11); lwz 9,0x4(31); stw 9,0xc(9); stw 0,0x8(31); 0:; lwz 3,0x4(31); cmpwi 3,0; beq 1f; li 4,72; bl _s800EC84C_2; 1:; addi 3,29,1692; li 4,2; bl _s800EC84C_3; lwz 3,0x680(29); addi 9,29,1664; cmpwi 3,0; beq 3f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 2f; bl _s800EC84C_4; b 3f; 2:; bl _s800EC84C_5; 3:; lwz 3,0x670(29); addi 9,29,1648; cmpwi 3,0; beq 5f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 4f; bl _s800EC84C_6; b 5f; 4:; bl _s800EC84C_7; 5:; lwz 3,0x660(29); addi 9,29,1632; cmpwi 3,0; beq 7f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 6f; bl _s800EC84C_8; b 7f; 6:; bl _s800EC84C_9; 7:; addi 10,29,64; li 9,0; addi 31,29,40; addi 30,29,24; addi 27,29,8; li 8,0; 8:; rlwinm 11,9,2,0,29; addi 0,9,1; lwzx 9,10,11; cmpwi 9,0; beq 10f; stwx 8,10,11; 9:; lwz 9,0xa4(9); cmpwi 9,0; bne 9b; 10:; mr 9,0; cmpwi 9,255; ble 8b; lwz 0,0x8(31); li 28,0; cmpwi 0,0; beq 11f; lwz 9,0x4(31); mr 3,31; lwz 4,0x4(9); bl _s800EC84C_10; lwz 9,0x4(31); stw 9,0x8(9); lwz 11,0x4(31); stw 28,0x4(11); lwz 9,0x4(31); stw 9,0xc(9); stw 28,0x8(31); 11:; lwz 3,0x4(31); cmpwi 3,0; beq 12f; li 4,24; bl _s800EC84C_11; 12:; lwz 0,0x8(30); cmpwi 0,0; beq 13f; lwz 9,0x4(30); mr 3,30; lwz 4,0x4(9); bl _s800EC84C_12; lwz 9,0x4(30); stw 9,0x8(9); lwz 11,0x4(30); stw 28,0x4(11); lwz 9,0x4(30); stw 9,0xc(9); stw 28,0x8(30); 13:; lwz 3,0x4(30); cmpwi 3,0; beq 14f; li 4,24; bl _s800EC84C_13; 14:; mr 3,27; li 4,0; bl _s800EC84C_14; lis 9,-32698; andi. 0,26,1; addi 9,9,6296; stw 9,0x0(29); beq 15f; mr 3,29; bl _s800EC84C_15; 15:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800EC84C_0();
extern "C" void _s800EC84C_1();
extern "C" void _s800EC84C_2();
extern "C" void _s800EC84C_3();
extern "C" void _s800EC84C_4();
extern "C" void _s800EC84C_5();
extern "C" void _s800EC84C_6();
extern "C" void _s800EC84C_7();
extern "C" void _s800EC84C_8();
extern "C" void _s800EC84C_9();
extern "C" void _s800EC84C_10();
extern "C" void _s800EC84C_11();
extern "C" void _s800EC84C_12();
extern "C" void _s800EC84C_13();
extern "C" void _s800EC84C_14();
extern "C" void _s800EC84C_15();
extern "C" void f_800EC84C() {}
