// 0x800BF920 IFFResFile2::Write(Memory::HandleNode (572 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stmw 26,0x60(1); stw 0,0x7c(1); mr 31,3; mr 26,4; lwz 9,0xc(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; mr 3,31; li 4,-49; bl _s800BF920_0; b 1f; 0:; mr 3,31; li 4,0; bl _s800BF920_1; 1:; mr 3,31; bl _s800BF920_2; cmpwi 3,0; bne 10f; lwz 9,0xc(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 2f; mr 3,31; li 4,-49; bl _s800BF920_3; b 10f; 2:; lwz 9,0xc(31); lha 3,0x50(9); lwz 0,0x54(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 3f; mr 3,31; li 4,-45; bl _s800BF920_4; b 10f; 3:; lwz 3,0x138(31); mr 4,26; addi 5,1,88; li 6,0; bl _s800BF920_5; mr. 27,3; bne 4f; mr 3,31; li 4,-99; bl _s800BF920_6; b 10f; 4:; mr 3,31; li 4,0; bl _s800BF920_7; cmpwi 26,0; li 0,0; beq 5f; lwz 0,0x0(26); 5:; lwz 5,0x0(27); stw 0,0x5c(1); cmpwi 5,-1; beq 6f; mr 3,31; addi 4,1,8; bl _s800BF920_8; lwz 9,0x5c(1); lwz 0,0xc(1); addi 9,9,76; cmpw 0,9; beq 7f; lwz 4,0x0(27); mr 3,31; bl _s800BF920_9; lwz 5,0x5c(1); mr 3,31; addi 4,1,8; mr 6,27; bl _s800BF920_10; b 7f; 6:; mr 5,0; mr 3,31; addi 4,1,8; mr 6,27; bl _s800BF920_11; 7:; lwz 0,0x58(1); addi 30,27,16; addi 29,1,8; addi 28,1,20; stw 0,0x8(1); mr 3,30; lhz 0,0x6(27); sth 0,0x10(1); lhz 9,0x8(27); sth 9,0x12(1); bl _s800BF920_12; mr 3,30; bl _s800BF920_13; mr 4,3; li 5,63; mr 3,28; bl _s800BF920_14; li 0,0; mr 4,29; stb 0,0x4b(29); mr 3,31; lwz 5,0x0(27); bl _s800BF920_15; mr. 4,3; bne 8f; lwz 4,0x0(27); addi 30,31,16; mr 3,30; addi 4,4,76; bl _s800BF920_16; mr. 4,3; bne 8f; lwz 4,0x4(26); mr 3,30; addi 5,1,92; bl _s800BF920_17; mr. 4,3; beq 9f; 8:; mr 3,31; bl _s800BF920_18; b 10f; 9:; lhz 0,0x8(27); mr 3,30; sth 0,0xa(27); bl _s800BF920_19; 10:; lwz 0,0x7c(1); mtspr 8,0; lmw 26,0x60(1); addi 1,1,120"
extern "C" void _s800BF920_0();
extern "C" void _s800BF920_1();
extern "C" void _s800BF920_2();
extern "C" void _s800BF920_3();
extern "C" void _s800BF920_4();
extern "C" void _s800BF920_5();
extern "C" void _s800BF920_6();
extern "C" void _s800BF920_7();
extern "C" void _s800BF920_8();
extern "C" void _s800BF920_9();
extern "C" void _s800BF920_10();
extern "C" void _s800BF920_11();
extern "C" void _s800BF920_12();
extern "C" void _s800BF920_13();
extern "C" void _s800BF920_14();
extern "C" void _s800BF920_15();
extern "C" void _s800BF920_16();
extern "C" void _s800BF920_17();
extern "C" void _s800BF920_18();
extern "C" void _s800BF920_19();
extern "C" void f_800BF920() {}
