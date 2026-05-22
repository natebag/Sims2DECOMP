// 0x8031FDCC ERShader::InitDayNightShaders(int, (676 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 24,0x28(1); stw 0,0x4c(1); mr 24,3; mr 25,4; lis 3,-32692; li 4,-1; addi 3,3,-17444; bl _s8031FDCC_0; lis 3,-32693; li 4,-1; lwz 9,0x17b8(3); addi 3,3,6072; lha 0,0x10(9); lwz 9,0x14(9); add 3,0,3; mtspr 8,9; blrl; li 0,0; addi 9,1,8; lwz 10,-22620(13); addi 11,9,8; stw 0,0x8(1); mr 27,9; stw 0,0x4(9); li 4,0; stw 0,0x4(11); cmpwi 10,0; beq 1f; 0:; lwz 10,0x8(10); addi 4,4,1; cmpwi 10,0; bne 0b; 1:; addi 3,1,8; bl _s8031FDCC_1; lwz 28,-22620(13); cmpwi 28,0; beq 15f; mr 26,27; 2:; lwz 3,0x0(28); bl _s8031FDCC_2; lwz 9,0x4(26); lwz 0,0xc(26); cmpw 9,0; beq 3f; lwz 0,0x0(28); stw 0,0x0(9); lwz 9,0x4(27); addi 9,9,4; stw 9,0x4(27); b 14f; 3:; lwz 30,0x4(27); li 9,1; lwz 0,0x8(1); addi 11,1,36; stw 9,0x24(1); addi 10,1,32; subf 0,0,30; srawi 9,0,2; stw 9,0x20(1); cmplwi 9,1; bge 4f; mr 10,11; 4:; lwz 0,0x0(10); add. 0,9,0; beq 6f; rlwinm 0,0,2,0,29; mr 29,0; cmplwi 0,128; ble 5f; mr 3,29; bl _s8031FDCC_3; mr 31,3; b 7f; 5:; mr 3,29; bl _s8031FDCC_4; mr 31,3; b 7f; 6:; li 31,0; li 29,0; 7:; lwz 4,0x0(27); cmpw 30,4; beq 8f; subf 30,4,30; mr 3,31; mr 5,30; bl _s8031FDCC_5; add 0,3,30; b 9f; 8:; mr 0,31; 9:; lwz 9,0x24(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 11f; 10:; lwz 0,0x0(28); stw 0,0x0(30); addi 30,30,4; bdnz 10b; 11:; lwz 3,0x0(27); lwz 0,0xc(27); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 13f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 12f; bl _s8031FDCC_6; b 13f; 12:; bl _s8031FDCC_7; 13:; add 0,29,31; stw 31,0x0(27); stw 30,0x4(27); stw 0,0xc(27); 14:; lwz 28,0x8(28); cmpwi 28,0; bne 2b; 15:; lis 3,-32693; lwz 9,0x17b8(3); addi 3,3,6072; lha 0,0x18(9); lwz 9,0x1c(9); add 3,0,3; mtspr 8,9; blrl; lis 3,-32692; addi 3,3,-17444; bl _s8031FDCC_8; lwz 30,0x8(1); lwz 0,0x4(27); cmpw 30,0; beq 18f; 16:; lwz 3,0x0(30); lwz 0,0x58(3); andi. 9,0,32; beq 17f; mr 4,24; mr 5,25; bl _s8031FDCC_9; 17:; lwz 0,0x4(27); addi 30,30,4; cmpw 30,0; bne 16b; 18:; lwz 30,0x8(1); b 20f; 19:; lwz 3,0x0(30); addi 30,30,4; bl _s8031FDCC_10; 20:; lwz 0,0x4(27); cmpw 30,0; bne 19b; lwz 3,0x8(1); cmpwi 3,0; beq 22f; lwz 0,0xc(27); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 21f; bl _s8031FDCC_11; b 22f; 21:; bl _s8031FDCC_12; 22:; lwz 0,0x4c(1); mtspr 8,0; lmw 24,0x28(1); addi 1,1,72"
extern "C" void _s8031FDCC_0();
extern "C" void _s8031FDCC_1();
extern "C" void _s8031FDCC_2();
extern "C" void _s8031FDCC_3();
extern "C" void _s8031FDCC_4();
extern "C" void _s8031FDCC_5();
extern "C" void _s8031FDCC_6();
extern "C" void _s8031FDCC_7();
extern "C" void _s8031FDCC_8();
extern "C" void _s8031FDCC_9();
extern "C" void _s8031FDCC_10();
extern "C" void _s8031FDCC_11();
extern "C" void _s8031FDCC_12();
extern "C" void f_8031FDCC() {}
