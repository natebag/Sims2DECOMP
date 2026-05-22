// 0x800D54C0 NghResFile::ReadThumbSection(void (524 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; mfcr 12; stmw 18,0x60(1); stw 0,0x9c(1); stw 12,0x5c(1); lis 9,-32696; li 0,0; addi 31,9,25388; mr 25,3; lwz 9,0x4(31); mr 21,4; li 4,2; lwz 18,0x64(9); stw 0,0x50(1); bl _s800D54C0_0; cmpwi 3,0; li 3,1; bne 9f; mr 3,25; li 4,1; bl _s800D54C0_1; cmpwi 3,0; bne 0f; li 3,0; b 9f; 0:; li 0,1; mr 19,31; stw 0,0x54(1); li 23,0; cmpwi 4,21,0; li 20,1; addi 22,1,8; 1:; stw 20,0x54(1); beq cr4,2f; lwz 9,0x4(19); lwz 0,0x64(9); mullw 0,23,0; add 27,21,0; b 3f; 2:; lwz 9,0x4(19); mr 3,25; mr 5,18; addi 6,1,80; addi 9,9,96; addi 7,1,84; lwz 4,0x4(9); lwz 0,0x8(9); mullw 4,23,4; add 4,0,4; bl _s800D54C0_2; mr 27,3; 3:; lwz 0,0x54(1); cmpwi 0,1; bne 7f; lwz 5,0x50(1); mr 4,27; mr 3,25; bl _s800D54C0_3; mr 29,3; addi 4,22,8; lwz 24,0x4(29); mr 3,22; li 5,64; bl _s800D54C0_4; lwz 0,0xc(29); addi 9,23,1; lwz 30,0x8(29); rlwinm 26,9,0,16,31; lwz 28,0x18(29); cmpwi 0,0; beq 6f; bl _s800D54C0_5; li 4,12; li 5,0; bl _s800D54C0_6; mr 31,3; cmpwi 30,0; stw 30,0x0(31); beq 4f; bl _s800D54C0_7; mr 4,30; li 5,0; bl _s800D54C0_8; stw 3,0x4(31); b 5f; 4:; stw 30,0x4(31); 5:; stw 20,0x8(31); add 4,29,24; lwz 3,0x4(31); mr 5,30; crxor 6,6,6; bl _s800D54C0_9; cmpwi 28,0; beq 6f; mr 3,25; mr 5,28; mr 4,26; bl _s800D54C0_10; lwz 9,0xc(25); lis 5,29800; mr 4,31; extsh 6,26; lha 3,0xf8(9); ori 5,5,28002; lwz 0,0xfc(9); addi 7,1,8; add 3,25,3; li 8,1; mtspr 8,0; blrl; 6:; bl _s800D54C0_11; mr 4,29; bl _s800D54C0_12; 7:; bne cr4,8f; bl _s800D54C0_13; mr 4,27; bl _s800D54C0_14; 8:; lwz 3,0x54(1); cmpwi 3,1; bne 9f; addi 23,23,1; cmpwi 23,36; blt 1b; 9:; lwz 0,0x9c(1); lwz 12,0x5c(1); mtspr 8,0; lmw 18,0x60(1); mtcrf 8,12; addi 1,1,152"
extern "C" void _s800D54C0_0();
extern "C" void _s800D54C0_1();
extern "C" void _s800D54C0_2();
extern "C" void _s800D54C0_3();
extern "C" void _s800D54C0_4();
extern "C" void _s800D54C0_5();
extern "C" void _s800D54C0_6();
extern "C" void _s800D54C0_7();
extern "C" void _s800D54C0_8();
extern "C" void _s800D54C0_9();
extern "C" void _s800D54C0_10();
extern "C" void _s800D54C0_11();
extern "C" void _s800D54C0_12();
extern "C" void _s800D54C0_13();
extern "C" void _s800D54C0_14();
extern "C" void f_800D54C0() {}
