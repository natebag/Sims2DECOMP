// 0x800D51A8 NghResFile::ReadBothSection(void (572 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; mfcr 12; stmw 21,0x6c(1); stw 0,0x9c(1); stw 12,0x68(1); lis 9,-32696; li 0,0; lwz 11,0x6330(9); mr 29,3; mr 31,4; addi 11,11,72; li 4,1; lwz 28,0xc(11); lwz 30,0x8(11); stw 0,0x54(1); bl _s800D51A8_0; cmpwi 3,0; beq 0f; li 3,1; b 10f; 0:; li 0,1; mr. 21,31; stw 0,0x58(1); bne 1f; mr 4,30; mr 5,28; mr 3,29; addi 6,1,84; addi 7,1,88; bl _s800D51A8_1; mr 21,3; 1:; lwz 0,0x58(1); cmpwi 4,31,0; cmpwi 0,1; bne 8f; lwz 5,0x54(1); mr 4,21; mr 3,29; li 23,0; bl _s800D51A8_2; mr 25,3; li 5,64; lwz 22,0x18(25); addi 3,1,8; lwz 9,0x4(25); addi 4,3,8; rlwinm 0,22,2,0,29; add 26,25,9; add 27,26,0; add 28,27,0; add 24,28,0; bl _s800D51A8_3; cmplw 23,22; bge 6f; 2:; lwz 0,0x0(26); lwz 9,0x54(1); addi 26,26,4; stw 0,0x5c(1); cmpwi 9,0; lwz 0,0x0(27); addi 27,27,4; stw 0,0x60(1); lwz 9,0x0(28); addi 28,28,4; stw 9,0x64(1); lhz 0,0x0(24); addi 24,24,2; sth 0,0x50(1); bne 3f; addi 4,1,92; mr 3,29; bl _s800D51A8_4; addi 4,1,96; mr 3,29; bl _s800D51A8_5; mr 3,29; addi 4,1,100; bl _s800D51A8_6; mr 3,29; addi 4,1,80; bl _s800D51A8_7; 3:; lwz 31,0x64(1); bl _s800D51A8_8; li 4,12; li 5,0; bl _s800D51A8_9; mr 30,3; cmpwi 31,0; stw 31,0x0(30); beq 4f; bl _s800D51A8_10; mr 4,31; li 5,0; bl _s800D51A8_11; stw 3,0x4(30); b 5f; 4:; stw 31,0x4(30); 5:; li 0,1; lwz 3,0x4(30); stw 0,0x8(30); addi 23,23,1; lwz 4,0x60(1); lwz 5,0x64(1); add 4,25,4; crxor 6,6,6; bl _s800D51A8_12; lwz 9,0xc(29); mr 4,30; lwz 5,0x5c(1); addi 7,1,8; lha 3,0xf8(9); li 8,1; lwz 0,0xfc(9); add 3,29,3; lha 6,0x50(1); mtspr 8,0; blrl; cmplw 23,22; blt 2b; 6:; lwz 0,0x18c(29); cmpwi 0,0; beq 7f; lwz 0,0x20(29); cmpwi 0,0; bne 7f; lwz 0,0x10(25); stw 0,-31928(13); 7:; bl _s800D51A8_13; mr 4,25; bl _s800D51A8_14; 8:; bne cr4,9f; bl _s800D51A8_15; mr 4,21; bl _s800D51A8_16; 9:; lwz 3,0x58(1); 10:; lwz 0,0x9c(1); lwz 12,0x68(1); mtspr 8,0; lmw 21,0x6c(1); mtcrf 8,12; addi 1,1,152"
extern "C" void _s800D51A8_0();
extern "C" void _s800D51A8_1();
extern "C" void _s800D51A8_2();
extern "C" void _s800D51A8_3();
extern "C" void _s800D51A8_4();
extern "C" void _s800D51A8_5();
extern "C" void _s800D51A8_6();
extern "C" void _s800D51A8_7();
extern "C" void _s800D51A8_8();
extern "C" void _s800D51A8_9();
extern "C" void _s800D51A8_10();
extern "C" void _s800D51A8_11();
extern "C" void _s800D51A8_12();
extern "C" void _s800D51A8_13();
extern "C" void _s800D51A8_14();
extern "C" void _s800D51A8_15();
extern "C" void _s800D51A8_16();
extern "C" void f_800D51A8() {}
