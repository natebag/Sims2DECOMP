// 0x800B3354 ChainResFile::AddWithLanguage(Memory::HandleNode (540 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 21,0xc(1); stw 0,0x3c(1); mr 30,3; mr 25,4; mr 27,5; mr 24,6; mr 23,8; mr 21,9; mr 22,7; li 4,0; bl _s800B3354_0; lwz 9,0xc(30); mr 4,27; mr 5,24; mr 6,23; lha 3,0x98(9); li 7,0; lwz 0,0x9c(9); add 3,30,3; mtspr 8,0; blrl; mr. 3,3; beq 1f; cmpw 3,25; bne 0f; lwz 9,0xc(30); mr 4,25; lwz 0,0xdc(9); lha 3,0xd8(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0xc(30); mr 4,27; mr 5,24; mr 6,23; lha 3,0x98(9); li 7,0; lwz 0,0x9c(9); add 3,30,3; mtspr 8,0; blrl; 0:; lwz 9,0xc(30); mr 4,3; lha 3,0x110(9); lwz 0,0x114(9); add 3,30,3; mtspr 8,0; blrl; mr 3,30; bl _s800B3354_1; cmpwi 3,0; bne 11f; 1:; mr 3,30; li 4,-94; bl _s800B3354_2; li 26,0; addi 9,30,16; lwzx 0,9,26; mr 29,9; cmpwi 0,0; beq 11f; addi 31,30,20; li 28,0; 2:; lwz 9,0x0(31); li 8,1; lwz 0,0x4(31); li 11,0; addi 10,30,36; b 4f; 3:; lwz 0,0x4(31); addi 9,9,4; 4:; cmpw 9,0; beq 5f; lwz 0,0x0(9); cmpw 0,27; bne 3b; li 11,1; 5:; lwzx 0,10,28; cmpwi 0,0; beq 6f; cmpwi 11,0; beq 8f; b 7f; 6:; cmpwi 11,0; bne 8f; 7:; li 8,0; 8:; cmpwi 8,0; beq 9f; lwzx 3,28,29; lwz 9,0xc(3); lha 0,0x50(9); lwz 9,0x54(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 10f; lwzx 10,28,29; mr 4,25; mr 5,27; mr 6,24; lwz 11,0xc(10); mr 7,22; mr 8,23; mr 9,21; lha 3,0x100(11); lwz 0,0x104(11); add 3,10,3; mtspr 8,0; blrl; lwzx 3,28,29; bl _s800B3354_3; mr 4,3; mr 3,30; bl _s800B3354_4; b 11f; 9:; mr 3,30; li 4,-92; bl _s800B3354_5; 10:; addi 26,26,1; addi 31,31,24; addi 28,28,24; cmpwi 26,7; bgt 11f; lwzx 0,28,29; cmpwi 0,0; bne 2b; 11:; lwz 0,0x3c(1); mtspr 8,0; lmw 21,0xc(1); addi 1,1,56"
extern "C" void _s800B3354_0();
extern "C" void _s800B3354_1();
extern "C" void _s800B3354_2();
extern "C" void _s800B3354_3();
extern "C" void _s800B3354_4();
extern "C" void _s800B3354_5();
extern "C" void f_800B3354() {}
