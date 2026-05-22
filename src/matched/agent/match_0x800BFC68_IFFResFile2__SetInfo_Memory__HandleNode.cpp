// 0x800BFC68 IFFResFile2::SetInfo(Memory::HandleNode (364 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stmw 26,0x60(1); stw 0,0x7c(1); mr 31,3; mr 30,4; lwz 9,0xc(31); mr 29,5; mr 26,6; lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; mr 3,31; li 4,-49; bl _s800BFC68_0; b 1f; 0:; mr 3,31; li 4,0; bl _s800BFC68_1; 1:; mr 3,31; bl _s800BFC68_2; cmpwi 3,0; bne 7f; lwz 3,0x138(31); mr 4,30; addi 5,1,88; li 6,0; bl _s800BFC68_3; mr. 27,3; beq 5f; lwz 0,0x4(27); li 30,0; cmpw 0,29; beq 2f; stw 29,0x4(27); li 30,1; 2:; addi 28,27,16; mr 3,26; mr 4,28; bl _s800BFC68_4; cmpwi 3,0; beq 3f; mr 4,26; mr 3,28; bl _s800BFC68_5; li 30,1; 3:; cmpwi 30,0; beq 6f; lwz 5,0x0(27); cmpwi 5,-1; beq 6f; mr 3,31; addi 4,1,8; bl _s800BFC68_6; mr. 26,3; bne 4f; lhz 0,0x6(27); addi 30,1,8; addi 29,1,20; mr 3,28; sth 0,0x10(1); bl _s800BFC68_7; mr 3,28; bl _s800BFC68_8; mr 4,3; li 5,63; mr 3,29; bl _s800BFC68_9; stb 26,0x4b(30); mr 4,30; mr 3,31; lwz 5,0x0(27); bl _s800BFC68_10; 4:; mr 4,26; mr 3,31; bl _s800BFC68_11; b 6f; 5:; mr 3,31; li 4,-99; bl _s800BFC68_12; 6:; addi 3,31,16; bl _s800BFC68_13; 7:; lwz 0,0x7c(1); mtspr 8,0; lmw 26,0x60(1); addi 1,1,120"
extern "C" void _s800BFC68_0();
extern "C" void _s800BFC68_1();
extern "C" void _s800BFC68_2();
extern "C" void _s800BFC68_3();
extern "C" void _s800BFC68_4();
extern "C" void _s800BFC68_5();
extern "C" void _s800BFC68_6();
extern "C" void _s800BFC68_7();
extern "C" void _s800BFC68_8();
extern "C" void _s800BFC68_9();
extern "C" void _s800BFC68_10();
extern "C" void _s800BFC68_11();
extern "C" void _s800BFC68_12();
extern "C" void _s800BFC68_13();
extern "C" void f_800BFC68() {}
