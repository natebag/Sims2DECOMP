// 0x8004C644 ISimsObjectModel::~ISimsObjectModel(void) (428 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 30,3; lis 11,-32698; lwz 10,0x3c8(30); lis 9,-32698; addi 11,11,-15896; addi 9,9,-15840; mr 24,4; stw 11,0x320(30); stw 9,0x0(30); cmpwi 10,0; beq 0f; lwz 4,0x1c(10); bl _s8004C644_0; 0:; addi 29,30,1104; lwz 9,0x4(29); mr 25,29; addi 28,30,1088; addi 27,30,1188; addi 26,30,1124; b 3f; 1:; lwz 0,0x8(29); lwz 11,0x0(9); cmpwi 0,0; lwz 31,0x4(9); beq 2f; lwz 9,0x0(11); lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 2:; mr 9,31; 3:; li 31,1; cmpwi 9,0; bne 4f; li 31,0; 4:; cmpwi 31,0; bne 1b; mr 3,29; bl _s8004C644_1; lwz 3,0x41c(30); cmpwi 3,0; beq 5f; bl _s8004C644_2; stw 31,0x41c(30); 5:; lwz 9,0x4(28); b 8f; 6:; lwz 0,0x8(28); lwz 3,0x0(9); cmpwi 0,0; lwz 31,0x4(9); beq 7f; cmpwi 3,0; beq 7f; li 4,3; bl _s8004C644_3; 7:; mr 9,31; 8:; li 31,1; cmpwi 9,0; bne 9f; li 31,0; 9:; cmpwi 31,0; bne 6b; mr 3,28; bl _s8004C644_4; lwz 4,0x4b4(30); cmpwi 4,0; beq 10f; lis 3,-32693; addi 3,3,11064; bl _s8004C644_5; stw 31,0x4b4(30); 10:; lwz 3,0x4a4(30); cmpwi 3,0; beq 12f; lwz 0,0xc(27); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 11f; bl _s8004C644_6; b 12f; 11:; bl _s8004C644_7; 12:; li 4,2; mr 3,26; bl _s8004C644_8; mr 3,25; bl _s8004C644_9; mr 3,28; bl _s8004C644_10; mr 3,30; li 4,0; bl _s8004C644_11; andi. 0,24,1; beq 13f; bl _s8004C644_12; mr 4,30; bl _s8004C644_13; 13:; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void _s8004C644_0();
extern "C" void _s8004C644_1();
extern "C" void _s8004C644_2();
extern "C" void _s8004C644_3();
extern "C" void _s8004C644_4();
extern "C" void _s8004C644_5();
extern "C" void _s8004C644_6();
extern "C" void _s8004C644_7();
extern "C" void _s8004C644_8();
extern "C" void _s8004C644_9();
extern "C" void _s8004C644_10();
extern "C" void _s8004C644_11();
extern "C" void _s8004C644_12();
extern "C" void _s8004C644_13();
extern "C" void f_8004C644() {}
