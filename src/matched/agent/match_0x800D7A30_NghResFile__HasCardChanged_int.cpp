// 0x800D7A30 NghResFile::HasCardChanged(int, (492 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 22,0x10(1); stw 0,0x3c(1); lwz 0,0x20(3); mr 27,4; mr 24,5; cmpwi 0,1; bne 1f; li 3,0; b 8f; 0:; li 31,0; b 5f; 1:; addi 23,3,40; lis 9,-32696; addi 22,9,25388; mr 28,23; li 25,0; li 26,0; b 4f; 2:; lwz 29,-26384(13); mr 3,28; lwz 30,0x0(29); lha 0,0x20(30); addi 30,30,32; add 29,29,0; bl _s800D7A30_0; lwz 0,0x4(30); mr 4,3; mr 3,29; mr 5,27; mtspr 8,0; blrl; mr 31,3; cmpwi 31,1; bne 5f; bl _s800D7A30_1; li 25,1; li 4,8192; li 5,64; li 6,0; li 7,0; bl _s800D7A30_2; mr. 26,3; beq 0b; lwz 29,-26384(13); mr 3,28; lwz 30,0x0(29); lha 0,0x38(30); addi 30,30,56; add 29,29,0; bl _s800D7A30_3; lwz 9,0x4(22); mr 4,3; lwz 0,0x4(30); mr 3,29; lwz 7,0x50(9); mr 5,27; li 6,8192; mr 8,26; mtspr 8,0; blrl; mr 31,3; cmpwi 31,1; bne 5f; lwz 9,0x10(26); li 11,0; lwz 0,-31928(13); cmpw 9,0; beq 3f; lwz 0,-31924(13); cmpw 9,0; beq 3f; li 11,1; 3:; stw 11,0x0(24); b 5f; 4:; lwz 29,-26384(13); mr 3,28; lwz 30,0x0(29); lha 0,0xc8(30); addi 30,30,200; add 29,29,0; bl _s800D7A30_4; lwz 0,0x4(30); mr 4,3; mr 3,29; mr 5,27; addi 6,1,8; mtspr 8,0; blrl; mr 31,3; cmpwi 31,1; bne 5f; lwz 0,0x8(1); cmpwi 0,0; bne 2b; li 31,-7; 5:; cmpwi 26,0; beq 6f; bl _s800D7A30_5; mr 4,26; bl _s800D7A30_6; 6:; cmpwi 25,0; beq 7f; lwz 29,-26384(13); mr 3,23; lwz 30,0x0(29); lha 0,0x28(30); addi 30,30,40; add 29,29,0; bl _s800D7A30_7; lwz 0,0x4(30); mr 4,3; mr 3,29; mr 5,27; mtspr 8,0; blrl; 7:; mr 3,31; 8:; lwz 0,0x3c(1); mtspr 8,0; lmw 22,0x10(1); addi 1,1,56"
extern "C" void _s800D7A30_0();
extern "C" void _s800D7A30_1();
extern "C" void _s800D7A30_2();
extern "C" void _s800D7A30_3();
extern "C" void _s800D7A30_4();
extern "C" void _s800D7A30_5();
extern "C" void _s800D7A30_6();
extern "C" void _s800D7A30_7();
extern "C" void f_800D7A30() {}
