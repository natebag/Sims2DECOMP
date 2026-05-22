// 0x800BF744 IFFResFile2::AddWithLanguage(Memory::HandleNode (416 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 30,3; mr 24,4; lwz 11,0xc(30); mr 28,5; mr 26,6; mr 23,7; lha 3,0x60(11); mr 25,8; lwz 0,0x64(11); mr 27,9; add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; mr 3,30; li 4,-49; bl _s800BF744_0; b 1f; 0:; mr 3,30; li 4,0; bl _s800BF744_1; 1:; mr 3,30; bl _s800BF744_2; mr. 29,3; bne 10f; lwz 9,0xc(30); lha 3,0x60(9); lwz 0,0x64(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; bne 2f; mr 3,30; li 4,-49; bl _s800BF744_3; b 10f; 2:; lwz 9,0xc(30); lha 3,0x50(9); lwz 0,0x54(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; bne 3f; mr 3,30; li 4,-45; bl _s800BF744_4; b 10f; 3:; lwz 3,0x138(30); mr 4,28; mr 5,26; mr 6,25; li 7,0; bl _s800BF744_5; mr. 31,3; beq 6f; lwz 0,0xc(31); cmpw 0,24; bne 4f; stw 29,0xc(31); 4:; mr 4,31; mr 3,30; bl _s800BF744_6; mr. 4,3; beq 5f; mr 3,30; bl _s800BF744_7; b 10f; 5:; addi 3,30,16; bl _s800BF744_8; b 7f; 6:; lwz 3,0x138(30); mr 4,28; bl _s800BF744_9; mr 31,3; 7:; stw 26,0x4(31); cmpwi 27,0; beq 8f; li 0,16; sth 0,0x8(31); b 9f; 8:; sth 27,0x8(31); 9:; mr 4,25; addi 3,31,8; bl _s800BF744_10; li 0,0; stw 24,0xc(31); sth 0,0xa(31); mr 4,23; addi 3,31,16; bl _s800BF744_11; li 0,-1; stw 0,0x0(31); 10:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s800BF744_0();
extern "C" void _s800BF744_1();
extern "C" void _s800BF744_2();
extern "C" void _s800BF744_3();
extern "C" void _s800BF744_4();
extern "C" void _s800BF744_5();
extern "C" void _s800BF744_6();
extern "C" void _s800BF744_7();
extern "C" void _s800BF744_8();
extern "C" void _s800BF744_9();
extern "C" void _s800BF744_10();
extern "C" void _s800BF744_11();
extern "C" void f_800BF744() {}
