// 0x801995A0 CASSelectionTarget::SetVariable(char (544 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 26,0x38(1); stw 0,0x54(1); mr 31,3; mr 30,4; lis 3,-32705; mr 29,5; addi 3,3,-14792; bl _s801995A0_0; cmpwi 3,0; bne 0f; mr 3,31; mr 4,29; bl _s801995A0_1; mr. 30,3; blt 6f; lwz 0,0x8c(31); cmpw 30,0; bge 6f; addi 9,31,748; lbzx 0,9,30; rlwinm 27,0,31,31,31; stb 0,0x8(1); cmpwi 27,0; bne 6f; mr 3,31; mr 4,30; bl _s801995A0_2; mr 4,29; li 5,2; addi 3,31,1496; bl _s801995A0_3; stb 27,0x5da(31); addi 9,31,148; mr 3,31; addi 4,1,48; lbzx 26,9,30; bl _s801995A0_4; cmpwi 3,0; beq 6f; lis 30,-32698; addi 28,1,16; lwz 3,0x84(31); addi 30,30,28616; li 0,3; addi 29,1,24; stw 0,0x10(1); mr 4,28; stw 30,0x14(1); bl _s801995A0_5; stw 30,0x14(1); mr 3,28; li 4,2; bl _s801995A0_6; lwz 11,0x30(1); lis 30,-32698; addi 30,30,25096; li 0,4; stw 0,0x18(1); li 9,2; stw 11,0x20(1); mr 4,29; stw 30,0x1c(1); stw 9,0xc(29); lwz 3,0x84(31); stw 26,0x28(1); stw 27,0x14(29); bl _s801995A0_7; mr 3,29; stw 30,0x1c(1); li 4,2; bl _s801995A0_8; lwz 9,0x84(31); lwz 3,0x1c(9); cmpwi 3,0; beq 6f; li 4,295; bl _s801995A0_9; b 6f; 0:; lis 3,-32705; mr 4,30; addi 3,3,-14776; bl _s801995A0_10; mr 28,3; cmpwi 28,0; bne 3f; mr 3,31; mr 4,29; bl _s801995A0_11; mr. 30,3; blt 1f; lwz 0,0x8c(31); cmpw 30,0; blt 2f; 1:; li 0,-1; stw 0,0x90(31); b 6f; 2:; mr 4,29; addi 3,31,1496; li 5,2; bl _s801995A0_12; stw 30,0x90(31); stb 28,0x5da(31); b 6f; 3:; lis 3,-32705; mr 4,30; addi 3,3,-14816; bl _s801995A0_13; cmpwi 3,0; bne 5f; lbz 0,0x0(29); extsb 0,0; addic. 0,0,-48; bne 4f; mr 3,31; bl _s801995A0_14; b 6f; 4:; cmpwi 0,1; bne 6f; mr 3,31; bl _s801995A0_15; b 6f; 5:; lis 3,-32705; mr 4,30; addi 3,3,-14756; bl _s801995A0_16; cmpwi 3,0; bne 6f; mr 3,31; bl _s801995A0_17; 6:; lwz 0,0x54(1); mtspr 8,0; lmw 26,0x38(1); addi 1,1,80"
extern "C" void _s801995A0_0();
extern "C" void _s801995A0_1();
extern "C" void _s801995A0_2();
extern "C" void _s801995A0_3();
extern "C" void _s801995A0_4();
extern "C" void _s801995A0_5();
extern "C" void _s801995A0_6();
extern "C" void _s801995A0_7();
extern "C" void _s801995A0_8();
extern "C" void _s801995A0_9();
extern "C" void _s801995A0_10();
extern "C" void _s801995A0_11();
extern "C" void _s801995A0_12();
extern "C" void _s801995A0_13();
extern "C" void _s801995A0_14();
extern "C" void _s801995A0_15();
extern "C" void _s801995A0_16();
extern "C" void _s801995A0_17();
extern "C" void f_801995A0() {}
